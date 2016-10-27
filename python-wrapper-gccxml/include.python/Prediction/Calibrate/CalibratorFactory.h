#ifndef PREDICTION__CALIBRATE__CALIBRATOR_FACTORY_H_
#define PREDICTION__CALIBRATE__CALIBRATOR_FACTORY_H_
#include "Prediction/Calibrate/Calibrator.h"
#include "Prediction/Calibrate/SigmoidCalibrator.h"
#include "Prediction/Calibrate/PAVCalibrator.h"
#include "Prediction/Calibrate/NaiveCalibrator.h"
namespace gezi {
class CalibratorFactory
{
public:
static CalibratorPtr CreateCalibrator(string name);
static CalibratorPtr CreateCalibrator(string name, string path);
static CalibratorPtr Load(string path);
static void Save(CalibratorPtr calibrator, string path);
protected:
private:
};
}
#endif
