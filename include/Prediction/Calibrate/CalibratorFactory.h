/**
 *  ==============================================================================
 *
 *          \file   Prediction/Calibrate/CalibratorFactory.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-08 18:56:15.521982
 *
 *  \Description:
 *  ==============================================================================
 */

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
	static CalibratorPtr CreateCalibrator(const string& name_)
	{
		string name = boost::to_lower_copy(name_);
		if (name == "sigmoid" || name == "platt")
		{
			return make_shared<SigmoidCalibrator>();
		}
		if (name == "pav")
		{
			return make_shared<PAVCalibrator>();
		}
		if (name == "naive")
		{
			return make_shared<NaiveCalibrator>();
		}
		LOG(WARNING) << name_ << " is not supported now, do not use calibrator, return nullptr";
		return nullptr;
	}
protected:
private:

};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__CALIBRATE__CALIBRATOR_FACTORY_H_
