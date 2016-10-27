#ifndef UNORDERED_SET_SERIALIZE_H_
#define UNORDERED_SET_SERIALIZE_H_
#include "hashmap_util.h"
#include <boost/config.hpp>
//#include <boost/serialization/utility.hpp>
//#include <boost/serialization/hash_collections_save_imp.hpp>
//#include <boost/serialization/hash_collections_load_imp.hpp>
//#include <boost/serialization/split_free.hpp>
namespace boost {
namespace serialization {
namespace stl {
template<class Archive, class Container, class InputFunction>
inline void load_hash_collection_unordered_set(Archive & ar, Container &s);
}
template<
class Archive,
class Key,
class HashFcn,
class EqualKey,
class Allocator
>
inline void save(
Archive & ar,
const std::unordered_set<
Key, HashFcn, EqualKey, Allocator
> &t,
const unsigned int file_version
);
template<
class Archive,
class Key,
class HashFcn,
class EqualKey,
class Allocator
>
inline void load(
Archive & ar,
std::unordered_set<
Key, HashFcn, EqualKey, Allocator
> &t,
const unsigned int file_version
);
template<
class Archive,
class Key,
class HashFcn,
class EqualKey,
class Allocator
>
inline void serialize(
Archive & ar,
std::unordered_set<
Key, HashFcn, EqualKey, Allocator
> &t,
const unsigned int file_version
);
}
}
#endif
