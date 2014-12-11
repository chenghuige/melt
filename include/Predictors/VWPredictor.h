/**
 *  ==============================================================================
 *
 *          \file   Predictors/VWPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-19 15:40:37.618780
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__V_W_PREDICTOR_H_
#define PREDICTORS__V_W_PREDICTOR_H_

#include "MLCore/Predictor.h"
class example;
class vw;
namespace VW{
	class primitive_feature_space;
}
namespace gezi {

	class VWPredictor : public Predictor
	{
	public:
		VWPredictor();

		VWPredictor(vw* vw_, VW::primitive_feature_space* psf_,
			NormalizerPtr normalizer, CalibratorPtr calibrator,
			const FeatureNamesVector& featureNames);

		~VWPredictor();

		virtual string Name() override
		{
			return "VW";
		}

		virtual Float Output(InstancePtr instance) override
		{
			if (instance->line.empty())
			{
				return Predictor::Output(instance);
			}
			else
			{
				return Output(instance->line);
			}
		}

		virtual Float Output(string line) override;

		example* Vector2Example(Vector& features);

		bool InitFeatureSapce(Vector& features);

		virtual void Load_(string file) override;
		virtual void Save_(string file) override;

		friend class cereal::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			ar & CEREAL_BASE_OBJECT_NVP(Predictor);
		}
	protected:
		virtual Float Margin(Vector& features) override;
	protected:
		void Free();
	private:
		vw* _vw = NULL;
		VW::primitive_feature_space* _pFeatureSpace = NULL;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__V_W_PREDICTOR_H_
