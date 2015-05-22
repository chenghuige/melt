/**
 *  ==============================================================================
 *
 *          \file   MLCore/PredictionKind.h
 *
 *        \author   chenghuige
 *
 *          \date   2015-05-22 21:56:47.085775
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef M_L_CORE__PREDICTION_KIND_H_
#define M_L_CORE__PREDICTION_KIND_H_

namespace gezi {

	enum class PredictionKind
	{
		Unknown = 0,
		Custom = 1,
		BinaryClassification = 2,
		MultiClassClassification = 3,
		Regression = 4,
		MultiOutputRegression = 5,
		Ranking = 6,
		Recommendation = 7,
		// More to be added later.
		// When adding values, also add to PredictionKindMask.
	};

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__PREDICTION_KIND_H_
