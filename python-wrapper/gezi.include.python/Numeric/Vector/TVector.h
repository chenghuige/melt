#ifndef NUMERIC__VECTOR__FVECTOR_H_
#define NUMERIC__VECTOR__FVECTOR_H_
#include "common_util.h"
#include "serialize_util.h"
namespace gezi {
template<typename ValueType>
class TVector
{
public:
TVector();
virtual ~TVector();
//TVector(TVector&&);
//TVector& operator = (TVector&&);
TVector(const TVector&);
TVector& operator = (const TVector&);
typedef vector<ValueType> Vec;
TVector(int length_);
TVector(ValueType value_, int length_);
void Swap(TVector<ValueType>& other);
void Init(Vec& values_);
void ToDense(Vec& values_);
void ToDense();
void ToSparse();
void MakeDense();
void MakeSparse();
void Add(ValueType value);
void Add(int index, ValueType value);
void PrepareDense();
void Sparsify(Float maxSparsity);
void Sparsify();
void Densify(Float maxSparsity);
void Densify();
ValueType operator[](int i) const;
//ValueType& operator[](int i);
TVector<ValueType>& operator()(int index, ValueType value);
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
int size() const;
void SetLength(int length_);
bool Empty() const;
bool empty() const;
int Count() const;
int NumNonZeros();
const ivec& Indices() const;
const Vec& Values() const;
ivec& Indices();
Vec& Values();
int Index(int index) const;
int Index(int index);
ValueType Value(int index) const;
#ifndef GCCXML
//ValueType& Value(int index);
#endif
void Clear();
void CheckInvariants();
string Str(string sep = ",");
string DenseStr(string sep = ",");
string str(string sep = ",");
const ValueType ZeroValue() const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
private:
int GetNumNonZeros();
public:
ivec indices;
Vec values;
Float sparsityRatio;
bool keepDense;
bool keepSparse;
bool normalized;
int numNonZeros;
private:
int length;
ValueType _zeroValue;
};
typedef TVector<int> IntArray;
class PyIntArray : public IntArray
{
};
}
#endif
