#ifndef PREDICTORS__ENSEMBLE_PREDICTOR_H_
#define PREDICTORS__ENSEMBLE_PREDICTOR_H_
#include "MLCore/Predictor.h"
#include "MLCore/PredictorFactory.h"
namespace gezi {
class EnsemblePredictor : public Predictor
{
public:
//EnsemblePredictor(vector<PredictorPtr>&& predictors, CalibratorPtr calibrator);
EnsemblePredictor();
using Predictor::Predict;
using Predictor::Output;
virtual Float Predict(Vector& features);
protected:
virtual Float Margin(Vector& features);
virtual string Name();
virtual void SaveBin(string path);
virtual bool LoadBin(string path);
protected:
vector<PredictorPtr> _predictors;
private:
};
}
#endif
