#ifndef RAPIDJSON_GENERICSTREAM_H_
#define RAPIDJSON_GENERICSTREAM_H_
#include "rapidjson.h"
#include <iostream>
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4127)
#pragma warning(disable: 4512)
#pragma warning(disable: 4100)
#endif
namespace rapidjson {
class GenericReadStream
{
public:
typedef char Ch;
GenericReadStream(std::istream & is);
Ch Peek() const;
Ch Take();
size_t Tell() const;
void Put(Ch);
void Flush();
Ch* PutBegin();
size_t PutEnd(Ch*);
std::istream * is_;
};
class GenericWriteStream
{
public:
typedef char Ch;
//GenericWriteStream(std::ostream& os);
void Put(char c);
void PutN(char c, size_t n);
void Flush();
size_t Tell() const;
char Peek() const;
char Take();
char* PutBegin();
size_t PutEnd(char*);
private:
std::ostream& os_;
};
template<>
inline void PutN(GenericWriteStream& stream, char c, size_t n);
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif
