/**
 *  ==============================================================================
 *
 *          \file   Utils/evaluate_def.h
 *
 *        \author   chenghuige
 *
 *          \date   2015-05-26 12:55:23.206613
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef UTILS_EVALUATE_DEF_H_
#define UTILS_EVALUATE_DEF_H_
#include <limits>
#include "common_def.h"
namespace gezi {
	namespace evaluate
	{
		//-----------Node is depreciated
		struct Node
		{
			Float label;
			Float prediction;
			Float weight = 1.0;

			Node()
			{

			}
			Node(Float label_, Float prediction_, Float weight_ = 1.0)
				:label(label_), prediction(prediction_), weight(weight_)
			{

			}
		};

		struct Instance
		{
			Float label = std::numeric_limits<double>::quiet_NaN();
			Float weight = 1.0;
			Instance()
			{

			}
			Instance(Float label_, Float weight_ = 1.0)
				:label(label_), weight(weight_)
			{

			}
		};
	} //----end of namespace evaluate
	typedef evaluate::Node EvaluateNode;
	typedef evaluate::Instance EvaluateInstance;
	typedef EvaluateInstance IsEvaluateAble;
	typedef shared_ptr<EvaluateInstance> EvaluateInstancePtr;
}  //----end of namespace gezi

#endif  //----end of UTILS_EVALUATE_DEF_H_
