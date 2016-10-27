#ifndef STRING2ARGCARGV_H_
#define STRING2ARGCARGV_H_
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
namespace gezi {
inline bool _isQuote(char c);
inline bool _isEscape(char c);
inline bool _isEscape(char c);
inline bool _isWhitespace(char c);
inline std::vector<std::string> _parse(const std::string& args);
inline void stringToArgcArgv(const std::string& str, int* argc, char*** argv);
inline void freeArgcArgv(int argc, char**& argv);
inline void stringToArgcArgv(const std::string& str, int* argc, char*** argv);
inline std::vector<std::string> _parse(const std::string& args);
inline bool _isQuote(char c);
inline bool _isEscape(char c);
inline bool _isWhitespace(char c);
class String2ArgcArgv
{
public:
String2ArgcArgv(const std::string& str);
~String2ArgcArgv();
int argc() const;
char** argv() const;
private:
int _argc;
char** _argv;
};
}
#endif
