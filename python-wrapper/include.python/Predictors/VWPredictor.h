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
virtual string Name();
virtual Float Output(InstancePtr instance);
virtual Float Output(string line);
example* Vector2Example(Vector& features);
bool InitFeatureSapce(Vector& features);
virtual bool Load_(string file);
virtual void Save_(string file);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
virtual Float Margin(Vector& features);
protected:
void Free();
private:
vw* _vw;
VW::primitive_feature_space* _pFeatureSpace;
};
}
#endif
