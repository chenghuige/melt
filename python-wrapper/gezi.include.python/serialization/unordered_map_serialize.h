#ifndef _UNORDERD_MAP_SERIALIZE_H
#define	_UNORDERD_MAP_SERIALIZE_H
#include "hashmap_util.h"
#include <boost/config.hpp>
//#include <boost/serialization/utility.hpp>
//#include <boost/serialization/collections_save_imp.hpp>
//#include <boost/serialization/collections_load_imp.hpp>
//#include <boost/serialization/split_free.hpp>
namespace boost {
namespace serialization {
template<class Archive, class Type, class Key, class Hash, class
Compare, class Allocator >
inline void save(
Archive & ar,
const std::unordered_map<Key, Type, Hash, Compare, Allocator> &t,
const unsigned int
);
template<class Archive, class Type, class Key, class Hash, class
Compare, class Allocator >
inline void load(
Archive & ar,
std::unordered_map<Key, Type, Hash, Compare, Allocator> &t,
const unsigned int
);
template<class Archive, class Type, class Key, class Hash, class
Compare, class Allocator >
inline void serialize(
Archive & ar,
std::unordered_map<Key, Type, Hash, Compare, Allocator> &t,
const unsigned int file_version
);
}
}
#endif
