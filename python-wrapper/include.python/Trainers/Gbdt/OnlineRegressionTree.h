#ifndef TRAINERS_GBDT__ONLINE_REGRESSION_TREE_H_
#define TRAINERS_GBDT__ONLINE_REGRESSION_TREE_H_
#include "common_util.h"
#include "Numeric/Vector/Vector.h"
#include "Prediction/Instances/FeatureNamesVector.h"
namespace gezi {
class GbdtPredictor;
class OnlineRegressionTree
{
public:
friend class GbdtPredictor;
~OnlineRegressionTree();
OnlineRegressionTree();
//OnlineRegressionTree(OnlineRegressionTree&&);
//OnlineRegressionTree& operator = (OnlineRegressionTree&&);
OnlineRegressionTree(const OnlineRegressionTree&);
OnlineRegressionTree& operator = (const OnlineRegressionTree&);
bool operator == (const OnlineRegressionTree& other) const;
public:
Float Output(Vector& features);
void GainMap(Vector& features, map<int, double>& m);
void Print(int node = 0, int depth = 0);
void Print(const Vector& features, int node = 0, int depth = 0, string suffix = "$");
template<typename T, typename U>
void Print(const T& features, const U& threshold, int node = 0, int depth = 0, string suffix = "$");
int GetLeaf(const Vector& features);
void SetFeatureNames(const FeatureNamesVector& featureNames);
FeatureNamesVector& FeatureNames();
const FeatureNamesVector& FeatureNames() const;
protected:
template<typename T, typename U>
int GetLeaf_(const T& features, const U& threshold);
public:
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
#ifdef _DEBUG
struct DebugNode
{
int id;
svec paths;
double score;
bool operator < (const DebugNode& other) const;
};
DebugNode _debugNode;
#endif
public:
int NumLeaves;
protected:
#ifdef PYTHON_WRAPPER
public:
#endif
dvec _gainPValue;
ivec _lteChild;
ivec _gtChild;
dvec _leafValue;
dvec _threshold;
ivec _splitFeature;
dvec _splitGain;
double _maxOutput;
dvec _previousLeafValue;
double _weight;
FeatureNamesVector* _featureNames;
};
}
#endif
