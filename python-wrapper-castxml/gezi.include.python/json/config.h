#ifndef JSON_CONFIG_H_INCLUDED
# define JSON_CONFIG_H_INCLUDED
# define JSON_USE_EXCEPTION 1
# ifdef JSON_IN_CPPTL
#  include <cpptl/config.h>
#  ifndef JSON_USE_CPPTL
#   define JSON_USE_CPPTL 1
#  endif
# endif
# ifdef JSON_IN_CPPTL
#  define JSON_API CPPTL_API
# elif defined(JSON_DLL_BUILD)
#  define JSON_API __declspec(dllexport)
# elif defined(JSON_DLL)
#  define JSON_API __declspec(dllimport)
# else
#  define JSON_API
# endif
#if defined(_MSC_VER)  &&  _MSC_VER <= 1200
#define JSON_USE_INT64_DOUBLE_CONVERSION 1
#endif
#if defined(_MSC_VER)  &&  _MSC_VER >= 1500
# define JSONCPP_DEPRECATED(message) __declspec(deprecated(message))
#endif
#if !defined(JSONCPP_DEPRECATED)
# define JSONCPP_DEPRECATED(message)
#endif
namespace Json {
typedef int Int;
typedef unsigned int UInt;
# if defined(JSON_NO_INT64)
typedef int LargestInt;
typedef unsigned int LargestUInt;
#  undef JSON_HAS_INT64
# else
#  if defined(_MSC_VER)
typedef __int64 Int64;
typedef unsigned __int64 UInt64;
#  else
typedef long long int Int64;
typedef unsigned long long int UInt64;
#  endif
typedef Int64 LargestInt;
typedef UInt64 LargestUInt;
#  define JSON_HAS_INT64
# endif
}
#endif
