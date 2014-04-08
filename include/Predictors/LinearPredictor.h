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
namespace gezi {

class LinearPredictor : public Predictor
{
public:
	LinearPredictor(const Vector& weights, Float bias,
		NormalizerPtr normalizer, ICalibratorPtr calibrator, 
		const svec& featureNames)
		:_weights(weights), _bias(bias),
		_normalizer(normalizer), _calibrator(calibrator),
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



	virtual Float Output(Vector& features) override
	{
		if (_normalizer != nullptr && !features.normalized)
		{
			_normalizer->Normalize(features);
		}
		return Margin(features);
	}

private:
	Float Margin(const Vector& features)
	{
		return _bias + dot(_weights, features);
	}
protected:
private:
	Vector _weights;
	Float _bias;
	NormalizerPtr _normalizer = nullptr;
	ICalibratorPtr _calibrator = nullptr;
	svec _featureNames;
};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__LINEAR_PREDICTOR_H_
