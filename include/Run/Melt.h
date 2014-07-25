/**
 *  ==============================================================================
 *
 *          \file   Run/Melt.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-01 11:51:11.160085
 *
 *  \Description: 机器学习工具库melt 最外层RunExperiments 对应melt.cc
 *  @TODO cmmand处理 脚本统一化 增加原名和简称两种FLAGS同时存在
 *  @TODO 数据分割  train  test // validate ?
 *  @TODO 数据shrink  去掉特定的pos 或者 特定的 neg 使得 正反比例达到预设比如 1:1 1:2 先随机数据 然后舍弃部分index 顺序即可 done
 *  暂时 不支持missing feature, class feature, text feature
 * 初步只实现
 * 1. 输入解析 done
 * 2. Instances 数据结构 稀疏 Dense 自动转换  Done
 * 3. Normalization 当前实现了 MinMax @TODO Gussian and Bin  done
 * 4. 训练支持 Cross Fold 随机cross 已实现 , test 还未实现
 *    尽快实现完整的 train, test, train-test, cross fold
 * 5. @TODO 特征evaluatore 组合特征 判断效果
 * 6. @TODO 参数选择  grid sweeping 初步实现 其它参数选择 ?
 * 7. 初步实现Binary分类 后续再考虑其他
 * 8. 尽快实现二分类的 LinearSvm   FastRank -> @TODO 逻辑回归, KernelSvm,LibLinear, 随机森林。。。
 * 9. 打印feature特征 最小值 最大值 均值 方差 正例中情况 反例中情况  根据特征名或者index 获取结果
 *  ==============================================================================
 */

#ifndef RUN__MELT_H_
#define RUN__MELT_H_

#include "common_util.h"
#include "Run/MeltArguments.h"
#include "Prediction/Instances/InstanceParser.h"
#include "Run/CVFoldCreator.h"
#include "Prediction/Normalization/MinMaxNormalizer.h"
#include "Prediction/Normalization/NormalizerFactory.h"
#include "Utils/FeatureStatus.h"
#include "Prediction/Instances/instances_util.h"
#include "MLCore/TrainerFactory.h"

#include "MLCore/Predictor.h"

#include "Prediction/Instances/instances_util.h"
#include "MLCore/PredictorFactory.h"

#include "Utils/performance_evaluate.h"

namespace gezi {
	class Melt
	{
	public:
		Melt()
		{
			ParseArguments();
			Pval(_cmd.randSeed);
		}
		~Melt()
		{
		}
		void ParseArguments();

		enum class RunType
		{
			UNKNOWN = 0,
			EVAL, //交叉验证,默认执行的command
			EVAL_PARAM, //交叉验证 但是只输出auc的值,主要用于检测不同参数效果对比
			TRAIN, //训练
			TEST,  //测试
			TRAIN_TEST,  //训练+测试
			FEATURE_SELECTION,  //特征选择  //参数选择放到外围python脚本 
			CREATE_INSTANCES,  //将不符合normal格式的输入转换为符合的,例如catogry,text域的展开
			NORMALIZE,  //进行归一化，输出结果到文本
			CHECK_DATA, //检查数据 当前是进行minmax归一 提示无用特征
			FEATURE_STATUS, //打印特征的均值方差信息　mean var
			SHOW_FEATURES, //打印特征名
			SHOW_INFOS, //展示输入数据的基本信息  特征数目，样本数目，正例比例
			CONVERT, //对输入样本文件载入然后输出要求的格式 比如 dense -> sparse
			SPLIT_DATA, //对输入样本进行切分  比如 1:1 1:3:2 同时保持每份中正反例比例维持和原始数据一致
			CHANGE_RAIO //对输入样本进行正反例比例调整 比如 原始 1:30 调整为 1:1
		};

		enum class CrossValidationType
		{
			DEFAULT = 0, //默认生成instance文件，调用外部python脚本处理instance文件生成evaluate结果
			AUC = 1 //不生成instance文件,只是内部计算auc或者其它evaluate数据@TODO,用于参数选取
		};

		MeltArguments& Cmd()
		{
			return _cmd;
		}

		void PrintCommands()
		{
			VLOG(0) << "Supported commands now are below:";
			for (auto item : _commands)
			{
				VLOG(0) << setiosflags(ios::left) << setfill(' ') << setw(40)
					<< item.first << " " << (int)item.second;
			}
		}

		static string GetOutputFileName(string infile, string suffix)
		{
			return endswith(infile, ".txt") ? boost::replace_last_copy(infile, ".txt", "." + suffix + ".txt") : infile + "." + suffix;
		}

		void RunCrossValidation(Instances& instances, CrossValidationType cvType)
		{
			//--------------------------- 输出文件头
			try_create_dir(_cmd.resultDir);
			string instFile = _cmd.resultDir + "/" + STR(_cmd.resultIndex) + ".inst.txt";
			ofstream ofs(instFile);
			WriteInstFileHeader(ofs);

			if (_cmd.preNormalize)
			{
				NormalizerPtr normalizer = NormalizerFactory::CreateNormalizer(_cmd.normalizerName);
				CHECK_NE(normalizer.get(), NULL);
				Pval(normalizer->Name());
				normalizer->RunNormalize(instances);
			}
			const int randomStep = 10000;
			//const int randomStep = 1;
			BinaryClassficationEvaluatorPtr evaluator = nullptr;
			if (cvType == CrossValidationType::AUC)
			{
				evaluator = make_shared<AucEvaluator>();
			}
			string trainerParam;
			for (size_t runIdx = 0; runIdx < _cmd.numRuns; runIdx++)
			{
				VLOG(0) << "The " << runIdx << " round";
				RandomEngine rng = random_engine(_cmd.randSeed, runIdx * randomStep);
				if (!_cmd.foldsSequential)
					instances.Randomize(rng);

				ivec instanceFoldIndices = CVFoldCreator::CreateFoldIndices(instances, _cmd, rng);
				for (size_t foldIdx = 0; foldIdx < _cmd.numFolds; foldIdx++)
				{
					VLOG(0) << "Croos validaion foldIdx " << foldIdx;
					string instfile = (format("%s/%d_%d_%d.inst.txt") % _cmd.resultDir % _cmd.resultIndex
						% runIdx % foldIdx).str();

					Instances trainData, testData;
					//只是trainProportion < 1 才需要rng
					CVFoldCreator::CreateFolds(instances, _cmd.trainProportion,
						instanceFoldIndices, foldIdx, _cmd.numFolds, trainData, testData,
						random_engine(_cmd.randSeed, runIdx * randomStep));

					//------------------------------------Train
					TrainerPtr trainer = TrainerFactory::CreateTrainer(_cmd.classifierName);
					if (foldIdx == 0)
					{
						VLOG(0) << "Folds " << foldIdx << " are trained with " << trainData.Size() << " instances, and tested on " << testData.Size() << " instances";
						Pval3(trainData[0]->name, trainData.PositiveCount(), trainData.NegativeCount());
						Pval3(testData[0]->name, testData.PositiveCount(), testData.NegativeCount());
					}

					trainer->SetNormalizeCopy();
					trainer->Train(trainData);
					PredictorPtr predictor = trainer->CreatePredictor();
					predictor->SetNormalizeCopy();

					if (cvType == CrossValidationType::DEFAULT)
					{
						//@TODO 每个test 输出一个inst 文件也 然后每个给出一个结果
						VLOG(0) << "-------------------------------------Testing";
						Test(testData, predictor, instfile, ofs);
						string command = _cmd.evaluate + instfile;
#pragma omp critical
						{
							EXECUTE(command);
						}
					}
					else if (cvType == CrossValidationType::AUC)
					{
						Test(testData, predictor, evaluator);
					}
					else
					{
						LOG(ERROR) << "Not supported crosss validation type"; 
						return;
					}
					if (foldIdx == 0)
					{
						trainerParam = trainer->GetParam();
					}
				}
			}

			if (cvType == CrossValidationType::DEFAULT)
			{
				string command = _cmd.evaluate + instfile;
#pragma omp critical
				{
					EXECUTE(command);
				}
			}
			else if (cvType == CrossValidationType::AUC)
			{
				double aucScore = evaluator->Finish();
				cout << aucScore << "\t" << trainerParam << endl; 
			}
		}

		void RunCrossValidation(CrossValidationType cvType = CrossValidationType::DEFAULT)
		{
			Noticer nt((format("%d fold cross-validation") % _cmd.numFolds).str());
			//----------------------------check if command ok
			CHECK_GE(_cmd.numFolds, 2) << "The number of folds must be at least 2 for cross validation";
			//-----------------------------parse input
			Instances instances = create_instances(_cmd.datafile);
			CHECK_GT(instances.Count(), 0) << "Read 0 instances, aborting experiment";
			instances.PrintSummary();
			//------------------------------run
			RunCrossValidation(instances, cvType);
		}

		void WriteInstFileHeader(ofstream& ofs)
		{
			ofs << "Instance\tTrue\tAssigned\tOutput\tProbability" << endl;
		}

		//@TODO 多做了一次预测等于
		void Test(Instances& instances, PredictorPtr predictor,
			string outfile, ofstream& ofs)
		{
			Test(instances, predictor, outfile);
#pragma omp critical
			{
				Test(instances, predictor, ofs);
			}
		}
		void Test(Instances& instances, PredictorPtr predictor, string outfile)
		{
			ofstream ofs(outfile);
			WriteInstFileHeader(ofs);
			Test(instances, predictor, ofs);
		}

		void Test(Instances& instances, PredictorPtr predictor, ofstream& ofs)
		{
			int idx = 0;
			ProgressBar pb(instances.Count(), "Testing");
			for (InstancePtr instance : instances)
			{
				++pb;
				double output;
				double probability = predictor->Predict(instance, output);
				string name = instance->name.empty() ? STR(idx) : instance->name;
				if (startswith(name, '_'))
				{
					name = name.substr(1);
				}

				int assigned = output > 0 ? 1 : 0;
				ofs << name << "\t" << instance->label << "\t"
					<< assigned << "\t" << output << "\t"
					<< probability << endl;
				VLOG(6) << name << "\t" << instance->label << "\t"
					<< assigned << "\t" << output << "\t"
					<< probability;
				idx++;
			}
		}


		//AUC test
		void Test(Instances& instances, PredictorPtr predictor, 
			BinaryClassficationEvaluatorPtr evaluator)
		{
			for (InstancePtr instance : instances)
			{
				double probability = predictor->Predict(instance);
				evaluator->Add(instance->label, probability, instance->weight);
			}
		}

		PredictorPtr Train(Instances& instances)
		{
			Pval(_cmd.classifierName);
			auto trainer = TrainerFactory::CreateTrainer(_cmd.classifierName);
			if (trainer == nullptr)
			{
				LOG(WARNING) << _cmd.classifierName << " has not been supported yet";
				return;
			}
			trainer->Train(instances);
			auto predictor = trainer->CreatePredictor();
			predictor->SetParam(trainer->GetParam());
			return predictor;
		}

		void RunTrain()
		{
			PredictorPtr predictor;
			{
				Noticer nt("Train!");
				auto instances = create_instances(_cmd.datafile);
				CHECK_GT(instances.Count(), 0) << "Read 0 test instances, aborting experiment";
				predictor = Train(instances);
			}
			{
				Noticer nt("Test itself!");
				try_create_dir(_cmd.resultDir);
				string instFile = _cmd.resultDir + "/" + STR(_cmd.resultIndex) + ".inst.txt";
				auto testInstances = create_instances(_cmd.datafile);
				CHECK_GT(testInstances.Count(), 0) << "Read 0 test instances, aborting experiment";
				Test(testInstances, predictor, instFile);
				string command = _cmd.evaluate + instFile;
				EXECUTE(command);
			}
			{
				Noticer nt("Write train result!");
				predictor->Save(_cmd.modelFolder);
				if (_cmd.modelfileText)
				{
					predictor->SaveText();
				}
			}
		}

		void RunTest()
		{
			Noticer nt("Test! with model from " + _cmd.modelFolder);
			//------load predictor
			auto predictor = PredictorFactory::LoadPredictor(_cmd.modelFolder);
			//------test
			try_create_dir(_cmd.resultDir);
			string instFile = _cmd.resultDir + "/" + STR(_cmd.resultIndex) + ".inst.txt";

			//hack for text input format //Not tested correctness yet
			InstanceParser::TextFormatParsedTime(); //++ pared text from time这样表示需要使用词表数据
			string testDatafile = _cmd.testDatafile.empty() ? _cmd.datafile : _cmd.testDatafile;
			auto testInstances = create_instances(testDatafile);
			CHECK_GT(testInstances.Count(), 0) << "Read 0 test instances, aborting experiment";
			Test(testInstances, predictor, instFile);
			string command = _cmd.evaluate + instFile;
			EXECUTE(command);
		}

		void RunTrainTest()
		{
			Noticer nt("TrainTest!");
			PredictorPtr predictor;
			Instances instances;
			{
				Noticer nt("Train!");
				instances = create_instances(_cmd.datafile);
				CHECK_GT(instances.Count(), 0) << "Read 0 train instances, aborting experiment";
				predictor = Train(instances);
			}
			{
				Noticer nt("Test!");
				try_create_dir(_cmd.resultDir);
				string instFile = _cmd.resultDir + "/" + STR(_cmd.resultIndex) + ".inst.txt";

				auto testInstances = create_instances(_cmd.testDatafile);
				CHECK_GT(testInstances.Count(), 0) << "Read 0 test instances, aborting experiment";
				CHECK_EQ(instances.schema == testInstances.schema, 1);
				Test(testInstances, predictor, instFile);
				string command = _cmd.evaluate + instFile;
				EXECUTE(command);
			}
			{
				Noticer nt("Write train result!");
				predictor->Save(_cmd.modelFolder);
				if (_cmd.modelfileText)
				{
					predictor->SaveText();
				}
			}
		}

		void RunFeatureSelection()
		{
			Noticer nt("FeatureSelection!");
			Instances instances = create_instances(_cmd.datafile);
		}

		void RunCreateInstances()
		{

		}

		void RunShowFeatures()
		{
			Instances instances = create_instances(_cmd.datafile);
			int num = 0;
			for (string feature : instances.FeatureNames())
			{
				std::cout << num++ << "\t" << feature << endl;
			}
		}

		//只是为了输出normalize后的数据 查看normalize后效果
		void RunNormalizeInstances()
		{
			Noticer nt("NormalizeInstances!");
			NormalizerPtr normalizer = NormalizerFactory::CreateNormalizer(_cmd.normalizerName);
			CHECK_NE(normalizer.get(), NULL);
			Pval(normalizer->Name());

			string infile = _cmd.datafile;
			string suffix = normalizer->Name() + ".normed";
			string outfile = _cmd.outfile.empty() ? GetOutputFileName(infile, suffix) : _cmd.outfile;
			Pval(outfile);
			string normalizerFile = _cmd.normalizerfile.empty() ?
				(endswith(infile, ".txt") ?
				boost::replace_last_copy(infile, ".txt", ".normalizer.txt") : infile + ".normalizer") : _cmd.normalizerfile;
			Pval(normalizerFile);

			Instances instances = create_instances(_cmd.datafile);

			normalizer->RunNormalize(instances);
			normalizer->SaveText(normalizerFile);
			FileFormat fileFormat = get_value(_formats, _cmd.outputFileFormat, FileFormat::Unknown);
			write(instances, outfile, fileFormat);
		}

		void RunCheckData()
		{
			Noticer nt("CheckData!(need GLOG_v=4 ./melt)");
			Instances instances = create_instances(_cmd.datafile);
			NormalizerPtr normalizer = make_shared<MinMaxNormalizer>();
			normalizer->Prepare(instances);
		}

		void RunShowInfos()
		{
			auto instances = create_instances(_cmd.datafile); //内部打印信息
		}

		void RunFeatureStatus()
		{
			Noticer nt("FeatureStatus!");
			string infile = _cmd.datafile;
			string suffix = "featurestatus";
			string outfile = _cmd.outfile.empty() ? GetOutputFileName(infile, suffix)
				: _cmd.outfile;
			Instances instances = create_instances(_cmd.datafile);
			FeatureStatus::GenMeanVarInfo(instances, outfile, _cmd.featureName);
		}

		//输入文件转换后输出
		void RunConvert()
		{
			FileFormat fileFormat = get_value(_formats, _cmd.outputFileFormat, FileFormat::Unknown);
			Instances instances = create_instances(_cmd.datafile);
			if (fileFormat == FileFormat::Unknown)
			{
				LOG(WARNING) << "Not specified ouput file format, do nothing";
			}
			else if (fileFormat == instances.schema.fileFormat)
			{
				LOG(WARNING) << "Specified ouput file format is the same as input , do nothing";
			}
			else
			{
				if (!_cmd.outfile.empty())
				{
					write(instances, _cmd.outfile, fileFormat);
				}
				else
				{
					string outfile = fileFormat == FileFormat::Arff ?
						boost::replace_last_copy(_cmd.datafile, ".txt", "") + ".arff" :
						GetOutputFileName(_cmd.datafile, "converted");
					if (fileFormat == FileFormat::Arff)
						VLOG(0) << "Writting to arff file " << outfile;
					else
						LOG(WARNING) << "Not specify the out file name so write to " << outfile;
					write(instances, outfile, fileFormat);
				}
			}
		}

		void SplitDataByLabel(Instances& instances)
		{
			Instances posInstances(instances.schema);
			Instances negInstances(instances.schema);
			for (InstancePtr instance : instances)
			{
				if (instance->IsPositive())
					posInstances.push_back(instance);
				else
					negInstances.push_back(instance);
			}
			{
				string outfile = GetOutputFileName(_cmd.datafile, "pos");
				Pval(outfile);
				write(posInstances, outfile);
			}
			{
				string outfile = GetOutputFileName(_cmd.datafile, "neg");
				Pval(outfile);
				write(negInstances, outfile);
			}
		}
		//当前复用cross fold思路 
		void RunSplitData()
		{
			auto instances = create_instances(_cmd.datafile);
			if (_cmd.commandInput.empty())
			{
				VLOG(0) << "No input assume to split by label";
				SplitDataByLabel(instances);
				return;
			}
			RandomEngine rng = random_engine(_cmd.randSeed);
			if (!_cmd.foldsSequential)
				instances.Randomize(rng);

			ivec segs;
			try
			{
				segs.resize(boost::lexical_cast<int>(_cmd.commandInput), 1);
			}
			catch (...)
			{
				svec segs_ = split(_cmd.commandInput, ':');
				if (segs_.size() <= 1)
				{
					LOG(WARNING) << "Need input like -ci 1:1  -ci 1:3:2 or -ci 5";
					return;
				}
				segs = from(segs_) >> select([](string a) { return INT(a); }) >> to_vector();
			}
			_cmd.numFolds = sum(segs);
			Pval(_cmd.numFolds);
			int partNum = segs.size();
			ivec instanceFoldIndices = CVFoldCreator::CreateFoldIndices(instances, _cmd, rng);
			vector<Instances> parts(partNum);

			ivec maps(_cmd.numFolds);
			int idx = 0;
			for (int i = 0; i < partNum; i++)
			{
				for (int j = 0; j < (int)segs[i]; j++)
				{
					maps[idx++] = i;
				}
			}

			for (int i = 0; i < partNum; i++)
			{
				parts[i].CopySchema(instances.schema);
			}

			for (size_t i = 0; i < instances.size(); i++)
			{
				parts[maps[instanceFoldIndices[i]]].push_back(instances[i]);
			}

			string infile = _cmd.datafile;
			for (int i = 0; i < partNum; i++)
			{
				string suffix = STR(i) + "_" + STR(partNum);
				string outfile = GetOutputFileName(infile, suffix);
				Pval(outfile);
				write(parts[i], outfile);
			}
		}

		//改变正反例的比例
		void RunChangeRatio()
		{
			auto instances = create_instances(_cmd.datafile);
			RandomEngine rng = random_engine(_cmd.randSeed);
			if (!_cmd.foldsSequential)
				instances.Randomize(rng);
			svec segs = split(_cmd.commandInput, ':');
			int partNum = (int)segs.size();
			if (partNum != 2)
			{
				LOG(WARNING) << "Need input like -ci 1:2 -ci 1:2 the part num should be 2 not " << partNum;
				return;
			}

			double posPart = DOUBLE(segs[0]);
			double negPart = DOUBLE(segs[1]);

			uint64 posNum = instances.PositiveCount();
			uint64 negNum = instances.Count() - posNum;

			uint64 posAdjustedNum = negNum / negPart * posPart;

			string infile = _cmd.datafile;
			string suffix = replace(_cmd.commandInput, ':', '-');
			string outfile = GetOutputFileName(infile, suffix);
			if (posAdjustedNum == posNum)
			{
				LOG(WARNING) << "Need to do nothing";
			}
			else
			{
				Instances newInstances(instances.schema);
				if (posAdjustedNum > posNum)
				{
					uint64 negAdjustedNum = posNum / posPart * negPart;
					VLOG(0) << "Shrink neg part num to " << negAdjustedNum;
					int negCount = 0;
					for (InstancePtr instance : instances)
					{
						if (instance->IsNegative())
						{
							if (negCount >= negAdjustedNum)
							{
								continue;
							}
							negCount++;
						}
						newInstances.push_back(instance);
					}
				}
				else
				{
					VLOG(0) << "Shrink pos part num to " << posAdjustedNum;
					int posCount = 0;
					for (InstancePtr instance : instances)
					{
						if (instance->IsPositive())
						{
							if (posCount >= posAdjustedNum)
							{
								continue;
							}
							posCount++;
						}
						newInstances.push_back(instance);
					}
				}
				Pval(outfile);
				write(newInstances, outfile);
			}
		}

		void RunExperiments()
		{
			if (_cmd.numThreads)
			{
				omp_set_num_threads(_cmd.numThreads);
			}
			Pval(get_num_threads());
			//解析命令模式
			string commandStr = erase(boost::to_lower_copy(_cmd.command), "_-");
			Pval(commandStr);
			RunType command = get_value(_commands, commandStr, RunType::UNKNOWN);
			switch (command)
			{
			case RunType::EVAL:
				RunCrossValidation();
				break;
			case  RunType::EVAL_PARAM:
				RunCrossValidation(CrossValidationType::AUC);
				break;
			case RunType::TRAIN:
				RunTrain();
				break;
			case  RunType::TEST:
				RunTest();
				break;
			case RunType::TRAIN_TEST:
				RunTrainTest();
				break;
			case  RunType::FEATURE_SELECTION:
				RunFeatureSelection();
				break;
			case  RunType::CREATE_INSTANCES:
				RunCreateInstances();
				break;
			case RunType::NORMALIZE:
				RunNormalizeInstances();
				break;
			case RunType::CHECK_DATA:
				RunCheckData();
				break;
			case RunType::FEATURE_STATUS:
				RunFeatureStatus();
				break;
			case RunType::SHOW_FEATURES:
				RunShowFeatures();
				break;
			case RunType::SHOW_INFOS:
				RunShowInfos();
				break;
			case RunType::CONVERT:
				RunConvert();
				break;
			case RunType::SPLIT_DATA:
				RunSplitData();
				break;
			case RunType::CHANGE_RAIO:
				RunChangeRatio();
				break;
			case RunType::UNKNOWN:
			default:
				LOG(WARNING) << commandStr << " is not supported yet ";
				PrintCommands();
				break;
			}
		}

	protected:
	private:
		MeltArguments _cmd;
		map<string, RunType> _commands = {
			{ "cv", RunType::EVAL },
			{ "eval", RunType::EVAL },
			{ "eval_param", RunType::EVAL_PARAM },
			{ "cv2", RunType::EVAL_PARAM },
			{ "train", RunType::TRAIN },
			{ "tr", RunType::TRAIN },
			{ "test", RunType::TEST },
			{ "te", RunType::TEST },
			{ "traintest", RunType::TRAIN_TEST },
			{ "tt", RunType::TRAIN_TEST },
			{ "featureselection", RunType::FEATURE_SELECTION },
			{ "fs", RunType::FEATURE_SELECTION },
			{ "createinstances", RunType::CREATE_INSTANCES },
			{ "ci", RunType::CREATE_INSTANCES },
			{ "norm", RunType::NORMALIZE },
			{ "check", RunType::CHECK_DATA },
			{ "featurestatus", RunType::FEATURE_STATUS },
			{ "fss", RunType::FEATURE_STATUS },
			{ "showfeatures", RunType::SHOW_FEATURES },
			{ "sf", RunType::SHOW_FEATURES },
			{ "showinfos", RunType::SHOW_INFOS },
			{ "si", RunType::SHOW_INFOS },
			{ "convert", RunType::CONVERT },
			{ "splitdata", RunType::SPLIT_DATA },
			{ "sd", RunType::SPLIT_DATA },
			{ "changeratio", RunType::CHANGE_RAIO },
			{ "cr", RunType::CHANGE_RAIO }
		};

		map<string, FileFormat> _formats = {
			{ "unknown", FileFormat::Unknown },
			{ "dense", FileFormat::Dense },
			{ "sparse", FileFormat::Sparse },
			{ "text", FileFormat::Text },
			{ "libsvm", FileFormat::LibSVM },
			{ "arff", FileFormat::Arff }
		};
	};
} //end of namespace gezi


#endif  //----end of RUN__MELT_H_
