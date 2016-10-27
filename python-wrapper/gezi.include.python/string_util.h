#ifndef STRING_UTIL_H_
#define STRING_UTIL_H_
#include <string>
#include <vector>
#include "format.h"
#ifdef WIN32
#ifndef NO_BAIDU_DEP
#define NO_BAIDU_DEP
#endif
#else
#include <iconv.h>
#endif
#ifndef NO_BAIDU_DEP
#include "chinese.h"
#include "encoding_convert.h"
#endif
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/remove_if.hpp>
#include "wstring_util.h"
#include "common_def.h"
#include "reg_util.h"
#include "stl_util.h"
namespace gezi {
static const int kSmallStringLength = 1024;
inline bool is_gb2312(unsigned char ch1, unsigned char ch2);
inline bool is_gbk_ch(unsigned char ch1, unsigned char ch2);
inline bool is_gbk_ch(string phrase);
inline bool all_en(string phrase);
inline bool is_en_dominate(string phrase, int var = 3);
inline string extract_gbk_dual(string temp);
inline string extract_suspect_symb(string temp);
inline string filter_str(string temp, bool withSpace = false);
inline string normalize_str(string input, bool withSpace = false);
inline string extract_chinese(string temp);
inline string remove_space_cn(string phrase);
inline string remove_space_cnonly(string phrase);
inline int wchar_count(const char* buf, int len);
inline int word_count(string phrase);
inline vector<int> unicode_index(string input);
inline string remove_dupspace(string input);
inline string replace_special_whitespace(string s, const char rep = ' ');
template<typename String>
inline vector<String> cut_wstring(const String & s, int unit, int max_len = 0);
inline string str_replace_all(string tstr, string old_value, string new_value);
inline string replace(string input, char a, char b);
inline bool is_alpha_only(string input);
inline string gbk_substr(string input, int start_, size_t len = string::npos);
inline bool startswith(string input, string part);
inline bool startswith(string input, char part);
inline bool endswith(string input, string part);
inline bool contains(string input, char part);
inline bool contains(string input, string part);
inline string max(string input, int length);
inline string first(string input, int length);
inline string last(string input, int length);
inline string erase(string content, string chars);
inline string erase_chars(string content, string chars);
inline string replace_chars(string content, string chars, char dest);
inline string erase_from(string content, string part);
inline vector<string> to_cnvec(string line);
inline string conf_trim(string input);
inline void normalize_feature_str(string& feature_str);
inline vector<string> get_words(const vector<string>& l, int ngram = 3, string sep = "\x01");
inline void get_skipn_bigram(const svec& l, svec& li, int n, string sep = "\x01");
inline void get_skip_bigram(const svec& l, svec& li, int n, string sep = "\x01");
inline bool json_empty(string value);
template<typename Func>
void gbk_foreach(string input, Func func);
template<typename Func>
void gbk_foreach_dual(string input, Func func);
template<typename Func>
void gbk_dual_foreach(string input, Func func);
template<typename Func>
void gbk_foreach_single(string input, Func func);
inline string GetOutputFileNameWithSuffix(string infile, string suffix, bool removeTxt = false);
inline string pad_right(string input, int count);
inline string arg(string input);
}
#endif
