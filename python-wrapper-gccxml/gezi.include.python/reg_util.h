#ifndef REG_UTIL_H_
#define REG_UTIL_H_
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>
using boost::regex;
using boost::algorithm::split_regex;
#include "vector_def.h"
#include "string_def.h"
namespace gezi
{
inline string reg_search(const string& content, boost::regex& reg, int index = 1);
inline void reg_search(const string& content, boost::regex& reg, vector<string>& result, int index = 1);
inline wstring reg_search(const wstring& content, boost::wregex& reg, int index = 1);
inline void reg_search(const wstring& content, boost::wregex& reg, vector<wstring>& result, int index = 1);
inline bool reg_find(const string& content, string pattern);
inline string reg_search(const string& content, string pattern, int index = 1);
inline void reg_search(const string& content, string pattern, vector<string>& result, int index = 1);
inline wstring reg_search(const wstring& content, wstring pattern, int index = 1);
inline void reg_search(const wstring& content, wstring pattern, vector<wstring>& result, int index = 1);
inline string reg_replace(const string& input, string pattern, string replacement = "");
inline wstring reg_replace(const wstring& input, wstring pattern, wstring replacement = L"");
inline string reg_remove(const string& input, string pattern);
inline wstring reg_remove(const wstring& input, wstring pattern);
inline vector<string> reg_split(const string& input, string pattern);
inline vector<wstring> reg_split(const wstring& input, wstring pattern);
namespace ufo
{
inline vector<string> split_regex(const string& input, string pattern);
inline vector<string> reg_search(const string& content, boost::regex& reg, int index = 1);
inline vector<string> reg_search(const string& content, string pattern, int index = 1);
inline vector<wstring> reg_search(const wstring& content, boost::wregex& reg, int index = 1);
inline vector<wstring> wreg_search(const wstring& content, wstring pattern, int index = 1);
}
}
#endif
