#ifndef RAPIDJSON_READER_H_
#define RAPIDJSON_READER_H_
#include "rapidjson.h"
#include "internal/pow10.h"
#include "internal/stack.h"
#include <csetjmp>
#include <limits>
#include <cmath>
#include <sstream>
#ifdef RAPIDJSON_SSE42
#include <nmmintrin.h>
#elif defined(RAPIDJSON_SSE2)
#include <emmintrin.h>
#endif
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4127)
#pragma warning(disable : 4702)
#endif
#ifndef RAPIDJSON_PARSE_ERROR
#define RAPIDJSON_PARSE_ERROR(msg, offset) \
RAPIDJSON_MULTILINEMACRO_BEGIN \
parseError_ = msg; \
errorOffset_ = offset; \
longjmp(jmpbuf_, 1); \
RAPIDJSON_MULTILINEMACRO_END
#endif
namespace rapidjson {
enum ParseFlag
{
kParseDefaultFlags = 0,
kParseInsituFlag = 1
};
template<typename Encoding = UTF8<> >
struct BaseReaderHandler
{
typedef typename Encoding::Ch Ch;
void Default();
void Null_();
void Bool_(bool);
void Int(int);
void Uint(unsigned);
void Int64(int64_t);
void Uint64(uint64_t);
void Double(double);
void String(const Ch*, SizeType, bool);
void StartObject();
void EndObject(SizeType);
void StartArray();
void EndArray(SizeType);
};
template<typename Stream>
void SkipWhitespace(Stream& stream);
#ifdef RAPIDJSON_SSE42
inline const char *SkipWhitespace_SIMD(const char* p);
#elif defined(RAPIDJSON_SSE2)
inline const char *SkipWhitespace_SIMD(const char* p);
#endif
#ifdef RAPIDJSON_SIMD
{
stream.src_;
}
{
stream.src_;
}
#endif
template <typename Encoding, typename Allocator = MemoryPoolAllocator<> >
class GenericReader
{
public:
typedef typename Encoding::Ch Ch;
GenericReader(Allocator* allocator = 0, size_t stackCapacity = kDefaultStackCapacity);
template <unsigned parseFlags, typename Stream, typename Handler>
bool Parse(Stream& stream, Handler& handler);
}
template<unsigned parseFlags, typename Stream, typename Handler>
void ParseArray(Stream& stream, Handler& handler);
template<unsigned parseFlags, typename Stream, typename Handler>
void ParseNaNNull_(Stream& stream, Handler& handler);
template<unsigned parseFlags, typename Stream, typename Handler>
void ParseInfinity(Stream& stream, Handler& handler);
template<unsigned parseFlags, typename Stream, typename Handler>
void ParseTrue(Stream& stream, Handler& handler);
template<unsigned parseFlags, typename Stream, typename Handler>
void ParseFalse(Stream& stream, Handler& handler);
template<typename Stream>
unsigned ParseHex4(Stream& stream);
#ifdef _MSC_VER
template <class Ch>
bool characterOk( Ch c );
template <>
bool characterOk<char>( char );
#else
template <class T>
static constexpr int to_int( T t );
typename std::enable_if < to_int(std::numeric_limits<Ch>::max()) < to_int(256), bool>::type
characterOk( Ch );
typename std::enable_if< to_int(std::numeric_limits<Ch>::max()) >= to_int(256), bool>::type
characterOk(Ch c);
#endif
template<unsigned parseFlags, typename Stream, typename Handler>
void ParseString(Stream& stream, Handler& handler);
template<unsigned parseFlags, typename Stream, typename Handler>
void ParseNumber(Stream& stream, Handler& handler);
template<unsigned parseFlags, typename Stream, typename Handler>
void ParseValue(Stream& stream, Handler& handler);
typedef GenericReader<UTF8<> > Reader;
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif
