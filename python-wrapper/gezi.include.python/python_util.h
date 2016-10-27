#ifndef PYTHON_UTIL_H_
#define PYTHON_UTIL_H_
#ifndef GCCXML
#define BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
#include <boost/bind.hpp>
#include <boost/lambda/lambda.hpp>
using namespace boost::lambda;
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/suite/indexing/map_indexing_suite.hpp>
#include <boost/python/iterator.hpp>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
namespace bp = boost::python;
inline void IndexError();
template<class Vec>
struct PyVectorUtil
{
typedef typename Vec::value_type ValueType;
static void erase(Vec & vec, int i);
static void push_back(Vec & vec, const ValueType& val);
static void resize(Vec & vec, int length, const ValueType & val);
static std::string str(Vec& vec);
static void init(Vec& vec, const boost::python::list& list);
static boost::python::list tolist(Vec& vec);
};
template<class Map>
struct PyMapUtil
{
typedef typename std::pair<typename Map::key_type, typename Map::mapped_type> ValueType;
static void init(Map& m, const boost::python::dict& dict_);
static boost::python::dict todict(Map& m);
};
template <typename SetType>
struct set_wrapper
{
typedef SetType w_t;
typedef typename SetType::value_type e_t;
static void insert_element(w_t& self, e_t const& x);
static void insert_set(w_t& self, w_t const& other);
static bool contains(w_t const& self, e_t const& x);
static boost::python::tuple getinitargs(w_t const& self);
static void wrap(std::string const& python_name);
};
using bp::vector_indexing_suite;
using bp::map_indexing_suite;
using bp::class_;
#define VEC_METHOD(Vec)\
.def("__delitem__", &PyVectorUtil<Vec>::erase)\
.def("push_back", &PyVectorUtil<Vec>::push_back)\
.def("size", &Vec::size)\
.def("clear", &Vec::clear)\
.def("erase", &PyVectorUtil<Vec>::erase)\
.def("resize", &PyVectorUtil<Vec>::resize)\
.def("init", &PyVectorUtil<Vec>::init)\
.def("tolist", &PyVectorUtil<Vec>::tolist)
#define DEF_VEC(Vec) \
class_<Vec >(#Vec) \
.def(vector_indexing_suite<Vec, true>())\
VEC_METHOD(Vec)
#define VEC_METHOD2(Base, Vec)\
Base.def(vector_indexing_suite<Vec >())\
.def("__delitem__", &PyVectorUtil<Vec>::erase)\
.def("push_back", &PyVectorUtil<Vec>::push_back)\
.def("size", &Vec::size)\
.def("clear", &Vec::clear)\
.def("erase", &PyVectorUtil<Vec>::erase)\
.def("resize", &PyVectorUtil<Vec>::resize)\
.def("init", &PyVectorUtil<Vec>::init)\
.def("tolist", &PyVectorUtil<Vec>::tolist)
#define  MAP_METHOD(Map)\
.def("clear", &Map::clear)\
.def("size", &Map::size)\
.def("init", &PyMapUtil<Map>::init)\
.def("todict", &PyMapUtil<Map>::todict)
#define DEF_MAP(Map) \
class_<Map >(#Map)\
.def(map_indexing_suite<Map,true>())\
MAP_METHOD(Map)
#define DEF_PAIR(Pair) \
class_<Pair >(#Pair)\
.def_readwrite("first", &Pair::first)\
.def_readwrite("second", &Pair::second)
#define  DEF_SET(Set) \
set_wrapper<Set>::wrap(#Set)
#ifndef COMMA
#define  COMMA ,
#endif
#endif
#endif
