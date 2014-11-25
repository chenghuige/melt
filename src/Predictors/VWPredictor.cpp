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
	namespace {
		void dispatch_example(vw& all, example& ec) //copied from learner.cc
		{
			if (ec.test_only || !all.training)
				all.l->predict(ec);
			else
				all.l->learn(ec);
			all.l->finish_example(all, ec);
		}

	
	}

	VWPredictor::VWPredictor(vw* vw_, VW::primitive_feature_space* psf_,
		NormalizerPtr normalizer, CalibratorPtr calibrator,
		const FeatureNamesVector& featureNames)
		:Predictor(normalizer, calibrator, featureNames), _vw(vw_), _pFeatureSpace(psf_)
	{

	}

	VWPredictor::~VWPredictor()
	{
		FREE_ARRAY(_pFeatureSpace->fs);
		VW::finish(*_vw);
	}

	example* VWPredictor::Vector2Example(Vector& features)
	{
		int idx = 0;
		features.ForEachNonZero([&](int index, Float value) {
			_pFeatureSpace->fs[idx].weight_index = index;
			_pFeatureSpace->fs[idx].x = value;
			idx++;
		});
		_pFeatureSpace->len = idx;
		example* ec = import_example(*_vw, _pFeatureSpace, 1);
		ec->test_only = true;
		return ec;
	}

	Float VWPredictor::Margin(Vector& features)
	{
		example* ec = Vector2Example(features);
		//_vw->learn(ec); //@TODO TLC还是learn了 在predict的时候 check this
		dispatch_example(*_vw, *ec);
		Float output = VW::get_prediction(ec);
		//VW::finish_example(*_vw, ec);
		return output;
	}

}  //----end of namespace gezi

#endif  //----end of V_W_PREDICTOR_CPP_
