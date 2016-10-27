#pragma once
#include <math.h>
#include "example.h"
#include "parse_regressor.h"
#include "parser.h"
#include "gd.h"
namespace GDMF{
LEARNER::learner* setup(vw& all, po::variables_map& vm);
}
