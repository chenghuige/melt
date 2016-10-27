#ifndef PREDICTION__INSTANCES__INSTANCE_H_
#define PREDICTION__INSTANCES__INSTANCE_H_
#include "common_util.h"
#include "Numeric/Vector/Vector.h"
namespace gezi {
struct Instance
{
public:
~Instance();
Instance();
//Instance(Instance&&);
//Instance& operator = (Instance&&);
Instance(const Instance&);
Instance& operator = (const Instance&);
typedef Vector::value_type value_type;
typedef Vector::index_type index_type;
Instance(int length);
size_t size() const;
int FeatureNum() const;
int NumFeatures() const;
void SelectFeatures(const BitArray& includedFeatures);
void SelectFeaturesAndCompact(ivec& featuresToKeep);
Vector& Features();
bool IsDense() const;
bool IsSparse() const;
bool IsPositive();
bool IsNegative();
bool IsUnknown();
bool HasMissingFeatures();
value_type operator[](index_type index) const;
//value_type& operator[](index_type index);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
public:
Float label;
Float weight;
Vector features;
bool hasMissingFeatures;
string name;
svec names;
svec attributes;
string groupKey;
string metaData;
bool sparse;
bool normalized;
string line;
};
typedef shared_ptr<Instance> InstancePtr;
typedef vector<InstancePtr> ListInstances;
}
#endif
