#pragma once
#define BS_TYPE_MEAN 0
#define BS_TYPE_VOTE 1
#include "global_data.h"
namespace BS
{
LEARNER::learner* setup(vw& all, po::variables_map& vm);
void print_result(int f, float res, float weight, v_array<char> tag, float lb, float ub);
void output_example(vw& all, example* ec, float lb, float ub);
inline uint32_t weight_gen();
}
