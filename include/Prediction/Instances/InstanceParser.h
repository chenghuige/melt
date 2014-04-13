/**
*  ==============================================================================
*
*          \file   Prediction/Instances/InstanceParser.h
*
*        \author   chenghuige
*
*          \date   2014-03-27 17:47:57.438203
*
*  \Description:   输入是数据文件 可能是dense 或者 sparse格式 输出是Instances
*                  @TODO目前只考虑Instances内容数组都保存在内存 不考虑 StreamingInstances @TODO
* 输入数据格式 dense (default)
*  //with header
*	#id label age weight
*  _123 0    32   18
*  //whithout header
*  _123 0  32 18 //id label feature1 feature2
* 输入数据格式 sparse (default)
*   0 5 0:0.4 3:0.1
*   1 5 1:0.3
* 内部数据处理和TLC一致 不管输入是dense还是sparse都是判断当前0的数目 如果> 1/2 * FeatureNum 则dense否则sparse
*  ==============================================================================
*/

#ifndef PREDICTION__INSTANCES__INSTANCE_PARSER_H_
#define PREDICTION__INSTANCES__INSTANCE_PARSER_H_

#include "common_util.h"
#include "RegexSearcher.h"
#include "Identifer.h"
#include "Prediction/Instances/Instances.h"

namespace gezi {

	//不做clear清理工作每次 create 一个新的InstanceParser使用即可
	class InstanceParser
	{
	public:
		struct Arguments
		{
			int labelIdx = -1;
			int weightIdx = -1;
			//nameIdx|, seprated like 1,2,3, name filed will be shown in .inst.txt result file
			string namesIdx = "";
			//|the same as nameIdx, attrIdx will be filed to be ignored
			string attrsIdx = "";
			bool hasHeader = false; //|header: no header by default
			string sep = "tab"; //|or space or something like , ; etc. 
			string ncsep = "|"; //|contact names filed like pid|title|content 4003|good title|good content
			//|excl vs. incl determines whether features for the expression below are included or excluded. expression=[s:substringList | r:regexList | i:indexList | e:exactNameList]
			string excl = "";
			//|use excl will exlude those specified, use incl will only include those specified, use incl + excl means first incl then excl
			string incl = "";
			bool keepSparse = false; //sparse|
			bool keepDense = false; //dense|
			string inputFormat = "normal";//format|support melt/tlc format as normal, also support libSVM, may support weka/arff, malloc format later

			string resultDir = "";//rd|
		};

		InstanceParser()
		{
			ParseArguments();
			InitParam();
		}

		void ParseArguments();

		Arguments& Args()
		{
			return _args;
		}

		ivec GetIndexesFromInput(string input)
		{
			ivec result;
			svec sv = split(input, ",");
			for (auto item : sv)
			{
				if (contains(item, "-"))
				{
					svec t = split(item, "-");
					int start = INT(t[0]);
					int end = INT(t[1]) + 1;
					for (int i = start; i < end; i++)
					{
						result.push_back(i);
					}
				}
				else
				{
					result.push_back(INT(item));
				}
			}
		}
		void InitParam()
		{
			_format = boost::to_lower_copy(_args.inputFormat);
			if (_args.sep == "tab")
			{
				_sep = "\t";
			}
			else if (_args.sep == "space")
			{
				_sep = " ";
			}
			else if (_args.sep.empty())
			{
				_sep = "\t";
			}
			else
			{
				_sep = _args.sep;
			}

			if (_format == "libsvm")
			{
				_sep = " ";
			}


			if (!_args.attrsIdx.empty())
			{
				_attributesIdx = GetIndexesFromInput(_args.attrsIdx);
				PVEC(_attributesIdx);
			}

			if (!_args.namesIdx.empty())
			{
				_namesIdx = GetIndexesFromInput(_args.namesIdx);
				PVEC(_namesIdx);
			}
		}

		//@TODO 当前值考虑支持一种 比如 i, e, s, r不考虑多个同时存在,一般 最常用的r 正则匹配即可
		ivec GetSelectedFeatures(string input)
		{
			string pattern, content;
			if (contains(input, ":"))
			{
				pattern = input.substr(0, 1);
				content = input.substr(2);
			}
			else
			{
				pattern = "r";
				content = input;
			}
			if (pattern == "i")
			{
				return GetIndexesFromInput(content);
			}
			ivec result;
			svec t = split(content, ",");
			set<string> s(t.begin(), t.end());
			if (pattern == "e")
			{ //exact
				for (int i = 0; i < _featureNum; i++)
				{
					if (s.count(_instances.schema.featureNames[i]))
					{
						result.push_back(i);
					}
				}
			}
			else if (pattern == "s")
			{ //substr
				for (int i = 0; i < _featureNum; i++)
				{
					for (auto p : s)
					{
						if (contains(_instances.schema.featureNames[i], p))
						{
							result.push_back(i);
						}
					}
				}
			}
			else if (pattern == "r")
			{ //regex
				RegexSearcher rs;
				rs.add(s);
				for (int i = 0; i < _featureNum; i++)
				{
					if (rs.has_match(_instances.schema.featureNames[i]))
					{
						result.push_back(i);
					}
				}
			}
			else
			{
				LOG(FATAL) << "Unsupported pattern " << input << " only support i: e: s: r:";
			}
			return result;
		}

		BitArray GetSelectedArray()
		{
			BitArray filterArray;
			if (!_args.incl.empty())
			{
				ivec incls = GetSelectedFeatures(_args.incl);

				if (incls.empty())
				{
					LOG(WARNING) << "Do not has any match for incl " << _args.incl;
				}
				else
				{
					filterArray.resize(_featureNum, false);
					for (int idx : incls)
					{
						LOG(INFO) << "Including feature: " << _instances.schema.featureNames[idx];
						filterArray[idx] = true;
					}
				}
			}

			if (!_args.excl.empty())
			{
				ivec excls = GetSelectedFeatures(_args.excl);

				if (excls.empty())
				{
					LOG(WARNING) << "Do not has any match for excl " << _args.excl;
				}
				else
				{
					if (filterArray.empty())
					{
						filterArray.resize(_featureNum, true);
					}
					for (int idx : excls)
					{
						LOG(INFO) << "Excluding feature: " << _instances.schema.featureNames[idx];
						filterArray[idx] = false;
					}
				}
			}

			if (filterArray.empty())
			{
				filterArray.resize(_featureNum, true);
			}

			return filterArray;
		}
		bool IsSparse()
		{
			return !IsDense();
		}
		bool IsDense()
		{
			return _fileFormat == FileFormat::Dense;
		}
		void InitColumnTypes(svec& lines)
		{
			for (int idx : _attributesIdx)
			{
				_columnTypes[idx] = ColumnType::Attribute;
			}

			for (int idx : _namesIdx)
			{
				_columnTypes[idx] = ColumnType::Name;
			}

			if (_args.weightIdx >= 0)
			{
				_columnTypes[_args.weightIdx] = ColumnType::Weight;
				_hasWeight = true;
			}

			if (_args.labelIdx >= 0)
			{
				_columnTypes[_args.labelIdx] = ColumnType::Label;
				_labelIdx = _args.labelIdx;
			}

			if (startswith(_firstColums[0], '#'))
			{
				_hasHeader = true;
				_columnTypes[0] = ColumnType::Name;

				if (_labelIdx < 0)
				{
					_labelIdx = 1;
					_columnTypes[1] = ColumnType::Label;
				}
			}

			//前面确认了是否有header
			if (_hasHeader)
			{
				_headerColums.swap(_firstColums);
				_firstColums = split(lines[_hasHeader], _sep);
			}

			if (startswith(_firstColums[0], '_'))
			{
				{
					_columnTypes[0] = ColumnType::Name;
					if (_labelIdx < 0)
					{
						_labelIdx = 1;
						_columnTypes[1] = ColumnType::Label;
					}
				}
			}

			if (_labelIdx < 0)
			{
				_labelIdx = 0;
				_columnTypes[0] = ColumnType::Label;
			}
		}

		//实际上Dense,Sparse格式 在这里完成了设置, SparseNoLength, Text将会在create instances中设置
		void InitNames()
		{
			if (_hasHeader)
			{
				for (int i = 0; i < _columnNum; i++)
				{
					switch (_columnTypes[i])
					{
					case ColumnType::Feature:
						_instances.schema.featureNames.push_back(_headerColums[i]);
						break;
					case ColumnType::Attribute:
						_instances.schema.attributeNames.push_back(_headerColums[i]);
						break;
					case ColumnType::Name:
						_instances.schema.tagNames.push_back(_headerColums[i]);
						break;
					default:
						break;
					}
				}
				_featureNum = _instances.FeatureNum();
			}
			else
			{
				int i = 0;
				if (_fileFormat == FileFormat::Dense)
				{
					for (auto type : _columnTypes)
					{
						if (type == ColumnType::Feature)
						{
							string name = "f" + STR(i);
							_instances.schema.featureNames.push_back(name);
							i++;
						}
					}
					_featureNum = _instances.FeatureNum();
				}
				else if (_fileFormat == FileFormat::Sparse)
				{ //注意已经解析首个数据行 获取到 特征数目了 但是注意 SparseNoLength, Text获取不到
					for (int i = 0; i < _featureNum; i++)
					{
						string name = "f" + STR(i);
						_instances.schema.featureNames.push_back(name);
					}
				}
			}
		}

		void SetSparseFeatureNames()
		{
			if (!_hasHeader)
			{
				for (int i = 0; i < _featureNum; i++)
				{
					string name = "f" + STR(i);
					_instances.schema.featureNames.push_back(name);
				}
			}
		}
		void SetTextFeatureNames()
		{
			if (!_hasHeader)
			{
				_instances.schema.featureNames = GetIdentifer().keys();
			}
		}
		void CreateInstancesFromDenseFormat(svec& lines, uint64 start)
		{
			uint64 end = start + _instanceNum;
#pragma omp parallel for 
			for (uint64 i = start; i < end; i++)
			{
				string line = lines[i];
				_instances[i - start] = make_shared<Instance>(_featureNum);
				Instance& instance = *_instances[i - start];
				Vector& features = instance.features;
				features.PrepareDense();
				svec l = split(line, _sep);
				CHECK_EQ(l.size(), _columnNum) << "has bad line"; //不允许有坏数据行
				int fidx = 0;
				double value = 0;
				for (int j = 0; j < _columnNum; j++)
				{
					string item = l[j];
					switch (_columnTypes[j])
					{
					case ColumnType::Feature:
						value = _selectedArray[fidx++] ? DOUBLE(item) : 0;
						features.Add(value);
						break;
					case ColumnType::Name:
						instance.names.push_back(item);
						break;
					case ColumnType::Label:
						instance.label = DOUBLE(item);
						break;
					case ColumnType::Weight:
						instance.weight = DOUBLE(item);
						break;
					case ColumnType::Attribute:
						instance.attributes.push_back(item);
						break;
					default:
						break;
					}
				}

				if (_args.keepSparse)
				{
					features.ToSparse();
				}
				else if (!_args.keepDense)
				{//if not keep dense   如果是0值数目<= FeatureNum/2转 sparse
					features.Sparsify(0.5);
				}

				if (!instance.names.empty())
				{
					if (startswith(instance.names[0], "_"))
						instance.names[0] = instance.names[0].substr(1);
					instance.name = join(instance.names, _args.ncsep);
				}
			}
		}

		//@TODO Instance Next(string line) 支持streaming
		//@TODO tlc貌似快很多thread.feature.txt 9w instance 
		//1000ms 这里需要2000ms是因为split c#的速度更快？ 另外注意能char split find不要用string
		//不过使用omp并行后 200ms就搞定
		void CreateInstancesFromSparseFormat(svec& lines, uint64 start)
		{
			uint64 end = start + _instanceNum;
#pragma omp parallel for 
			for (uint64 i = start; i < end; i++)
			{
				string line = lines[i];
				_instances[i - start] = make_shared<Instance>(_featureNum);
				Instance& instance = *_instances[i - start];
				Vector& features = instance.features;
				svec l = split(line, _sep);

				for (size_t j = 0; j < l.size(); j++)
				{
					string item = l[j];
					string index_, value_;
					bool ret = split(item, ':', index_, value_);
					if (ret)
					{
						int index = INT(index_); Float value = DOUBLE(value_);
						if (_selectedArray[index])
							features.Add(index, value);
					}
					else
					{
						//@TODO 暂时没有检查格式正确性 要求的是 所有非:的数据 都在后面
						switch (_columnTypes[j])
						{
						case ColumnType::Name:
							instance.names.push_back(item);
							break;
						case ColumnType::Label:
							instance.label = DOUBLE(item);
							break;
						case ColumnType::Weight:
							instance.weight = DOUBLE(item);
							break;
						case ColumnType::Attribute:
							instance.attributes.push_back(item);
							break;
						default:
							break;
						}
					}
				}
				if (_args.keepDense)
				{
					features.ToDense();
				}
				else if (!_args.keepSparse)
				{//if not keep sparse  如果是0值数目> FeatureNum/2转dense
					features.Densify(0.5);
				}

				instance.name = join(instance.names, _args.ncsep);
			}
		}

		void CreateInstancesFromSparseNoLengthFormat(svec& lines, uint64 start)
		{
			uint64 end = start + _instanceNum;
			int maxIndex = 0;
#pragma omp parallel for 
			for (uint64 i = start; i < end; i++)
			{
				string line = lines[i];
				_instances[i - start] = make_shared<Instance>();
				Instance& instance = *_instances[i - start];
				Vector& features = instance.features;
				svec l = split(line, _sep);

				for (size_t j = 0; j < l.size(); j++)
				{
					string item = l[j];
					string index_, value_;
					bool ret = split(item, ':', index_, value_);
					if (ret)
					{
						int index = INT(index_); Float value = DOUBLE(value_);
						if (_selectedArray[index])
							features.Add(index, value);
#pragma omp critical
						{
							if (index > maxIndex)
							{
								maxIndex = index;
							}
						}
					}
					else
					{
						//@TODO 暂时没有检查格式正确性 要求的是 所有非:的数据 都在后面 如果不符合会越界
						switch (_columnTypes[j])
						{
						case ColumnType::Name:
							instance.names.push_back(item);
							break;
						case ColumnType::Label:
							instance.label = DOUBLE(item);
							break;
						case ColumnType::Weight:
							instance.weight = DOUBLE(item);
							break;
						case ColumnType::Attribute:
							instance.attributes.push_back(item);
							break;
						default:
							break;
						}
					}
				}
				instance.name = join(instance.names, _args.ncsep);
			}
			_featureNum = maxIndex + 1;
			SetSparseFeatureNames();
#pragma omp parallel for 
			for (uint64 i = 0; i < _instanceNum; i++)
			{
				Vector& features = _instances[i]->features;
				features.SetLength(_featureNum);
				if (_args.keepDense)
				{
					features.ToDense();
				}
				else if (!_args.keepSparse)
				{//if not keep sparse  如果是0值数目> FeatureNum/2转dense
					features.Densify(0.5);
				}
			}
		}

		FileFormat GetFileFormat(string line)
		{
			for (int i = 0; i < _columnNum; i++)
			{
				if (_columnTypes[i] == ColumnType::Feature)
				{
					if (contains(_firstColums[i], ':'))
					{
						return FileFormat::SparseNoLenth;
					}

					int j = i + 1;
					while (j < _columnNum && _columnTypes[j] != ColumnType::Feature)
					{
						j++;
					}

					if (j == _columnNum)
					{
						return FileFormat::Dense;
					}
					else
					{
						if (contains(_firstColums[j], ':'))
						{
							_featureNum = INT(_firstColums[i]);
							_columnTypes[i] = ColumnType::Attribute;
							return FileFormat::Sparse;
						}
						else
						{
							return FileFormat::Dense;
						}
					}
				}
			}
			LOG(FATAL) << "Data format wrong not feature field " << line;
		}

		void SetHeaderSchema(string line)
		{
			_instances.SetHeader(line, _hasHeader);
			_instances.schema.fileFormat = _fileFormat;
			_instances.schema.hasWeights = _hasWeight;
			_instances.schema.cloumnTypes = _columnTypes;
		}

		//获取列信息，名字，是dense还是sparse表示
		void ParseFirstLine(svec lines)
		{
			string line = lines[0];
			_firstColums = split(line, _sep);
			_columnNum = _firstColums.size();
			PVAL(_columnNum);
			if (_columnNum < 2)
			{
				LOG(FATAL) << "The header must at least has label and one feature";
			}
			_columnTypes.resize(_columnNum, ColumnType::Feature);
			InitColumnTypes(lines);
			//libsvm格式已经特殊处理 这里可能的是 normal, text
			_fileFormat = _format == "text" ? FileFormat::Text : GetFileFormat(lines[_hasHeader]);
			InitNames();
			SetHeaderSchema(line);
		}

		void PrintInfo()
		{
			Pval(_instances.FeatureNum());
			Pval(_instances.Count());
			uint64 positiveCount = _instances.PositiveCount();
			Pval(positiveCount);
			Float positiveRatio = positiveCount / (double)_instances.Count();
			Pval(positiveRatio);

			PVEC(_instances.schema.tagNames);
			PVEC(_instances.schema.attributeNames);
			PVAL(IsDense());
			if (IsDense())
			{
				PVEC(_instances.schema.featureNames);
			}
			else
			{
				PVEC_TOPN(_instances.schema.featureNames, 10);
			}
			PVAL(_args.keepSparse);
			PVAL(_args.keepDense);
		}

		//libsvm格式不支持过滤特征 仅仅为了方便一直使用libsvm的同学
		Instances&& ParseLibSVM(string dataFile)
		{
			Timer timer;
			vector<string> lines = read_lines(dataFile);
			Pval_(timer.elapsed_ms(), "read_lines");
			if (lines.empty())
			{
				LOG(FATAL) << "Fail to load data file! " << dataFile << " is empty!";
			}

			_instanceNum = lines.size();
			_instances.resize(_instanceNum, nullptr);

			_hasHeader = false;
			_instances.SetHeader("", _hasHeader);
			_fileFormat = FileFormat::LibSVM;
			_instances.schema.fileFormat = _fileFormat;
			_hasWeight = false;
			_instances.schema.hasWeights = _hasWeight;

			int maxIndex = 1;
#pragma omp parallel for 
			for (uint64 i = 0; i < _instanceNum; i++)
			{
				string line = lines[i];
				_instances[i] = make_shared<Instance>();
				Instance& instance = *_instances[i];
				Vector& features = instance.features;
				svec l = split(line, ' '); //libsvm 是用空格分开
				for (size_t j = 0; j < l.size(); j++)
				{
					string item = l[j];
					if (j == 0)
					{
						instance.label = DOUBLE(item);
						continue;
					}
					string index_, value_;
					split(item, ':', index_, value_);
					int index = INT(index_); Float value = DOUBLE(value_);
#pragma omp critical
					{
						if (index > maxIndex)
						{
							maxIndex = index;
						}
					}
					features.Add(index - 1, value); //libsvm 是1开始 melt/tlc内部0开始处理
				}
			}
			_featureNum = maxIndex;
			for (int i = 0; i < _featureNum; i++)
			{
				string name = "f" + STR(i);
				_instances.schema.featureNames.push_back(name);
			}
#pragma omp parallel for 
			for (uint64 i = 0; i < _instanceNum; i++)
			{
				Vector& features = _instances[i]->features;
				features.SetLength(_featureNum);
				if (_args.keepDense)
				{
					features.ToDense();
				}
				else if (!_args.keepSparse)
				{//if not keep sparse  如果是0值数目> FeatureNum/2转dense
					features.Densify(0.5);
				}
			}

			PrintInfo();
			return move(_instances);
		}

		//训练文本解析
		Instances&& ParseTextForTrain(svec& lines, uint64 start)
		{
			Timer timer;
			uint64 end = start + _instanceNum;
#pragma omp parallel for 
			for (uint64 i = start; i < end; i++)
			{
				string line = lines[i];
				_instances[i - start] = make_shared<Instance>();
				Instance& instance = *_instances[i - start];
				Vector& features = instance.features;
				svec l = split(line, _sep);

				for (size_t j = 0; j < l.size(); j++)
				{
					string item = l[j];
					string key, value_;
					int index; Float value;
					bool ret = split(item, ':', key, value_);
					if (ret)
					{
						value = DOUBLE(value_);
#pragma  omp critical
						{
							//输入需要保证没有重复的key
							index = GetIdentifer().add(key);
						}
						if (_selectedArray[index])
							features.Add(index, value);
					}
					else
					{
						//@TODO 暂时没有检查格式正确性 要求的是 所有非:的数据 都在后面
						switch (_columnTypes[j])
						{
						case ColumnType::Name:
							instance.names.push_back(item);
							break;
						case ColumnType::Label:
							instance.label = DOUBLE(item);
							break;
						case ColumnType::Weight:
							instance.weight = DOUBLE(item);
							break;
						case ColumnType::Attribute:
							instance.attributes.push_back(item);
							break;
						default:
							break;
						}
					}
				}
				instance.name = join(instance.names, _args.ncsep);
			}
			_featureNum = GetIdentifer().size();
			SetTextFeatureNames();
#pragma omp parallel for 
			for (uint64 i = 0; i < _instanceNum; i++)
			{
				Vector& features = _instances[i]->features;
				features.SetLength(_featureNum);
				if (_args.keepDense)
				{
					features.ToDense();
				}
				else if (!_args.keepSparse)
				{//if not keep sparse  如果是0值数目> FeatureNum/2转dense
					features.Densify(0.5);
				}
			}
			GetIdentifer().save(_args.resultDir + "/identifer.txt");
		}

		//测试文本解析
		void ParseTextForTest(svec& lines, uint64 start)
		{
			Timer timer;
			_featureNum = GetIdentifer().size();
			if (_featureNum == 0)
			{ //可能RunTest模式 需要加载词表
				string path = _args.resultDir + "/identifer.txt";
				InstanceParser::GetIdentifer().load(path);
				_featureNum = GetIdentifer().size();
				CHECK(_featureNum != 0) << "No identifer in memory or to load from disk " << path;
			}
			
			SetTextFeatureNames();
			uint64 end = start + _instanceNum;
#pragma omp parallel for 
			for (uint64 i = start; i < end; i++)
			{
				string line = lines[i];
				_instances[i - start] = make_shared<Instance>(_featureNum);
				Instance& instance = *_instances[i - start];
				Vector& features = instance.features;
				svec l = split(line, _sep);

				for (size_t j = 0; j < l.size(); j++)
				{
					string item = l[j];
					string key, value_;
					bool ret = split(item, ':', key, value_);
					if (ret)
					{
						int index = GetIdentifer().id(key); Float value = DOUBLE(value_);
						if (index != Identifer::null_id() && _selectedArray[index])
							features.Add(index, value);
					}
					else
					{
						//@TODO 暂时没有检查格式正确性 要求的是 所有非:的数据 都在后面
						switch (_columnTypes[j])
						{
						case ColumnType::Name:
							instance.names.push_back(item);
							break;
						case ColumnType::Label:
							instance.label = DOUBLE(item);
							break;
						case ColumnType::Weight:
							instance.weight = DOUBLE(item);
							break;
						case ColumnType::Attribute:
							instance.attributes.push_back(item);
							break;
						default:
							break;
						}
					}
				}
				if (_args.keepDense)
				{
					features.ToDense();
				}
				else if (!_args.keepSparse)
				{//if not keep sparse  如果是0值数目> FeatureNum/2转dense
					features.Densify(0.5);
				}

				instance.name = join(instance.names, _args.ncsep);
			}
		}

		//1 张无忌:3.5 小甜甜:2.0 
		void CreateInstancesFromTextFormat(svec& lines, uint64 start)
		{
			int times = TextFormatParsedTime();
			if (times == 0)
				ParseTextForTrain(lines, start);
			else
				ParseTextForTest(lines, start);
		}

		//默认推荐格式解析
		Instances&& ParseNormal(string dataFile)
		{
			Timer timer;
			vector<string> lines = read_lines(dataFile);
			PVAL_(timer.elapsed_ms(), "read_lines");
			if (lines.empty())
			{
				LOG(FATAL) << "Fail to load data file! " << dataFile << " is empty!";
			}
			_instanceNum = lines.size();

			if (_args.hasHeader)
			{
				_instanceNum--;
				if (!_instanceNum)
				{
					LOG(FATAL) << "Only header no data! " << dataFile;
				}
				_hasHeader = true;
			}

			timer.restart();
			ParseFirstLine(lines);
			PVAL_(timer.elapsed_ms(), "ParseFirstLine");

			timer.restart();
			_selectedArray = GetSelectedArray();
			PVAL_(timer.elapsed_ms(), "GetSelectedArray");

			_instanceNum = lines.size() - _hasHeader; //必须有 因为_hasHeader可能通过解析变为true
			if (!_instanceNum)
			{
				LOG(FATAL) << "Only header no data! " << dataFile;
			}
			_instances.resize(_instanceNum, nullptr);

			timer.restart();

			switch (_fileFormat)
			{
			case FileFormat::Dense:
				CreateInstancesFromDenseFormat(lines, _hasHeader);
				break;
			case FileFormat::Sparse:
				CreateInstancesFromSparseFormat(lines, _hasHeader);
				break;
			case FileFormat::SparseNoLenth:
				CreateInstancesFromSparseNoLengthFormat(lines, _hasHeader);
				break;
			case FileFormat::Text:
				break;
			default:
				LOG(WARNING) << "well not supported file format ?";
				break;
			}

			PVAL_(timer.elapsed_ms(), "CreateInstances");

			PrintInfo();
			return move(_instances);
		}

		Instances&& Parse(string dataFile)
		{
			//-----------------判断输入文件类型
			if (_format == "libsvm")
			{//只能特殊处理 外部确认 因为libsvm 是1开始index 
				return ParseLibSVM(dataFile);
			}
			else
			{
				return ParseNormal(dataFile);
			}
		}

		void Clear()
		{
			_firstColums.clear();
			_headerColums.clear();
			_columnNum = 0;
		}

		//注意这个设计 一个global的identifer 同时意味生命期 最多两次parse text格式文本
		//parse 一次 比如 train, cross fold, 两次train test 不会更多次
		static Identifer& GetIdentifer()
		{
			static Identifer _identifer;
			return _identifer;
		}

		static int TextFormatParsedTime()
		{
			static int time = 0;
			return time++;
		}

	protected:
	private:
		Instances _instances;
		uint64 _instanceNum = 0;
		int _featureNum = 0;
		bool _hasHeader = false;
		bool _hasWeight = false;
		FileFormat _fileFormat = FileFormat::Dense;

		svec _firstColums;
		svec _headerColums;

		BitArray _selectedArray;
		vector<ColumnType> _columnTypes;
		int _columnNum = 0;
		int _labelIdx = -1;

		//----params
		Arguments _args;
		string _sep;
		ivec _namesIdx;
		ivec _attributesIdx;
		string _format;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__INSTANCE_PARSER_H_
