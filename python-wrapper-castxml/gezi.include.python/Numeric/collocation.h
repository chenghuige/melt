#ifndef COLLOCATION_H_
#define COLLOCATION_H_
#include "common_util.h"
namespace gezi
{
namespace collocation
{
enum Method
{
CHI,
IG,
MI,
MI2,
PMI,
ECE,
EMI,
T_TEST,
LIR,
FREQ,
IDF,
};
}
struct ChiSquareFunc
{
Float operator()(int a, int n1, int n2, uint64 total);
};
inline Float chi_square(int a, int n1, int n2, uint64 total);
struct EchoFunc
{
Float operator()(int a, int n1, int n2, uint64 n);
};
struct PointMutualInfoFunc
{
Float operator()(int a, int n1, int n2, uint64 n);
};
inline Float point_mutual_info(int a, int n1, int n2, uint64 n);
inline Float information_gain(int nfc, int nf, int nc, uint64 n);
inline Float mutual_info(int nfc, int nf, int nc, uint64 n);
inline Float mutual_info2(int nfc, int nf, int nc, uint64 n);
inline Float cross_entropy(int nfc, int nf, int nc, uint64 n);
struct DiscountedMutualInfoFunc
{
Float operator()(int a00, int nterm1, int nterm2, unsigned long long n);
};
struct EMutualInfoFunc
{
Float operator()(int a00, int nterm1, int nterm2, unsigned long long n);
};
struct TTestFunc
{
Float operator()(int a00, int nterm1, int nterm2, unsigned long long n);
};
struct EChiSquareFunc
{
Float operator()(int a00, int nterm1, int nterm2, unsigned long long n);
};
struct LogEChiSquareFunc
{
Float operator()(int a00, int nterm1, int nterm2, unsigned long long n);
};
}
#endif
