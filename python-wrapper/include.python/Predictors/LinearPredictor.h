#ifndef PREDICTORS__LINEAR_PREDICTOR_H_
#define PREDICTORS__LINEAR_PREDICTOR_H_
#include "MLCore/Predictor.h"
namespace gezi {
class LinearPredictor : public Predictor
{
public:
LinearPredictor();
LinearPredictor(const Vector& weights, Float bias,
NormalizerPtr normalizer, CalibratorPtr calibrator,
const FeatureNamesVector& featureNames,
string name = "");
LinearPredictor(string path);
virtual string Name();
virtual void Save_(string file);
virtual void SaveXml_(string file);
virtual void SaveJson_(string file);
virtual bool Load_(string file);
virtual void SaveText_(string file);
virtual bool LoadText_(string file);
virtual string ToFeaturesGainSummary(int topNum = 0);
virtual void SaveFeaturesGain(int topNum = 0);
const Vector& weights() const;
const Float bias() const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
virtual Float Margin(Vector& features);
private:
Vector _weights;
Float _bias;
string _name;
};
}
//CEREAL_REGISTER_TYPE(gezi::LinearPredictor);
#endif
