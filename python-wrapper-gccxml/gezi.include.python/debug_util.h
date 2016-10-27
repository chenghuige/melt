#ifndef DEBUG_UTIL_H_
#define	DEBUG_UTIL_H_
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iterator>
#ifdef SIMPLE_DEBUG
#define LOG(INFO) std::cerr
#define VLOG(0) std::cerr
#define VLOG(1) std::cerr
#define VLOG(2) std::cerr
#define VLOG(3) std::cerr
#define VLOG(4) std::cerr
#define VLOG(5) std::cerr
#else
#include <glog/logging.h>
#endif
using std::ios;
using std::setprecision;
using std::setw;
#include "string_def.h"
using std::stringstream;
#define VPVAL(s, u)\
VLOG(u) << #s <<" --- [" << s << "]"
#define PVAL(s)\
VLOG(4) << setprecision(16) << #s <<" --- [" << s << "]"
#define PVAL_(s, u)\
VLOG(4) << u << " " << #s <<" --- [" << s << "]"
#define Pval(s)\
VLOG(0) << setprecision(16) << #s << " --- [" << s << "]"
#define Pval_1(s)\
VLOG(1) << #s << " --- [" << s << "]"
#define Pval_2(s)\
VLOG(2) << #s << " --- [" << s << "]"
#define Pval_(s, u)\
VLOG(0)  << u << " " << #s <<" --- [" << s << "]"
#define PVAL2(a, b)\
VLOG(4) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "]"
#define Pval2(a, b)\
VLOG(0) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "]"
#define Pval2_2(a, b)\
VLOG(2) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "]"
#define Pval2_4(a, b)\
VLOG(4) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "]"
#define Pval2_1(a, b)\
VLOG(1) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "]"
#define PVAL3(a, b, c)\
VLOG(4) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "]"
#define Pval3(a, b, c)\
VLOG(0) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "]"
#define Pval3_2(a, b, c)\
VLOG(2) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "]"
#define PVAL4(a, b, c, d)\
VLOG(4) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "] " << #d <<" -- [" << d << "]"
#define Pval4(a, b, c, d)\
VLOG(0) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "] " << #d <<" -- [" << d << "]"
#define Pval4_2(a, b, c, d)\
VLOG(2) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "] " << #d <<" -- [" << d << "]"
#define PVAL5(a, b, c, d, e)\
VLOG(4) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "] " << #d <<" -- [" << d << "] " << #e <<" -- [" << e << "]"
#define Pval5(a, b, c, d, e)\
VLOG(0) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "] " << #d <<" -- [" << d << "] " << #e <<" -- [" << e << "]"
#define Pval6(a, b, c, d, e, f)\
VLOG(0) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "] " << #d <<" -- [" << d << "] " << #e <<" -- [" << e << "] " <<  #f <<" -- [" << f << "]"
#define PVAL6(a, b, c, d, e, f)\
VLOG(4) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "] " << #d <<" -- [" << d << "] " << #e <<" -- [" << e << "] " <<  #f <<" -- [" << f << "]"
#define Pval7(a, b, c, d, e, f, g)\
VLOG(0) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "] " << #d <<" -- [" << d << "] " << #e <<" -- [" << e << "] " <<  #f <<" -- [" << f << "] " <<  #g <<" -- [" << g << "]";
#define Pval8(a, b, c, d, e, f, g, h)\
VLOG(0) << #a <<" -- [" << a << "] " << #b <<" -- [" << b << "] "  << #c <<" -- [" << c << "] " << #d <<" -- [" << d << "] " << #e <<" -- [" << e << "] " <<  #f <<" -- [" << f << "] " <<  #g <<" -- [" << g << "] " << #h << " -- [" << h << "]";
#define Log7(a, b, c, d, e, f, g)\
VLOG(0) << #a <<":" << a << "\t" << #b << ":" << b << "\t"  << #c << ":" << c << "\t" << #d <<":" << d << "\t" << #e <<":" << e << "\t" <<  #f << ":" << f << "\t" <<  #g << ":" << g;
#define Log8(a, b, c, d, e, f, g, h)\
VLOG(0) << #a <<":" << a << "\t" << #b << ":" << b << "\t"  << #c << ":" << c << "\t" << #d <<":" << d << "\t" << #e <<":" << e << "\t" <<  #f << ":" << f << "\t" <<  #g << ":" << g << "\t" << #h << ":" << h;
#define Log9(a, b, c, d, e, f, g, h, i)\
VLOG(0) << #a <<":" << a << "\t" << #b << ":" << b << "\t"  << #c << ":" << c << "\t" << #d <<":" << d << "\t" << #e <<":" << e << "\t" <<  #f << ":" << f << "\t" <<  #g << ":" << g << "\t" << #h << ":" << h << "\t" << #i << ":" << i;
#define Log10(a, b, c, d, e, f, g, h, i, j)\
VLOG(0) << #a <<":" << a << "\t" << #b << ":" << b << "\t"  << #c << ":" << c << "\t" << #d <<":" << d << "\t" << #e <<":" << e << "\t" <<  #f << ":" << f << "\t" <<  #g << ":" << g << "\t" << #h << ":" << h << "\t" << #i << ":" << i << "\t" << #j << ":" << j;
#define PvalFile(s, ofs)\
ofs << #s <<" --- " << s << endl
//template<typename T>
//void Pvec_(const T&vec, std::ostream& out = std::cout, string sep = "\n", string last = "\n");
template<typename T>
void PrintPairVec(const T&vec, int level = 0, string sep = "\n", string last = "\n");
//template<typename T>
//void Pvec2_(const T&vec, std::ostream& out = std::cout, string sep = "\n", string last = "\n");
//template<typename Iter>
//void Prange2(Iter begin, Iter end, std::ostream& out = std::cout, string sep = "\n", string last = "\n");
//template<typename Iter>
//void Prange(Iter begin, Iter end, std::ostream& out = std::cout, string sep = "\n", string last = "\n");
//template<typename T>
//void PVec(const T&vec, std::ostream& out = std::cout, string sep = "\n", string last = "\n");
template<typename T>
void LOGVec(const T&vec, int level = 0, string sep = " ", string last = "\n");
//template<typename Iter>
//void PRange(Iter begin, Iter end, std::ostream& out = std::cout, string sep = "\n", string last = "\n");
template<typename Iter>
void LOGRange(Iter begin, Iter end, int level = 5);
#define PVEC(v)\
{\
stringstream ss;\
ss << #v << ":";\
for (size_t i_ = 0; i_ < v.size(); i_++)\
{\
if (v.size() > 6)\
{\
ss << i_ << ":";\
}\
ss << v[i_] << " ";\
}\
VLOG(5) << ss.str();\
}
#define Pvec(v)\
{\
stringstream ss;\
ss << #v << ":";\
for (size_t i_ = 0; i_ < v.size(); i_++)\
{\
if (v.size() > 6)\
{\
ss << i_ << ":"; \
}\
ss << v[i_] << " ";\
}\
VLOG(0) << ss.str();\
}
#define PVECTOR(v)\
VLOG(5) << #v <<" --- " << v.size();\
for (size_t i_ = 0; i_ < v.size(); i_++)\
{\
VLOG(5) << setiosflags(ios::left) << setfill(' ') << setw(10) << i_ << v[i_];\
}
#define PVEC_TOPN(v, n)\
VLOG(5) << #v <<" --- " << v.size();\
for (size_t i_ = 0; i_ < v.size() && i_ < n; i_++)\
{\
VLOG(5) << setiosflags(ios::left) << setfill(' ') << setw(10) << i_ << v[i_];\
}
#define Pvector(v)\
VLOG(0) << #v <<" --- " << v.size();\
for (size_t i_ = 0; i_ < v.size(); i_++)\
{\
VLOG(0) << setiosflags(ios::left) << setfill(' ') << setw(10) << i_ << v[i_];\
}
#define PRANGE(s, e)\
VLOG(5) << #s <<" ---";\
PRange(s, e)
//template<typename T>
//void WPvec(const T&vec, std::wostream& out = std::wcout, const wstring& end = L" ", const wstring& last = L"\n");
#define PrintVec(vec, arg1) \
VLOG(5) << #vec <<" --- " << vec.size();\
for (size_t i_ = 0; i_ < vec.size(); i_++) \
{  \
VLOG(5) << setiosflags(ios::left) << setfill(' ') << setw(4) << i_ << vec[i_].arg1; \
}
#define PrintVecTopN(vec, arg1, n) \
for (size_t i = 0; i < n; i++) \
{  \
VLOG(5) << setiosflags(ios::left) << setfill(' ') << setw(10) << i << vec[i].arg1; \
}
#define PrintVec2TopN(vec, arg1, arg2, n) \
for (size_t i = 0; i < n; i++) \
{  \
VLOG(5) << setiosflags(ios::left) << setfill(' ') << setw(10) << vec[i].arg1 << " " \
<< vec[i].arg2; \
}
#define PrintVec3TopN(vec, arg1, arg2, arg3, n) \
for (size_t i = 0; i < n; i++) \
{  \
VLOG(5) << setiosflags(ios::left) << setfill(' ') << setw(10) << vec[i].arg1 << " " \
<< vec[i].arg2 << " " << vec[i].arg3; \
}
#define PrintVec2(vec, arg1, arg2) \
VLOG(5) << #vec <<" --- " << vec.size();\
for (size_t i_ = 0; i_ < vec.size(); i_++) \
{  \
VLOG(5) << setiosflags(ios::left) << setfill(' ') << setw(10) << i_ << vec[i_].arg1 << " " \
<< vec[i_].arg2; \
}
#define PrintVec_(vec, arg1, file) \
std::ofstream out##file(#file); \
for (size_t i = 0; i < vec.size(); i++) \
{  \
out##file << setiosflags(ios::left) << setw(10) << vec[i].arg1; \
out##file << std::endl; \
}\
out##file << std::endl; \
out##file.close()
#define PrintVec2_(vec, arg1, arg2, file) \
std::ofstream out##file(#file); \
for (size_t i = 0; i < vec.size(); i++) \
{  \
out##file << setiosflags(ios::left) << setw(10) << vec[i].arg1 << " " \
<< vec[i].arg2; \
out##file << std::endl; \
}\
out##file << std::endl; \
out##file.close()
#define PrintVec3(vec, arg1, arg2, arg3) \
VLOG(5) << #vec <<" --- " << vec.size();\
for (size_t i = 0; i < vec.size(); i++) \
{  \
VLOG(5) << setiosflags(ios::left) << setfill(' ') << setw(10) << i << vec[i].arg1 << " " \
<< vec[i].arg2 << " " << vec[i].arg3; \
}
#define PrintVec4(vec, arg1, arg2, arg3, arg4) \
VLOG(5) << #vec <<" --- " << vec.size();\
for (size_t i = 0; i < vec.size(); i++) \
{  \
VLOG(5) << setiosflags(ios::left) << setfill(' ') << setw(10) << i << vec[i].arg1 << " " \
<< vec[i].arg2 << " " << vec[i].arg3 << " " << vec[i].arg4; \
}
#define PrintVec3_(vec, arg1, arg2, arg3, file) \
std::ofstream out##file(#file); \
for (size_t i = 0; i < vec.size(); i++) \
{  \
out##file << setiosflags(ios::left) << setw(10) << vec[i].arg1 << " " \
<< vec[i].arg2 << " " << vec[i].arg3; \
out##file << std::endl; \
}\
out##file << std::endl; \
out##file.close()
#define PrintVecAdd2(vec, arg1, arg2) \
for (size_t i = 0; i < vec.size(); i++) \
{  \
out << setiosflags(ios::left) << setw(10) << vec[i].arg1 << " " \
<< vec[i].arg2; \
out << std::endl; \
}
#define PrintVecFunc(vec, arg1, func1, file) \
std::ofstream out##file(#file); \
for (size_t i = 0; i < vec.size(); i++) \
{  \
out##file << setiosflags(ios::left) << setw(40) << func1(vec[i].arg1); \
out##file << std::endl; \
}\
out##file << std::endl; \
out##file.close()
#define PrintVecFunc2(vec, arg1, func1, arg2, func2, file) \
std::ofstream out##file(#file); \
for (size_t i = 0; i < vec.size(); i++) \
{  \
out##file << setiosflags(ios::left) << setw(40) << func1(vec[i].arg1) << " " << func2(vec[i].arg2); \
out##file << std::endl; \
}\
out##file << std::endl; \
out##file.close()
#define PrintRange(begin, end, arg1, file) \
std::ofstream out##file(#file); \
while(begin != end) \
{  \
out##file << setiosflags(ios::left) << setw(10) << (*begin).arg1; \
out##file << std::endl; \
++begin; \
}\
out##file << std::endl; \
out##file.close()
#define PrintRange2(begin, end, arg1, arg2, file) \
std::ofstream out##file(#file); \
while(begin != end) \
{  \
out##file << setiosflags(ios::left) << setw(10) << (*begin).arg1 << " " << (*begin).arg2; \
out##file << std::endl; \
++begin; \
}\
out##file << std::endl; \
out##file.close()
#define printRange2(begin, end, arg1, arg2, file) \
while(begin != end) \
{  \
out << setiosflags(ios::left) << setw(10) << (*begin).arg1 << " " << (*begin).arg2; \
out << std::endl; \
++begin; \
}\
out << std::endl; \
out.close()
#define printRangeFunc2(begin, end, arg1, func1, arg2, func2, file) \
while(begin != end) \
{  \
out << setiosflags(ios::left) << setw(10) << func1((*begin).arg1) << " " << func2((*begin).arg2); \
out << std::endl; \
++begin; \
}\
out << std::endl; \
out.close()
#endif
