#ifndef TESTERS__DATASET_METRICS_H_
#define TESTERS__DATASET_METRICS_H_
#include "common_util.h"
namespace gezi {
class DatasetMetrics : public WithArgs
{
public:
DatasetMetrics();
virtual ~DatasetMetrics();
virtual string LabelColumnName();
//virtual vector<string> PerInstanceColumnNames() = 0;
virtual vector<string> Names();
virtual Fvec ProcessInstance(InstancePtr instance, PredictorPtr predictor);
virtual Fvec ProcessInstance(Float label, Float prediction, Float probability = std::numeric_limits<Float>::quiet_NaN(), Float weight = 1.0);
virtual Fvec ProcessInstance(Float label,const Fvec& prediction, Float probability = std::numeric_limits<Float>::quiet_NaN(), Float weight = 1.0);
void Print(string prefix = "");
protected:
virtual void Finish();
virtual void Print_(string prefix);
protected:
Fvec _results;
svec _names;
private:
};
typedef shared_ptr<DatasetMetrics> DatasetMetricsPtr;
}
#endif
