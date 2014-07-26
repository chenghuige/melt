/**
 *  ==============================================================================
 *
 *          \file   PredictorFactory.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-24 22:26:45.329479
 *
 *  \Description:
 *  ==============================================================================
 */

#include "PythonWrapper/PredictorFactory.h"
#include "MLCore/PredictorFactory.h"
#include "MLCore/Predictor.h"
namespace gezi {
	namespace py {
		PredictorPtr _predictor;
		Predictor PredictorFactory::LoadPredictor(string path)
		{
			_predictor = gezi::PredictorFactory::LoadPredictor(path);
			Predictor predictor;
			predictor._predictor = _predictor.get();
			return predictor;
		}
	}
}  //----end of namespace gezi
