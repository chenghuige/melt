#ifndef RSTREE_H_
#define RSTREE_H_
#include "SuffixTree.h"
#include "debug_util.h"
#ifdef GEZI_USE_CONF
#include "conf_util.h"
#endif
namespace gezi
{
class Rstree : public SuffixTree
{
public:
int _min_substr_len;
int _min_substr_len2;
int _max_substr_len;
int _min_frequency;
int _max_tree_size;
double _max_jump;
Rstree(const wstring& end_mark = L"\n", int min_substr_len = 8,
int max_substr_len = 40, int min_frequency = 15, int max_tree_size = 300000);
enum SEG_POS
{
SINGLE,
LEFT,
MIDDLE,
RIGHT
};
#ifdef GEZI_USE_CONF
bool init();
bool init(const comcfg::Configure& conf,
string section = "Rstree");
bool read_config(const comcfg::Configure& conf,
string section = "Rstree");
bool read_config(string path = "./conf", string config_file = "Rstree.conf",
string section = "Rstree");
bool init(string path, string config_file,
string section = "Rstree");
bool read_config(const char* path, const char* config_file,
string section = "Rstree");
#endif
void init(int min_substr_len, int max_substr_len, int min_freq, int tree_size);
inline void set_min_frequency(int freq);
inline int min_frequency();
inline void set_min_substr_len(int len);
inline int min_substr_len();
inline void set_max_substr_len(int len);
inline int max_substr_len();
void set_tree_size(int size);
void set_max_jump(int len);
inline int max_tree_size();
typedef std::pair<wstring, int> Pair;
vector<Pair> find_all_substrs();
struct SubstrNode
{
wstring substr;
int freq;
set<int> tids;
#ifdef PYTHON_WRAPPER
SubstrNode();
bool operator == (const SubstrNode& other);
#endif
//SubstrNode(wstring substr_, int freq_, set<int>&& tids_);
};
vector<SubstrNode> find_all();
#ifndef GCCXML
void add_find(const wstring& text, vector<Pair>& result_vec, const vector<int>* pos_types = NULL);
vector<Pair> add_find(const wstring& text, const vector<int>* pos_types = NULL);
bool is_node_ok(const Node* node);
bool is_node_up_ok(const Node* node, bool& need_up);
bool is_node_ok(const Node* node, bool& need_down);
inline wstring trim(const wstring& text, const vector<int>& splits, int start, int end);
inline wstring trim(const Node* node, const wstring& text, const vector<int>* pos_types = NULL);
inline Node* get_node(Node* node);
void find_all_substrs(Node* node, vector<Pair>& result_vec);
void find_all(Node* node, vector<SubstrNode>& result_vec);
void find_substrs(vector<Pair>& result_vec);
vector<Pair>  find_substrs(int idx);
void find_substrs(int idx, vector<Pair>& result_vec);
void find_substrs(vector<Pair>& result_vec, const vector<int>* pos_types);
void find_substrs(int idx, vector<Pair>& result_vec, const vector<int>* pos_types);
#endif
};
}
#endif
