#ifndef UTILS__EVALUATOR_UTILS_H_
#define UTILS__EVALUATOR_UTILS_H_
#include "Evaluator.h"
#include "MLCore/PredictionKind.h"
#include "MLCore/Trainer.h"
namespace gezi {
class EvaluatorUtils
{
public:
static vector<EvaluatorPtr> GetEvaluators(TrainerPtr trainer);
static EvaluatorPtr GetEvaluator(LossKind lossKind);
static EvaluatorPtr CreateEvaluator(string evaluatorName);
static vector<EvaluatorPtr> GetEvaluators(PredictionKind predictionKind);
static vector<EvaluatorPtr> CreateEvaluators(string evaluatorNames);
static vector<string> GetEvaluatorsNames(const vector<EvaluatorPtr>& evaluators);
protected:
private:
};
}
#endif
