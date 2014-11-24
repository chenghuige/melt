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

#include "ThirdPredictor.h"
class svm_model;
namespace gezi {

class LibSVMPredictor : public ThirdPredictor
{
public:

	LibSVMPredictor()
	{

	}
	LibSVMPredictor(svm_model* model_, 
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
	virtual Float Output_(InstancePtr instance) override;
private:
	svm_model* _model;
};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__LIB_S_V_M_PREDICTOR_H_
