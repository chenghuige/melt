#ifndef SF_HASH_WEIGHT_VECTOR_H__
#define SF_HASH_WEIGHT_VECTOR_H__
#include "sf-hash-inline.h"
#include "sf-weight-vector.h"
using std::string;
class SfHashWeightVector : public SfWeightVector
{
public:
SfHashWeightVector(int hash_mask_bits);
SfHashWeightVector(int hash_mask_bits,
const string& weight_vector_string);
virtual ~SfHashWeightVector();
virtual float InnerProduct(const SfSparseVector& x,
float x_scale = 1.0) const;
virtual void AddVector(const SfSparseVector& x, float x_scale);
private:
SfHashWeightVector();
int hash_mask_bits_;
int hash_mask_;
};
#endif
