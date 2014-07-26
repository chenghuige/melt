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
		vector<PredictorPtr> _predictors;
		Predictor PredictorFactory::LoadPredictor(std::string path)
		{
			_predictors.push_back(gezi::PredictorFactory::LoadPredictor(path));
			Predictor predictor;
			predictor._predictor = _predictors.back().get();
			return predictor;
		}
	}
}  //----end of namespace gezi
