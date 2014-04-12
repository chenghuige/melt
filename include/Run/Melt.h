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
 *  @TODO 数据shrink  去掉特定的pos 或者 特定的 neg 使得 正反比例达到预设比如 1:1 1:2 先随机数据 然后舍弃部分index 顺序即可
 *  暂时 不支持missing feature, class feature, text feature
 * 初步只实现
 * 1. 输入解析 done
 * 2. Instances 数据结构 稀疏 Dense 自动转换  Done
 * 3. Normalization 当前实现了 MinMax @TODO Gussian and Bin
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
#include "Predictors/PredictorFactory.h"

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
			EVAL,
			TRAIN,
			TEST,
			TRAIN_TEST,
			FEATURE_SELECTION,
			CREATE_INSTANCES,
			NORMALIZE,
			CHECK_DATA,
			FEATURE_STATUS,
			SHOW_FEATURES,
			CONVERT
		};

		MeltArguments& Cmd()
		{
			return _cmd;
		}

		void PrintCommands()
		{
			LOG(INFO) << "Supported commands now are below:";
			for (auto item : _commands)
			{
				LOG(INFO) << setiosflags(ios::left) << setfill(' ') << setw(40)
					<< item.first << " " << (int)item.second;
			}
		}

		void RunCrossValidation(Instances& instances)
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
			for (size_t runIdx = 0; runIdx < _cmd.numRuns; runIdx++)
			{
				LOG(INFO) << "The " << runIdx << " round";
				RandomEngine rng = random_engine(_cmd.randSeed, runIdx * randomStep);
				if (!_cmd.foldsSequential)
					instances.Randomize(rng);

				ivec instanceFoldIndices = CVFoldCreator::CreateFoldIndices(instances, _cmd, rng);
#pragma omp parallel for 
				for (size_t foldIdx = 0; foldIdx < _cmd.numFolds; foldIdx++)
				{
					string instfile = (format("%s/%d_%d_%d.inst.txt") % _cmd.resultDir % _cmd.resultIndex
						% runIdx % foldIdx).str();

					Instances trainData, testData;
					//只是trainProportion < 1 才需要rng
					CVFoldCreator::CreateFolds(instances, _cmd.trainProportion,
						instanceFoldIndices, foldIdx, _cmd.numFolds, trainData, testData,
						random_engine(_cmd.randSeed, runIdx * randomStep));

					if (foldIdx == 0)
					{
						VLOG(0) << "Folds " << foldIdx << " are trained with " << trainData.Size() << " instances, and tested on " << testData.Size() << " instances";
						Pval3(trainData[0]->name, trainData.PositiveCount(), trainData.NegativeCount());
						Pval3(testData[0]->name, testData.PositiveCount(), testData.NegativeCount());
					}

					//------------------------------------Train
					TrainerPtr trainer = TrainerFactory::CreateTrainer(_cmd.classifierName);
					trainer->SetNormalizeCopy();
					trainer->Train(trainData);
					PredictorPtr predictor = trainer->CreatePredictor();
					predictor->SetNormalizeCopy();

					//@TODO 每个test 输出一个inst 文件也 然后每个给出一个结果
					LOG(INFO) << "-------------------------------------Testing";
					Test(testData, predictor, instfile, ofs);
					string command = _cmd.evaluate + instfile;
					{
						EXECUTE(command);
					}
				}
			}
			string command = _cmd.evaluate + instFile;
#pragma omp critical
			{
				EXECUTE(command);
			}
		}

		void RunCrossValidation()
		{
			Noticer nt((format("%d fold cross-validation") % _cmd.numFolds).str());
			//----------------------------check if command ok
			CHECK_GE(_cmd.numFolds, 2) << "The number of folds must be at least 2 for cross validation";
			//-----------------------------parse input
			Instances instances = create_instances(_cmd.datafile);
			CHECK_GT(instances.Count(), 0) << "Read 0 instances, aborting experiment";
			instances.PrintSummary();
			//------------------------------run
			RunCrossValidation(instances);
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
			for (InstancePtr instance : instances)
			{
				double output;
				double probability = predictor->Predict(instance, output);
				string name = instance->name.empty() ? STR(idx) : instance->name;
				int assigned = output > 0 ? 1 : 0;
				ofs << name << "\t" << instance->label << "\t"
					<< assigned << "\t" << output << "\t"
					<< probability << endl;
				idx++;
			}
		}

		PredictorPtr Train(Instances& instances)
		{
			Pval(_cmd.classifierName);
			auto trainer = TrainerFactory::CreateTrainer(_cmd.classifierName);
			if (trainer == nullptr)
			{
				return;
			}
			trainer->Train(instances);
			auto predictor = trainer->CreatePredictor();
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
				predictor->Save(_cmd.resultDir + "/" + _cmd.modelFolder);
				if (_cmd.modelfileText)
				{
					predictor->SaveText();
				}
			}
		}

		void RunTest()
		{
			Noticer nt("Test!");
			//------load predictor
			auto predictor = PredictorFactory::LoadPredictor(_cmd.resultDir + "/" + _cmd.modelFolder);
			//------test
			try_create_dir(_cmd.resultDir);
			string instFile = _cmd.resultDir + "/" + STR(_cmd.resultIndex) + ".inst.txt";

			//hack for text input format //Not tested correctness yet
			InstanceParser::TextFormatParsedTime(); //++ pared text from time这样表示需要使用词表数据
			auto testInstances = create_instances(_cmd.testDatafile);
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
				predictor->Save(_cmd.resultDir + "/" + _cmd.modelFolder);
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
			string infile = _cmd.datafile;
			string outfile = endswith(infile, ".txt") ? boost::replace_last_copy(infile, ".txt", ".normed.txt") : infile + ".normed";
			Pval(outfile);
			string normalizerFile = _cmd.normalizerfile.empty() ?
				(endswith(infile, ".txt") ?
				boost::replace_last_copy(infile, ".txt", ".normalizer.txt") : infile + ".normalizer") : _cmd.normalizerfile;

			Instances instances = create_instances(_cmd.datafile);
			NormalizerPtr normalizer = NormalizerFactory::CreateNormalizer(_cmd.normalizerName);
			CHECK_NE(normalizer.get(), NULL);
			Pval(normalizer->Name());
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

		void RunFeatureStatus()
		{
			Noticer nt("FeatureStatus!");
			string infile = _cmd.datafile;
			string outfile = _cmd.outfile.empty() ? (endswith(infile, ".txt") ? boost::replace_last_copy(infile, ".txt", ".featurestatus.txt") : infile + ".featuestatus")
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
				write(instances, _cmd.outfile, fileFormat);
			}
		}

		void RunExperiments()
		{
			PVAL(omp_get_num_procs());
			if (_cmd.numThreads)
			{
				omp_set_num_threads(_cmd.numThreads);
			}
			//解析命令模式
			string commandStr = erase(boost::to_lower_copy(_cmd.command), "_-");
			Pval(commandStr);
			RunType command = get_value(_commands, commandStr, RunType::UNKNOWN);
			switch (command)
			{
			case RunType::EVAL:
				RunCrossValidation();
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
			case RunType::CONVERT:
				RunConvert();
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
			{ "train", RunType::TRAIN },
			{ "test", RunType::TEST },
			{ "traintest", RunType::TRAIN_TEST },
			{ "tt", RunType::TRAIN_TEST },
			{ "featureselection", RunType::FEATURE_SELECTION },
			{ "fs", RunType::FEATURE_SELECTION },
			{ "createinstances", RunType::CREATE_INSTANCES },
			{ "norm", RunType::NORMALIZE },
			{ "check", RunType::CHECK_DATA },
			{ "featurestatus", RunType::FEATURE_STATUS },
			{ "fss", RunType::FEATURE_STATUS },
			{ "showfeatures", RunType::SHOW_FEATURES },
			{ "sf", RunType::SHOW_FEATURES },
			{ "convert", RunType::CONVERT }
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
