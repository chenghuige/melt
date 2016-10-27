#ifndef TESTERS__RANKER_TESTER_H_
#define TESTERS__RANKER_TESTER_H_
#include "Tester.h"
namespace gezi {
class RankingMetrics : public DatasetMetrics
{
public:
RankingMetrics();
virtual void ParseArgs();
virtual vector<string> PerInstanceColumnNames();
virtual vector<string> Names();
virtual Fvec ProcessInstance(Float label, Float prediction, Float probability, Float weight);
dvec QueryMaxDCG(const vector<short>& labels);
template<typename ValueVec, typename Compare>
void index_sort(const ValueVec& valueVec, vector<int>& indexVec, Compare compare, int maxLen);
dvec QueryDCG(const vector<short>& labels, const Fvec& scores);
virtual Fvec FinishGroup();
virtual void Finish();
private:
void AddPerInstanceNameGroup(vector<string>& names, string prefix);
void AddNameGroup(vector<string>& names, string prefix);
protected:
int truncationLevel;
bool useLn;
bool excludeNoRelevant;
Fvec gainMap;
dvec discountMap;
vector<short> queryLabels;
Fvec queryOutputs;
Float currentQueryWeight;
Float sumWeights;
Float sumWeights2;
int numNoRelevantQuries;
Fvec sumDCGAtN;
Fvec sumNDCGAtN;
Float sumTop1Precision;
Float sumTop1Precision2;
};
class RankerTester : public Tester
{
public:
RankerTester();
virtual PredictionKind GetPredictionKind();
virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics();
virtual void ProcessInstances(Instances instances, PredictorPtr predictor);
protected:
private:
};
}
#endif
