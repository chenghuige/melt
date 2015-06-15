/**
 *  ==============================================================================
 *
 *          \file   MLCore/Trainer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-06 20:47:13.472915
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef M_L_CORE__TRAINER_H_
#define M_L_CORE__TRAINER_H_

#include "common_def.h"
#include "random_util.h"
#include "Prediction/Instances/Instances.h"
#include "MLCore/Predictor.h"
#include "Prediction/Normalization/Normalizer.h"
#include "Prediction/Calibrate/Calibrator.h"
#include "Utils/Evaluator.h"
#include "statistic_util.h"
#include "MLCore/LossKind.h"

namespace gezi {

	class Trainer : public WithArgs, public WithHelp
	{
	public:
		virtual PredictionKind GetPredictionKind()
		{
			return PredictionKind::BinaryClassification;
		}

		virtual LossKind GetLossKind()
		{
			return LossKind::Unknown;
		}

		//默认流程特别为类似线性分类需要normalize的流程准备 如果不需要比如Fastrank 可以自己override
		virtual void Train(Instances& instances)
		{
			VLOG(5) << "Train in trainer base";
			_trainingSchema = instances.schema;
			_instances = &instances;

			_numFeatures = instances.NumFeatures();
			_featureNames = instances.schema.featureNames;

			Init();
			Initialize(instances);

			TryInitializeNormalizer(instances, _isStreaming); //normalize and set _instances

			InnerTrain(*_instances);

			Finalize(*_instances);

			if (!GetParam().empty())
			{
				VLOG(0) << "Param: [" << GetParam() << " ]" << endl;
			}
		}

		virtual void TryInitializeNormalizer(Instances& instances, bool isStreaming)
		{
			//--- 将所有数据归一化 和TLC策略不同 TLC将normalize混在训练过程中(主要可能是兼容streaming模式)
			//特别是hadoop scope训练  @TODO  也许这里也会变化
			//如果不是类似交叉验证 比如就是训练测试 默认是 no normalize copy
			//目前这种就是全部normalize 可能有些情况 比如训练随机抽取一小部分 那么训练过程再normalize可能更合适@TODO
			if (!isStreaming && _normalizer != nullptr && !instances.IsNormalized())
			{
				if (!_normalizeCopy)
				{
					_normalizer->RunNormalize(instances);
				}
				else
				{
					normalizedInstances() = _normalizer->RunNormalizeCopy(instances);
					_instances = &normalizedInstances();
				}
			}
		}

		const HeaderSchema& TrainingSchema() const
		{
			return _trainingSchema;
		}

		virtual PredictorPtr CreatePredictor() = 0; //@TODO 也许应该在这强制加入Predictor::SetParam

		virtual string GetParam()
		{
			return "";
		}

		RandomPtr GetRandom()
		{
			return _rand;
		}

		NormalizerPtr GetNormalizer()
		{
			return _normalizer;
		}

		CalibratorPtr GetCalibrator()
		{
			return _calibrator;
		}

		void SetNormalizeCopy(bool normalizeCopy = true)
		{
			_normalizeCopy = normalizeCopy;
		}


		void SetNormalizer(NormalizerPtr normalizer)
		{
			_normalizer = normalizer;
		}

		void SetCalibrator(CalibratorPtr calibrator)
		{
			_calibrator = calibrator;
		}

		void SetStreaming()
		{
			_isStreaming = true;
		}

		virtual unsigned GetRandSeed() const
		{
			return _randSeed;
		}

		void SetRandSeed(unsigned randSeed)
		{
			_randSeed = randSeed;
		}

	protected:
		virtual void Init()
		{

		}

		virtual void Initialize(Instances& instances)
		{

		}
		virtual void InnerTrain(Instances& instances)
		{

		}

		virtual void Finalize(Instances& instances)
		{

		}
	protected:
		HeaderSchema _trainingSchema;

		bool _isStreaming = false;
		unsigned _randSeed = 0;
		RandomPtr _rand = nullptr;
		RandomRangePtr _randRange = nullptr;
		NormalizerPtr _normalizer = nullptr;
		CalibratorPtr _calibrator = nullptr;

		FeatureNamesVector _featureNames;
		/// <summary> Total number of features </summary>
		int _numFeatures = 0;

		bool _normalizeCopy = false;

		//希望不同的子类Trainer Share相同的normalizedInstance 但是不同的线程各有一份,另外不用到norm则不产生_normalizedInstance
		//@TODO 意义也不是很大。。  直接普通 Instances _normalizedInstances; 应该也ok了 如果避免多次normalize 应该先对输入做好norm，
		//这里更多的一样可能是不希望一个线程的多个不同Trainer实例有多个内存占用存储_normalizedInstances
		static Instances& normalizedInstances()
		{
			static thread_local Instances _normalizedInstances;
			return _normalizedInstances;
		}

		Instances* _instances = NULL;
	};

	typedef shared_ptr<Trainer> TrainerPtr;

	class ValidatingTrainer : public Trainer
	{
	public:
		using Trainer::Trainer;
		ValidatingTrainer()
		{//确保Scores至少有一个TrainingScore
			Scores.resize(1);
		}

		using Trainer::Train;

		//尽管instances传入不使用const 但是注意trainer要SetNormalizeCopy 实际还是保证不改变所有输入
		virtual void Train(Instances& instances, vector<Instances>& validationInstances, vector<EvaluatorPtr>& evaluators)
		{
			_instances = &instances;
			Trainer::SetNormalizeCopy(false);
			PVAL2(validationInstances.size(), _validationSets.size());
			_validationSets = move(validationInstances);
			PVAL2(validationInstances.size(), _validationSets.size());
			_evaluators = move(evaluators);
			_validating = true;
			//_valdationSetNames = from(_validationSets) >> select([](const Instances& a) { return a.name; }) >> to_vector();

			for (size_t i = 0; i < _validationSets.size(); i++)
			{
				_valdationSetNames.push_back(format("test[{}]", i));
			}

			if (_selfEvaluate)
			{
				_valdationSetNames.push_back("train");
				_validationSets.push_back(instances);
			}

			if (_selfEvaluate2)
			{
				_valdationSetNames.push_back("itrain"); //inner-train
			}

			Scores.resize(_validationSets.size());
			for (size_t i = 0; i < _validationSets.size(); i++)
			{
				Scores[i].resize(_validationSets[i].size(), 0.0);
			}

			TrainScores.resize(instances.size(), 0); //如果gbdt bagging sample with fraction then will modify this size

			if (GetPredictionKind() == PredictionKind::BinaryClassification)
			{
				bool needProb = false;
				for (auto& evaluator : _evaluators)
				{
					if (evaluator->UseProbability())
					{
						needProb = true;
					}
				}
				if (needProb)
				{
					Probabilities.resize(_validationSets.size());
					for (size_t i = 0; i < _validationSets.size(); i++)
					{
						Probabilities[i].resize(_validationSets[i].size(), 0.5);
					}
				}
			}

			_evaluateResults.resize(_evaluators.size());
			for (size_t i = 0; i < _evaluators.size(); i++)
			{
				_evaluateResults[i].resize(_valdationSetNames.size(), 0);
			}

			if (_earlyStop)
			{
				InitEarlyStop();
			}
			//Trainer::Train(instances);  //不用Trainer::会提示找不到重载 注意要在外面使用using Trainer::Train 在这里用Trainer::会造成多态失效
			Train(instances);
		}

		virtual void Train(Instances& instances, vector<Instances>&& validationInstances, vector<EvaluatorPtr>&& evaluators)
		{
			PVAL2(validationInstances.size(), _validationSets.size());
			vector<Instances> _validationSets = move(validationInstances);
			vector<EvaluatorPtr> _evaluators = move(evaluators);
			PVAL2(validationInstances.size(), _validationSets.size());
			return Train(instances, _validationSets, _evaluators);
		}

		int BestIteration() const
		{
			return _bestCheckIteration * _earlyStopCheckFrequency;
		}

		bool Validating() const
		{
			return _validating;
		}

	protected:

		//继承类 每轮迭代都要调用,round从1开始, forceEvaluate比如最后一轮 强制Evaluate需要具体trainer传递这个信息
		//返回值表示是否earlyStop检测为true
		bool Evaluate(int round, bool forceEvaluate = false)
		{
			if (_validating)
			{
				_round = round;
				bool earlyStopCheck = _earlyStop && round % _earlyStopCheckFrequency == 0;
				bool evaluateCheck = round % _evaluateFrequency == 0 || forceEvaluate;
				if (earlyStopCheck)
				{
					EvaluateOnce();
					if (CheckEarlyStop())
					{
						PrintEvaluateResult(round);
						VLOG(0) << "Early stop at check round: " << _checkCounts
							<< " stop iteration: " << round
							<< " best iteration: " << _bestCheckIteration * _earlyStopCheckFrequency
							<< " best score: " << _bestScore;
						return true;
					}
					if (evaluateCheck)
					{
						PrintEvaluateResult(round);
					}
				}
				else if (evaluateCheck)
				{
					EvaluateOnce();
					PrintEvaluateResult(round);
				}
				return false;
			}
			return false;
		}

		void EvaluateOnce()
		{
			GenPredicts();
			GenProabilites();
			EvaluatePredicts();
		}
		//FastRank是在ScoreTracker中处理,没棵树建立完ScoreTracker会对所有TrackedScore更新Scores 所以空即可
		//Or UpdateScores
		virtual void GenPredicts()
		{
			//---below for one test check for same Insatnce DataSet
			//static int round = 0;
			//for (size_t i = 0; i < Scores[0].size(); i++)
			//{
			//	CHECK_EQ(Scores[0][i], Scores[1][i]) << "round:" << round << " instance:" << i;
			//}
			//round++;
		}

		template<typename Func>
		void DoGenPredicts(Func func)
		{
			for (size_t i = 0; i < Scores.size(); i++)
			{
				for (size_t j = 0; j < Scores[i].size(); j++)
				{
					Scores[i][j] = func(_validationSets[i][j]);
				}
			}
		}

		template<typename Func>
		void DoAddPredicts(Func func)
		{
			for (size_t i = 0; i < Scores.size(); i++)
			{
				for (size_t j = 0; j < Scores[i].size(); j++)
				{
					Scores[i][j] += func(_validationSets[i][j]);
				}
			}
		}

		template<typename Func>
		void DoPredicts(Func func)
		{
			for (size_t i = 0; i < Scores.size(); i++)
			{
				for (size_t j = 0; j < Scores[i].size(); j++)
				{
					func(ref(Scores[i][j]), _validationSets[i][j]);
				}
			}
		}

		virtual void GenProabilites()
		{
			if (!Probabilities.empty())
			{
				for (size_t i = 0; i < Scores.size(); i++)
				{
					for (size_t j = 0; j < Scores[i].size(); j++)
					{//_calibrator 其实是 null的 train的iter过程中 没有calibrate 最后统一做的 所以 可能和test的值存在不一致
						Probabilities[i][j] = _calibrator == nullptr ? gezi::sigmoid(Scores[i][j] / _scale) :
							_calibrator->PredictProbability(Scores[i][j] / _scale);
					}
				}
				TrainProbabilities.resize(TrainScores.size(), 0.5);
				for (size_t i = 0; i < TrainScores.size(); i++)
				{
					TrainProbabilities[i] = _calibrator == nullptr ? gezi::sigmoid(TrainScores[i] / _scale) :
						_calibrator->PredictProbability(TrainScores[i] / _scale);
				}
			}
		}

		virtual void EvaluatePredicts()
		{
			Fvec scaledScores;
			for (size_t i = 0; i < _evaluators.size(); i++)
			{
				for (size_t j = 0; j < _validationSets.size(); j++)
				{
					Fvec* pscore = &Scores[j];
					if (_scale != 1.0)
					{
						scaledScores = Scores[j];
						for (size_t k = 0; k < Scores[j].size(); k++)
						{
							scaledScores[k] /= _scale;
						}
						pscore = &scaledScores;
					}
					_evaluateResults[i][j] =
						Probabilities.empty() || !_evaluators[i]->UseProbability() ?
						//_evaluators[i]->Evaluate(Scores[j], _validationSets[j]) :
						_evaluators[i]->Evaluate(*pscore, _validationSets[j]) :
						_evaluators[i]->Evaluate(Probabilities[j], _validationSets[j]);
				}
				if (_selfEvaluate2)
				{
					Fvec* pscore = &TrainScores;
					if (_scale != 1.0)
					{
						scaledScores = TrainScores;
						for (size_t k = 0; k < TrainScores.size(); k++)
						{
							scaledScores[k] /= _scale;
						}
						pscore = &scaledScores;
					}
					_evaluateResults[i].back() =
						TrainProbabilities.empty() || !_evaluators[i]->UseProbability() ?
						//_evaluators[i]->Evaluate(TrainScores, *_instances) :
						_evaluators[i]->Evaluate(*pscore, *_instances) :
						_evaluators[i]->Evaluate(TrainProbabilities, *_instances);
				}
			}
		}

		virtual void StoreBestStage()
		{

		}

		virtual void RestoreBestStage()
		{

		}

	private:
		void PrintEvaluateResult(int round)
		{
			static int evluateRound = 1;
			for (size_t i = 0; i < _evaluators.size(); i++)
			{
				std::cerr << std::setiosflags(ios::left) << std::setfill(' ') << std::setw(30)
					<< format("[{}|{}]{}", evluateRound, round, _evaluators[i]->Name())
					<< gezi::print2str_row(_valdationSetNames, _evaluateResults[i], 13)
					<< std::endl;
			}
			evluateRound++;
		}

		void InitEarlyStop()
		{
			if (_evaluators[0]->LowerIsBetter())
			{
				_bestScore = std::numeric_limits<Float>::max();
			}
			else
			{
				_bestScore = std::numeric_limits<Float>::lowest();
			}
		}
	
		bool IsBetter(Float now, Float before)
		{
			return _evaluators[0]->LowerIsBetter() ? now < before :
				now > before;
		}

		bool CheckEarlyStop()
		{
			_checkCounts++;
			if (IsBetter(_evaluateResults[0][0], _bestScore))
			{
				if (_useBestStage)
				{
					StoreBestStage();
				}
				_bestScore = _evaluateResults[0][0];
				_bestCheckIteration = _checkCounts;
			}
			else
			{
				if (_checkCounts - _bestCheckIteration >= _stopRounds)
				{
					if (_useBestStage)
					{
						RestoreBestStage();
					}
					return true;
				}
			}
			return false;
		}
	public:
		ValidatingTrainer& SetEvaluateFrequency(int freq)
		{
			_evaluateFrequency = freq;
			return *this;
		}

		ValidatingTrainer& SetSelfEvaluate(bool evaluate)
		{
			_selfEvaluate = evaluate;
			return *this;
		}

		ValidatingTrainer& SetSelfEvaluate2(bool evaluate)
		{
			_selfEvaluate2 = evaluate;
			return *this;
		}

		void SetScale(double scale)
		{
			_scale = scale;
		}

		void SetSelfEvaluateInstances(const Instances& instances)
		{
			_instances = &instances;
		}

		ValidatingTrainer& SetEarlyStop(bool earlyStop = true)
		{
			_earlyStop = earlyStop;
			return *this;
		}

		ValidatingTrainer& SetEarlyStopCheckFrequency(int earlyStopCheckFrequency)
		{
			_earlyStopCheckFrequency = earlyStopCheckFrequency;
			return *this;
		}

		ValidatingTrainer& SetEarlyStopRounds(int stopRounds)
		{
			_stopRounds = stopRounds;
			return *this;
		}

		ValidatingTrainer& SetUseBestStage(bool useBestStage = true)
		{
			_useBestStage = useBestStage;
			return *this;
		}

	public:
		vector<Fvec> Scores;    //在gbdt这种类型的迭代中Scores还起着保留现有结果后续累加的作用 引用传递给ScoreTracker处理
		vector<Fvec> Probabilities;

		Fvec TrainScores;        //真实的内部训练数据实际score
		Fvec TrainProbabilities;
	protected:
		//-----validating args
		bool _validating = false;
		bool _selfEvaluate = false; //the same as loading the training file again but only need loading once
		bool _selfEvaluate2 = false; //truly internal self invaluate
		int _evaluateFrequency = 1; //每_testFrequency轮 做一次eval,并展示结果

		vector<Fvec> _evaluateResults; //每个evaluator对应一个vec  长度是 _numValidations
		vector<Instances> _validationSets;
		vector<EvaluatorPtr> _evaluators;
		vector<string> _valdationSetNames;

		Float _scale = 1.0; //目前主要是gbdt中bagging的时候 为了过程的output尽可能真实

		//-----------------------early stop
		//----early stop args
		bool _earlyStop = false;
		int _earlyStopCheckFrequency = 1; //gbdt应该每轮都check,但是对应比如linearSVM没有必要 可以100轮测试一次
		//如果_stopRounds轮表现没有提升 那么stop 这个轮数是指的earlyStop的check轮数,实际算法迭代次数是* _earlyStopCheckFrequency
		//比如 如果当前轮和上一轮相比没有基本 而stopRound设置为1 那么就立即停止了
		int _stopRounds = 100;
		bool _useBestStage = false;

		int _bestCheckIteration = 0;
		int _roundsAfterBestIteration = 0;
		int _checkCounts = 0;
		Float _bestScore = 0;

		int _round;
	};

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__TRAINER_H_
