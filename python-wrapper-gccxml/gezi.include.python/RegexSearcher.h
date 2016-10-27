#ifndef REGEX_SEARCHER_H_
#define REGEX_SEARCHER_H_
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <boost/regex.hpp>
namespace gezi
{
using namespace std;
class RegexSearcher
{
public:
void add(string pattern, bool icase = true);
template<typename Vec>
void add(const Vec& patterns, bool icase = true);
void add(const wstring& pattern, bool icase = true);
bool init(const char* file, bool icase = true);
bool init2(const char* file, bool icase = true);
bool init(string file, bool icase = true);
bool init2(string file, bool icase = true);
bool Load(string file, bool icase = true);
int count(const string & src);
bool has_match(string src);
int count(const wstring & src);
bool has_match(const wstring& src);
int sreg_count();
int wreg_count();
int reg_count();
private:
vector<boost::regex> reg_list_;
vector<boost::wregex> wreg_list_;
};
}
#endif
