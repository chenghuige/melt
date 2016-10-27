#ifndef RAPIDJSON_PRETTYWRITER_H_
#define RAPIDJSON_PRETTYWRITER_H_
#include "writer.h"
namespace rapidjson {
template<typename Stream, typename Encoding = UTF8<>, typename Allocator = MemoryPoolAllocator<> >
class PrettyWriter : public Writer<Stream, Encoding, Allocator>
{
public:
typedef Writer<Stream, Encoding, Allocator> Base;
typedef typename Base::Ch Ch;
PrettyWriter(Stream& stream, int precision = 20, Allocator* allocator = 0, size_t levelDepth = Base::kDefaultLevelDepth);
PrettyWriter& SetIndent(Ch indentChar, unsigned indentCharCount);
PrettyWriter& Null_();
PrettyWriter& Bool_(bool b);
PrettyWriter& Int(int i);
PrettyWriter& Uint(unsigned u);
PrettyWriter& Int64(int64_t i64);
PrettyWriter& Uint64(uint64_t u64);
PrettyWriter& Double(double d);
PrettyWriter& String(const Ch* str, SizeType length, bool copy = false);
PrettyWriter& StartObject();
PrettyWriter& EndObject(SizeType memberCount = 0);
PrettyWriter& StartArray();
PrettyWriter& EndArray(SizeType memberCount = 0);
PrettyWriter& String(const Ch* str);
protected:
void PrettyPrefix(Type type);
void WriteIndent();
Ch indentChar_;
unsigned indentCharCount_;
};
}
#endif
