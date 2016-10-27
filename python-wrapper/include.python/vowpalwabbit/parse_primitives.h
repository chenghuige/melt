#pragma once
#include<iostream>
#include <stdint.h>
#include <math.h>
#include "v_array.h"
#include "io_buf.h"
#include "example.h"
#ifdef _WIN32
#include <WinSock2.h>
#include <Windows.h>
typedef CRITICAL_SECTION MUTEX;
typedef CONDITION_VARIABLE CV;
#else
typedef pthread_mutex_t MUTEX;
typedef pthread_cond_t CV;
#endif
struct substring
{
char *begin;
char *end;
};
struct shared_data
{
size_t queries;
uint64_t example_number;
uint64_t total_features;
double t;
double weighted_examples;
double weighted_unlabeled_examples;
double old_weighted_examples;
double weighted_labels;
double sum_loss;
double sum_loss_since_last_dump;
float dump_interval;
double gravity;
double contraction;
float min_label;
float max_label;
double weighted_holdout_examples;
double weighted_holdout_examples_since_last_dump;
double holdout_sum_loss_since_last_dump;
double holdout_sum_loss;
double holdout_best_loss;
double weighted_holdout_examples_since_last_pass;
double holdout_sum_loss_since_last_pass;
size_t holdout_best_pass;
bool binary_label;
uint32_t k;
};
struct parser;
struct label_parser
{
void (*default_label)(void*);
void (*parse_label)(parser*, shared_data*, void*, v_array<substring>&);
void (*cache_label)(void*, io_buf& cache);
size_t (*read_cached_label)(shared_data*, void*, io_buf& cache);
void (*delete_label)(void*);
float (*get_weight)(void*);
void (*copy_label)(void*&,void*);
size_t label_size;
};
typedef size_t (*hash_func_t)(substring, uint32_t);
struct parser
{
v_array<substring> channels;
v_array<substring> words;
v_array<substring> name;
io_buf* input;
int (*reader)(void*, example* ae);
hash_func_t hasher;
bool resettable;
io_buf* output;
bool write_cache;
bool sort_features;
bool sorted_cache;
size_t ring_size;
uint64_t begin_parsed_examples;
uint64_t end_parsed_examples;
uint64_t local_example_number;
uint32_t in_pass_counter;
example* examples;
uint64_t used_index;
bool emptylines_separate_examples;
MUTEX examples_lock;
CV example_available;
CV example_unused;
MUTEX output_lock;
CV output_done;
bool done;
v_array<size_t> gram_mask;
v_array<size_t> ids;
v_array<size_t> counts;
size_t finished_count;
int label_sock;
int bound_sock;
int max_fd;
v_array<substring> parse_name;
label_parser lp;
};
void tokenize(char delim, substring s, v_array<substring> &ret, bool allow_empty=false);
inline char* safe_index(char *start, char v, char *max);
inline void print_substring(substring s);
inline float parseFloat(char * p, char **end);
inline bool nanpattern( float value );
inline bool infpattern( float value );
inline float float_of_substring(substring s);
inline int int_of_substring(substring s);
