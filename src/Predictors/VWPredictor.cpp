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


#ifdef USE_FOLLY_VECTOR
#undef USE_FOLLY_VECTOR
#include "common_util.h"
#endif // USE_FOLLY_VECTOR

#include "vowpalwabbit/parser.h"
#include "vowpalwabbit/simple_label.h"
#include "vowpalwabbit/parse_args.h"
#include "vowpalwabbit/vw.h"
#include "vowpalwabbit/example.h"
#include "vowpalwabbit/parse_regressor.h"


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

	VWPredictor::VWPredictor()
	{

	}

	VWPredictor::~VWPredictor()
	{
		Free();
	}

	void VWPredictor::Free()
	{
		if (_pFeatureSpace)
		{
			FREE_ARRAY(_pFeatureSpace->fs);
			_pFeatureSpace = NULL;
		}
		if (_vw)
		{
			VW::finish(*_vw);
			_vw = NULL;
		}
	}

	namespace {
		static thread_local VW::primitive_feature_space _pFeatureSpaceForPredict;
	}

	bool VWPredictor::InitFeatureSapce(Vector& features)
	{
		if (!_pFeatureSpace)
		{
			_pFeatureSpace = &_pFeatureSpaceForPredict;
			_pFeatureSpace->name = 'a';
			_pFeatureSpace->fs = new feature[_featureNames.size()];
			PVAL(_featureNames.size());
		}
		return true;
	}

	example* VWPredictor::Vector2Example(Vector& features)
	{
		static thread_local bool isInited = InitFeatureSapce(features);
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

	Float VWPredictor::Output(string line)
	{
		example* ec = VW::read_example(*_vw, line);
		dispatch_example(*_vw, *ec);
		Float output = VW::get_prediction(ec);
		return output;
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

	bool VWPredictor::Load_(string file)
	{
		bool ret = serialize_util::load(*this, file);
		if (!ret)
			return false;
		_vw = NULL;
		_pFeatureSpace = NULL;
		_vw = VW::initialize(format("-i {}", ThirdModelName(file)));
		CHECK_NOTNULL(_vw);
		_vw->training = false;
		CHECK_NOTNULL(_vw->l);
		return true;
	}

	void VWPredictor::Save_(string file)
	{
		serialize_util::save(*this, file);
		save_predictor(*_vw, ThirdModelName(file), _vw->current_pass);
	}

}  //----end of namespace gezi

#endif  //----end of V_W_PREDICTOR_CPP_
