#ifndef WSTRING_UTIL_H_
#define WSTRING_UTIL_H_
#include "string_def.h"
#include "vector_def.h"
#include "encoding_def.h"
#include "common_define.h"
#if IS_HIGH_COMPILER
#include <boost/locale.hpp>
#endif
namespace gezi
{
#ifdef GEZI_UTF8_AS_DEFAULT_ENCODING
inline void setlocale();
#else
inline void setlocale();
#endif
inline void setlocale_gbk();
inline void setlocale_utf8();
inline wstring str_to_wstr(const char* pc, int len);
inline wstring str_to_wstr(string src);
inline wstring to_wstr(string src);
#ifndef GCCXML
inline string wstr_to_str(const wchar_t *pw, int len);
#endif
inline string wstr_to_str(const wstring& src);
inline string to_str(const wstring& src);
inline wstring str2wstr(string src);
inline string wstr2str(const wstring& src);
inline string encode(const wstring& src);
inline wstring wstr(string src);
inline wstring decode(string src);
#if IS_HIGH_COMPILER
inline string wstr2str(const wstring& src, EncodingType encodingType);
inline wstring wstr(string src, EncodingType encodingType);
inline wstring wstr_replace_all(const wstring& tstr, const wstring& old_value, const wstring& new_value);
#endif
}
#endif
