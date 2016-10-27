#ifndef FILE_UTIL_H_
#define FILE_UTIL_H_
#include "common_def.h"
#include "hashmap_util.h"
#include <glog/logging.h>
#define  BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <map>
#include <set>
#include <string>
#include "format.h"
#include "serialize_util.h"
namespace bfs = boost::filesystem;
namespace gezi {
inline void copy_file(string src, string dest);
inline void try_create_dir(string dir);
inline string read_file(const string& infile);
template<typename T>
inline void write_file(const T& content, string outfile);
template<typename T>
inline bool read_file(string infile, T& content);
template<typename Container>
bool file_to_set(const string& infile, Container& container);
template<typename Container>
bool file_to_vec(const string& infile, Container& container);
inline vector<string> read_lines(string infile);
inline vector<string> read_lines_fast(string infile);
inline vector<string> read_lines_noempty(string infile);
inline vector<string> read_lines(string infile, string ignore);
inline vector<string> read_lines_fast(string infile, string ignore);
//inline vector<string> read_lines(ifstream& ifs);
inline void read_lines(string infile, vector<string>& vec);
template<typename T>
inline void write_lines(vector<T>& lines, string file);
template<typename Set>
inline void read_set(string infile, Set& container);
inline set<string> to_set(string infile);
inline unordered_set<string> to_hashset(string infile);
inline void read_to_set(const string& infile, std::set<string>& container,
int index = 0, string sep = "\t ");
inline void read_to_set(const string& infile, unordered_set<string>& container,
int index = 0, string sep = "\t ");
template<typename Container>
void read_to_set(const string& infile, Container& container, int index = 0, string sep = "\t ");
inline void read_to_vec(const string& infile, vector<string>& container,
int index = 0, string sep = "\t ");
inline vector<string> read_to_vec(const string& infile, int index = 0, string sep = "\t ");
template<typename Container>
void read_to_vec(const string& infile, Container& container, int index = 0, string sep = "\t ");
template<typename T>
vector<T> read_to_vec(const string& infile, int index = 0, string sep = "\t ");
template<typename Container, typename Container2>
void read_to_vec(const string& infile, Container& container, Container2& container2, int index = 0, int index2 = 1, string sep = "\t ");
inline void read_map(const string& infile, std::map<string, string>& container,
string sep = "\t", int key_idx = 0, int value_idx = 1);
inline void read_map(const string& infile, unordered_map<string, string>& container,
string sep = "\t", int key_idx = 0, int value_idx = 1);
template<typename Container>
void read_map(const string& infile, Container& container, string sep = "\t",
int key_idx = 0, int value_idx = 1);
inline unordered_map<string, int> to_identifer_hashmap(string infile, int start = 0);
inline map<string, int> to_identifer_map(string infile, int start = 0);
template<typename Map>
void write_map(const Map& m, const string& ofile, const string& sep = "\t");
template<typename _Node>
void write_vec(const vector<_Node>& vec, const string& file);
template<typename _Node>
bool read_vec(const string& file, vector<_Node>& vec);
//template<typename _Node>
//void write_vec(const vector<_Node>& vec, std::ofstream& ofs);
//template<typename _Node>
//vector<_Node> read_vec(std::ifstream& ifs);
//template<typename _Node>
//void read_vec(std::ifstream& ifs, vector<_Node>& vec);
template<typename T>
void write_elem(const T& elem, const string& file);
template<typename T>
bool read_elem(const string& file, T& elem);
//template<typename T>
//void write_elem(const T& elem, std::ofstream& ofs);
//template<typename T>
//void read_elem(std::ifstream& ifs, T& elem);
//template<typename _Node>
//void write_vec2d(const vector<vector<_Node> >& vec, std::ofstream& ofs);
template<typename _Node>
void write_vec2d(const vector<vector<_Node> >& vec, const string& file);
template<typename _Node>
bool read_vec2d(const string& file, vector<vector<_Node> >& vec);
class Vec2dWriter
{
public:
Vec2dWriter(const string& file);
template<typename _Node>
void write(const vector<_Node>& vec);
template<typename _Iter>
void write(_Iter begin, _Iter end);
void close();
private:
std::ofstream _ofs;
};
#ifndef GCCXML
class VecWriter
{
public:
//VecWriter(std::ofstream& ofs);
template<typename _Node>
VecWriter& write(const vector<_Node>& vec);
template<typename _Iter>
VecWriter& write(_Iter begin, _Iter end);
void close();
private:
std::ofstream& _ofs;
};
#endif
#define OBJ_PATH(obj, path)\
format("{}/{}.bin", path, gezi::conf_trim(#obj))
template<typename T>
inline void save_shared_ptr(T obj, string path, string name);
template<typename T>
inline void save_shared_ptr_astext(T obj, string name);
template<typename T>
inline void save_shared_ptr_asxml(T obj, string name);
template<typename T>
inline void save_shared_ptr_asjson(T obj, string name);
}
#define SAVE_SHARED_PTR(obj, path)\
gezi::save_shared_ptr(obj, path, gezi::conf_trim(#obj))
#define SAVE_SHARED_PTR_ASTEXT(obj, path)\
gezi::save_shared_ptr_astext(obj, format("{}/{}.txt", path, gezi::conf_trim((#obj))))
#define SAVE_SHARED_PTR_ASXML(obj, path)\
gezi::save_shared_ptr_asxml(obj, format("{}/{}.xml", path, gezi::conf_trim((#obj))))
#define SAVE_SHARED_PTR_ASJSON(obj, path)\
gezi::save_shared_ptr_asjson(obj, format("{}/{}.json", path, gezi::conf_trim((#obj))))
#define  OBJ_NAME_PATH(obj, path)\
format("{}/{}.name.txt", path, gezi::conf_trim(#obj))
#endif
