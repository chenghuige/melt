#ifndef FEATURE_SELECTION_H_
#define FEATURE_SELECTION_H_
#include "common_util.h"
#include "Matrix.h"
#include "collocation.h"
namespace gezi
{
enum ScoreFeatureStrategy
{
MAX,
AVG
};
template<typename Func>
void score_feature(IMat& counts,
vector<int>& featureCounts, vector<int>& classTotals,
uint64 numInstances, vector<double> scores, const Func& func = Func(),
ScoreFeatureStrategy strategy = MAX);
}
#endif
