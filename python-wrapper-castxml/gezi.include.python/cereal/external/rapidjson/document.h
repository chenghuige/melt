#ifndef RAPIDJSON_DOCUMENT_H_
#define RAPIDJSON_DOCUMENT_H_
#include "reader.h"
#include "internal/strfunc.h"
#include <new>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4127)
#endif
namespace rapidjson {
#pragma pack (push, 4)
template <typename Encoding, typename Allocator = MemoryPoolAllocator<> >
class GenericValue
{
public:
struct Member
{
GenericValue<Encoding, Allocator> name;
GenericValue<Encoding, Allocator> value;
};
typedef Encoding EncodingType;
typedef Allocator AllocatorType;
typedef typename Encoding::Ch Ch;
typedef Member* MemberIterator;
typedef const Member* ConstMemberIterator;
typedef GenericValue* ValueIterator;
typedef const GenericValue* ConstValueIterator;
GenericValue();
private:
GenericValue(const GenericValue& rhs);
public:
GenericValue(Type type);
GenericValue(bool b) : flags_(b ? kTrueFlag;
GenericValue(int i);
GenericValue(unsigned u);
GenericValue(int64_t i64);
GenericValue(uint64_t u64);
GenericValue(double d);
GenericValue(const Ch* s, SizeType length);
GenericValue(const Ch* s);
GenericValue(const Ch* s, SizeType length, Allocator& allocator);
GenericValue(const Ch*s, Allocator& allocator);
~GenericValue();
GenericValue& operator=(GenericValue& rhs);
template <typename T>
GenericValue& operator=(T value);
Type GetType()	const;
bool IsNull_()	const;
bool IsFalse()	const;
bool IsTrue()	const;
bool IsBool_()	const;
bool IsObject()	const;
bool IsArray()	const;
bool IsNumber() const;
bool IsInt()	const;
bool IsUint()	const;
bool IsInt64()	const;
bool IsUint64()	const;
bool IsDouble() const;
bool IsString() const;
GenericValue& SetNull_();
bool GetBool_() const;
GenericValue& SetBool_(bool b);
GenericValue& SetObject();
GenericValue& operator[](const Ch* name);
const GenericValue& operator[](const Ch* name) const;
ConstMemberIterator MemberBegin() const;
ConstMemberIterator MemberEnd()	const;
MemberIterator MemberBegin();
MemberIterator MemberEnd();
bool HasMember(const Ch* name) const;
GenericValue& AddMember(GenericValue& name, GenericValue& value, Allocator& allocator);
GenericValue& AddMember(const Ch* name, Allocator& nameAllocator, GenericValue& value, Allocator& allocator);
GenericValue& AddMember(const Ch* name, GenericValue& value, Allocator& allocator);
template <typename T>
GenericValue& AddMember(const Ch* name, T value, Allocator& allocator);
bool RemoveMember(const Ch* name);
GenericValue& SetArray();
SizeType Size() const;
SizeType Capacity() const;
bool Empty() const;
void Clear();
//GenericValue& operator[](SizeType index);
const GenericValue& operator[](SizeType index) const;
ValueIterator Begin();
ValueIterator End();
ConstValueIterator Begin() const;
ConstValueIterator End() const;
GenericValue& Reserve(SizeType newCapacity, Allocator &allocator);
GenericValue& PushBack(GenericValue& value, Allocator& allocator);
template <typename T>
GenericValue& PushBack(T value, Allocator& allocator);
GenericValue& PopBack();
int GetInt() const;
unsigned GetUint() const;
int64_t GetInt64() const;
uint64_t GetUint64() const;
double GetDouble() const;
GenericValue& SetInt(int i);
GenericValue& SetUint(unsigned u);
GenericValue& SetInt64(int64_t i64);
GenericValue& SetUint64(uint64_t u64);
GenericValue& SetDouble(double d);
const Ch* GetString() const;
SizeType GetStringLength() const;
GenericValue& SetString(const Ch* s, SizeType length);
GenericValue& SetString(const Ch* s);
GenericValue& SetString(const Ch* s, SizeType length, Allocator& allocator);
GenericValue& SetString(const Ch* s, Allocator& allocator);
template <typename Handler>
const GenericValue& Accept(Handler& handler) const;
private:
friend class GenericDocument;
enum
{
kBool_Flag = 0x100,
kNumberFlag = 0x200,
kIntFlag = 0x400,
kUintFlag = 0x800,
kInt64Flag = 0x1000,
kUint64Flag = 0x2000,
kDoubleFlag = 0x4000,
kStringFlag = 0x100000,
kCopyFlag = 0x200000,
kNull_Flag = kNull_Type,
kTrueFlag = kTrueType | kBool_Flag,
kFalseFlag = kFalseType | kBool_Flag,
kNumberIntFlag = kNumberType | kNumberFlag | kIntFlag | kInt64Flag,
kNumberUintFlag = kNumberType | kNumberFlag | kUintFlag | kUint64Flag | kInt64Flag,
kNumberInt64Flag = kNumberType | kNumberFlag | kInt64Flag,
kNumberUint64Flag = kNumberType | kNumberFlag | kUint64Flag,
kNumberDoubleFlag = kNumberType | kNumberFlag | kDoubleFlag,
kConstStringFlag = kStringType | kStringFlag,
kCopyStringFlag = kStringType | kStringFlag | kCopyFlag,
kObjectFlag = kObjectType,
kArrayFlag = kArrayType,
kTypeMask = 0xFF
};
static const SizeType kDefaultArrayCapacity = 16;
static const SizeType kDefaultObjectCapacity = 16;
struct String
{
const Ch* str;
SizeType length;
unsigned hashcode;
};
union Number
{
#if RAPIDJSON_ENDIAN == RAPIDJSON_LITTLEENDIAN
struct I
{
int i;
char padding[4];
}
i;
struct U
{
unsigned u;
char padding2[4];
}
u;
#else
struct I
{
char padding[4];
int i;
}
i;
struct U
{
char padding2[4];
unsigned u;
}
u;
#endif
int64_t i64;
uint64_t u64;
double d;
};
struct Object
{
Member* members;
SizeType size;
SizeType capacity;
};
struct Array
{
GenericValue<Encoding, Allocator>* elements;
SizeType size;
SizeType capacity;
};
union Data
{
String s;
Number n;
Object o;
Array a;
};
Member* FindMember(const Ch* name);
const Member* FindMember(const Ch* name) const;
void SetArrayRaw(GenericValue* values, SizeType count, Allocator& alloctaor);
void SetObjectRaw(Member* members, SizeType count, Allocator& alloctaor);
void SetStringRaw(const Ch* s, SizeType length);
void SetStringRaw(const Ch* s, SizeType length, Allocator& allocator);
void RawAssign(GenericValue& rhs);
Data data_;
unsigned flags_;
};
#pragma pack (pop)
typedef GenericValue<UTF8<> > Value;
template <typename Encoding, typename Allocator = MemoryPoolAllocator<> >
class GenericDocument : public GenericValue<Encoding, Allocator>
{
public:
typedef typename Encoding::Ch Ch;
typedef GenericValue<Encoding, Allocator> ValueType;
typedef Allocator AllocatorType;
GenericDocument(Allocator* allocator = 0, size_t stackCapacity = kDefaultStackCapacity);
template <unsigned parseFlags, typename Stream>
GenericDocument& ParseStream(Stream& stream);
template <unsigned parseFlags>
GenericDocument& ParseInsitu(Ch* str);
template <unsigned parseFlags>
GenericDocument& Parse(const Ch* str);
bool HasParseError() const;
const char* GetParseError() const;
size_t GetErrorOffset() const;
Allocator& GetAllocator();
size_t GetStackCapacity() const;
private:
GenericDocument& operator=(const GenericDocument&);
friend class GenericReader<Encoding, Allocator>;
void Null_();
void Bool_(bool b);
void Int(int i);
void Uint(unsigned i);
void Int64(int64_t i);
void Uint64(uint64_t i);
void Double(double d);
void String(const Ch* str, SizeType length, bool copy);
void StartObject();
void EndObject(SizeType memberCount);
void StartArray();
void EndArray(SizeType elementCount);
void ClearStack();
static const size_t kDefaultStackCapacity = 1024;
internal::Stack<Allocator> stack_;
const char* parseError_;
size_t errorOffset_;
};
typedef GenericDocument<UTF8<> > Document;
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif
