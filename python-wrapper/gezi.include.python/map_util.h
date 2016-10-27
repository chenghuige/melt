#ifndef MAP_UTIL_H_
#define MAP_UTIL_H_
#include <iostream>
#include <iomanip>
namespace gezi {
template<typename Map>
inline bool map_contains(Map* history, string name);
template<typename Map>
inline bool map_contains(Map& history, string name);
template<typename Map>
inline int length(Map* history, string name);
template<typename Map>
inline int length(Map& history, string name);
template<typename Map, typename T>
void add_one(Map& map, T name, int count = 1);
template<typename Map, typename T, typename U>
void add_value(Map& map, T name, U value);
template<typename ValueType, typename KeyType, typename Map>
ValueType get_value(const Map& m, KeyType key, const ValueType& default_value);
template<typename ValueType, typename KeyType, typename Map, typename Func>
ValueType get_value(const Map& m, KeyType key, Func func, const ValueType& default_value);
template<typename ValueType, typename KeyType, typename Map>
bool try_add(Map& m, KeyType key, ValueType value);
template<typename _Map>
void print_enum_map(const _Map& m);
template<typename _Map>
void print_map(const _Map& m);
}
#endif
