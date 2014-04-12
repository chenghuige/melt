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

		//训练器中使用构造
		LinearPredictor(const Vector& weights, Float bias,
			NormalizerPtr normalizer, CalibratorPtr calibrator,
			const svec& featureNames, 
			string name = "LinearPredictor")
			:Predictor(normalizer, calibrator),
			_weights(weights), _bias(bias),
			_featureNames(featureNames),
			_name(name)
		{

		}

		LinearPredictor(string path)
		{

		}

		virtual string Name() override
		{
			return _name;
		}

		virtual void Save(string path) override
		{
			Predictor::Save(path);
			string modelFile = path + "/model";
			serialize_util::save(*this, modelFile);
		}

		virtual void Load(string path) override
		{
			Predictor::Load(path);
			string modelFile = path + "/model";
			serialize_util::load(*this, modelFile);
		}

		//SaveText是可选的 如果要使用 务必先调用Save 因为加载至使用Load
		virtual void SaveText(string path)
		{
			Predictor::SaveText(path);
			ofstream ofs(path);
			ofs << "ModelName=" << Name() << endl;
			ofs << "FeatureNum=" << _featureNames.size() << endl;
			_weights.ForEachNonZero([&ofs,this](int index, Float value)
			{
				ofs << index << "\t" << _featureNames[index] << "\t" << value << endl;
			});
			ofs << _featureNames.size() << "\t" << "Bias" << "\t" << _bias;
		}

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<Predictor>(*this);
			ar & _weights;
			ar & _bias;
			ar & _featureNames;
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

		string _name = "LinearPredictor";
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__LINEAR_PREDICTOR_H_
