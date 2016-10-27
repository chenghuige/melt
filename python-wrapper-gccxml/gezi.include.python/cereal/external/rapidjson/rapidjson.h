#ifndef RAPIDJSON_RAPIDJSON_H_
#define RAPIDJSON_RAPIDJSON_H_
#include <cstdlib>
#include <cstring>
#ifndef RAPIDJSON_NO_INT64DEFINE
#ifdef _MSC_VER
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <inttypes.h>
#endif
#endif
#define RAPIDJSON_LITTLEENDIAN	0
#define RAPIDJSON_BIGENDIAN		1
#ifndef RAPIDJSON_ENDIAN
#ifdef __BYTE_ORDER__
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define RAPIDJSON_ENDIAN RAPIDJSON_LITTLEENDIAN
#else
#define RAPIDJSON_ENDIAN RAPIDJSON_BIGENDIAN
#endif
#else
#define RAPIDJSON_ENDIAN RAPIDJSON_LITTLEENDIAN
#endif
#endif
#if defined(RAPIDJSON_SSE2) || defined(RAPIDJSON_SSE42)
#define RAPIDJSON_SIMD
#endif
#ifndef RAPIDJSON_NO_SIZETYPEDEFINE
namespace rapidjson {
typedef unsigned SizeType;
}
#endif
#ifndef RAPIDJSON_ASSERT
#include <cassert>
#define RAPIDJSON_ASSERT(x) assert(x)
#endif
#define RAPIDJSON_MULTILINEMACRO_BEGIN do {
#define RAPIDJSON_MULTILINEMACRO_END \
} while((void)0, 0)
namespace rapidjson {
class CrtAllocator
{
public:
static const bool kNeedFree = true;
void* Malloc(size_t size);
void* Realloc(void* originalPtr, size_t originalSize, size_t newSize);
static void Free(void *ptr);
};
template <typename BaseAllocator = CrtAllocator>
class MemoryPoolAllocator
{
public:
static const bool kNeedFree = false;
MemoryPoolAllocator(size_t chunkSize = kDefaultChunkCapacity, BaseAllocator* baseAllocator = 0);
MemoryPoolAllocator(char *buffer, size_t size, size_t chunkSize = kDefaultChunkCapacity, BaseAllocator* baseAllocator = 0);
~MemoryPoolAllocator();
void Clear();
size_t Capacity();
size_t Size();
void* Malloc(size_t size);
void* Realloc(void* originalPtr, size_t originalSize, size_t newSize);
static void Free(void *);
private:
void AddChunk(size_t capacity);
static const int kDefaultChunkCapacity = 64 * 1024;
struct ChunkHeader
{
size_t capacity;
size_t size;
ChunkHeader *next;
};
ChunkHeader *chunkHead_;
size_t chunk_capacity_;
char *userBuffer_;
BaseAllocator* baseAllocator_;
BaseAllocator* ownBaseAllocator_;
};
template<typename CharType = char>
struct UTF8
{
typedef CharType Ch;
//static Ch* Encode(Ch *buffer, unsigned codepoint);
};
template<typename CharType = wchar_t>
struct UTF16
{
typedef CharType Ch;
//static Ch* Encode(Ch* buffer, unsigned codepoint);
};
template<typename CharType = unsigned>
struct UTF32
{
typedef CharType Ch;
static Ch *Encode(Ch* buffer, unsigned codepoint);
};
template<typename Stream, typename Ch>
inline void PutN(Stream& stream, Ch c, size_t n);
template <typename Encoding>
struct GenericStringStream
{
typedef typename Encoding::Ch Ch;
GenericStringStream(const Ch *src);
Ch Peek() const;
Ch Take();
size_t Tell() const;
Ch* PutBegin();
void Put(Ch);
size_t PutEnd(Ch*);
const Ch* src_;
const Ch* head_;
};
typedef GenericStringStream<UTF8<> > StringStream;
template <typename Encoding>
struct GenericInsituStringStream
{
typedef typename Encoding::Ch Ch;
GenericInsituStringStream(Ch *src);
Ch Peek();
Ch Take();
size_t Tell();
Ch* PutBegin();
void Put(Ch c);
size_t PutEnd(Ch* begin);
Ch* src_;
Ch* dst_;
Ch* head_;
};
typedef GenericInsituStringStream<UTF8<> > InsituStringStream;
enum Type
{
kNull_Type = 0,
kFalseType = 1,
kTrueType = 2,
kObjectType = 3,
kArrayType = 4,
kStringType = 5,
kNumberType = 6,
};
}
#endif
