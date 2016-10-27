#ifndef RSTREE_WORKER_H_
#define RSTREE_WORKER_H_
#include "Rstree.h"
#include "post_process/PostProcessor.h"
#include "Segmentor.h"
#include "all_util.h"
#include "rstree_def.h"
#include "hashmap_util.h"
namespace gezi
{
class RstreeWorker
{
public:
RstreeWorker();
private:
int _min_text_length;
int _max_text_length;
int _max_result_count;
bool _use_seg;
bool _simple_sort;
static const int MAX_SEG_BUFSIZE = 15000;
Rstree _rstree;
PostProcessor _post_processor;
PostAdjustor _post_adjustor;
public:
static void init_static();
void init();
void merge_map(std::unordered_map<wstring, int> & m1, const std::unordered_map<wstring, int> & m2);
bool get_postype(const SegHandle& handle, int len, vector<int>& vec);
bool get_postype(string sub_c, int len, vector<int>& splits);
struct Cmp
{
bool operator() (const ONode& left, const ONode& right);
};
vector<ONode> get_substrs(string content_, int min_freq, int min_len, int max_len);
inline int tree_size();
};
}
#endif
