#ifndef SERIALIZE_BOOST_H_
#define SERIALIZE_BOOST_H_
#include <fstream>
#include <iostream>
//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/nvp.hpp>
//#include <boost/archive/xml_oarchive.hpp>
//#include <boost/serialization/utility.hpp>
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/xml_oarchive.hpp>
//#include <boost/archive/xml_iarchive.hpp>
//#include <boost/serialization/string.hpp>
//#include <boost/serialization/map.hpp>
//#include <boost/serialization/vector.hpp>
//#include <boost/serialization/set.hpp>
//#include "serialization/unordered_map_serialize.h"
//#include "serialization/unordered_set_serialize.h"
namespace serialize_util {
using std::string;
template<typename T>
void save(const T& data, string file);
template<typename T>
void save_xml(const T& data, string file);
template<typename T>
void save_json(const T& data, string file);
template<typename T>
void Save(const T& data, string file);
template<typename T>
void SaveText(const T& data, string file);
template<typename T>
void save_text(const T& data, string file);
template<typename T>
bool load(string file, T& data);
template<typename T>
bool load_xml(string file, T& data);
template<typename T>
bool load_json(string file, T& data);
template<typename T>
bool load_text(string file, T& data);
template<typename T>
bool Load(string file, T& data);
template<typename T>
bool LoadText(string file, T& data);
template<typename T>
bool load(T& data, string file);
template<typename T>
bool load_xml(T& data, string file);
template<typename T>
bool load_json(T& data, string file);
template<typename T>
bool load_text(T& data, string file);
template<typename T>
bool Load(T& data, string file);
template<typename T>
bool LoadText(T& data, string file);
}
#endif
