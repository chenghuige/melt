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

namespace gezi {
	class Melt
	{
	public:
		Melt()
		{
			ParseArguments();
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
			SHOW_FEATURES
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
				LOG(INFO) << item.first << " ---- type number: " << (int)item.second;
			}
		}

		void RunCrossValidation(const Instances& instances)
		{
			const int randomStep = 10000;
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
					Instances trainData, testData;
					//只是trainProportion < 1 才需要rng
					CVFoldCreator::CreateFolds(instances, _cmd.trainProportion,
						instanceFoldIndices, foldIdx, _cmd.numFolds, trainData, testData,
						random_engine(_cmd.randSeed, runIdx * randomStep));
					LOG(INFO) << "Folds " << foldIdx << " are trained with " << trainData.Size() << " instances, and tested on " << testData.Size() << " instances";
#ifndef NDEBUG
					PVAL3(trainData[0]->name, trainData.PositiveCount(), trainData.NegativeCount());
					PVAL3(testData[0]->name, testData.PositiveCount(), testData.NegativeCount());
#endif // !NDEBUG
				}
			}
		}

		void RunCrossValidation()
		{
			Noticer nt((format("%d fold cross-validation") % _cmd.numFolds).str());
			//----------------------------check if command ok
			CHECK_GE(_cmd.numFolds, 2) << "The number of folds must be at least 2 for cross validation";
			if (!_cmd.modelfile.empty() || !_cmd.modelfileCode.empty() || !_cmd.modelfileText.empty())
			{
				LOG(FATAL) << "You cannot specify a model file to output when running cross-validation";
			}
			//-----------------------------parse input
			Instances instances = create_instances(_cmd.datafile);
			CHECK_GT(instances.Count(), 0) << "Read 0 instances, aborting experiment";
			instances.PrintSummary();
			//------------------------------run
			RunCrossValidation(instances);
		}

		void RunTrain()
		{
			Noticer nt("Train!");
			Instances instances = create_instances(_cmd.datafile);
		}

		void RunTest()
		{
			Noticer nt("Test!");
		}

		void RunTrainTest()
		{
			Noticer nt("TrainTest!");
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
			normalizer->PrepareAndNormalize(instances);
			normalizer->Save(normalizerFile);
			//@TODO instances_util.h 完成Instances写出
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
			{"showfeatures", RunType::SHOW_FEATURES},
			{ "sf", RunType::SHOW_FEATURES }
		};
	};
} //end of namespace gezi


#endif  //----end of RUN__MELT_H_
