/**
 *  ==============================================================================
 *
 *          \file   Prediction/Instances/instances_util.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-02 20:34:03.488226
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__INSTANCES_INSTANCES_UTIL_H_
#define PREDICTION__INSTANCES_INSTANCES_UTIL_H_

#include "InstanceParser.h"
namespace gezi {
	inline Instances create_instances(string infile)
	{
		InstanceParser parser;
		return parser.Parse(infile);
	}

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES_INSTANCES_UTIL_H_
