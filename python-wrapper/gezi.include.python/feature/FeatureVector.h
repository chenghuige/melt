#ifndef FEATURE__FEATURE_VECTOR_H_
#define FEATURE__FEATURE_VECTOR_H_
#include "Numeric/Vector/Vector.h"
namespace gezi {
class FeatureVector : public Vector
{
public:
~FeatureVector();
//FeatureVector(FeatureVector&&);
//FeatureVector& operator = (FeatureVector&&);
FeatureVector(const FeatureVector&);
FeatureVector& operator = (const FeatureVector&);
//using Vector::Vector;
FeatureVector(bool useSparse = true);
explicit FeatureVector(index_type length_)
:Vector(length_)
{
}
public:
struct Feature
{
Feature();
Feature(index_type index_, value_type value_);
Feature(int index_);
int index;
value_type value;
bool operator == (const Feature& other) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
value_type operator[](index_type i) const;
//value_type& operator[](index_type i);
value_type value_at(index_type index) const;
//value_type& value_at(index_type index);
value_type at(index_type index) const;
//value_type& at(index_type index);
int dimension() const;
void finalize();
vector<Feature>& features();
const vector<Feature>& features() const;
int count() const;
bool empty() const;
void clear();
string str(string sep = ",");
string Str(string sep = ",");
vector<string>& names();
const vector<string>& names() const;
vector<string>& section_names();
const vector<string>& section_names() const;
vector<int>& name_counts();
const	vector<int>& name_counts() const;
void add(value_type value, string name = "");
void add(value_type* values_, index_type len, string name = "");
template<typename T>
void add(const vector<T>& values_, string name = "");
template<typename T, size_t Len>
void add(std::array<T, Len>& values_, string name = "");
template<typename Vec>
void adds(const Vec& values_, string name = "");
void add_section(string name);
void add(int index, value_type value);
template<typename T>
void add_sparse(vector<T>& values);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
public:
//static bool& useNames();
protected:
private:
bool _useSectionName;
svec _names;
svec _sectionNames;
ivec _nameCounts;
int _idx;
bool _useSparseAlso;
vector<Feature> _features;
};
typedef shared_ptr<FeatureVector> FeatureVectorPtr;
typedef FeatureVector Features;
typedef FeatureVectorPtr FeaturesPtr;
#ifdef PYTHON_WRAPPER
class PyFeatures : public Features
{
};
#endif
}
#endif
