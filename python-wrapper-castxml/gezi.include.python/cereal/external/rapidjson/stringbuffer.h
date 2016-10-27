#ifndef RAPIDJSON_STRINGBUFFER_H_
#define RAPIDJSON_STRINGBUFFER_H_
#include "rapidjson.h"
#include "internal/stack.h"
namespace rapidjson {
template <typename Encoding, typename Allocator = CrtAllocator>
struct GenericStringBuffer
{
typedef typename Encoding::Ch Ch;
GenericStringBuffer(Allocator* allocator = 0, size_t capacity = kDefaultCapacity);
void Put(Ch c);
void Clear();
const char* GetString() const;
size_t Size() const;
static const size_t kDefaultCapacity = 256;
mutable internal::Stack<Allocator> stack_;
};
typedef GenericStringBuffer<UTF8<> > StringBuffer;
template<>
inline void PutN(GenericStringBuffer<UTF8<> >& stream, char c, size_t n);
}
#endif
