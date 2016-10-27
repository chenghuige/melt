#ifndef STL_UTIL_H_
#define STL_UTIL_H_
#include "common_def.h"
#include "convert_type.h"
#include "map_util.h"
#include <boost/lexical_cast.hpp>
namespace gezi {
template<typename T>
string join(const vector<T>& vec, const string& sep = " ");
template<typename Iter>
string join(Iter begin, Iter end, const string& sep = " ");
template<typename T>
vector<T> join_vec2d(const vector<vector<T> >& input);
template<typename T>
string get_json(const vector<T>& vec);
template<typename T>
string get_json(const vector<T>& vec, int len);
inline vector<string> to_vec(string input_, string sep = ",");
inline vector<string> split2(string s, const char delimiter);
inline vector<string> split(string input, char sep);
template<typename Vec>
inline vector<Vec> split(const Vec& input, int length);
inline vector<string> split(string input, string sep = "\t ");
inline vector<string> splits(string s, string delim, bool keep_empty = true);
inline bool split(string input, string sep, string& first, string& second);
inline bool split_first_of(string input, string sep, string& first, string& second);
inline bool split(string input, const char sep, string& first, string& second);
inline bool split(string input, string sep, string& first, string& second, string& third);
inline bool split(string input, const char sep, string& first, string& second, string& third);
template<typename T>
bool split(string input, const char sep, int& first, T& second);
inline size_t find_char(string input, const char mark, int start, int len);
inline unsigned int fast_atou(const char* str);
inline unsigned int fast_atou(const char* str, const char* end);
inline int fast_atoi(const char *buff);
template<typename FindFunc, typename UnfindFunc>
void splits_int_double(string input, const char sep, const char inSep, FindFunc findFunc, UnfindFunc unfindFunc);
template<typename Func>
int split_enumerate(string input, const char sep, Func func);
template<typename FindFunc, typename UnfindFunc>
void splits_string_double(string input, const char sep, const char inSep, FindFunc findFunc, UnfindFunc unfindFunc);
template<typename FindFunc>
void splits_int_double(string input, const char sep, const char inSep, FindFunc findFunc);
template<typename T>
inline void to_vec(string input_, vector<T>& ovec, string sep = ",");
inline vector<double> to_dvec(string input, const char sep);
template<typename T>
void covert_append(const vector<string>&ivec, vector<T>& ovec);
template<typename T>
void convert(const vector<string>&ivec, vector<T>& ovec);
template<typename T>
vector<string> convert(const vector<T>& ivec);
template<typename T>
int compare(T a, T b);
template<typename Vec>
void free_memory(Vec& vec);
template<typename Map>
void free_map(Map& m);
template<typename Vec>
bool generalized_same(const Vec& l, const Vec& r);
template<typename Container>
void merge(Container& dest, Container& src);
//template<typename Container>
//void append(Container& dest, Container&& src);
template<typename Container>
void append(Container& dest, Container& src);
//template<typename Container>
//void merge(Container& dest, Container&& src);
template<typename Container, typename Container2>
void merge_map(Container& dest, Container2& src);
template<typename Vec>
int non_empty_count(const Vec& vecs);
template<typename Vec>
int distinct_count_vec2d(const Vec& vecs);
template<typename Vec, typename Func>
void process_adjacent(Vec& vec, Func func);
template<typename Vec1, typename Vec2, typename Func>
void process_adjacent_when_unequal(Vec1& vec, const Vec2& conditons, Func func);
template<typename Vec1, typename Vec2, typename Func>
Vec1 filter_adjacent_when_unequal(const Vec1& vec, const Vec2& conditons, Func func);
template<typename Vec1, typename Vec2, typename Func>
void process_adjacent_when_equal(Vec1& vec, const Vec2& conditons, Func func);
template<typename Vec1, typename Vec2, typename Func>
Vec1 filter_adjacent_when_equal(const Vec1& vec, const Vec2& conditons, Func func);
template<typename Vec>
Vec to_delta_vec(const Vec& vec);
template<typename Vec, typename Vec2>
Vec to_delta_vec_when_unequal(const Vec& vec, const Vec2& vec2);
template<typename Vec>
Vec to_delta_rvec(const Vec& vec);
template<typename Vec, typename Vec2>
Vec to_delta_rvec_when_unequal(const Vec& vec, const Vec2& vec2);
template<typename Vec, typename Func>
Vec to_delta_vec(const Vec& vec, Func func);
template<typename DestVec, typename RefVec>
int max_count_by(const DestVec& uids, const RefVec& ips);
template<typename DestVec, typename RefVec>
int min_count_by(const DestVec& uids, const RefVec& ips);
template<typename Container, typename Container2>
void add_vec(Container& vec1, const Container2& vec2);
template<typename Container, typename Container2>
void vec_add(Container& vec1, const Container2& vec2);
namespace ufo
{
template<typename Container>
vector<typename Container::value_type> set_symmetric_difference(const Container& l, const Container& r);
template<typename Container>
vector<typename Container::value_type> set_difference(const Container& l, const Container& r);
template<typename Container, typename T>
void erase(Container& vec, const T& value);
template<typename Container, typename Func>
void erase_if(Container& vec, Func func);
}
template<typename T, typename U, typename Func>
vector<T> join_vec(const vector<U>& input, Func func);
template<typename T, typename U>
void print(const vector<T>& names, const vector<U>& results, string inSep = "\t", string outSep = "\n", int space = 40);
template<typename T, typename U>
void print_key_value(const T& name, const U& result, string inSep = "", string outSep = "\n", int space = 40);
template<typename T, typename U>
string print2str(const vector<T>& names, const vector<U>& results, string inSep = "", string outSep = "\n", int space = 40);
template<typename T, typename U>
string print2str_row(const vector<T>& names, const vector<U>& results, int space = 40, string inSep = ":", char outSep = ' ');
template<typename Vec>
void normalize_vec(Vec& vec);
template<typename Vec, typename T>
void reset_vec(Vec& vec, int len, T value);
//template<typename T>
//inline T* begin_ptr(vector<T>& vec);
template<typename T>
inline const T* begin_ptr(const vector<T>& vec);
inline vector<int> range_vec(size_t length);
}
#endif
