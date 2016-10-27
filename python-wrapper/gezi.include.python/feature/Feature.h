#ifndef _FEATURE_H_
#define _FEATURE_H_
#include "common_util.h"
namespace gezi {
class Feature
{
public:
struct Node
{
Node();
Node(int index_, Float value_);
Node(int index_);
int index;
Float value;
};
typedef vector<Node>::iterator Iter;
typedef vector<Node>::const_iterator ConstIter;
typedef vector<Float>::iterator VIter;
typedef vector<Float>::const_iterator ConstVIter;
Feature(bool keep_dense = false, bool keep_sparse = false, int dimension = 1000, bool use_section_name = true, Float zero_thre = 0.0);
Feature(int length);
~Feature();
//Feature(Feature&&);
//Feature& operator = (Feature&&);
Feature(const Feature&);
Feature& operator = (const Feature&);
bool keep_sparse() const;
Feature& keep_sparse(bool sparse_);
bool keep_dense() const;
Feature& keep_dense(bool dense_);
bool is_dense() const;
bool is_sparse() const;
bool only_sparse() const;
bool only_dense() const;
int size() const;
int dimension() const;
bool empty() const;
int featureNum() const;
int feature_num() const;
int count();
int features() const;
vector<Node>& nodes();
const vector<Node>& nodes() const;
Feature& dimension(int dimension);
void set_dimension(int dimension);
void to_dense();
void add(Float value, string name = "");
void add(Float* values, int len, string name = "");
template<typename T>
void add(vector<T>& values, string name = "");
void add_section(string name);
void add(int index, Float value);
template<typename T>
void add_sparse(vector<T>& values);
void finalize();
void set(int index, Float value);
const Float value(int index) const;
const Float operator[](int index) const;
const Float value_at(int index) const;
const Float at(int index) const;
string str();
vector<string>& names();
vector<string>& section_names();
vector<int>& name_counts();
vector<Float>& values();
const vector<Float>& values() const;
const vector<string>& names() const;
const vector<string>& section_names() const;
const vector<int>& name_counts() const;
static Float default_min();
static Float default_mean();
static Float default_max();
//friend  ostream & operator <<(ostream & os, Feature& fe);
template<typename ValueVistor>
void ForEach(ValueVistor visitor) const;
template<typename ValueVistor>
void ForEach(ValueVistor visitor);
bool IsDense() const;
template<typename ValueVistor>
void ForEachDense(ValueVistor visitor);
template<typename ValueVistor>
void ForEachSparse(ValueVistor visitor) const;
void Add(Float value);
void Add(int index, Float value);
int Count() const;
int Index(int index) const;
int Index(int index);
Float Value(int index) const;
Float& Value(int index);
const vector<Float>& Values() const;
vector<Float>& Values();
int Length();
private:
vector<Node> _nodes;
Float _zero_thre;
bool _use_section_name;
vector<string> _names;
vector<string> _section_names;
vector<Float>_values;
vector<int> _name_counts;
int _idx;
bool _keep_sparse;
bool _keep_dense;
int _dimension;
public:
bool normalized;
};
typedef Feature::Node fnode_t;
}
#endif
