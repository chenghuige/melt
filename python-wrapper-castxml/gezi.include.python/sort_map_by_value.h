#ifndef SORT_MAP_BY_VALUE_H_
#define SORT_MAP_BY_VALUE_H_
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <complex>
#include <cmath>
#include "sort_util.h"
namespace gezi {
template <typename Map>
vector<std::pair<typename Map::key_type, typename Map::mapped_type> > sort_map(Map& tmap);
template <typename Map>
vector<std::pair<typename Map::key_type, typename Map::mapped_type> > sort_map_desc(Map& tmap);
template < typename Map, typename Func>
vector<std::pair<typename Map::key_type, typename Map::mapped_type> > sort_map(Map& tmap, int n, Func func);
template < typename Map, typename Func>
vector<std::pair<typename Map::key_type, typename Map::mapped_type> > partial_sort_map(Map& tmap, Func func);
template <typename Map>
vector<std::pair<typename Map::key_type, typename Map::mapped_type> > partial_sort_map(Map& tmap, int n);
template <typename Map>
vector<std::pair<typename Map::key_type, typename Map::mapped_type> > partial_sort_map_desc(Map& tmap, int n);
template<typename Map, typename Vec>
void sort_map_by_value(Map& tmap, Vec& tvec);
template<typename Map, typename Vec, typename Func>
void sort_map_by_value(Map& tmap, Vec& tvec, Func func);
template<typename Map, typename Vec>
void sort_map_by_key(Map& tmap, Vec& tvec);
template<typename Map, typename Vec>
void sort_map_by_value_reverse(Map& tmap, Vec& tvec);
template<typename Map, typename Vec>
void sort_map_by_absvalue_reverse(Map& tmap, Vec& tvec);
template<typename Map, typename Vec>
void patital_sort_map_by_value(Map& tmap, Vec& tvec, int n = 10);
template<typename Map, typename Vec>
void patital_sort_map_by_value_reverse(Map& tmap, Vec& tvec, int n = 10);
}
#endif
