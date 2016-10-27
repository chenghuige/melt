#ifndef NUMERIC__VECTOR__WEIGHT_VECTOR_H_
#define NUMERIC__VECTOR__WEIGHT_VECTOR_H_
#include "Vector.h"
namespace gezi {
class WeightVector : public Vector
{
public:
//using Vector::Vector;
WeightVector();
virtual ~WeightVector();
WeightVector(index_type length_);
WeightVector(index_type length_, value_type val);
void Sparsify(value_type maxSparsity);
void Sparsify();
void SetLength(index_type length_);
using Vector::Init;
void Init(index_type length_, value_type val);
void Resize(index_type length_, value_type value_ = 0);
void ScaleBy(value_type scalingFactor);
Float Norm();
void ScaleToOne();
value_type operator[](index_type index) const;
//value_type& operator[](index_type index);
value_type Value(index_type index) const;
using Vector::Add;
void Add(const Vector& other);
void AddSparse(const Vector& other);
void AddScale(const Vector& other, value_type scale);
Vector ToVector();
Float dot(const Vector& other) const;
Float dot(const Vector& other, Float scale) const;
Float dotOnDifference(const Vector& other1, const Vector& other2, Float scale = 1.0) const;
value_type SquaredNorm() const;
public:
Float squaredNorm;
protected:
Float _scale;
};
class SparseWeightVector : public WeightVector
{
public:
//using WeightVector::WeightVector;
void Add(Vector& a);
void Add(SparseWeightVector& a);
void AddScale(Vector& a, value_type scale);
void AddScale(SparseWeightVector& a, value_type scale);
template<typename Vector_, typename ParallelManipulator>
void WeightApplyWith(Vector_& a, ParallelManipulator manip);
};
}
#endif
