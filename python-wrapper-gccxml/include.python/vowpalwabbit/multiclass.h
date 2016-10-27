#pragma once
#include "io_buf.h"
#include "parse_primitives.h"
#include "example.h"
namespace MULTICLASS
{
struct multiclass
{
uint32_t label;
float weight;
uint32_t prediction;
};
//extern label_parser mc_label;
void output_example(vw& all, example& ec);
inline int label_is_test(multiclass* ld);
inline int example_is_test(example* ec);
inline uint32_t get_example_label(example* ec);
}
