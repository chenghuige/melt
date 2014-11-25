/**
 *  ==============================================================================
 *
 *          \file   Predictors/ThirdPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-24 07:04:32.328854
 *
 *  \Description:  third party predictor, now no usage... dereciated
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
	ThirdPredictor()
	{

	}
	ThirdPredictor(NormalizerPtr normalizer, CalibratorPtr calibrator, const FeatureNamesVector& featuresNames)
		:Predictor(normalizer, calibrator, featuresNames)
	{

	}
	

private:

};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__THIRD_PREDICTOR_H_
