#ifndef INCLUDE__PREDICTION__CALIBRATE__SIGMOID_CALIBRATOR_H_
#define INCLUDE__PREDICTION__CALIBRATE__SIGMOID_CALIBRATOR_H_
#include "statistic_util.h"
#include "Prediction/Calibrate/Calibrator.h"
namespace gezi {
class SigmoidCalibrator : public CalibratorWrapper
{
public:
SigmoidCalibrator();
SigmoidCalibrator(double a, double b);
virtual Float PredictProbability(Float output);
virtual string Name();
virtual bool Load(string path);
virtual void Save(string path);
virtual void SaveXml(string path);
virtual void SaveJson(string path);
virtual void SaveText(string file);
double ParamA() const;
double ParamB() const;
protected:
virtual void TrainModel(CalibratorStore& data);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
private:
double paramA;
double paramB;
double POSINFINITY;
double NEGINFINITY;
};
}
//CEREAL_REGISTER_TYPE(gezi::SigmoidCalibrator);
#endif
