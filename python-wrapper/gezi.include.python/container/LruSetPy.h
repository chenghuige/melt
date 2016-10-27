#ifndef GEZI_CONTAINER__LRU_SET_PY_H_
#define GEZI_CONTAINER__LRU_SET_PY_H_
#ifdef GCCXML
#include <set>
#else
#include "container/LruSet.h"
#endif
namespace gezi {
#ifdef GCCXML
typedef std::set<unsigned long long> LruHashSet_uint64;
typedef std::set<int> LruHashSet_int;
#else
typedef LruHashSet<unsigned long long> LruHashSet_uint64;
typedef LruHashSet<int> LruHashSet_int;
#endif
struct PyHack_LruHashSet_uint64 : public LruHashSet_uint64
{
};
struct PyHack_LruHashSet_int : public LruHashSet_int
{
};
}
#endif
