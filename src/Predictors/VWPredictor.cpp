/**
 *  ==============================================================================
 *
 *          \file   VWPredictor.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-24 08:01:18.831836
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef V_W_PREDICTOR_CPP_
#define V_W_PREDICTOR_CPP_

#include "vowpalwabbit/parser.h"
#include "vowpalwabbit/simple_label.h"
#include "vowpalwabbit/parse_args.h"
#include "vowpalwabbit/vw.h"
#include "vowpalwabbit/example.h"

#include "Predictors/VWPredictor.h"

namespace gezi {

	VWPredictor::VWPredictor(vw* vw_, VW::primitive_feature_space* psf_,
		NormalizerPtr normalizer, CalibratorPtr calibrator,
		const FeatureNamesVector& featureNames)
		:ThirdPredictor(normalizer, calibrator, featureNames), _vw(vw_), _pFeatureSpace(psf_)
	{

	}

	VWPredictor::~VWPredictor()
	{
		FREE_ARRAY(_pFeatureSpace->fs);
		VW::finish(*_vw);
	}

	Float VWPredictor::Output_(InstancePtr instance) 
	{
		example* ec = Instance2Example(instance, false);
		_vw->learn(ec); //@TODO TLC还是learn了 在predict的时候 check this
		Float output = VW::get_prediction(ec);
		VW::finish_example(*_vw, ec);
		return output;
	}

	example* VWPredictor::Instance2Example(InstancePtr instance, bool includeLabel)
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

}  //----end of namespace gezi

#endif  //----end of V_W_PREDICTOR_CPP_
