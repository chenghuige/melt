#ifndef NUMERIC__VECTOR__VECTOR_H_
#define NUMERIC__VECTOR__VECTOR_H_
#include "common_util.h"
#include "serialize_util.h"
namespace gezi {
template<typename Vector_, typename Vector2_>
inline Float dot(const Vector_& a, const Vector2_& b);
template<typename Vector_, typename Vector2_>
inline Float cos(const Vector_& a, const Vector2_& b);
template<typename Vector_, typename Vector2_>
inline Float cos(const Vector_& a, const Vector2_& b, Float l2norm1, Float l2norm2);
class Vector
{
public:
Vector();
virtual ~Vector();
//Vector(Vector&&);
//Vector& operator = (Vector&&);
Vector(const Vector&);
Vector& operator = (const Vector&);
bool operator == (const Vector& other);
typedef int index_type;
typedef Float value_type;
typedef size_t size_type;
typedef int  difference_type;
typedef vector<value_type>::iterator iterator;
typedef vector<value_type>::const_iterator const_iterator;
explicit Vector(index_type length_)
: length(length_)
{
}
Vector(value_type value_, int length_);
Vector(index_type length_, value_type value_);
Vector(const map<index_type, double>& m);
void Resize(index_type length_, value_type value_ = 0);
void resize(index_type length_, value_type value_ = 0);
Vector(index_type length_, ivec& indices_, vector<value_type>& values_);
Vector(ivec& indices_, vector<value_type>& values_, index_type length_ = 1024000);
Vector(vector<value_type>& values_);
Vector(string input, index_type startIndex = 0, index_type length_ = 1024000, string sep = ",\t ",
bool indexOnly = false);
Vector(iterator first, iterator end);
#ifndef GCCXML
Vector(const std::initializer_list<value_type>& il);
#endif
void Init(string input, index_type startIndex = 0, index_type length_ = 0, string sep = ",\t ", bool indexOnly = false);
void Init(index_type length_, vector<index_type>& indices_, vector<value_type>& values_);
void Swap(Vector& other);
void Init(vector<value_type>& values_);
template<typename Iter>
void assign(Iter begin, Iter end);
//iterator begin();
//iterator end();
value_type front();
value_type back();
void push_back(value_type item);
template<typename Iter>
void insert(iterator dest, Iter begin, Iter end);
iterator insert(iterator position, const value_type& val);
void erase(iterator pos);
void erase(iterator first, iterator last);
void ToDense(vector<value_type>& values_);
void ToDense();
void ToSparse();
void MakeDense();
void ForceDense();
void MakeSparse();
void ForceSparse();
void Add(value_type value);
void Add(index_type index, value_type value);
template<typename Range>
void AddRange(const Range& m);
template<typename Range>
void AddMap(const Range& m);
void AddMap(const map<index_type, value_type>& m);
void PrepareDense();
void Sparsify(value_type maxSparsity);
void Sparsify();
void Densify(value_type maxSparsity);
void Densify();
value_type operator[](index_type index) const;
//value_type& operator[](index_type index);
Vector& operator()(int index, value_type value);
template<typename ValueVistor>
void ForEach(ValueVistor visitor) const;
template<typename ValueVistor>
void ForEachAll(ValueVistor visitor) const;
template<typename ValueVistor>
bool ForEachAllIf(ValueVistor visitor) const;
template<typename ValueVistor>
void ForEachAllSparse(ValueVistor visitor) const;
template<typename ValueVistor>
bool ForEachAllSparseIf(ValueVistor visitor) const;
template<typename ValueVistor>
void ForEach(ValueVistor visitor);
template<typename ValueVistor>
void ForEachDense(ValueVistor visitor) const;
template<typename ValueVistor>
bool ForEachDenseIf(ValueVistor visitor) const;
template<typename ValueVistor>
void ForEachDense(ValueVistor visitor);
template<typename ValueVistor>
void ForEachSparse(ValueVistor visitor) const;
template<typename ValueVistor>
bool ForEachSparseIf(ValueVistor visitor) const;
template<typename ValueVistor>
void ForEachSparse(ValueVistor visitor);
template<typename ValueVistor>
void ForEachNonZero(ValueVistor visitor) const;
template<typename ValueVistor>
void ForEachNonZero(ValueVistor visitor);
public:
bool IsDense() const;
bool IsSparse() const;
int Length() const;
size_t size() const;
void SetLength(int length_);
bool Empty() const;
bool empty() const;
int Count() const;
int NumNonZeros();
const ivec& Indices() const;
const vector<value_type>& Values() const;
ivec& Indices();
vector<value_type>& Values();
index_type Index(index_type index) const;
//index_type& Index(index_type index);
void SetIndex(index_type index, index_type indexValue);
value_type Value(index_type index) const;
//value_type& Value(index_type index);
void SetValue(index_type index, value_type value);
void Clear();
void clear();
void CheckInvariants();
Vector& operator *= (value_type d);
Vector& operator /= (value_type d);
Vector& operator += (const Vector& other);
Vector& operator -= (const Vector& other);
Float dot(const Vector& other) const;
void ScaleBy(value_type d);
inline void Add(const Vector& other);
inline void Subtract(const Vector& other);
template<typename ParallelManipulator>
void ApplyWith(const Vector& a, ParallelManipulator manip);
value_type Norm() const;
value_type SquaredNorm() const;
string Str(string sep = ",") const;
string AllStr(string sep = ",") const;
string DenseStr(string sep = ",") const;
string str(string sep = ",") const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
private:
int GetNumNonZeros();
public:
vector<index_type> indices;
vector<value_type> values;
value_type sparsityRatio;
bool keepDense;
bool keepSparse;
bool normalized;
int numNonZeros;
protected:
index_type length;
value_type _zeroValue;
};
typedef shared_ptr<Vector> VectorPtr;
typedef vector<Vector> Vectors;
#ifdef PYTHON_WRAPPER
struct PyHack_Vectors : public Vectors
{
};
#endif
template<typename Map>
void add(Vector& fe, const Map& m);
#ifndef GCCXML
inline Vector operator+(const Vector& l, const Vector& r);
#endif
}
#endif
