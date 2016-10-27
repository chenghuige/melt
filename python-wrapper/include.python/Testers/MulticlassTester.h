#ifndef TESTERS__MULTICLASS_TESTER_H_
#define TESTERS__MULTICLASS_TESTER_H_
#include "Tester.h"
namespace gezi {
class MulticlassTester : public Tester
{
public:
virtual PredictionKind GetPredictionKind();
virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics();
protected:
private:
};
}
#endif
