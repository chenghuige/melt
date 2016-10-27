#ifndef TOOLS__FEATURE_STATUS_H_
#define TOOLS__FEATURE_STATUS_H_
#include "common_util.h"
#include "Prediction/Instances/Instances.h"
namespace gezi {
class FeatureStatus
{
public:
static void GenMeanVarInfo(const Instances& instances, string outFile,  string outFile2,
string featureName = "");
protected:
private:
static void MeanVar(dvec& means, dvec& vars, int featureNum, uint64 instanceNum);
};
}
#endif
