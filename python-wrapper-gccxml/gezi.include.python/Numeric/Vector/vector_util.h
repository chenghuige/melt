#ifndef NUMERIC__VECTOR_VECTOR_UTIL_H_
#define NUMERIC__VECTOR_VECTOR_UTIL_H_
#include "common_def.h"
#include "Numeric/Vector/Vector.h"
namespace gezi {
template<typename Func>
void apply(Fvec& values, const ivec& shiftIndices, Func func);
template<typename Func, typename _Vector>
void apply_sparse(_Vector& vec, const ivec& shiftIndices, Func func);
template<typename Func>
void apply(Vector& vec, const ivec& shiftIndices, Func func);
}
#endif
