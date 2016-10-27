#ifndef TESTERS__MULTIOUTPUT_REGRESSOR_TESTER_H_
#define TESTERS__MULTIOUTPUT_REGRESSOR_TESTER_H_
#include "Tester.h"
namespace gezi {
class MultioutputRegressorTester : public Tester
{
public:
virtual PredictionKind GetPredictionKind();
virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics();
protected:
private:
};
}
#endif
