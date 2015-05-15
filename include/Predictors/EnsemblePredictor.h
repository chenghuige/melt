/**
 *  ==============================================================================
 *
 *          \file   Predictors/EnsemblePredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2015-04-17 22:12:39.554834
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__ENSEMBLE_PREDICTOR_H_
#define PREDICTORS__ENSEMBLE_PREDICTOR_H_
#include "MLCore/Predictor.h"
namespace gezi {

	class EnsemblePredictor : public Predictor
	{
	public:

	protected:
		virtual Float Margin(Vector& features) override
		{
			Float out = 0;
			for (PredictorPtr predictor : _predictors)
			{
				out += predictor->Margin(features);
			}
			return out / _predictors.size();
		}
	private:
		vector<PredictorPtr> _predictors;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__ENSEMBLE_PREDICTOR_H_
