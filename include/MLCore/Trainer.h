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

namespace gezi {

	class Trainer : public WithArgs, public WithHelp
	{
	public:
		virtual PredictionKind GetPredictionKind()
		{
			return PredictionKind::BinaryClassification;
		}

		//默认流程特别为类似线性分类需要normalize的流程准备 如果不需要比如Fastrank 可以自己override
		virtual void Train(Instances& instances)
		{
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

		//尽管instances传入不使用const 但是注意trainer要SetNormalizeCopy 实际还是保证不改变所有输入
		virtual void Train(Instances& instances,
			vector<Instances>& validationInstances, vector<EvaluatorPtr>& evaluators,
			bool selfEvaluate = false, int testFrequency = 1)
		{
			//Trainer::SetNormalizeCopy();
			PVAL2(validationInstances.size(), evaluators.size());
			_validationSets = move(validationInstances);
			_evaluators = move(evaluators);
			PVAL2(validationInstances.size(), evaluators.size());
			PVAL2(_validationSets.size(), _evaluators.size());
			_validating = true;
			_testFrequency = testFrequency;
			//_valdationSetNames = from(_validationSets) >> select([](const Instances& a) { return a.name; }) >> to_vector();

			for (size_t i = 0; i < _validationSets.size(); i++)
			{
				_valdationSetNames.push_back(format("test[{}]", i));
			}

			_selfEvaluate = selfEvaluate;
			_numValidationsExcludeSelf = _validationSets.size();
			_numValidations = _validationSets.size() + (int)selfEvaluate;
			_scoresSize = _numValidationsExcludeSelf + 1; //Scores至少要有TrainingScores 尽管最后可能不用
			CHECK_GE(_scoresSize, 1);
			Scores.resize(_scoresSize);

			_evaluateResults.resize(_evaluators.size());
			for (size_t i = 0; i < _evaluators.size(); i++)
			{
				_evaluateResults[i].resize(_numValidations, 0);
			}

			if (selfEvaluate)
			{
				_valdationSetNames.push_back("train");
				_validationSets.push_back(instances);
			}
			PVAL4(_numValidations, _evaluators.size(), _validationSets.size(), _scoresSize);
			Trainer::Train(instances);  //不用Trainer::会提示找不到 重载覆盖 另外也可以函数外面类里面 using Trainer::Train
		}

		virtual void Train(Instances& instances,
			vector<Instances>&& validationInstances, vector<EvaluatorPtr>&& evaluators,
			bool selfEvaluate = false, int testFrequency = 1)
		{
			PVAL2(validationInstances.size(), evaluators.size());
			vector<Instances> _validationSets = move(validationInstances);
			vector<EvaluatorPtr> _evaluators = move(evaluators);
			PVAL2(validationInstances.size(), evaluators.size());
			PVAL2(_validationSets.size(), _evaluators.size());
			return Train(instances, _validationSets, _evaluators, selfEvaluate, testFrequency);
		}
	protected:
	
		void Evaluate()
		{
			EvaluatePredicts();
			PrintEvaluateResult();
		}

		virtual void EvaluatePredicts()
		{
			for (size_t i = 0; i < _evaluators.size(); i++)
			{
				for (size_t j = 0; j < _numValidations; j++)
				{
					_evaluateResults[i][j] = _evaluators[i]->Evaluate(Scores[j], _validationSets[j]);
				}
			}
		}

	private:
		void PrintEvaluateResult()
		{
			for (size_t i = 0; i < _evaluators.size(); i++)
			{
				std::cerr << "[" << i << "]" << _evaluators[i]->Name() << " ";
				gezi::print(_valdationSetNames, _evaluateResults[i], ":", "\t", 5);
				std::cerr << std::endl;
			}
		}

	public:
		//Fvec InitTrainScores;
		vector<Fvec> Scores; //InitTrainScores 放在InitValidScores的最后,Scores可以看做Predictions
	protected:
		bool _validating = false;

		vector<Fvec> _evaluateResults; //每个evaluator对应一个vec  长度是 _numValidations

		vector<Instances> _validationSets;
		vector<EvaluatorPtr> _evaluators;

		vector<string> _valdationSetNames;

		int _numValidations = 0;
		int _numValidationsExcludeSelf = 0;
		int _scoresSize = 1;

		bool _selfEvaluate = false;
		int _testFrequency = 1;
	};

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__TRAINER_H_
