#pragma once
#include "io_buf.h"
#include "parse_primitives.h"
#include "global_data.h"
#include "example.h"
#include "parse_args.h"
#include "v_hashmap.h"
#include "simple_label.h"
namespace TOPK
{
LEARNER::learner* setup(vw& all, po::variables_map& vm);
}
