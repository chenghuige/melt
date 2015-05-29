/**
 *  ==============================================================================
 *
 *          \file   Utils/loss.h
 *
 *        \author   chenghuige
 *
 *          \date   2015-05-28 14:24:37.283724
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef UTILS_LOSS_H_
#define UTILS_LOSS_H_

namespace gezi {
	namespace loss {
		inline double logistic(double trueProb, double prediction, double beta = 2.0)
		{
			return log(1.0 + std::exp(-beta * trueProb * prediction));
		}
	} //-----end of namespace loss
}  //----end of namespace gezi

#endif  //----end of UTILS_LOSS_H_
