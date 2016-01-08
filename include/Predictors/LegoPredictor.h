/**
 *  ==============================================================================
 *
 *          \file   Predictors/LegoPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2016-01-07 14:28:58.603769
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef GEZI_PREDICTORS__LEGO_PREDICTOR_H_
#define GEZI_PREDICTORS__LEGO_PREDICTOR_H_

#include "MLCore/Predictor.h"
#include "liblego/lego.h"

namespace gezi {

class LegoPredictor : public ProbabilityPredictor
{
public:
	virtual bool Load(string path) override
	{
		bool ret = true;
		string netFile = path + "/net.prototxt";
		ret = _net.set_net_parameter_from_file(netFile.c_str());
		if (ret != 0)
		{
			return false;
		}

		string modelFile = path + "/model.bin";
		ret = _net.init(modelFile.c_str());
		if (ret != 0)
		{
			return false;
		}

		_tlr_ptr = _net.register_thread();

		if (!_tlr_ptr)
		{
			return false;
		}

		_blob = _net.input_blobs(_tlr_ptr)[0];

		ret = LoadNormalizerAndCalibrator(path);
		return ret;
	}

	virtual	~LegoPredictor()
	{
		_net.destroy_thread(_tlr_ptr);
	}

protected:
	//@TODO should be const Vector& features
	virtual Float Margin(Vector& features) override
	{
		SetDataFromVector(features);
		_net.predict(_tlr_ptr);
		return _net.result_blob(_tlr_ptr)->data[1];
	}

private:
	void SetDataFromVector(const Vector& features)
	{
		int idx = 0;
		features.ForEachNonZero([&, this](int index, double value) { 
			_blob->data[idx++] = index;
		});
		_blob->dim0 = idx;
	}
private:
	liblego::Net _net;
	void* _tlr_ptr = NULL;

	liblego::Blob* _blob = NULL;
};

}  //----end of namespace gezi

#endif  //----end of GEZI_PREDICTORS__LEGO_PREDICTOR_H_
