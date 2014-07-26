/**
 *  ==============================================================================
 *
 *          \file   PredictorFactory.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-07-26 09:34:14.603965
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTOR_FACTORY_CPP_
#define PREDICTOR_FACTORY_CPP_

#include "Simple/PredictorFactory.h"
#include "MLCore/PredictorFactory.h"
#include "MLCore/Predictor.h"
namespace gezi {
	namespace simple {
		PredictorPtr _predictor;
		Predictor PredictorFactory::LoadPredictor(std::string path)
		{
			_predictor = gezi::PredictorFactory::LoadPredictor(path);
			Predictor predictor;
			predictor._predictor = _predictor.get();
			return predictor;
		}
	}
}  //----end of namespace gezi

#endif
