#ifndef RANDOM_UTIL_H_
#define RANDOM_UTIL_H_
#if __GNUC__ > 3
#include <random>
#else
#include <boost/random.hpp>
namespace std {
using boost::random::uniform_int_distribution;
using boost::random::uniform_real_distribution;
typedef boost::random::mt19937 default_random_engine;
}
#endif
#include "common_def.h"
namespace gezi {
inline unsigned random_seed();
typedef std::default_random_engine RandomEngine;
typedef std::uniform_int_distribution<uint32_t> UintDistribution;
inline RandomEngine random_engine(unsigned randSeed = 0, int offset = 0);
class RandomInt
{
public:
RandomInt(int max, int min = 0);
RandomInt(int max, const RandomEngine& rng, int min = 0);
int Next() const;
private:
std::uniform_int_distribution<size_t> _d;
RandomEngine _rng;
};
class RandomDouble
{
public:
RandomDouble(double lower = 0.0, double upper = 1.0);
RandomDouble(const RandomEngine& rng, double lower = 0.0, double upper = 1.0);
double Next() const;
private:
std::uniform_real_distribution<> _d;
RandomEngine _rng;
};
class Random
{
public:
Random();
Random(unsigned seed);
Random(const RandomEngine& rng);
void seed(unsigned seed_);
int Next() const;
int Next(int max) const;
int Next(int min, int max) const;
double NextDouble() const;
Float NextFloat() const;
private:
RandomEngine _rng;
};
typedef shared_ptr<Random> RandomPtr;
class RandomRange
{
public:
RandomRange(int max);
RandomRange(int max, const RandomEngine& rng);
int Next();
private:
void Init();
private:
ivec _vec;
int _end;
int _index;
RandomEngine _rng;
};
typedef shared_ptr<RandomRange> RandomRangePtr;
template<typename Vec>
void shuffle(Vec& vec, unsigned randSeed = 0);
#ifndef GCCXML
//template<typename Vec, typename Rng>
//void shuffle(Vec& vec, Rng&& rng);
//template<typename RandomAccessIterator, typename RandomNumberEngine>
//void sample(RandomAccessIterator first, RandomAccessIterator last, size_t sample_num, RandomNumberEngine&& rng);
//template<typename RandomAccessIterator, typename RandomNumberEngine>
//void sample_reverse(RandomAccessIterator first, RandomAccessIterator last, size_t sample_num, RandomNumberEngine&& rng);
//template<typename RandomAccessIterator, typename RandomNumberEngine>
//void shuffle2(RandomAccessIterator first, RandomAccessIterator last, RandomNumberEngine&& rng);
template<typename Vec>
void sample(Vec& vec, size_t maxNum, unsigned randSeed = 0);
//template<typename Vec, typename Rng>
//void sample(Vec& vec, size_t maxNum, Rng&& rng);
//template<typename Vec, typename Rng>
//void sample_reverse(Vec& vec, size_t maxNum, Rng&& rng);
template<typename Vec>
int max_pos_rand(const Vec& vec, Random& rand, double fraction);
template<typename Vec, typename CmpFunc>
int max_pos_rand(const Vec& vec, Random& rand, double fraction, CmpFunc cmp);
#endif
}
#endif
