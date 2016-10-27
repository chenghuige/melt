#ifndef GEZI_FLOATING_POINT_H_
#define GEZI_FLOATING_POINT_H_
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdexcept>
#include <ctype.h>
#include <float.h>
#include <string.h>
#include <iomanip>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>
#ifdef Max
#undef  Max
#endif
#ifdef Min
#undef Min
#endif
namespace gezi {
template <size_t size>
class TypeWithSize
{
public:
typedef void UInt;
};
template <>
class TypeWithSize<4>
{
public:
typedef int Int;
typedef unsigned int UInt;
};
template <>
class TypeWithSize<8>
{
public:
typedef long long Int;
typedef unsigned long long UInt;
};
template <typename RawType>
class FloatingPoint
{
public:
typedef typename TypeWithSize<sizeof(RawType)>::UInt Bits;
static const size_t kBitCount = 8 * sizeof(RawType);
static const size_t kFractionBitCount =
std::numeric_limits<RawType>::digits - 1;
static const size_t kExponentBitCount = kBitCount - 1 - kFractionBitCount;
static const Bits kSignBitMask = static_cast<Bits>(1) << (kBitCount - 1);
static const Bits kFractionBitMask =
~static_cast<Bits>(0) >> (kExponentBitCount + 1);
static const Bits kExponentBitMask = ~(kSignBitMask | kFractionBitMask);
static const size_t kMaxUlps = 4;
explicit FloatingPoint(const RawType& x);
static RawType ReinterpretBits(const Bits bits);
static RawType Infinity();
static RawType Max();
const Bits &bits() const;
Bits exponent_bits() const;
Bits fraction_bits() const;
Bits sign_bit() const;
bool is_nan() const;
bool AlmostEquals(const FloatingPoint& rhs) const;
private:
union FloatingPointUnion
{
RawType value_;
Bits bits_;
};
static Bits SignAndMagnitudeToBiased(const Bits &sam);
static Bits DistanceBetweenSignAndMagnitudeNumbers(const Bits &sam1,
const Bits &sam2);
FloatingPointUnion u_;
};
template <>
inline float FloatingPoint<float>::Max();
template <>
inline double FloatingPoint<double>::Max();
typedef FloatingPoint<float> float_;
typedef FloatingPoint<double> double_;
}
#endif
