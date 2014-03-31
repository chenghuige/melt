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
*                  目前不只考虑Instances内容数组都保存在内存 不考虑 StreamingInstances @TODO
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
#include "Prediction/Instances/Instances.h"
#include "RegexSearcher.h"

namespace gezi {

	enum class ColumnType
	{
		Feature = 0,
		Name,
		Label,
		Weight,
		Attribute,
		Category
	};

	class InstanceParser
	{
	public:
		struct Arguments
		{
			//input
			int labelIdx;
			int weightIdx;
			string namesIdx;
			string attrsIdx;
			bool hasHeader;
			string sep;
			string ncsep;
			string excl;
			string incl;
			bool keepSparse;
			bool keepDense;
		};
		
		virtual ~InstanceParser()
		{
		}
		InstanceParser()
		{
			ParseArguments();
			InitParam();
		}
		
		void ParseArguments();

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
			if (_cmd.sep == "tab")
			{
				_sep = "\t";
			}
			else if (_cmd.sep == "space")
			{
				_sep = " ";
			}
			else if (_cmd.sep.empty())
			{
				_sep = "\t";
			}
			else
			{
				_sep = _cmd.sep;
			}

			if (!_cmd.attrsIdx.empty())
			{
				_attributesIdx = GetIndexesFromInput(_cmd.attrsIdx);
				PVEC(_attributesIdx);
			}

			if (!_cmd.namesIdx.empty())
			{
				_namesIdx = GetIndexesFromInput(_cmd.namesIdx);
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
			if (!_cmd.incl.empty())
			{
				ivec incls = GetSelectedFeatures(_cmd.incl);

				if (incls.empty())
				{
					LOG(WARNING) << "Do not has any match for incl " << _cmd.incl;
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

			if (!_cmd.excl.empty())
			{
				ivec excls = GetSelectedFeatures(_cmd.excl);

				if (excls.empty())
				{
					LOG(WARNING) << "Do not has any match for excl " << _cmd.excl;
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
			return _instanceType == InstanceType::Sparse;
		}
		bool IsDense()
		{
			return _instanceType == InstanceType::Dense;
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

			if (_cmd.weightIdx >= 0)
			{
				_columnTypes[_cmd.weightIdx] = ColumnType::Weight;
			}

			if (_cmd.labelIdx >= 0)
			{
				_columnTypes[_cmd.labelIdx] = ColumnType::Label;
				_labelIdx = _cmd.labelIdx;
			}

			if (startswith(_firstColums[0], "#"))
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

			if (startswith(_firstColums[0], "_"))
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
				if (_instanceType == InstanceType::Dense)
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
				else
				{
					for (int i = 0; i < _featureNum; i++)
					{
						string name = "f" + STR(i);
						_instances.schema.featureNames.push_back(name);
					}
				}
			}
		}

		void CreateInstancesFromDenseFormat(svec& lines, uint64 start)
		{
			Noticer nt("CreateInstancesFromDenseFormat", true);
			uint64 end = start + _instanceNum;
#pragma omp parallel for 
			for (uint64 i = start; i < end; i++)
			{
				string line = lines[i];
				_instances.data[i - start] = make_shared<Instance>(_featureNum);
				Instance& instance = *_instances.data[i - start];
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
						value = _selectedArray[fidx++] ? FLOAT_(item) : 0;
						features.Add(value);
						break;
					case ColumnType::Name:
						instance.names.push_back(item);
						break;
					case ColumnType::Label:
						instance.label = FLOAT_(item);
						break;
					case ColumnType::Weight:
						instance.weight = FLOAT_(item);
					default:
						break;
					}
				}
				if (!_cmd.keepDense)
				{//if not keep dense   如果是0值数目<= FeatureNum/2转 sparse
					features.TrySparse();
				}
				instance.name = join(instance.names, _cmd.ncsep);
			}
		}
		
		void CreateInstancesFromSparseFormat(svec& lines, uint64 start)
		{
			Noticer nt("CreateInstancesFromSparseFormat", true);
			uint64 end = start + _instanceNum;
#pragma omp parallel for 
			for (uint64 i = start; i < end; i++)
			{
				string line = lines[i];
				_instances.data[i - start] = make_shared<Instance>(_featureNum);
				Instance& instance = *_instances.data[i - start];
				Vector& features = instance.features;
				svec l = split(line, _sep);
				
				for (size_t j = 0; j < l.size(); j++)
				{
					string item = l[j];
					if (contains(item, ":"))
					{
						string index_, value_; split(item, ":", index_, value_);
						int index = INT(index_); Float value = FLOAT_(value_);
						if (_selectedArray[index])
							features.Add(INT(index), FLOAT_(value));
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
							instance.label = FLOAT_(item);
							break;
						case ColumnType::Weight:
							instance.weight = FLOAT_(item);
							break;
						default:
							break;
						}
					}
				}
				if (!_cmd.keepSparse)
				{//if not keep sparse  如果是0值数目> FeatureNum/2转dense
					features.TryDense();
				}
				instance.name = join(instance.names, _cmd.ncsep);
			}
		}

		InstanceType GetInstanceType(string line)
		{
			for (int i = 0; i < _columnNum; i++)
			{
				if (_columnTypes[i] == ColumnType::Feature)
				{
					int j = i + 1;
					while (j < _columnNum && _columnTypes[j] != ColumnType::Feature)
					{
						j++;
					}

					if (j == _columnNum)
					{
						return InstanceType::Dense;
					}
					else
					{
						if (contains(_firstColums[j], ":"))
						{
							_featureNum = INT(_firstColums[i]);
							_columnTypes[i] = ColumnType::Attribute;
							return InstanceType::Sparse;
						}
						else
						{
							return InstanceType::Dense;
						}
					}
				}
			}
			LOG(FATAL) << "Data format wrong not feature field " << line;
		}

		//获取列信息，名字，是dense还是sparse表示
		void ParseFirstLine(svec lines)
		{
			string line = lines[0];
			_firstColums = split(line, _sep);
			_columnNum = _firstColums.size();
			if (_columnNum < 2)
			{
				LOG(FATAL) << "The header must at least has label and one feature";
			}
			_columnTypes.resize(_columnNum, ColumnType::Feature);
			InitColumnTypes(lines);
			_instanceType = GetInstanceType(lines[_hasHeader]);
			InitNames();
			_instances.SetHeader(line, _hasHeader);
			_instances.schema.instanceType = _instanceType;
		}

		void PrintInfo()
		{
			LOG(INFO) << "The total feature num is " << _featureNum;
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
			PVAL(_cmd.keepSparse);
			PVAL(_cmd.keepDense);
		}
		
		Instances&& Parse(const string& dataFile)
		{
			vector<string> lines = read_lines(dataFile);
			if (lines.empty())
			{
				LOG(FATAL) << "Fail to load data file! " << dataFile << " is empty!";
			}
			int instanceNum = lines.size();

			if (_cmd.hasHeader)
			{
				instanceNum--;
				if (!instanceNum)
				{
					LOG(FATAL) << "Only header no data! " << dataFile;
				}
				_hasHeader = true;
			}

			ParseFirstLine(lines);
			
			_selectedArray = GetSelectedArray();

			_instanceNum = lines.size() - _hasHeader;
			_instances.data.resize(_instanceNum, nullptr);

			if (_instanceType == InstanceType::Dense)
			{
				CreateInstancesFromDenseFormat(lines, _hasHeader);
			}
			else
			{
				CreateInstancesFromSparseFormat(lines, _hasHeader);
			}

			PrintInfo();
			
			return move(_instances);
		}

	protected:
	private:
		Instances _instances;
		uint64 _instanceNum = 0;
		int _featureNum = 0;
		bool _hasHeader = false;
		InstanceType _instanceType = InstanceType::Dense;

		svec _firstColums;
		svec _headerColums;

		BitArray _selectedArray;
		vector<ColumnType> _columnTypes;
		int _columnNum;
		int _labelIdx = -1;

		//----params
		Arguments _cmd;
		string _sep;
		ivec _namesIdx;
		ivec _attributesIdx;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__INSTANCE_PARSER_H_
