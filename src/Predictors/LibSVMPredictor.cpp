/**
 *  ==============================================================================
 *
 *          \file   LibSVMPredictor.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-24 07:50:18.688015
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef LIB_S_V_M_PREDICTOR_CPP_
#define LIB_S_V_M_PREDICTOR_CPP_

#include "common_util.h"
#include "libsvm/svm.h"
#include "Predictors/LibSVMPredictor.h"

namespace gezi {

	LibSVMPredictor::LibSVMPredictor(svm_model* model_, svm_problem* prob_, svm_node* node_, svm_parameter* param_,
		NormalizerPtr normalizer, CalibratorPtr calibrator,
		const FeatureNamesVector& featureNames)
		:Predictor(normalizer, calibrator, featureNames), _model(model_), _prob(prob_), _xspace(node_), _param(param_)
	{

	}

	LibSVMPredictor::~LibSVMPredictor()
	{
		if (_model)
		{
			svm_free_and_destroy_model(&_model);
		}
		
		if (_param)
		{
			svm_destroy_param(_param);
		}
	
		if (_prob)
		{
			free(_prob->y);
			free(_prob->x);
		}

		FREE(_xspace);
	}

	namespace
	{
		//@TODO can be static share with LibSVMTrainer.cpp
		vector<svm_node> Vector2SvmNodeVec(Vector& features)
		{
			vector<svm_node> vec;
			features.ForEachNonZero([&](int index, Float value) {
				svm_node node;
				node.index = index + 1;
				node.value = value;
				vec.emplace_back(node);
			});
			svm_node node;
			node.index = -1;
			vec.emplace_back(node);
			return vec;
		}
	}

	Float LibSVMPredictor::Margin(Vector& features)
	{
		vector<svm_node> vec = Vector2SvmNodeVec(features);
		svm_node* x = vec.empty() ? NULL : &vec[0];
		CHECK_EQ(_model->nr_class, 2);
		vector<double> probs(_model->nr_class, 0);
		svm_predict_probability(_model, x, &probs[0]); //@TODO 注意svm_predict输出就是0,1 那么svm predict_probability [0-1]?不需要再calibrate?
		return probs[1];
	}

	void LibSVMPredictor::Load_(string file)
	{
		serialize_util::load(*this, file);
		_model = svm_load_model(ThirdModelName(file).c_str());
		CHECK_NOTNULL(_model);
	}
	
	void LibSVMPredictor::Save_(string file)
	{
		serialize_util::save(*this, file);
		svm_save_model(ThirdModelName(file).c_str(), _model);
	}

}  //----end of namespace gezi

#endif  //----end of LIB_S_V_M_PREDICTOR_CPP_
