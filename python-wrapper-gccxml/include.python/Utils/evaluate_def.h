#ifndef UTILS_EVALUATE_DEF_H_
#define UTILS_EVALUATE_DEF_H_
#include <limits>
#include "common_def.h"
namespace gezi {
namespace evaluate
{
struct Node
{
Float label;
Float prediction;
Float weight;
Node();
Node(Float label_, Float prediction_, Float weight_ = 1.0);
};
struct Instance
{
Float label;
Float weight;
Instance();
Instance(Float label_, Float weight_ = 1.0);
};
}
typedef evaluate::Node EvaluateNode;
typedef evaluate::Instance EvaluateInstance;
typedef EvaluateInstance IsEvaluateAble;
typedef shared_ptr<EvaluateInstance> EvaluateInstancePtr;
}
#endif
