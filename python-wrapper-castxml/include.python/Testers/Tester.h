#ifndef TESTERS__TESTER_H_
#define TESTERS__TESTER_H_
#include "common_util.h"
#include "MLCore/Predictor.h"
#include "Testers/DatasetMetrics.h"
namespace gezi {
class Tester
{
public:
virtual ~Tester();
//virtual PredictionKind GetPredictionKind() = 0;
//virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics() = 0;
void WriteHeader(Instances& instances);
static string InstanceName(InstancePtr instance);
void PrintInstanceOutput(int64 instanceCnt, InstancePtr instance, const vector<double>& instanceMetrics, string groupKey = "");
virtual void ProcessInstances(Instances instances, PredictorPtr predictor);
void Finalize();
void Test(Instances& instances, PredictorPtr predictor, string lossOutfile = "");
protected:
void FinalizeProcessInstances();
public:
bool writeTSVHeader;
int runIdx;
int foldIdx;
bool collectOutputsAndLabels;
bool hasWeights;
bool hasRankingMetric;
ofstream ofs;
vector<DatasetMetricsPtr> datasetMetrics;
vector<DatasetMetricsPtr> globalDatasetMetrics;
string foldSeparatorString;
bool isCrossValidationMode;
protected:
private:
};
typedef shared_ptr<Tester> TesterPtr;
}
#endif
