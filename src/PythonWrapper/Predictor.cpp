/**
 *  ==============================================================================
 *
 *          \file   Predictor.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-24 22:26:32.558633
 *
 *  \Description:
 *  ==============================================================================
 */

#include "PythonWrapper/Predictor.h"
#include "MLCore/Predictor.h"
namespace gezi {

	Float PyPredictor::Output(Vector& features)
	{
		return (static_cast<Predictor*>(_predictor))->Output(features);
	}

	Float PyPredictor::Predict(Vector& features)
	{
		return  (static_cast<Predictor*>(_predictor))->Predict(features);
	}

	Float PyPredictor::Predict(Vector& features, Float& output)
	{
		return  (static_cast<Predictor*>(_predictor))->Predict(features, output);
	}
}  //----end of namespace gezi

