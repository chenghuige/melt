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
 *  ==============================================================================
 */

#ifndef RUN__MELT_H_
#define RUN__MELT_H_
#include "common_util.h"
#include "Run/MeltArguments.h"
#include "Prediction/Instances/InstanceParser.h"
#include "Run/CVFoldCreator.h"
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
				LOG(INFO) << item.first;
			}
		}

		void RunCrossValidation(const Instances& instances)
		{
			LOG(INFO) << format("%d fold cross-validation") % _cmd.numFolds;
			CHECK_GE(_cmd.numFolds, 2) << "The number of folds must be at least 2 for cross validation";
			if (!_cmd.modelfile.empty() || !_cmd.modelfileCode.empty() || !_cmd.modelfileText.empty())
			{
				LOG(FATAL) << "You cannot specify a model file to output when running cross-validation";
			}
			//-----------------------------run
			const int randomStep = 10000;
			for (size_t runIdx = 0; runIdx < _cmd.numRuns; runIdx++)
			{
				LOG(INFO) << "The " << runIdx << " round";
				RandomEngine rng = random_engine(_cmd.randSeed, runIdx * randomStep);
				if (!_cmd.foldsSequential)
					instances.Randomize(rng);
				ivec instanceFoldIndices = CVFoldCreator::CreateFoldIndices(instances.data, _cmd, rng);
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
			//-----------------------------parse input
			InstanceParser parser;
			Instances instances = parser.Parse(_cmd.datafile);
			CHECK_GT(instances.Count(), 0) << "Read 0 instances, aborting experiment";
			Pval(instances.GetSummary());
			//------------------------------run
			RunCrossValidation(instances);
		}

		void RunTrain()
		{
			LOG(INFO) << "Train!";
			vector<int> vec;
			vec.push_back(3);
		}

		void RunTest()
		{
		}

		void RunTrainTest()
		{

		}

		void RunFeatureSelection()
		{

		}

		void RunCreateInstances()
		{

		}

		void RunExperiments()
		{
			Pval(omp_get_num_procs());
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
			case RunType::UNKNOWN:
				PrintCommands();
				//THROW("Unhandled test command: " + _cmd.command);
				break;
			default:
				LOG(WARNING) << commandStr << " is not supported yet ";
				RunCrossValidation();
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
			{ "featureselection", RunType::FEATURE_SELECTION },
			{ "createinstances", RunType::CREATE_INSTANCES }
		};
	};
} //end of namespace gezi


#endif  //----end of RUN__MELT_H_
