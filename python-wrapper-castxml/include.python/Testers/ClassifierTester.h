#ifndef TESTERS__CLASSIFIER_TESTER_H_
#define TESTERS__CLASSIFIER_TESTER_H_
#include "Testers/Tester.h"
#include "Utils/Evaluator.h"
#include "statistic_util.h"
namespace gezi {
class ClassificationPrecisionRecall : public DatasetMetrics
{
public:
ClassificationPrecisionRecall();
virtual void ParseArgs();
virtual vector<string> PerInstanceColumnNames();
virtual Fvec ProcessInstance(Float label, Float prediction, Float probability, Float weight);
protected:
virtual void Finish();
virtual void Print_(string prefix);
protected:
Float numTruePos;
int64 numUnlabeledInstances;
Float logLossProb;
Float numLogLossPositives, numLogLossNegatives;
Float trainPrior;
double posThre;
bool useLn;
Float logTolerance;
Float accuracy, precisionPos, recallPos, precisionNeg, recallNeg, avgLogLossProb, avgLogLoss, logLossReduction;
};
class ClassificationAUC : public DatasetMetrics
{
public:
ClassificationAUC();
virtual vector<string> PerInstanceColumnNames();
virtual Fvec ProcessInstance(Float label, Float prediction, Float probability, Float weight);
protected:
virtual void Finish();
virtual void Print_(string prefix);
public:
private:
AucEvaluator _evaluator, _evaluatorByOutput;
Float _auc, _aucByOutput;
};
class ClassifierTester : public Tester
{
public:
virtual PredictionKind GetPredictionKind();
virtual vector<DatasetMetricsPtr> ConstructDatasetMetrics();
};
}
#endif
