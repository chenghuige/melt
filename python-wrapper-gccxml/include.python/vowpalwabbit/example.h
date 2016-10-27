#pragma once
#include <stdint.h>
#include "v_array.h"
size_t wap_ldf_namespace;
size_t history_namespace;
size_t constant_namespace;
size_t nn_output_namespace;
size_t autolink_namespace;
size_t neighbor_namespace;
size_t affix_namespace;
size_t spelling_namespace;
size_t conditioning_namespace;
struct feature
{
float x;
uint32_t weight_index;
bool operator==(feature j);
};
struct audit_data
{
char* space;
char* feature;
size_t weight_index;
float x;
bool alloced;
};
struct example
{
void* ld;
v_array<char> tag;
size_t example_counter;
v_array<unsigned char> indices;
v_array<feature> atomics[256];
uint32_t ft_offset;
v_array<audit_data> audit_features[256];
size_t num_features;
float partial_prediction;
float updated_prediction;
v_array<float> topic_predictions;
float loss;
float example_t;
float sum_feat_sq[256];
float total_sum_feat_sq;
float revert_weight;
bool test_only;
bool end_pass;
bool sorted;
bool in_use;
};
struct vw;
struct flat_example
{
void* ld;
size_t tag_len;
char* tag;
size_t example_counter;
uint32_t ft_offset;
float global_weight;
size_t num_features;
float total_sum_feat_sq;
size_t feature_map_len;
feature* feature_map;
};
flat_example* flatten_example(vw& all, example *ec);
flat_example* flatten_sort_example(vw& all, example *ec);
void free_flatten_example(flat_example* fec);
example *alloc_examples(size_t,size_t);
void dealloc_example(void(*delete_label)(void*), example&);
inline int example_is_newline(example& ec);
