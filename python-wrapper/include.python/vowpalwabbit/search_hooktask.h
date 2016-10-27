#pragma once
#include "search.h"
namespace HookTask {
void initialize(Search::search&, size_t&, po::variables_map&);
void finish(Search::search&);
void run(Search::search&, vector<example*>&);
//extern Search::search_task task;
struct task_data
{
void (*run_f)(Search::search&);
void *run_object;
void (*delete_run_object)(void*);
void (*delete_extra_data)(task_data&);
po::variables_map* var_map;
const void* extra_data;
const void* extra_data2;
size_t num_actions;
};
}
