#ifndef PREDICTORS__THIRD_PREDICTOR_H_
#define PREDICTORS__THIRD_PREDICTOR_H_
#include "MLCore/Predictor.h"
namespace gezi {
class ThirdPredictor : public Predictor
{
public:
//using Predictor::Predictor;
ThirdPredictor();
ThirdPredictor(NormalizerPtr normalizer, CalibratorPtr calibrator, const FeatureNamesVector& featuresNames);
private:
};
}
#endif
