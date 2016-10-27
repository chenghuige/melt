#ifndef RAPIDJSON_FILESTREAM_H_
#define RAPIDJSON_FILESTREAM_H_
#include <cstdio>
namespace rapidjson {
class FileStream
{
public:
typedef char Ch;
FileStream(FILE* fp);
char Peek() const;
char Take();
size_t Tell() const;
void Put(char c);
char* PutBegin();
size_t PutEnd(char*);
private:
void Read();
FILE* fp_;
char current_;
size_t count_;
};
}
#endif
