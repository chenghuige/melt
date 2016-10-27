#ifndef RAPIDJSON_WRITER_H_
#define RAPIDJSON_WRITER_H_
#include "rapidjson.h"
#include "internal/stack.h"
#include "internal/strfunc.h"
#include <cstdio>
#include <new>
#include <limits>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4127)
#endif
namespace rapidjson {
template<typename Stream, typename Encoding = UTF8<>, typename Allocator = MemoryPoolAllocator<> >
class Writer
{
public:
typedef typename Encoding::Ch Ch;
Writer(Stream& stream, int precision = 20, Allocator* allocator = 0, size_t levelDepth = kDefaultLevelDepth);
protected:
char double_format[32];
char long_double_format[32];
public:
Writer& Null_();
Writer& Bool_(bool b);
Writer& Int(int i);
Writer& Uint(unsigned u);
Writer& Int64(int64_t i64);
Writer& Uint64(uint64_t u64);
Writer& Double(double d);
Writer& LongDouble(long double d);
Writer& LongLong(long long d);
Writer& ULongLong(unsigned long long d);
Writer& String(const Ch* str, SizeType length, bool copy = false);
Writer& StartObject();
Writer& EndObject(SizeType memberCount = 0);
Writer& StartArray();
Writer& EndArray(SizeType elementCount = 0);
Writer& String(const Ch* str);
protected:
struct Level
{
Level(bool inArray_);
bool inArray;
size_t valueCount;
};
static const size_t kDefaultLevelDepth = 32;
void WriteNull_();
void WriteBool_(bool b);
void WriteInt(int i);
void WriteUint(unsigned u);
void WriteInt64(int64_t i64);
void WriteUint64(uint64_t u64);
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
void WriteDouble(double d);
void WriteLongDouble(long double d);
void WriteLongLong(long long d);
void WriteULongLong(unsigned long long d);
void WriteString(const Ch* str, SizeType length);
void WriteStartObject();
void WriteStartArray();
void WriteEndArray();
void Prefix(Type type);
Stream& stream_;
internal::Stack<Allocator> level_stack_;
private:
Writer& operator=(const Writer& w);
};
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif
