/**
 *  ==============================================================================
 *
 *          \file   Testers/DatasetMetrics.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-12 08:44:47.138453
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef TESTERS__DATASET_METRICS_H_
#define TESTERS__DATASET_METRICS_H_

#include "common_util.h"

namespace gezi {

class DatasetMetrics 
{
public:
	virtual string LabelColumnName() = 0;
	virtual vector<string> PerInstanceColumnNames() = 0;

	virtual dvec ProcessInstance(InstancePtr instance, PredictorPtr predictor)
	{
		return dvec();
	}

	void Print()
	{
		Finish();
		Print_();
	}
protected:
	virtual void Finish()
	{

	}

	virtual void Print_()
	{

	}

private:

};

typedef shared_ptr<DatasetMetrics> DatasetMetricsPtr;

}  //----end of namespace gezi

#endif  //----end of TESTERS__DATASET_METRICS_H_
