/**
 *  ==============================================================================
 *
 *          \file   ITrainer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-02-03 18:04:21.621591
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef ITRAINER_H_
#define ITRAINER_H_
#include "Prediction/Instances/Instances.h"
namespace gezi {

	class ITrainer
	{
	public:
		virtual void Train(Instances& data) = 0;
	};
}  //----end of namespace gezi

#endif  //----end of ITRAINER_H_
