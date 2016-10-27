#ifndef URL_UTIL_H_
#define URL_UTIL_H_
#define _HTTP_REQ_BUF_SIZE_ 512
#define _XML_BUF_SIZE_ 100*1024
DECLARE_string(host);
enum EUrlType
{
E_URL_LINK = 0,
E_URL_SRC = 1,
E_URL_FILTED = 2
};
#include <string>
#include <iostream>
enum
{
E_URL_CHR_RESERVED = 1,
E_URL_UNSAFE = 2
};
#define URL_CHR_TEST(c, mask)   (URL_CHR_TABLE[(unsigned char)(c)] & (mask))
#define URL_RESERVED_CHAR(c)    URL_CHR_TEST(c, E_URL_CHR_RESERVED)
#define URL_UNSAFE_CHAR(c)      URL_CHR_TEST(c, E_URL_UNSAFE)
#define XNUM_TO_DIGIT(x)        ("0123456789ABCDEF"[x] + 0)
#define R   E_URL_CHR_RESERVED
#define U   E_URL_UNSAFE
#define RU  R|U
const unsigned char URL_CHR_TABLE[256];
#undef RU
#undef U
#undef R
inline string EncodeUrl(string strUrl, bool bEncodeReserved = false);
#endif
