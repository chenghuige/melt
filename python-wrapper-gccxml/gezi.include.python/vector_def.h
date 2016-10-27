#ifndef VECTOR_DEF_H_
#define VECTOR_DEF_H_
#ifdef USE_FOLLY_VECTOR_AS_DEFAULT
#include <folly/FBVector.h>
using ::vector;
#else
#include <vector>
using std::vector;
#endif
namespace gezi {
}
#endif
