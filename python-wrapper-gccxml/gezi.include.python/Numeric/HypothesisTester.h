#ifndef NUMERIC__HYPOTHESIS_TESTER_H_
#define NUMERIC__HYPOTHESIS_TESTER_H_
#include "statistic_util.h"
namespace gezi {
//#include <boost/math/distributions/students_t.hpp>
namespace bm = boost::math;
template<typename TestModel = bm::students_t>
class HypothesisTester
{
public:
HypothesisTester(TestModel& dist_);
ValType get_pr(ValType t, int sides = 2);
std::pair<ValType, ValType> get_bound(ValType confidence);
ValType get_upperbound(ValType confidence);
ValType get_lowerbound(ValType confidence);
public:
TestModel& dist;
};
}
#endif
