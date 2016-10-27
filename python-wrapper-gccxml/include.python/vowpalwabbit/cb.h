#pragma once
namespace CB {
struct cb_class
{
float cost;
uint32_t action;
float probability;
float partial_prediction;
bool operator==(cb_class j);
};
struct label
{
v_array<cb_class> costs;
uint32_t prediction;
};
//extern label_parser cb_label;
}
namespace CB_EVAL {
//extern label_parser cb_eval;
}
