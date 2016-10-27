#ifndef REGEXREPLACEPROCESSOR_H_
#define REGEXREPLACEPROCESSOR_H_
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <boost/regex.hpp>
#include "IProcessor.h"
#include "log_util.h"
#include "string_util.h"
namespace gezi
{
using namespace std;
class RegexReplaceProcessor : public IStringProcessor
{
public:
RegexReplaceProcessor();
virtual ~RegexReplaceProcessor();
void add(string pattern, bool icase = true);
void add(const wstring& pattern, bool icase = true);
bool init(const char* file, bool icase = true);
bool init2(const char* file, bool icase = true);
bool init(string file, bool icase = true);
bool init2(string file, bool icase = true);
virtual string process(const string & src);
wstring process(const wstring & src);
void set_replacer(string replacer);
void set_replacer(const wstring& wreplacer);
private:
string replacer_;
wstring wreplacer_;
vector<boost::regex> reg_list_;
vector<boost::wregex> wreg_list_;
};
}
#endif
