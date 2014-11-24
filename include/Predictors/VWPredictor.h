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

#include "ThirdPredictor.h"
class example;
class vw;
namespace VW{
	class primitive_feature_space;
}
namespace gezi {

	class VWPredictor : public ThirdPredictor
	{
	public:
		VWPredictor(vw* vw_, VW::primitive_feature_space* psf_,
			NormalizerPtr normalizer, CalibratorPtr calibrator,
			const FeatureNamesVector& featureNames);

		~VWPredictor();

		virtual string Name() override
		{
			return "VW";
		}

	protected:
		virtual Float Output_(InstancePtr instance) override;
		example* Instance2Example(InstancePtr instance, bool includeLabel);

	protected:

	private:
		vw* _vw;
		VW::primitive_feature_space* _pFeatureSpace;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__V_W_PREDICTOR_H_
