#ifndef BLOOM_FILTER_H_
#define BLOOM_FILTER_H_
#include <string>
#include <vector>
#include <fstream>
#include <cstddef>
#include <algorithm>
#include <cmath>
#include <limits>
#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS
#include "common_help.h"
#include "ul_log_help.h"
#include "debug_help.h"
class BloomFilter
{
public:
typedef unsigned int bloom_type;
public:
BloomFilter(double false_prob = 0.00001, size_t random_seed = 0);
BloomFilter(size_t elem_num, double false_prob = 0.00001, size_t random_seed = 0);
void set_max_bits_num(size_t num);
void add(const std::string& phrase);
bool has(const std::string& phrase);
int size() const;
void clear();
void save(const std::string& dir);
bool load(const std::string& dir);
bool create(const std::string& file);
private:
void generate_unique_salt();
void find_optimal_parameters();
inline bloom_type hash_ap(const unsigned char* begin, std::size_t remaining_length, bloom_type hash) const;
public:
boost::dynamic_bitset<unsigned char> _bits;
size_t _bits_num;
int _hash_num;
size_t _elem_num;
double _false_prob;
size_t _random_seed;
std::vector<bloom_type> _salt;
size_t _max_bits_num;
};
#endif
