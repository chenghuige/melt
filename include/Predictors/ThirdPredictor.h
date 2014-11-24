/**
 *  ==============================================================================
 *
 *          \file   Predictors/ThirdPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-24 07:04:32.328854
 *
 *  \Description:  third party predictor
 *  ==============================================================================
 */

#ifndef PREDICTORS__THIRD_PREDICTOR_H_
#define PREDICTORS__THIRD_PREDICTOR_H_

#include "MLCore/Predictor.h"

namespace gezi {

class ThirdPredictor : public Predictor
{
public:
	using Predictor::Predictor;
	ThirdPredictor(NormalizerPtr normalizer, CalibratorPtr calibrator, const FeatureNamesVector& featuresNames)
		:Predictor(normalizer, calibrator, featuresNames)
	{

	}
	virtual Float Predict(InstancePtr instance, Float& output) override
	{
		output = Output(instance);
		if (_calibrator == nullptr)
			return 1.0 / (1.0 + exp(-output * 5));
		else
			return _calibrator->PredictProbability(output);
	}

	virtual Float Predict(InstancePtr instance) override
	{
		Float output;
		return Predict(instance, output);
	}

	InstancePtr GetNormalizedInstance(InstancePtr instance)
	{
		if (_normalizer != nullptr && !instance->normalized)
		{
			if (!_normalizeCopy)
			{
				_normalizer->Normalize(instance);
			}
			else
			{
				return _normalizer->NormalizeCopy(instance);
			}
		}
		return instance;
	}

	virtual Float Output(InstancePtr instance) override
	{
		instance = GetNormalizedInstance(instance);
		return Output_(instance);
	}

protected:
	virtual Float Output_(InstancePtr instance)
	{
		return 0;
	}

private:

};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__THIRD_PREDICTOR_H_
