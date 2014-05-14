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
	static CalibratorPtr CreateCalibrator(string name)
	{
		boost::to_lower(name);
		if (name.empty() || name == "none")
		{
			VLOG(0) << "Do not use calibrator so return nullptr";
			return nullptr;
		}
		
		if (contains(name, "sigmoid") || contains(name, "platt"))
		{
			return make_shared<SigmoidCalibrator>();
		}
		if (name == "pav" || name == "pavcalibrator")
		{
			return make_shared<PAVCalibrator>();
		}
		if (name == "naive" || name == "naivecalibrator")
		{
			return make_shared<NaiveCalibrator>();
		}
		LOG(WARNING) << name << " is not supported now, do not use calibrator, return nullptr";
		return nullptr;
	}

	static CalibratorPtr CreateCalibrator(string name, string path)
	{
		CalibratorPtr calibrator = CreateCalibrator(name);
		if (calibrator != nullptr)
		{
			calibrator->Load(path);
		}
		return calibrator;
	}
protected:
private:

};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__CALIBRATE__CALIBRATOR_FACTORY_H_
