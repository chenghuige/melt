#ifndef TESTERS__REGRESSOR_TESTER_H_
#define TESTERS__REGRESSOR_TESTER_H_
#include "Tester.h"
namespace gezi {
class RegressionMetrics : public DatasetMetrics
{
public:
virtual vector<string> PerInstanceColumnNames();
virtual vector<string> Names();
virtual Fvec ProcessInstance(Float label, Float prediction, Float probability, Float weight);
virtual void Finish();
private:
Float sumWeights;
Float totalL1Loss;
};
class RegressorTester : public Tester
{
public:
virtual PredictionKind GetPredictionKind();
virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics();
protected:
private:
};
}
#endif
