#ifndef PREDICTION__CALIBRATE__P_A_V_CALIBRATOR_H_
#define PREDICTION__CALIBRATE__P_A_V_CALIBRATOR_H_
#include "common_util.h"
#include "Prediction/Calibrate/Calibrator.h"
namespace gezi {
class PAVCalibrator : public CalibratorWrapper
{
public:
struct Piece
{
Float minX;
Float maxX;
Float val;
Float n;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
virtual bool Load(string path);
virtual void Save(string path);
virtual Float PredictProbability(Float score);
Float PredictLogOdds(Float score);
virtual string Name();
protected:
virtual void TrainModel(CalibratorStore& data);
Float FindValue(Float score);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
private:
vector<Piece> piecewise;
Float minToReturn;
Float maxToReturn;
};
}
//CEREAL_REGISTER_TYPE(gezi::PAVCalibrator);
#endif
