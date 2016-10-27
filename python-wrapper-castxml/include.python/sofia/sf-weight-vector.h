#ifndef SF_WEIGHT_VECTOR_H__
#define SF_WEIGHT_VECTOR_H__
#include "sf-sparse-vector.h"
using std::string;
class SfWeightVector
{
public:
SfWeightVector(int dimensionality);
SfWeightVector(const string& weight_vector_string);
SfWeightVector(const SfWeightVector& weight_vector);
virtual ~SfWeightVector();
string AsString();
virtual float InnerProduct(const SfSparseVector& x,
float x_scale = 1.0) const;
float InnerProductOnDifference(const SfSparseVector& a,
const SfSparseVector& b,
float x_scale = 1.0) const;
virtual void AddVector(const SfSparseVector& x, float x_scale);
void ScaleBy(double scaling_factor);
float ValueOf(int index) const;
void ProjectToL1Ball(float lambda);
void ProjectToL1Ball(float lambda, float epsilon);
double GetSquaredNorm() const;
int GetDimensions() const;
protected:
void ScaleToOne();
float* weights_;
double scale_;
double squared_norm_;
int dimensions_;
private:
SfWeightVector();
};
#endif
