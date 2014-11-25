/**
 *  ==============================================================================
 *
 *          \file   Predictors/LibSVMPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-20 05:11:22.676886
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__LIB_S_V_M_PREDICTOR_H_
#define PREDICTORS__LIB_S_V_M_PREDICTOR_H_

#include "MLCore/Predictor.h"
class svm_model;
class svm_problem;
class svm_node;
class svm_parameter;
namespace gezi {

class LibSVMPredictor : public Predictor
{
public:

	LibSVMPredictor()
	{

	}
	LibSVMPredictor(svm_model* model_, svm_problem* probl_, svm_node* node_, svm_parameter* param_,
		NormalizerPtr normalizer, CalibratorPtr calibrator,
		const FeatureNamesVector& featureNames);

	~LibSVMPredictor();

	virtual string Name() override
	{
		return "LibSVM";
	}

	virtual void Load_(string file) override;
	virtual void Save_(string file) override;

protected:
	virtual Float Margin(Vector& features) override;
private:
	svm_model* _model = NULL;
	svm_problem* _prob = NULL;
	svm_node* _xspace = NULL;
	svm_parameter* _param = NULL;
};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__LIB_S_V_M_PREDICTOR_H_
