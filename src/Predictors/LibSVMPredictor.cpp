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

	LibSVMPredictor::LibSVMPredictor(svm_model* model_,
		NormalizerPtr normalizer, CalibratorPtr calibrator,
		const FeatureNamesVector& featureNames)
		:ThirdPredictor(normalizer, calibrator, featureNames), _model(model_)
	{

	}

	LibSVMPredictor::~LibSVMPredictor()
	{
		svm_free_and_destroy_model(&_model);
	}

	//@TODO can be static share with LibSVMTrainer.cpp
	vector<svm_node> Instance2SvmNodeVec(InstancePtr instance)
	{
		vector<svm_node> vec;
		instance->features.ForEachNonZero([&](int index, Float value) { 
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

	Float LibSVMPredictor::Output_(InstancePtr instance)
	{
		vector<svm_node> vec = Instance2SvmNodeVec(instance);
		svm_node* x = vec.empty() ? NULL : &vec[0];
		vector<double> probs(_model->nr_class, 0);
		svm_predict_probability(_model, x, &probs[0]); //@TODO 注意svm_predict输出就是0,1 那么svm predict_probability [0-1]?不需要再calibrate?
		return probs[1];
	}

	void LibSVMPredictor::Load_(string file)
	{
		_model = svm_load_model(file.c_str());
		CHECK_NOTNULL(_model);
	}
	
	void LibSVMPredictor::Save_(string file)
	{
		svm_save_model(file.c_str(), _model);
	}

}  //----end of namespace gezi

#endif  //----end of LIB_S_V_M_PREDICTOR_CPP_
