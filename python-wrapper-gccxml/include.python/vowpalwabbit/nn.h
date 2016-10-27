#pragma once
#include "global_data.h"
#include "parse_args.h"
namespace NN
{
LEARNER::learner* setup(vw& all, po::variables_map& vm);
}
