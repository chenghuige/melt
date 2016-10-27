#ifndef TOOLS_IPFINDER_H_
#define TOOLS_IPFINDER_H_
#include <string.h>
#include <string>
#include "common_util.h"
namespace gezi {
class IpFinder
{
public:
IpFinder();
IpFinder(string file);
IpFinder(const char* pszFileName);
~IpFinder();
const static int INDEX_LENGTH = 7;
const static int IP_LENGTH = 4;
const static int OFFSET_LENGTH = 3;
enum
{
REDIRECT_MODE_1 = 0x01,
REDIRECT_MODE_2 = 0x02,
};
void GetAddressByIp(unsigned long ipValue, std::string& strCountry, std::string& strLocation) const;
void GetAddressByIp(const char* pszIp, std::string& strCountry, std::string& strLocation) const;
inline void GetAddressByIp(const std::string& ip, std::string& strCountry, std::string& strLocation) const;
void GetAddressByOffset(unsigned long ulOffset, std::string& strCountry, std::string& strLocation) const;
unsigned long GetString(std::string& str, unsigned long indexStart) const;
unsigned long GetValue3(unsigned long indexStart) const;
unsigned long GetValue4(unsigned long indexStart) const;
unsigned long IpString2IpValue(const char *pszIp) const;
void IpValue2IpString(unsigned long ipValue, char* pszIpAddress, int nMaxCount) const;
bool IsRightIpString(const char* pszIp) const;
unsigned long OutputData(const char* pszFileName, unsigned long indexStart = 0, unsigned long indexEnd = 0) const;
unsigned long OutputDataByIp(const char* pszFileName, unsigned long ipValueStart, unsigned long ipValueEnd) const;
unsigned long OutputDataByIp(const char* pszFileName, const char* pszStartIp, const char* pszEndIp) const;
unsigned long SearchIp(unsigned long ipValue, unsigned long indexStart = 0, unsigned long indexEnd = 0) const;
unsigned long SearchIp(const char* pszIp, unsigned long indexStart = 0, unsigned long indexEnd = 0) const;
bool Open(string file);
bool Open(const char* pszFileName);
bool Init(string file);
private:
FILE *_fpIpDataFile;
unsigned long _indexStart;
unsigned long _indexEnd;
};
}
#endif
