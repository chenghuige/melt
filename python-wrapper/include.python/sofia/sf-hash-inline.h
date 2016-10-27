#ifndef SF_HASH_INLINE_H__
#define SF_HASH_INLINE_H__
#include <vector>
using std::vector;
unsigned int SfHash(int key, int mask);
unsigned int SfHash(int key_1, int key_2, int mask);
unsigned int SfHash(const vector<int>& keys, int mask);
int SfHashMask(int num_bits);
#endif
