#ifndef RUN__C_V_FOLD_CREATOR_H_
#define RUN__C_V_FOLD_CREATOR_H_
#include "Prediction/Instances/Instance.h"
#include "Run/MeltArguments.h"
namespace gezi {
class CVFoldCreator
{
public:
static ivec CreateFoldIndices(const Instances& data, const MeltArguments& cmd, const RandomEngine& rng);
static ivec CreateFoldIndicesBalanced(const Instances& data, int numFolds);
static ivec CreateFoldIndicesSequential(const Instances& data, int numFolds, const RandomEngine& rng);
static ivec CreateFoldIndicesOneByOne(const Instances& data, int numFolds);
static ivec CreateFoldIndicesStratified(const Instances& data, int numFolds, const RandomEngine& rng);
static void CreateFolds(const Instances& data, Float trainProportion,
ivec& instanceFoldIndices, int foldIdx, int numFolds,
Instances& trainData, Instances& testData,
const RandomEngine& rng);
};
}
#endif
