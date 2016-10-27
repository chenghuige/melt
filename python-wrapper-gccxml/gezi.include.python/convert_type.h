#ifndef CONVERT_TYPE_H_
#define CONVERT_TYPE_H_
#include "format.h"
#include <sstream>
#include <string>
#include <boost/lexical_cast.hpp>
#define TO_UINT boost::lexical_cast<unsigned int>
#define TO_INT64 boost::lexical_cast<long long>
#define TO_UINT64 boost::lexical_cast<unsigned long long>
#define TO_BOOL boost::lexical_cast<bool>
#define TO_FLOAT boost::lexical_cast<float>
#undef  TO_STR
#define TO_STR boost::lexical_cast<std::string>
#define UINT boost::lexical_cast<unsigned int>
#define INT64 boost::lexical_cast<long long>
#define UINT64 boost::lexical_cast<unsigned long long>
#define FLOAT_ boost::lexical_cast<Float>
#undef BOOL
#define BOOL boost::lexical_cast<bool>
#undef FLOAT
#define FLOAT boost::lexical_cast<float>
#undef INT
#undef  DOUBLE
#undef  STRING
#define STRING boost::lexical_cast<std::string>
#include "common_define.h"
#undef  STR
#if IS_HIGH_COMPILER
#define STR std::to_string
#else
#define STR boost::lexical_cast<std::string>
#endif
#define  STR_TO_INT(a) \
atoi(a.c_str())
#define STR_TO_DOUBLE(a) \
atof(a.c_str())
#define  TO_INT(a) \
atoi(a.c_str())
#define TO_DOUBLE(a) \
atof(a.c_str())
#define  ATOI(a) \
atoi(a.c_str())
#define ATOF(a) \
atof(a.c_str())
#define  INT_PARSE(a) \
atoi(a.c_str())
#define DOUBLE_PARSE(a) \
atof(a.c_str())
#define  INT(a) \
atoi(a.c_str())
#define  INT_(a) \
atoi(a)
#define DOUBLE(a) \
atof(a.c_str())
#define DOUBLE_(a) \
atof(a)
#endif
