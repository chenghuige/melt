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

namespace gezi {

	class Trainer : public WithArgs, public WithHelp
	{
	public:
		virtual void Train(Instances& instances, bool isStreaming = false)
		{
			_trainingSchema = instances.schema;
			_instances = &instances;

			Init();
			Initialize(instances);

			InitializeNormalizer(instances, isStreaming); //normalize and set _instances

			InnerTrain(*_instances);

			Finalize(*_instances);

			VLOG(0) << "Param: [" << GetParam() << " ]" << endl;
		}

		virtual void InitializeNormalizer(Instances& instances, bool isStreaming)
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

		RandomPtr _rand = nullptr;
		RandomRangePtr _randRange = nullptr;
		NormalizerPtr _normalizer = nullptr;
		CalibratorPtr _calibrator = nullptr;

		bool _normalizeCopy = false;

		static Instances& normalizedInstances()
		{
			static thread_local Instances _normalizedInstances;
			return _normalizedInstances;
		}
		Instances* _instances = NULL;
	};

	typedef shared_ptr<Trainer> TrainerPtr;

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__TRAINER_H_
