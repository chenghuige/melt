#ifndef HASHMAP_UTIL_H_
#define HASHMAP_UTIL_H_
#include "common_define.h"
#if IS_HIGH_COMPILER_
#include <unordered_map>
#include <unordered_set>
#else
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
namespace std {
using ::boost::unordered_map;
using ::boost::unordered_set;
}
#endif
using std::unordered_map;
using std::unordered_set;
#endif
