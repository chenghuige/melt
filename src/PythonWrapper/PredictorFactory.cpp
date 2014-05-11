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

	PyPredictor PyPredictorFactory::LoadPredictor(string path)
	{
		PredictorPtr p = gezi::PredictorFactory::LoadPredictor(path);
		Vector fe("");
		Pval(p->Output(fe));
		PyPredictor p2;
		p2._predictor = p.get();
		return p2;
	}

}  //----end of namespace gezi
