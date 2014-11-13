/**
 *  ==============================================================================
 *
 *          \file   Testers/RegressorTester.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-12 08:46:15.842250
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef TESTERS__REGRESSOR_TESTER_H_
#define TESTERS__REGRESSOR_TESTER_H_
#include "Tester.h"
namespace gezi {

class RegressorTester : public Tester
{
public:
	virtual PredictionKind GetPredictionKind()
	{
		return PredictionKind::Regression;
	}
	virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics()
	{
		return vector<DatasetMetricsPtr>();
	}
protected:
private:

};

}  //----end of namespace gezi

#endif  //----end of TESTERS__REGRESSOR_TESTER_H_
