#ifndef MULTIHASH_H_
#define MULTIHASH_H_
#include <cstddef>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include "common_util.h"
namespace gezi {
using namespace std;
class Hash
{
public:
static uint ComputeHash(string input, uint hash);
};
class MultiHash
{
protected:
vector<uint> _saltList;
uint SaltCount;
uint64 RandomSeed;
public:
MultiHash();
uint GetHash(string input, int index = 0);
template<typename T>
uint GetHash(T input, int index = 0);
uint ComputeHash(string input, int index = 0);
};
}
#endif
