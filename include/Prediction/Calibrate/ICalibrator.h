/**
 *  ==============================================================================
 *
 *          \file   Prediction/Calibrate/ICalibrator.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-07 20:52:24.932084
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__CALIBRATE__I_CALIBRATOR_H_
#define PREDICTION__CALIBRATE__I_CALIBRATOR_H_

#include "common_def.h"

namespace gezi {

class ICalibrator 
{
public:
	/// <summary> Given a classifier output, produce the probability </summary>		
	virtual Float PredictProbability(Float output) = 0;

	/// <summary> Training calibrators:  provide the  output and the class label </summary>		
	virtual void ProcessTrainingExample(Float output, bool clicked, Float weight) = 0;

	/// <summary> Finish up training after seeing all examples </summary>
	virtual void FinishTraining() = 0;

	/// <summary> Serialize a text version of the calibrator </summary>		
	virtual void Save(const string& file) = 0;

	/// <summary> Get the summary of current calibrator settings </summary>
	virtual void PrintInfo() = 0;
};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__CALIBRATE__I_CALIBRATOR_H_
