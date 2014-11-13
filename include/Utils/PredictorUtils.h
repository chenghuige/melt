/**
 *  ==============================================================================
 *
 *          \file   Utils/PredictorUtils.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-12 18:03:14.078850
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef UTILS__PREDICTOR_UTILS_H_
#define UTILS__PREDICTOR_UTILS_H_

#include "MLCore/Predictor.h"
#include "Testers/testers.h"

namespace gezi {

	class PredictorUtils
	{
	public:
		static TesterPtr GetTester(PredictionKind kind)
		{
			switch (kind)
			{
			case PredictionKind::Unknown:
				return nullptr;
			case PredictionKind::Custom:
				return nullptr;
			case PredictionKind::BinaryClassification:
				return make_shared<ClassifierTester>();
			case PredictionKind::MultiClassClassification:
				return make_shared<MulticlassTester>();
			case PredictionKind::Regression:
				return make_shared<RegressorTester>();
			case PredictionKind::MultiOutputRegression:
				return make_shared<MultioutputRegressorTester>();
			case PredictionKind::Ranking:
				return make_shared<RankerTester>();
			case PredictionKind::Recommendation:
				return nullptr;
			default:
				return nullptr;
			}
		}

		static	TesterPtr GetTester(PredictorPtr predictor)
		{
			return GetTester(predictor->GetPredictionKind());
		}

	protected:
	private:

	};

}  //----end of namespace gezi

#endif  //----end of UTILS__PREDICTOR_UTILS_H_
