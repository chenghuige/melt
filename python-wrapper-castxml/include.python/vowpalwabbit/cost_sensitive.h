#pragma once
#include "io_buf.h"
#include "parse_primitives.h"
#include "global_data.h"
#include "example.h"
#include "parser.h"
#include "parse_args.h"
namespace COST_SENSITIVE {
struct wclass
{
float x;
uint32_t class_index;
float partial_prediction;
float wap_value;
bool operator==(wclass j);
};
struct label
{
v_array<wclass> costs;
uint32_t prediction;
};
void output_example(vw& all, example& ec);
//extern label_parser cs_label;
bool example_is_test(example& ec);
void print_update(vw& all, bool is_test, example& ec);
}
namespace CSOAA_AND_WAP_LDF {
void global_print_newline(vw& all);
void output_example(vw& all, example& ec, bool& hit_loss);
}
