#ifndef SF_DATA_SET_H__
#define SF_DATA_SET_H__
#include <string>
#include <vector>
#include "sf-sparse-vector.h"
class SfDataSet
{
public:
SfDataSet(bool use_bias_term);
SfDataSet(const string& file_name, int buffer_mb, bool use_bias_term);
string AsString() const;
long int NumExamples() const;
const SfSparseVector& VectorAt (long int index) const;
void AddVector(const string& vector_string);
void AddVector(const char* vector_string);
void AddLabeledVector(const SfSparseVector& x, float y);
private:
vector<SfSparseVector> vectors_;
bool use_bias_term_;
};
#endif
