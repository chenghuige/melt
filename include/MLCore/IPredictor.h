/**
 *  ==============================================================================
 *
 *          \file   IPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-02-03 18:04:14.599408
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef IPREDICTOR_H_
#define IPREDICTOR_H_

#include "common_util.h"
#include "Prediction/Instances/Instance.h"
namespace gezi {

	//由于考虑线上Feature类修改 这里暂时不支持线上预测
	class IPredictor
	{
	public:
		//输出未经Calibrator矫正的数值 -n,+n 0表示分界 越高越倾向postive
		Float Output(const Instance& instance)
		{
			return Output(instance.features);
		}
		Float Output(InstancePtr instance)
		{
			return Output(instance->features);
		}
		virtual Float Output(const Vector& features) = 0;
	};

	class IDistributionPredictor 
	{
	public:
		//输出经Calibrator矫正的数值 [0,1]
		Float Predict(const Instance& instance)
		{
			return Predict(instance.features);
		}
		Float Predict(InstancePtr instance)
		{
			return Predict(instance->features);
		}
		virtual Float Predict(const Vector& features) = 0;
	};
}  //----end of namespace gezi

#endif  //----end of IPREDICTOR_H_
