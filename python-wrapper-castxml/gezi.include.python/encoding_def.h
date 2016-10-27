#ifndef GEZI_ENCODING_DEF_H_
#define GEZI_ENCODING_DEF_H_
#include "common_define.h"
namespace gezi {
#if IS_HIGH_COMPILER
const char* const kEncodings[];
enum  EncodingType
{
EncodingType__enum__GBK,
EncodingType__enum__UTF8,
};
#ifndef GEZI_UTF8_AS_DEFAULT_ENCODING
static const EncodingType kDefaultEncoding = EncodingType::GBK;
#else
static const EncodingType kDefaultEncoding = EncodingType::UTF8;
#endif
#endif
}
#endif
