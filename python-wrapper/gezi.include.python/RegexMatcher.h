#ifndef REGEX_MATCHER_H_
#define REGEX_MATCHER_H_
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <boost/regex.hpp>
#include "log_util.h"
namespace gezi
{
using namespace std;
class RegexMatcher
{
public:
void add(string pattern, bool icase = true);
template<typename Container>
void add(const Container& patterns, bool icase = true);
bool init(const char* file, bool icase = true);
bool init(string file, bool icase = true);
int count(const string & src);
bool has_match(string src);
private:
vector<boost::regex>  reg_list_;
};
}
#endif
