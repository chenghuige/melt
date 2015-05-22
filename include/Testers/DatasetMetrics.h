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

class DatasetMetrics : public WithArgs
{
public:
	DatasetMetrics()
	{
	}
	virtual ~DatasetMetrics(){}
	virtual string LabelColumnName() = 0;
	virtual vector<string> PerInstanceColumnNames() = 0;

	virtual vector<string> Names()
	{
		return vector<string>();
	}

	virtual Fvec ProcessInstance(InstancePtr instance, PredictorPtr predictor) 
	{
		Float label = instance->label;
		Float weight = instance->weight;
		Float prediction = 0, probability = std::numeric_limits<double>::quiet_NaN();
		probability = predictor->Predict(instance, prediction);

		return ProcessInstance(label, prediction, probability, weight);
	}

	virtual Fvec ProcessInstance(Float label, Float prediction, Float probability = std::numeric_limits<double>::quiet_NaN(), Float weight = 1.0)
	{
		return Fvec();
	}

	virtual Fvec ProcessInstance(Float label,const Fvec& prediction, Float probability = std::numeric_limits<double>::quiet_NaN(), Float weight = 1.0)
	{
		return Fvec();
	}

	void Print(string prefix = "")
	{
		_names = Names();
		Finish();
		Print_(prefix);
	}

protected:
	virtual void Finish()
	{

	}

	virtual void Print_(string prefix)
	{
		CHECK_EQ(_names.size(), _results.size());
		gezi::print(_names, _results);
	}

protected:
	Fvec _results;
	svec _names;
private:
};

typedef shared_ptr<DatasetMetrics> DatasetMetricsPtr;

}  //----end of namespace gezi

#endif  //----end of TESTERS__DATASET_METRICS_H_
