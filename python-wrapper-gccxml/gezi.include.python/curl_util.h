#ifndef  __INCLUDE_CURLUTIL_H_
#define  __INCLUDE_CURLUTIL_H_
#include <string>
#include <iostream>
#include <curl/curl.h>
#include "common_util.h"
using namespace std;
class CurlString
{
public:
CurlString(char * str);
~CurlString();
char *str();
void free();
private:
char * _str;
};
class CurlUtil
{
public:
CurlUtil();
~CurlUtil();
void setTimeout(int timeout);
struct Chunk
{
char *memory;
size_t size;
};
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);
char* easy_escape(const char * url);
CurlString escape(string url);
CURLcode post(const char* url, char* data, string& resStr);
string get(string url);
CURLcode get(string url, string& resStr);
CURLcode get(const char* url, string&resStr);
private:
CURL* _curl;
};
inline CurlString curl_escape(string url);
#endif
