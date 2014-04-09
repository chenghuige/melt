/**
 *  ==============================================================================
 *
 *          \file   Predictors/LinearPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-07 21:50:18.354006
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__LINEAR_PREDICTOR_H_
#define PREDICTORS__LINEAR_PREDICTOR_H_

#include "MLCore/Predictor.h"
#include "Prediction/Normalization/Normalizer.h"
#include "Prediction/Calibrate/Calibrator.h"
namespace gezi {

class LinearPredictor : public Predictor
{
public:
	LinearPredictor() = default;

	LinearPredictor(const Vector& weights, Float bias,
		NormalizerPtr normalizer, CalibratorPtr calibrator, 
		const svec& featureNames)
		:Predictor(normalizer, calibrator),
		_weights(weights), _bias(bias),
		_featureNames(featureNames)
	{

	}

	//通过文本文件载入预测模型
	LinearPredictor(const string& modelFile = "",
		const string& normalizerFile = "",
		const string& calibratorFile = "")
	{

	}

	//输入是模型路径 另外的载入方式是序列化 serialize_util::load(file, predictor)
	LinearPredictor(const string& modelDir)
	{

	}
	
protected:
	virtual Float Margin(const Vector& features) override
	{
		return _bias + dot(_weights, features);
	}
private:
	Vector _weights;
	Float _bias;
	svec _featureNames;
};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__LINEAR_PREDICTOR_H_
