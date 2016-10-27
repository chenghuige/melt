#ifndef PREDICTION__INSTANCES__FEATURE_NAMES_VECTOR_H_
#define PREDICTION__INSTANCES__FEATURE_NAMES_VECTOR_H_
#include "common_util.h"
#include "file_util.h"
namespace gezi {
inline string get_feature_name(const svec& featureNames, int index);
inline string get_feature_name(const svec* const featureNames, int index);
class Predictor;
class FeatureNamesVector
{
public:
friend class Predictor;
FeatureNamesVector();
FeatureNamesVector(int numFeatures);
FeatureNamesVector(const svec& featureNames);
//FeatureNamesVector(svec&& featureNames);
typedef svec::iterator iterator;
void push_back(string name);
bool empty();
//iterator begin();
//iterator end();
string operator[](int index) const;
string at(int index) const;
size_t size() const;
void SetNumFeatures(int numFeatures);
bool operator == (const FeatureNamesVector& other);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
void Load(string file);
void Save(string file);
private:
int _numFeatures;
shared_ptr<svec> _featureNames;
};
}
#endif
