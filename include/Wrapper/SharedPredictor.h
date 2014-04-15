/**
 *  ==============================================================================
 *
 *          \file   Wrapper/SharedPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-15 12:51:20.935057
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef WRAPPER__SHARED_PREDICTOR_H_
#define WRAPPER__SHARED_PREDICTOR_H_


#include "Wrapper/PredictorFactory.h"
namespace gezi {
namespace wrapper {

class SharedPredictor
{
public:
	static PredictorPtr& Instance()
	{
		static PredictorPtr predictor = PredictorFactory::LoadPredictors()[0];
		return predictor;
	}
};

}  //----end of namespace wrapper
}  //----end of namespace gezi

#endif  //----end of WRAPPER__SHARED_PREDICTOR_H_
