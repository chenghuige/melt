#ifndef STATISTIC_UTIL_H_
#define STATISTIC_UTIL_H_
#if __GNUC__ > 3
#define BOOST_HAS_TR1_TUPLE 1
#include <boost/tr1/detail/config.hpp>
#undef BOOST_HAS_INCLUDE_NEXT
#endif
#include <algorithm>
#include <numeric>
#include <cmath>
#include "hashmap_util.h"
#include "common_util.h"
#include "Numeric/find_bins.h"
#include "floating_point.h"
namespace gezi {
static const Float EPSILON = (Float)1e-15;
inline bool are_same(double a, double b);
inline bool is_zero(double a);
inline double sigmoid(double score, double A = -2.0, double B = 0.0);
template<typename Iter>
typename Iter::value_type sum(Iter start, Iter end);
template<typename Container>
typename Container::value_type sum(const Container& vec);
template<typename value_type, typename Iter>
value_type sum(Iter start, Iter end);
template<typename value_type, typename Container>
value_type sum(const Container& vec);
template<typename Iter>
size_t num_zeros(Iter start, Iter end);
template<typename Container>
size_t num_zeros(const Container& vec);
template<typename Iter>
size_t num_nonzeros(Iter start, Iter end);
template<typename Container>
size_t num_nonzeros(const Container& vec);
template<typename Iter>
double mean(Iter start, Iter end);
template<typename Container>
double mean(const Container& vec);
template<typename Container>
double mean(const Container& vec, int n);
template<typename Container, typename T>
size_t first_ge(const Container& vec, T value);
template<typename Container>
size_t min_index(const Container& vec);
template<typename Container>
size_t max_index(const Container& vec);
template<typename Container, typename ValueType>
size_t find_index(const Container& vec, const ValueType& val);
template<typename Container>
void zeroset(Container& vec);
template<typename Container>
void set_zero(Container& vec);
template<typename Iter, typename Iter2>
void fill_range(Iter dest, Iter2 src, int len);
template<typename Iter, typename Iter2>
void copy_range(Iter dest, Iter2 src, int len);
struct sd_op
{
template<typename T1, typename T2 >
T1 operator()(T1 init, T2 cur);
};
template<typename Container>
double norm(const Container& values);
template<typename Container>
double sqared_norm(const Container& values);
template<typename Container>
double var(const Container& vec);
template<typename Container>
double var(const Container& vec, int n);
template<typename Iter>
double var(Iter start, Iter end);
template<typename Iter>
void mean_var(Iter start, Iter end, double& mean_, double& var_);
template<typename Container>
void mean_var(const Container& vec, double& mean_, double& var_);
template<typename Iter>
double var(Iter start, Iter end, double meanVal);
template<typename Container>
double var(const Container& vec, double meanVal);
template<typename Container>
double var(const Container& vec, double meanVal, int n);
template<typename Container>
double var_(const Container& vec);
template<typename Container>
double sd(const Container& vec);
template<typename Iter>
double sd(Iter start, Iter end);
namespace ufo {
template<typename Container>
double mean(const Container& vec, double defaultValue);
template<typename Container>
double mean(const Container& vec);
template<typename Container>
double var(const Container& vec);
template<typename Container>
double var(const Container& vec, double defaultValue, int minCount = 2);
template<typename Container>
void mean_var(const Container& vec, double& meanVal, double& varVal, int minCount = 2);
template<typename Container>
void mean_min_max(const Container& vec, double& meanVal, double& minVal, double& maxVal);
template<typename Container>
typename Container::value_type min(const Container& vec);
template<typename Container, typename T>
typename Container::value_type  min(const Container& vec, T defaultValue);
template<typename Container, typename Iter>
Iter min_element(const Container& vec);
template<typename Container>
typename Container::value_type max(const Container& vec);
template<typename Container, typename T>
typename Container::value_type  max(const Container& vec, T defaultValue);
template<typename Container>
typename Container::const_iterator max_element(const Container& vec);
template<typename Container, typename ValueType>
void fill(Container& vec, const ValueType& val);
}
namespace x2 {
inline double get_val(int n00, int n01, int n10, int n11);
inline double get_val(int n, int n00, int n01, int n10, int n11);
}
namespace student_t {
template<typename Iter>
double get_val(Iter start, Iter end, double u);
template<typename Container>
double get_val(const Container& vec, double u);
inline double get_val(int n, double e, double v, double u);
inline std::pair<double, double> get_bound(const std::pair<double, double>& bound, int n, double e, double v, double u);
inline std::pair<double, double> get_bound2(const std::pair<double, double>& bound, int n, double e, double v, double u);
}
namespace sth = student_t;
inline int bin_index(double value, int bin_num, double min = 0, double max = 1.0);
inline int bin_index(double value, const vector<double>& thres);
inline vector<int> bin_counts(const vector<double>& values, int bin_num,
double min = 0, double max = 1.0);
inline vector<double> bin_values(const vector<double>& values, int bin_num,
double min = 0, double max = 1.0);
inline vector<int> bin_counts(const vector<double>& values, const vector<double>& thres);
inline vector<double> bin_values(const vector<double>& values, const vector<double>& thres);
inline double discretize(double value, double from, double to, int bins, bool norm = true);
inline double scale_value(double value, double default_thre, double now_thre);
template<typename Iter>
inline double information(Iter begin, Iter end);
template<typename T>
inline double information(const vector<T>& vec);
template<typename KeyType>
inline double information(const map<KeyType, int>& m);
template<typename ValueType, typename Iter, typename Func>
std::size_t distinct_count(Iter begin, Iter end, Func func);
template<typename ValueType, typename Container, typename Func>
std::size_t distinct_count(Container& vec, Func func);
template<typename Iter>
std::size_t distinct_count(Iter begin, Iter end);
template<typename Container>
std::size_t distinct_count(Container& vec);
#if __GNUC__ > 3
template<typename Iter, typename Func>
std::size_t distinct_count(Iter begin, Iter end, Func func);
template<typename Container, typename Func>
std::size_t distinct_count(Container& vec, Func func);
#endif
inline double entropy(double prob, bool useLnNotLog2 = true);
inline double cross_entropy(double probTrue, double probPredicted, bool useLnNotLog2 = true);
inline double label2ProbTrueZeroIsMin(double label);
inline double label2ProbTrueZeroNotMin(double label);
inline double cross_entropy_fast(double probTrue, double probPredicted, bool useLnNotLog2 = true);
inline double cross_entropy_toleranced(double probTrue, double probPredicted, int logTolerance = 30.0, bool useLnNotLog2 = true);
namespace loss {
inline double logistic(double trueProb, double prediction, double beta = 2.0);
}
}
namespace sta = gezi;
#endif
