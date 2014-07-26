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
		Predictor PredictorFactory::LoadPredictor(string path)
		{
			PredictorPtr p = gezi::PredictorFactory::LoadPredictor(path);
			Predictor predictor;
			predictor._predictor = p.get();
			return predictor;
		}
	}
}  //----end of namespace gezi
