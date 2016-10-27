#pragma once
#include "global_data.h"
#include "example.h"
#include "hash.h"
#include "simple_label.h"
namespace VW {
vw* initialize(string s);
void cmd_string_replace_value( string& cmd, string flag_to_replace, string new_value );
char** get_argv_from_string(string s, int& argc);
void finish(vw& all, bool delete_all=true);
void start_parser(vw& all, bool do_init = true);
void end_parser(vw& all);
typedef pair< unsigned char, vector<feature> > feature_space;
struct primitive_feature_space
{
unsigned char name;
feature* fs;
size_t len;
};
example* read_example(vw& all, char* example_line);
example* read_example(vw& all, string example_line);
example* import_example(vw& all, primitive_feature_space* features, size_t len);
example* import_example(vw& all, vector< feature_space > ec_info);
void parse_example_label(vw&all, example&ec, string label);
void setup_example(vw& all, example* ae);
example* new_unused_example(vw& all);
example* get_example(parser* pf);
float get_topic_prediction(example*ec, size_t i);
float get_label(example*ec);
float get_importance(example*ec);
float get_initial(example*ec);
float get_prediction(example*ec);
size_t get_tag_length(example* ec);
const char* get_tag(example* ec);
size_t get_feature_number(example* ec);
feature* get_features(vw& all, example* ec, size_t& feature_number);
void return_features(feature* f);
void add_constant_feature(vw& all, example*ec);
void add_label(example* ec, float label, float weight = 1, float base = 0);
void finish_example(vw& all, example* ec);
void copy_example_data(bool audit, example*, example*, size_t, void(*copy_label)(void*&,void*));
void copy_example_data(bool audit, example*, example*);
primitive_feature_space* export_example(vw& all, example* e, size_t& len);
void releaseFeatureSpace(primitive_feature_space* features, size_t len);
inline uint32_t hash_space(vw& all, string s);
inline uint32_t hash_feature(vw& all, string s, unsigned long u);
inline uint32_t hash_feature_cstr(vw& all, char* fstr, unsigned long u);
inline float get_weight(vw& all, uint32_t index, uint32_t offset);
inline void set_weight(vw& all, uint32_t index, uint32_t offset, float value);
inline uint32_t num_weights(vw& all);
inline uint32_t get_stride(vw& all);
inline void update_dump_interval(vw& all);
}
