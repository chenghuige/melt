#ifndef ENCODING_CONVERT_H_
#define	ENCODING_CONVERT_H_
#include <string>
#include <vector>
#include "string_def.h"
#include "encoding_def.h"
#include "uconv.h"
namespace gezi {
inline string gbk_to_utf8(string src, int flags = UCONV_INVCHAR_IGNORE);
inline string utf8_to_gbk(string src, int flags = UCONV_INVCHAR_IGNORE);
inline string gbk2utf8(string src, int flags = UCONV_INVCHAR_IGNORE);
inline string utf82gbk(string src, int flags = UCONV_INVCHAR_IGNORE);
inline string to_gbk(string src, int flags = UCONV_INVCHAR_IGNORE);
inline string to_utf8(string src, int flags = UCONV_INVCHAR_IGNORE);
}
#undef uint16_t
#undef uint8_t
#undef uint32_t
#include "common_define.h"
#if IS_HIGH_COMPILER
#include <boost/locale.hpp>
namespace gezi {
inline string convert(string src, EncodingType fromType, EncodingType toType);
inline string convert(string src, string fromType, string toType);
}
#endif
#endif
