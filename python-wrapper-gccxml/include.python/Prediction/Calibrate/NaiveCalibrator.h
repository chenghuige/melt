#ifndef PREDICTION__CALIBRATE__NAIVE_CALIBRATOR_H_
#define PREDICTION__CALIBRATE__NAIVE_CALIBRATOR_H_
#include "Prediction/Calibrate/Calibrator.h"
namespace gezi {
class NaiveCalibrator : public Calibrator
{
public:
virtual void FinishTraining();
virtual bool Load(string path);
virtual void Save(string path);
virtual string Name();
virtual Float PredictProbability(Float output);
virtual void ProcessTrainingExample(Float output, bool clicked, Float weight);
private:
int GetBinIdx(Float output);
void Initialize();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
private:
Fvec cMargins;
Fvec ncMargins;
int numBins;
Float binSize;
Float _min;
Float _max;
Fvec binProbs;
};
}
#endif
