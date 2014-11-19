/**
 *  ==============================================================================
 *
 *          \file   Predictors/VWPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-19 15:40:37.618780
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__V_W_PREDICTOR_H_
#define PREDICTORS__V_W_PREDICTOR_H_

#include "MLCore/Predictor.h"

#include "vowpalwabbit/parser.h"
#include "vowpalwabbit/simple_label.h"
#include "vowpalwabbit/parse_args.h"
#include "vowpalwabbit/vw.h"
#include "vowpalwabbit/example.h"

#include "Trainers/VWTrainer.h"

namespace gezi {

class VWPredictor : public Predictor
{
public:
	VWPredictor()
	{

	}

	VWPredictor(vw* vw_, VW::primitive_feature_space* psf_)
		:_vw(vw_), _pFeatureSpace(psf_)
	{

	}
	~VWPredictor()
	{
		FREE_ARRAY(_pFeatureSpace->fs);
		VW::finish(*_vw);
	}


	virtual Float Output(InstancePtr instance) override
	{
		example* ec = Instance2Example(instance, false);
		_vw->learn(ec);
		Float output = VW::get_prediction(ec);
		VW::finish_example(*_vw, ec);
		return output;
	}

	virtual Float Predict(InstancePtr instance, Float& output) override
	{
		output = Output(instance);
		return 1.0 / (1.0 + exp(-output * 5));
	}

	virtual Float Predict(InstancePtr instance) override
	{
		Float result;
		return Predict(instance, result);
	}

protected:
	example* Instance2Example(InstancePtr instance, bool includeLabel)
	{
		int idx = 0;
		instance->features.ForEach([&](int index, Float value) {
			_pFeatureSpace->fs[idx].weight_index = index;
			_pFeatureSpace->fs[idx].x = value;
			idx++;
		});
		_pFeatureSpace->len = idx;
		example* ec = import_example(*_vw, _pFeatureSpace, 1);

		if (includeLabel)
		{
			Float label = instance->label <= 0 ? -1 : 1;
			VW::add_label(ec, label, instance->weight);
		}
		return ec;
	}
protected:

private:
	vw* _vw;
	VW::primitive_feature_space* _pFeatureSpace;
};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__V_W_PREDICTOR_H_
