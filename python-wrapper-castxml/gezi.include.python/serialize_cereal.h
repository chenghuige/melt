#ifndef SERIALIZE_CEREAL_H_
#define SERIALIZE_CEREAL_H_
#include <fstream>
#include <iostream>
#include <sstream>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/unordered_set.hpp>
#include <cereal/types/base_class.hpp>
#include <cereal/types/deque.hpp>
#include <cereal/types/vector.hpp>
#ifdef USE_FOLLY_VECTOR
#include <cereal/types/fbvector.hpp>
#endif
#include <cereal/types/map.hpp>
#include <cereal/types/set.hpp>
#include <cereal/types/list.hpp>
#include <cereal/types/deque.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/eigen.hpp>
namespace serialize_util {
using std::string;
template<typename T>
string save(const T& data);
template<typename T>
T load(string input);
template<typename T>
void load_from_str(string input, T& data);
template<typename T>
void load_from_str(T& data, string input);
template<typename T>
void save(const T& data, string file);
template<typename T>
void save_xml(const T& data, string file);
template<typename T>
void save_text(const T& data, string file);
template<typename T>
void save_json(const T& data, string file);
template<typename T>
bool load(string file, T& data);
template<typename T>
bool load_xml(string file, T& data);
template<typename T>
bool load_text(string file, T& data);
template<typename T>
bool load_json(string file, T& data);
template<typename T>
bool load(T& data, string file);
template<typename T>
bool load_xml(T& data, string file);
template<typename T>
bool load_text(T& data, string file);
template<typename T>
bool load_json(T& data, string file);
}
#endif
