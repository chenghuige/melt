/**
 *  ==============================================================================
 *
 *          \file   Predictors/RandomPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-09-10 06:00:02.378343
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__RANDOM_PREDICTOR_H_
#define PREDICTORS__RANDOM_PREDICTOR_H_

#include "MLCore/Predictor.h"
#include "random_util.h"
namespace gezi {

class RandomPredictor : public Predictor
{
public:
	RandomPredictor()
		:_randomInt(2)
	{

	}
protected:
	//随机产生0或者1
	virtual Float Margin(Vector& features) override
	{
		return _randomInt.Next();
	}
private:
	RandomInt _randomInt;
};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__RANDOM_PREDICTOR_H_
