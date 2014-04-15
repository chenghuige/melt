/**
 *  ==============================================================================
 *
 *          \file   Wrapper/SharedPredictors.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-15 12:51:20.935057
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef WRAPPER__SHARED_PREDICTORS_H_
#define WRAPPER__SHARED_PREDICTORS_H_


#include "Wrapper/PredictorFactory.h"
namespace gezi {
namespace wrapper {

class SharedPredictors
{
public:
	static PredictorPtr& Instance(int index = 0)
	{
		return  GetPredictors()[index];
	}

	static Predictors& GetPredictors()
	{
		static Predictors _predictors = PredictorFactory::LoadPredictors();
		return _predictors;
	}

	static int Size()
	{
		return GetPredictors().size();
	}
};

}  //----end of namespace wrapper
}  //----end of namespace gezi

#endif  //----end of WRAPPER__SHARED_PREDICTORS_H_
