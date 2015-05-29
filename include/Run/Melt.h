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
#define NO_BAIDU_DEP
#include "common_util.h"
#include "Run/MeltArguments.h"
#include "Prediction/Instances/InstanceParser.h"
#include "Run/CVFoldCreator.h"
#include "Prediction/Normalization/MinMaxNormalizer.h"
#include "Prediction/Normalization/NormalizerFactory.h"
#include "Prediction/Calibrate/CalibratorFactory.h"
#include "Utils/FeatureStatus.h"
#include "Prediction/Instances/instances_util.h"
#include "MLCore/TrainerFactory.h"
#include "MLCore/Predictor.h"
#include "MLCore/PredictorFactory.h"

#include "Utils/Evaluator.h"
#include "Utils/EvaluatorUtils.h"
#include "Testers/testers.h"
#include "Utils/PredictorUtils.h"

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
			HELP,
			HELP_TRAINERS, //Melt现在支持的trainers信息打印
			HELP_TRAINER, //打印当前-cl指定的trainer的Help信息(如果tainer有实现ShowHelp)
			EVAL, //交叉验证,默认执行的command
			EVAL_PARAM, //交叉验证 但是只输出auc的值,主要用于检测不同参数效果对比
			EVAL_FULL, //生成instance文件使用Tester，同时也使用Evaluator
			TRAIN, //训练
			TEST,  //测试
			TRAIN_TEST,  //训练+测试
			FEATURE_SELECTION,  //特征选择  //参数选择放到外围python脚本 
			CREATE_INSTANCES,  //将不符合normal格式的输入转换为符合的,例如catogry,text域的展开
			NORMALIZE,  //进行归一化，输出结果到文本,将normalizer信息序列化到-m对应的路径下
			NORMALIZE_FILE, //仅对文本进行归一化输出结果到结果文本
			CALIBRATE,  //进行output->[0-1]的归一化，将calibrator信息序列化到-m对应的路径下
			CHECK_DATA, //检查数据 当前是进行minmax归一 提示无用特征
			FEATURE_STATUS, //打印特征的均值方差信息　mean var
			SHOW_FEATURES, //打印特征名
			SHOW_INFOS, //展示输入数据的基本信息  特征数目，样本数目，正例比例
			CONVERT, //对输入样本文件载入然后输出要求的格式 比如 dense -> sparse
			SPLIT_DATA, //对输入样本进行切分  比如 1:1 1:3:2 同时保持每份中正反例比例维持和原始数据一致
			GEN_CROSS_DATA, //输出交叉验证的文本数据文件 方便对比其它机器学习工具的实验效果
			CHANGE_RAIO, //对输入样本进行正反例比例调整 比如 原始 1:30 调整为 1:1
			RANDOMIZE, //对输入样本随机化处理，配合 -num > 0则只输出前num个样本 如果配合 -ci fr 或者  -ci forceRatio 那么保证比例,默认是不保证比例
			WRITE_TEXT_MODEL, //读入binary模型后写出文本格式模型如-mt -mxml -mjson 注意模型内部的normalizer,calibrator默认都是不输出Text格式的，如果需要输出 -snt 1, -sct 1
			TEXT_MODEL_TO_BINARY //读取-m 指定路径下的model.txt 用户指定模型名称-cl 默认是LinearSVM 按照文本格式模型载入写出binary模型到-m路径
		};


		//目前兼容调用外部脚本 但是没考虑扩展性 暂时只考虑二分类，而内置的Tester考虑了可扩展性
		enum class CrossValidationType
		{
			DEFAULT = 0, //默认使用melt本身内置c++的Tester
			USE_SCRIPT, //调用外部python脚本处理instance文件生成evaluate结果 如~/tools/evaluate.py ~/tools/evaluate.full.py可以辅助输出ROC,PR曲线，调节阈值展示召回
			EVAL_PARAM, //不生成instance文件,只是使用内置的Evalator不使用默认的Tester, 主要用于参数选取
			EVAL_FULL, //生成instance文件使用Tester，同时也使用Evaluator
		};

		MeltArguments& Cmd()
		{
			return _cmd;
		}

		void PrintCommands()
		{
			VLOG(0) << "Supported commands now are below: [commandName or commandShortName] <-> [commandId]";
			print_enum_map(_commands);
			int i = (int)RunType::HELP_TRAINERS; // 0 UNKNOWN, 1 HELP, 2 HELP_TRAINERS
			VLOG(0) << i++ << " HELP_TRAINERS, //Melt现在支持的trainers信息打印";
			VLOG(0) << i++ << " HELP_TRAINER, //打印当前-cl指定的trainer的Help信息(如果tainer有实现ShowHelp)";
			VLOG(0) << i++ << " EVAL, //交叉验证,默认执行的command";
			VLOG(0) << i++ << " EVAL_PARAM, //交叉验证 但是只输出auc的值,主要用于检测不同参数效果对比";
			VLOG(0) << i++ << " TRAIN, //训练(-mt -mxml -mjson设置可以输出相应文本格式模型，如果要对内部的normalizer输出相应文本格式设置 -snt 1,calibrator类似 -sct 1)";
			VLOG(0) << i++ << " TEST,  //测试";
			VLOG(0) << i++ << " TRAIN_TEST,  //训练+测试";
			VLOG(0) << i++ << " FEATURE_SELECTION,  //特征选择  //参数选择放到外围python脚本";
			VLOG(0) << i++ << " CREATE_INSTANCES,  //将不符合normal格式的输入转换为符合的,例如catogry,text域的展开";
			VLOG(0) << i++ << " NORMALIZE,  //进行归一化，输出结果到文本,将normalizer信息序列化到-m对应的路径下(-mt -mxml -mjson设置可以输出相应文本格式 不需要设置-snt)";
			VLOG(0) << i++ << " NORMALIZE_FILE, //仅对文本进行归一化输出结果到结果文本";
			VLOG(0) << i++ << " CALIBRATE,  //进行output->[0-1]的归一化，将calibrator信息序列化到-m对应的路径下  -mt -mxml -mjson设置可以输出相应文本格式 不需要设置-sct";
			VLOG(0) << i++ << " CHECK_DATA, //检查数据 当前是进行minmax归一 提示无用特征";
			VLOG(0) << i++ << " FEATURE_STATUS, //打印特征的均值方差信息　mean var";
			VLOG(0) << i++ << " SHOW_FEATURES, //打印特征名";
			VLOG(0) << i++ << " SHOW_INFOS, //展示输入数据的基本信息  特征数目，样本数目，正例比例";
			VLOG(0) << i++ << " CONVERT, //对输入样本文件载入然后输出要求的格式 比如 dense -> sparse";
			VLOG(0) << i++ << " SPLIT_DATA, //对输入样本进行切分  比如 1:1 1:3:2 同时保持每份中正反例比例维持和原始数据一致";
			VLOG(0) << i++ << " GEN_CROSS_DATA, //输出交叉验证的文本数据文件 方便对比其它机器学习工具的实验效果";
			VLOG(0) << i++ << " CHANGE_RAIO //对输入样本进行正反例比例调整 比如 原始 1:30 调整为 1:1";
			VLOG(0) << i++ << " RANDOMIZE //对输入样本随机化处理，配合 -num > 0则只输出前num个样本 如果配合 -ci fr 或者  -ci forceRatio 那么保证比例,默认是不保证比例";
			VLOG(0) << i++ << " WRITE_TEXT_MODEL // 读入binary模型后写出文本格式模型如-mt -mxml -mjson(注意内部的normalizer如果需要文本输出需要-snt 1,类似的calibrator文本输出 -sct 1)";
			VLOG(0) << i++ << " TEXT_MODEL_TO_BINARY //读取-m 指定路径下的model.txt 用户指定模型名称-cl 默认是LinearSVM 按照文本格式模型载入写出binary模型到-m路径";
		}

		vector<EvaluatorPtr> CreateOrGetEvaluators()
		{
			vector<EvaluatorPtr> evaluators;
			if (!_cmd.evaluatorNames.empty())
			{
				evaluators = EvaluatorUtils::CreateEvaluators(_cmd.evaluatorNames);
			}
			else
			{
				evaluators = EvaluatorUtils::GetEvaluators(TrainerFactory::CreateTrainer(_cmd.classifierName));
			}
			CHECK_GT(evaluators.size(), 0);
			return evaluators;
		}

		void RunCrossValidation(Instances& instances, CrossValidationType cvType)
		{
			//--------------------------- 输出文件头
			string fullInstFile = _cmd.resultDir + "/" + STR(_cmd.resultIndex) + ".inst.txt";
			VLOG(0) << "Writting instance predict file to " << fullInstFile;
			ofstream ofs; //如果 cvType == CrossValidationType::USE_SCRIPT  使用
			if (cvType == CrossValidationType::USE_SCRIPT || cvType == CrossValidationType::DEFAULT)
			{
				try_create_dir(_cmd.resultDir);
				if (cvType == CrossValidationType::USE_SCRIPT)
				{
					ofs.open(fullInstFile);
					WriteInstFileHeader(ofs);
				}
			}

			if (_cmd.preNormalize)
			{
				NormalizerPtr normalizer = NormalizerFactory::CreateNormalizer(_cmd.normalizerName);
				CHECK(normalizer != nullptr);
				Pval(normalizer->Name());
				normalizer->RunNormalize(instances);
			}
			const int randomStep = 10000;
			//const int randomStep = 1;
			vector<EvaluatorPtr> evaluators;
			vector<Float> evaluatePredictions, evaluateProbabilities;
			vector<InstancePtr> evaluateInstances;
			if (cvType == CrossValidationType::EVAL_PARAM || cvType == CrossValidationType::EVAL_FULL)
			{ //@TODO check是否和PredictoionKind相匹配
				evaluators = CreateOrGetEvaluators();
			}
			string trainerParam;
			TesterPtr tester = nullptr;
			for (int runIdx = 0; runIdx < _cmd.numRuns; runIdx++)
			{
				VLOG(0) << "The " << runIdx << " round";
				RandomEngine rng = random_engine(_cmd.randSeed, runIdx * randomStep);
				if (!_cmd.foldsSequential)
					instances.Randomize(rng);

				ivec instanceFoldIndices = CVFoldCreator::CreateFoldIndices(instances, _cmd, rng);
				for (int foldIdx = 0; foldIdx < _cmd.numFolds; foldIdx++)
				{
					VLOG(0) << "Cross validaion foldIdx " << foldIdx;
					string instfile = format("{}/{}_{}_{}.inst.txt", _cmd.resultDir, _cmd.resultIndex
						, runIdx, foldIdx);

					Instances trainData, testData;
					//只是trainProportion < 1 才需要rng
					CVFoldCreator::CreateFolds(instances, _cmd.trainProportion,
						instanceFoldIndices, foldIdx, _cmd.numFolds, trainData, testData,
						random_engine(_cmd.randSeed, runIdx * randomStep));

					//------------------------------------Train
					TrainerPtr trainer = TrainerFactory::CreateTrainer(_cmd.classifierName);
					CHECK(trainer != nullptr);
					VLOG(0) << "Folds " << foldIdx << " are trained with " << trainData.Size() << " instances, and tested on " << testData.Size() << " instances";
					PVAL3(trainData[0]->name, trainData.PositiveCount(), trainData.NegativeCount());
					PVAL3(testData[0]->name, testData.PositiveCount(), testData.NegativeCount());

					trainer->SetNormalizeCopy();
					trainer->Train(trainData);
					PredictorPtr predictor = trainer->CreatePredictor();
					predictor->SetNormalizeCopy();

					if (cvType == CrossValidationType::USE_SCRIPT)
					{
						//@TODO 每个test 输出一个inst 文件也 然后每个给出一个结果
						VLOG(0) << "-------------------------------------Testing";
						Test(testData, predictor, instfile, ofs);
						string command = _cmd.evaluateScript + instfile;
#pragma omp critical
						{
							EXECUTE(command);
						}
					}
					else
					{
						if (cvType == CrossValidationType::DEFAULT || cvType == CrossValidationType::EVAL_FULL)
						{
							if (tester == nullptr)
							{
#pragma  omp critical
							{
								tester = PredictorUtils::GetTester(predictor);
								tester->isCrossValidationMode = true;
							}
							}
							else
							{
								tester->writeTSVHeader = false;
							}
							tester->Test(testData, predictor, fullInstFile);
						}
						if (cvType == CrossValidationType::EVAL_PARAM || cvType == CrossValidationType::EVAL_FULL)
						{
							Evaluate(testData, predictor, evaluatePredictions, evaluateProbabilities, evaluateInstances);
						}
					}

					if (foldIdx == 0)
					{
						trainerParam = trainer->GetParam();
					}
				}
			}

			if (cvType == CrossValidationType::USE_SCRIPT)
			{
				string command = _cmd.evaluateScript + fullInstFile;
#pragma omp critical
				{
					EXECUTE(command);
				}
			}
			else
			{
				if (cvType == CrossValidationType::DEFAULT || cvType == CrossValidationType::EVAL_FULL)
				{
					tester->Finalize();
				}
				if (cvType == CrossValidationType::EVAL_PARAM || cvType == CrossValidationType::EVAL_FULL)
				{
					vector<double> results(evaluators.size(), 0);
#pragma omp parallel for
					for (size_t i = 0; i < evaluators.size(); i++)
					{
						results[i] = evaluators[i]->Evaluate(evaluatePredictions, evaluateProbabilities, evaluateInstances);
					}
					cout << results[0] << "\t" << "trainerParam: " << trainerParam << endl;
					gezi::print(EvaluatorUtils::GetEvaluatorsNames(evaluators), results);
				}
			}
		}

		void RunCrossValidation(CrossValidationType cvType = CrossValidationType::DEFAULT)
		{
			Noticer nt(format("{} fold cross-validation", _cmd.numFolds));
			//----------------------------check if command ok
			CHECK_GE(_cmd.numFolds, 2) << "The number of folds must be at least 2 for cross validation";
			//-----------------------------parse input
			Instances instances = create_instances(_cmd.datafile);
			CHECK_GT(instances.Count(), 0) << "Read 0 instances, aborting experiment";
			instances.PrintSummary();
			if (cvType == CrossValidationType::DEFAULT && !_cmd.evaluateScript.empty())
			{
				cvType = CrossValidationType::USE_SCRIPT;
			}

			//@FIXME for rank and multil class ?
			if (TrainerFactory::CreateTrainer(_cmd.classifierName)->GetPredictionKind() != PredictionKind::BinaryClassification)
			{ //如果不是二分类 就不走按照0，1确保比例的分割fold方式 
				_cmd.foldsSequential = true;
			}
			//------------------------------run
			RunCrossValidation(instances, cvType);
		}

		void WriteInstFileHeader(ofstream& ofs)
		{
			ofs << "Instance\tTrue\tAssigned\tOutput\tProbability" << endl;
		}

		//------------------depreated 当前只是二分类支持这个 应该都走 tester->Test,当前保留只是为了二分类同时使用evaluate.py这样的外部脚本
		void Test(const Instances& instances, PredictorPtr predictor,
			string outfile, ofstream& ofs)
		{
			//@TODO 不再写每个round的单独文件 完善c++版本内部的evaluator进行输出展示
			ofstream currentOfs(outfile);
			WriteInstFileHeader(currentOfs);
			Test(instances, predictor, ofs, currentOfs);
		}

		void Test(const Instances& instances, PredictorPtr predictor, string outfile)
		{
			ofstream ofs(outfile);
			WriteInstFileHeader(ofs);
			Test(instances, predictor, ofs);
		}

		void Test(const Instances& instances, PredictorPtr predictor, ofstream& ofs)
		{
			int idx = 0;
			ProgressBar pb(instances.Count(), "Testing");
			//@TODO 并行加速预测？ BulkPredict ?  目前算法预测都很快 串行即可 暂时意义不大
			for (InstancePtr instance : instances)
			{
				++pb;
				double output;
				double probability = predictor->Predict(instance, output);
				CHECK(!std::isnan(output));
				string name = instance->name.empty() ? STR(idx) : instance->name;
				if (startswith(name, '_'))
				{
					name = name.substr(1);
				}

				int assigned = output > 0 ? 1 : 0;
				ofs << name << "\t" << instance->label << "\t"
					<< assigned << "\t" << output << "\t"
					<< probability << endl;

				idx++;
			}
		}

		void Test(const Instances& instances, PredictorPtr predictor, ofstream& ofs, ofstream& currentOfs)
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
#pragma  omp critical
				{
					ofs << name << "\t" << instance->label << "\t"
						<< assigned << "\t" << output << "\t"
						<< probability << endl;
				}
				currentOfs << name << "\t" << instance->label << "\t"
					<< assigned << "\t" << output << "\t"
					<< probability << endl;

				idx++;
			}
		}

		string TestLazyStore(const Instances& instances, PredictorPtr predictor)
		{
			stringstream ofs;
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

				idx++;
			}
			return ofs.str();
		}

		void Evaluate(const Instances& instances, PredictorPtr predictor, vector<Float>& predictions,
			vector<Float>& probabilities, vector<InstancePtr>& evaluateInstances)
		{
			int begin = predictions.size();
			predictions.resize(begin + instances.size());
			probabilities.resize(begin + instances.size());
			evaluateInstances.resize(begin + instances.size());
#pragma omp parallel for schedule(static)
			for (size_t i = 0; i < instances.size(); i++)
			{
				probabilities[begin + i] = predictor->Predict(instances[i], predictions[i]);
				evaluateInstances[begin + i] = instances[i];
			}
		}

		vector<Float> Evaluate(const Instances& instances, PredictorPtr predictor, vector<EvaluatorPtr>& evaluators)
		{
			vector<Float> predictions(instances.size(), 0), probabilities(instances.size(), 0);
#pragma omp parallel for schedule(static)
			for (size_t i = 0; i < instances.size(); i++)
			{
				probabilities[i] = predictor->Predict(instances[i], predictions[i]);
			}
			vector<Float> results(evaluators.size(), 0);
#pragma omp parallel for 
			for (size_t i = 0; i < evaluators.size(); i++)
			{
				results[i] = evaluators[i]->Evaluate(predictions, probabilities, instances);
			}
			return results;
		}

		PredictorPtr Train(Instances& instances)
		{
			auto trainer = TrainerFactory::CreateTrainer(_cmd.classifierName);
			CHECK(trainer != nullptr);
			if (_cmd.selfTest)
			{
				trainer->SetNormalizeCopy();
			}
			auto validatingTrainer = dynamic_pointer_cast<ValidatingTrainer>(trainer);
			if (validatingTrainer != nullptr && (_cmd.selfEvaluate || !_cmd.validationDatafile.empty() || _cmd.evaluateFraction > 0))
			{ //-----------------------Train with validation
				//对于可以在Training过程中支持Validating的ValidatingTrainer，如果输入-valid不是空， 那么
				//@TODO 对于后续的EarlyStop 考虑的效果 针对evaluateSet中的第一个数据的evaluate效果
				Instances* pTrainInstances = &instances;
				vector<EvaluatorPtr> evaluators = CreateOrGetEvaluators();
				VLOG(0) << "TrainWithValidating -- selfEvaluate:" << _cmd.selfEvaluate <<
					" validationDataFiles:" << _cmd.validationDatafile << " evaluators:" << gezi::join(EvaluatorUtils::GetEvaluatorsNames(evaluators), ",");

				vector<Instances> validatingSet;
				if (!_cmd.validationDatafile.empty())
				{
					vector<string> validatingSetNames = gezi::split(_cmd.validationDatafile, ',');
					for (string validatingSetName : validatingSetNames)
					{
						validatingSet.push_back(create_instances(validatingSetName));
						CHECK_GT(validatingSet.back().Count(), 0) << "Read 0 evaluate instances, aborting experiment";
					}
				}

				vector<Instances> parts;
				if (_cmd.evaluateFraction > 0)
				{
					parts = InstancesUtil::RandomSplit(instances, _cmd.evaluateFraction, _cmd.randSeed);
					VLOG(0) << "Split input insatnces to train and valid part with numTrainInsatnces: " << parts[0].Size()
						<< " numValidInstances: " << parts[1].Size();
					validatingSet.push_back(parts[1]);
					pTrainInstances = &parts[0];
				}

				(*validatingTrainer).SetTestFrequency(_cmd.evaluateFrequency).
					SetSelfEvaluate(_cmd.selfEvaluate).
					SetSelfEvaluate2(_cmd.selfEvaluate2);
				validatingTrainer->Train(*pTrainInstances, validatingSet, evaluators);
			}
			else
			{//--------------------------Simple Train
				trainer->Train(instances);
			}

			auto predictor = trainer->CreatePredictor();
			predictor->SetParam(trainer->GetParam());
			return predictor;
		}

		void PrintTrainerInfo()
		{
			Pval(_cmd.classifierName);
			auto trainer = TrainerFactory::CreateTrainer(_cmd.classifierName);
			if (trainer == nullptr)
			{
				LOG(WARNING) << _cmd.classifierName << " has not been supported yet";
				return;
			}
			trainer->ShowHelp();
		}

		void SavePredictor(PredictorPtr predictor)
		{
			Noticer nt("Save predictor");

			(*predictor).SetSaveNormalizerText(_cmd.saveNormalizerText)
				.SetSaveCalibratorText(_cmd.saveCalibratorText);

			predictor->Save(_cmd.modelFolder);
			if (_cmd.modelfileXml)
			{
				predictor->SaveXml();
			}
			if (_cmd.modelfileJson)
			{
				predictor->SaveJson();
			}
			if (_cmd.modelfileText)
			{
				predictor->SaveText();
			}
			if (_cmd.modelfileCode)
			{
				svec codeTypes = gezi::split(_cmd.codeType, ',');
				for (const auto& codeType : codeTypes)
				{
					predictor->SaveCode(codeType);
				}
			}
			if (_cmd.modelfileFeature)
			{
				predictor->SaveFeaturesGain(_cmd.num);
			}
		}

		PredictorPtr RunTrain(Instances& instances)
		{
			PredictorPtr predictor;
			{
				Noticer nt("Train!");
				instances = create_instances(_cmd.datafile);
				CHECK_GT(instances.Count(), 0) << "Read 0 test instances, aborting experiment";
				VLOG(0) << "Train " << _cmd.datafile << " using " << _cmd.classifierName << " trainer";
			}
			predictor = Train(instances);
			return predictor;
		}

		PredictorPtr RunTrain()
		{
			Instances instances;
			PredictorPtr predictor = RunTrain(instances);

			if (_cmd.selfTest)
			{
				VLOG(0) << "Test train file itself";
				RunTest(predictor, instances);
			}
			//如果是训练模式肯定save模型,如果是TrainTest模式为了速度默认是不save模型的可以通过--mf=1开启
			SavePredictor(predictor);
			return predictor;
		}

		void RunTest(PredictorPtr predictor, Instances& testInstances)
		{
			string instFile = _cmd.resultFile.empty() ? format("{}/{}.inst.txt", _cmd.resultDir, _cmd.resultIndex) : _cmd.resultFile;
			VLOG(0) << "Test " << testInstances.name << " and writting instance predict file to " << instFile;
			if (!_cmd.evaluatorNames.empty())
			{//多次test,确保testInstances不被改变
				predictor->SetNormalizeCopy();
			}
			if (!_cmd.evaluateScript.empty())
			{ //使用外部脚本 目前只支持二分类
				Test(testInstances, predictor, instFile);
				string command = _cmd.evaluateScript + instFile;
				EXECUTE(command);
			}
			else
			{ //默认走这里
				auto tester = PredictorUtils::GetTester(predictor);
				tester->Test(testInstances, predictor, instFile);
			}
			//使用Evaluator进行附加的evaluate 
			if (!_cmd.evaluatorNames.empty())
			{
				vector<EvaluatorPtr> evaluators = EvaluatorUtils::CreateEvaluators(_cmd.evaluatorNames);
				vector<Float> results = Evaluate(testInstances, predictor, evaluators);
				gezi::print(EvaluatorUtils::GetEvaluatorsNames(evaluators), results);
			}
		}

		void RunTest(PredictorPtr predictor)
		{
			//------test
			try_create_dir(_cmd.resultDir);
		
			//@TODO hack for text input format //Not tested correctness yet
			InstanceParser::TextFormatParsedTime(); //++ pared text from time这样表示需要使用词表数据
			string testDatafile = _cmd.testDatafile.empty() ? _cmd.datafile : _cmd.testDatafile;
			auto testInstances = create_instances(testDatafile);
			CHECK_GT(testInstances.Count(), 0) << "Read 0 test instances, aborting experiment";

			RunTest(predictor, testInstances);
		}

		void RunTest()
		{
			Noticer nt("Test! with model from " + _cmd.modelFolder);
			//------load predictor
			PredictorPtr predictor;
			{
				Noticer nt("Loading predictor");
				predictor = PredictorFactory::LoadPredictor(_cmd.modelFolder);
				CHECK(predictor != nullptr);
			}
			RunTest(predictor);
		}

		void RunTrainTest()
		{
			Noticer nt("TrainTest!");
			Instances instances;
			PredictorPtr predictor = RunTrain(instances);
			if (_cmd.modelfile)
			{ //训练+测试模式 默认是不save模型的 需要自己打开
				SavePredictor(predictor);
			}
			RunTest(predictor);
		}

		void RunFeatureSelection()
		{ //@TODO
			Noticer nt("FeatureSelection!");
			Instances instances = create_instances(_cmd.datafile);
		}

		void RunCreateInstances()
		{

		}

		void RunShowFeatures()
		{
			Instances instances = create_instances(_cmd.datafile);
			fmt::print("Num features: {}\n", instances.NumFeatures());
			int num = 0;
			for (string feature : instances.FeatureNames())
			{
				std::cout << num++ << "\t" << feature << endl;
			}
		}

#define  SAVE_SHARED_PTR_ALL(obj)\
										{\
		SAVE_SHARED_PTR(obj, _cmd.modelFolder); \
		if (_cmd.modelfileXml)\
										{\
		SAVE_SHARED_PTR_ASXML(obj, _cmd.modelFolder); \
										}\
		if (_cmd.modelfileJson)\
										{\
		SAVE_SHARED_PTR_ASJSON(obj, _cmd.modelFolder); \
										}\
		if (_cmd.modelfileText)\
										{\
		SAVE_SHARED_PTR_ASTEXT(obj, _cmd.modelFolder); \
										}\
										}

		void RunNormalize()
		{
			Noticer nt("Normalize!");
			NormalizerPtr normalizer = NormalizerFactory::CreateNormalizer(_cmd.normalizerName);
			CHECK(normalizer != nullptr);
			Pval(normalizer->Name());

			string infile = _cmd.datafile;
			//string suffix = normalizer->Name() + ".normed";
			string suffix = "normed";
			string outfile = _cmd.outfile.empty() ? GetOutputFileName(infile, suffix) : _cmd.outfile;
			Pval(outfile);

			Instances instances = create_instances(_cmd.datafile);

			normalizer->RunNormalize(instances);

			if (_cmd.saveOutputFile)
			{
				//FileFormat fileFormat = get_value(kFormats, _cmd.outputFileFormat, FileFormat::Unknown);
				FileFormat fileFormat = kFormats[_cmd.outputFileFormat];
				write(instances, outfile, fileFormat);
			}

			try_create_dir(_cmd.modelFolder);
			SAVE_SHARED_PTR_ALL(normalizer);
		}

		void RunNormalizeFile()
		{
			Noticer nt("Convert to normalized file!");
			NormalizerPtr normalizer = NormalizerFactory::CreateNormalizer(_cmd.normalizerName);
			CHECK(normalizer != nullptr);
			Pval(normalizer->Name());

			string infile = _cmd.datafile;
			//string suffix = normalizer->Name() + ".normed";
			string suffix = "normed";
			string outfile = _cmd.outfile.empty() ? GetOutputFileName(infile, suffix) : _cmd.outfile;
			Pval(outfile);

			Instances instances = create_instances(_cmd.datafile);

			normalizer->RunNormalize(instances);

			//FileFormat fileFormat = get_value(kFormats, _cmd.outputFileFormat, FileFormat::Unknown);
			FileFormat fileFormat = kFormats[_cmd.outputFileFormat];
			write(instances, outfile, fileFormat);
		}

		void RunCalibrate()
		{
			Noticer nt("Calibrate!");

			auto calibrator = CalibratorFactory::CreateCalibrator(_cmd.calibratorName);
			CHECK(calibrator != nullptr);
			Pval(calibrator->Name());

			Instances instances = create_instances(_cmd.datafile);
			auto predictor = PredictorFactory::LoadPredictor(_cmd.modelFolder);
			calibrator->Train(instances, [&predictor](InstancePtr instance) { return predictor->Output(instance); });

			try_create_dir(_cmd.modelFolder);
			//@WARNING calibrator 这个名字不能变 宏需要写到calibrator.bin... normalizer类似
			SAVE_SHARED_PTR_ALL(calibrator);
		}

		void RunCheckData()
		{
			Noticer nt("CheckData!(need GLOG_v=4 or -vl 4), this command is derecated try use -c fss -vl 1");
			Instances instances = create_instances(_cmd.datafile);
			NormalizerPtr normalizer = make_shared<MinMaxNormalizer>();
			normalizer->Prepare(instances);
		}

		void RunShowInfos()
		{
			auto instances = create_instances(_cmd.datafile, true); //内部打印信息
		}

		void RunFeatureStatus()
		{
			Noticer nt("FeatureStatus! You may try to use -vl 1 to print warning of possible no use features");
			string infile = _cmd.datafile;
			string suffix = "featurestatus";
			string outfile = _cmd.outfile.empty() ? GetOutputFileName(infile, suffix)
				: _cmd.outfile;
			string outfile2 = _cmd.outfile.empty() ? GetOutputFileName(infile, format("{}.csv", suffix), true)
				: format("{}.csv", _cmd.outfile);
			Instances instances = create_instances(_cmd.datafile);
			FeatureStatus::GenMeanVarInfo(instances, outfile, outfile2, _cmd.featureName);
		}

		//输入文件转换后输出
		void RunConvert()
		{
			FileFormat defaultFileFormat = _cmd.inputFileFormat == kFormatNames[FileFormat::LibSVM] ? FileFormat::Unknown : FileFormat::LibSVM;
			FileFormat fileFormat = get_value(kFormats, _cmd.outputFileFormat, defaultFileFormat);
			Instances instances = create_instances(_cmd.datafile);
			if (fileFormat == FileFormat::Unknown)
			{
				LOG(WARNING) << "Not specified ouput file format";
			}
			else if (fileFormat == instances.schema.fileFormat)
			{
				LOG(WARNING) << "Specified ouput file format is the same as input";
			}
			//else
			{
				string outfile = _cmd.outfile;
				if (outfile.empty())
				{
					string suffix = kFormatNames[fileFormat];
					outfile = GetOutputFileName(_cmd.datafile, suffix, true);
					if (outfile == _cmd.datafile)
					{
						outfile += ".bak";
					}
				}
				write(instances, outfile, fileFormat);
			}
		}

		void SplitDataByLabel(const Instances& instances)
		{
			Instances posInstances(instances.schema);
			Instances negInstances(instances.schema);
			//FileFormat fileFormat = get_value(kFormats, _cmd.outputFileFormat, FileFormat::Unknown);
			FileFormat fileFormat = kFormats[_cmd.outputFileFormat];
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
				write(negInstances, outfile, fileFormat);
			}
		}

		vector<Instances> SplitData(Instances& instances)
		{
			vector<Instances> parts;
			if (_cmd.commandInput.empty())
			{
				VLOG(0) << "No input assume to split by label >0 or <=0, notice only for binary classificaion purpose";
				SplitDataByLabel(instances);
				return parts;
			}

			ivec segs;
			try
			{
				segs.resize(boost::lexical_cast<int>(_cmd.commandInput), 1);
			}
			catch (...)
			{
				svec segs_ = split(_cmd.commandInput, ':');
				//Need input like -ci 1:1  -ci 1:3:2 or -ci 5 or -ci 0.25
				//如果没有-ci输入默认按照label分割
				if (segs_.size() == 1)
				{
					try
					{
						double ratio = DOUBLE(_cmd.commandInput);
						if (ratio < 1)
						{//like -ci 0.25
							return InstancesUtil::RandomSplit(instances, ratio, _cmd.randSeed);
						}
						else
						{ //like -ci 5
							segs.resize((size_t)ratio, 1);
						}
					}
					catch (...)
					{
						LOG(WARNING) << "Need input like -ci 1:1  -ci 1:3:2 or -ci 5 or -ci 0.25";
					}
				}
				else
				{
					segs = from(segs_) >> select([](string a) { return INT(a); }) >> to_vector();
				}
			}

			_cmd.numFolds = sum(segs);
			Pval(_cmd.numFolds);
			int partNum = segs.size();
			RandomEngine rng = random_engine(_cmd.randSeed);
			if (!_cmd.foldsSequential)
				instances.Randomize(rng);
			ivec instanceFoldIndices = CVFoldCreator::CreateFoldIndices(instances, _cmd, rng);
			parts.resize(partNum);

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

			return parts;
		}
		//当前复用cross fold思路 
		void RunSplitData()
		{
			auto instances = create_instances(_cmd.datafile);
			vector<Instances> parts = SplitData(instances);
			int partNum = parts.size();
			if (partNum > 0)
			{
				string infile = _cmd.datafile;
				//FileFormat fileFormat = get_value(kFormats, _cmd.outputFileFormat, FileFormat::Unknown);
				FileFormat fileFormat = kFormats[_cmd.outputFileFormat];
				for (int i = 0; i < partNum; i++)
				{
					string suffix = STR(i) + "_" + STR(partNum);
					string outfile = GetOutputFileName(infile, suffix);
					{
						string suffix = kFormatSuffixes[fileFormat];
						if (suffix != "txt")
						{
							outfile = GetOutputFileName(outfile, suffix, true);
						}
					}
					Pval(outfile);
					write(parts[i], outfile, fileFormat);
				}
			}
		}

		void 	RunGenCrossData()
		{
			//输入是什么格式 输出还是什么格式 如果输入格式参数错误按照libsvm输出 
			FileFormat fileFormat = get_value(kFormats, _cmd.outputFileFormat, FileFormat::LibSVM);
			auto instances = create_instances(_cmd.datafile);
			string outDir = _cmd.outDir.empty() ? "cross-data" : _cmd.outDir;
			try_create_dir(outDir);
			//输入 feature.txt 输出到outDir下  feature.train_0.txt feature.test_0.txt feature.train_1.txt ...
			//不考虑runIdx 统一累加 0,1,2...
			const int randomStep = 10000; //@TODO
			for (int runIdx = 0; runIdx < _cmd.numRuns; runIdx++)
			{
				VLOG(0) << "The " << runIdx << " round";
				RandomEngine rng = random_engine(_cmd.randSeed, runIdx * randomStep);
				if (!_cmd.foldsSequential)
					instances.Randomize(rng);

				ivec instanceFoldIndices = CVFoldCreator::CreateFoldIndices(instances, _cmd, rng);
				for (int foldIdx = 0; foldIdx < _cmd.numFolds; foldIdx++)
				{
					VLOG(0) << "Cross validaion foldIdx " << foldIdx;
					int idx = runIdx * _cmd.numFolds + foldIdx;

					Instances trainData, testData;
					//只是trainProportion < 1 才需要rng
					CVFoldCreator::CreateFolds(instances, _cmd.trainProportion,
						instanceFoldIndices, foldIdx, _cmd.numFolds, trainData, testData,
						random_engine(_cmd.randSeed, runIdx * randomStep));

					string trainSuffix = "feature.train_" + STR(idx);
					string trainFile = outDir + "/" + trainSuffix;
					string testSuffix = "feature.test_" + STR(idx);
					string testFile = outDir + "/" + testSuffix;
					Pval2(trainFile, testFile);

					write(trainData, trainFile, fileFormat);
					write(testData, testFile, fileFormat);
				}
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

			size_t posNum = instances.PositiveCount();
			size_t negNum = instances.Count() - posNum;

			size_t posAdjustedNum = negNum / negPart * posPart;

			string infile = _cmd.datafile;
			string suffix = replace(_cmd.commandInput, ':', '-');
			string outfile = GetOutputFileName(infile, suffix);
			FileFormat fileFormat = get_value(kFormats, _cmd.outputFileFormat, FileFormat::Unknown);
			if (posAdjustedNum == posNum)
			{
				LOG(WARNING) << "Need to do nothing";
			}
			else
			{
				Instances newInstances(instances.schema);
				if (posAdjustedNum > posNum)
				{
					size_t negAdjustedNum = posNum / posPart * negPart;
					VLOG(0) << "Shrink neg part num to " << negAdjustedNum;
					size_t negCount = 0;
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
					size_t posCount = 0;
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
				write(newInstances, outfile, fileFormat);
			}
		}

		void RunRandomize()
		{
			auto instances = create_instances(_cmd.datafile);
			RandomEngine rng = random_engine(_cmd.randSeed);
			
			FileFormat fileFormat = get_value(kFormats, _cmd.outputFileFormat, FileFormat::Unknown);
			string suffix = "rand";
			if (_cmd.num > 0)
			{
				suffix = format("{}.{}", suffix, _cmd.num);
			}
			string outfile = _cmd.outfile.empty() ? GetOutputFileName(_cmd.datafile, suffix) : _cmd.outfile;
			Pval(outfile);

			if (_cmd.num > 0 && _cmd.num < (int64)instances.Count())
			{
				if (!_cmd.foldsSequential)
				{
					instances.Randomize(rng);
				}
				Instances newInstances(instances.schema);
				if (_cmd.commandInput == "fr" || _cmd.commandInput == "forceRatio")
				{ //保证正负比例
					double posRatio = instances.PositiveCount() / (double)instances.Count();
					size_t posCount = (size_t)(_cmd.num * posRatio + 0.5);
					size_t negCount = _cmd.num - posCount;
					size_t numPoses = 0, numNegs = 0;
					for (size_t i = 0; i < instances.Count(); i++)
					{
						if (instances[i]->IsPositive())
						{
							if (numPoses < posCount)
							{
								numPoses++;
								newInstances.push_back(instances[i]);
								if (numPoses + numNegs == (size_t)_cmd.num)
								{
									break;
								}
							}
						}
						else
						{
							if (numNegs < negCount)
							{
								numNegs++;
								newInstances.push_back(instances[i]);
								if (numPoses + numNegs == (size_t)_cmd.num)
								{
									break;
								}
							}
						}
					}
				}
				else
				{ //完全依靠随机
					for (int i = 0; i < _cmd.num; i++)
					{
						newInstances.push_back(instances[i]);
					}
				}
				write(newInstances, outfile, fileFormat);
			}
			else
			{
				try
				{
					double ratio = DOUBLE(_cmd.commandInput);
					instances.ShrinkData(ratio, rng);
				}
				catch (...)
				{
					instances.Randomize(rng);
				}
				write(instances, outfile, fileFormat);
			}
		}

		void RunWriteTextModel()
		{
			if (!_cmd.modelfileText && !_cmd.modelfileXml && !_cmd.modelfileJson)
			{
				LOG(WARNING) << "Will do nothing, you have to set -mt 1 or -mxml 1 or -mjson 1";
				return;
			}

			Noticer nt("WiteTextModel! with model from " + _cmd.modelFolder);
			//------load predictor
			PredictorPtr predictor;
			if (!_cmd.saveNormalizerText && !_cmd.saveCalibratorText)
			{
				Predictor::loadNormalizerAndCalibrator() = false;
			}

			{
				Noticer nt("Loading predictor");
				predictor = PredictorFactory::LoadPredictor(_cmd.modelFolder);
			}

			(*predictor).SetSaveNormalizerText(_cmd.saveNormalizerText)
				.SetSaveCalibratorText(_cmd.saveCalibratorText)
				.SetPath(_cmd.modelFolder);

			if (_cmd.modelfileXml)
			{
				predictor->SaveXml();
			}
			if (_cmd.modelfileJson)
			{
				predictor->SaveJson();
			}
			if (_cmd.modelfileText)
			{
				predictor->SaveText();
			}
		}

		void RunTextModelToBinary()
		{
			Noticer nt("TextModelToBinary! with model from " + _cmd.modelFolder);
			//------load predictor
			PredictorPtr predictor;
			Predictor::loadNormalizerAndCalibrator() = false;
			{
				Noticer nt("Loading predictor");
				predictor = PredictorFactory::CreatePredictorFromTextFormat(_cmd.classifierName, _cmd.modelFolder);
			}
			predictor->Save(_cmd.modelFolder);
		}

		void RunExperiments()
		{
			Pval(omp_get_num_procs());
			if (_cmd.numThreads)
			{
				omp_set_num_threads(_cmd.numThreads);
			}
			else
			{ //@TODO openmp设置线程数目很微妙。。 如果有其它程序在跑12核 设置12 很慢 11，13 等都比12快很多。。
				int numProcs = omp_get_num_procs();
				numProcs = std::max(1, numProcs - 2);
				omp_set_num_threads(numProcs);
			}
			Pval(get_num_threads());
			//解析命令模式
			string commandStr = arg(_cmd.command);
			Pval(commandStr);
			//RunType command = get_value(_commands, commandStr, RunType::UNKNOWN);
			RunType command = _commands[commandStr];
			switch (command)
			{
			case RunType::EVAL:
				RunCrossValidation();
				break;
			case  RunType::EVAL_PARAM:
				RunCrossValidation(CrossValidationType::EVAL_PARAM);
				break;
			case RunType::EVAL_FULL:
				RunCrossValidation(CrossValidationType::EVAL_FULL);
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
				RunNormalize();
				break;
			case RunType::NORMALIZE_FILE:
				RunNormalizeFile();
				break;
			case RunType::CALIBRATE:
				RunCalibrate();
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
			case  RunType::GEN_CROSS_DATA:
				RunGenCrossData();
				break;
			case RunType::CHANGE_RAIO:
				RunChangeRatio();
				break;
			case RunType::RANDOMIZE:
				RunRandomize();
				break;
			case RunType::WRITE_TEXT_MODEL:
				RunWriteTextModel();
				break;
			case  RunType::TEXT_MODEL_TO_BINARY:
				RunTextModelToBinary();
				break;
			case RunType::HELP:
				PrintCommands();
				break;
			case RunType::HELP_TRAINERS:
				TrainerFactory::PrintTrainersInfo();
				break;
			case RunType::HELP_TRAINER:
				PrintTrainerInfo();
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
			{ "help", RunType::HELP },
			{ "helptrainers", RunType::HELP_TRAINERS },
			{ "hts", RunType::HELP_TRAINERS },
			{ "helptrainer", RunType::HELP_TRAINER },
			{ "ht", RunType::HELP_TRAINER },
			{ "cv", RunType::EVAL },
			{ "eval", RunType::EVAL },
			{ "evalparam", RunType::EVAL_PARAM },
			{ "cv2", RunType::EVAL_PARAM },
			{ "cvparam", RunType::EVAL_PARAM },
			{ "auc", RunType::EVAL_PARAM },
			{ "cvfull", RunType::EVAL_FULL },
			{ "cv3", RunType::EVAL_FULL },
			{ "evalfull", RunType::EVAL_FULL },
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
			{ "normfile", RunType::NORMALIZE_FILE },
			{ "calibrate", RunType::CALIBRATE },
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
			{ "gencrossdata", RunType::GEN_CROSS_DATA },
			{ "gcd", RunType::GEN_CROSS_DATA },
			{ "changeratio", RunType::CHANGE_RAIO },
			{ "cr", RunType::CHANGE_RAIO },
			{ "randomize", RunType::RANDOMIZE },
			{ "rand", RunType::RANDOMIZE },
			{ "writetextmodel", RunType::WRITE_TEXT_MODEL },
			{ "wtm", RunType::WRITE_TEXT_MODEL },
			{ "binarymodeltotext", RunType::WRITE_TEXT_MODEL },
			{ "bm2t", RunType::WRITE_TEXT_MODEL },
			{ "textmodeltobinary", RunType::TEXT_MODEL_TO_BINARY },
			{ "tm2b", RunType::TEXT_MODEL_TO_BINARY }
		};

	};
} //end of namespace gezi


#endif  //----end of RUN__MELT_H_
