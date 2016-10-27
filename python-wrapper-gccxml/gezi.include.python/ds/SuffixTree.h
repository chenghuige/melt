#ifndef SUFFIX_TREE_H_
#define SUFFIX_TREE_H_
#include <string>
#include <map>
#include <deque>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include "hashmap_util.h"
#include "string_util.h"
namespace gezi
{
class SuffixTree
{
public:
SuffixTree(const wstring& end_mark = L"#");
virtual ~SuffixTree();
#ifndef GEZI_SUFFIXTREE_INT_INDEX_TYPE
typedef unsigned long long index_type;
#else
typedef int index_type;
#endif
#ifndef GCCXML
struct Node;
typedef std::unordered_map<wchar_t, Node*> Edges;
typedef Edges::iterator NIter;
struct Node
{
Node();
void init();
Node(Node* parent_, index_type id_ = 0);
Node(Node* parent_, int start_, int end_, int length_, index_type id_ = 0, int freq_ = 0);
inline bool is_leaf();
int length;
int start;
int end;
int freq;
Node* parent;
Node* suffix_link;
Edges* next;
index_type text_id;
};
#endif
void init();
void reset_status();
void reset();
void free();
void clear();
inline wstring& end_mark();
inline size_t tree_size();
inline size_t size();
protected:
#ifndef GCCXML
Node* _root;
index_type _current_text_id;
index_type _oldest_text_id;
std::deque<wstring> _texts;
std::deque<Node*> _first_leafs;
wstring _end_mark;
#endif
public:
void build(const wstring& text);
void add(const wstring& text);
void insert(const wstring& text);
void remove();
void remove_newest();
void remove(int id);
#ifndef GCCXML
void clear(Node* node);
Node* find_longest_node(const wstring& text, int start = 0);
#endif
int find_longest(const wstring& text, int start);
int find_longest(const wstring& text, int start, int & freq);
bool find(const wstring& text, int start = 0);
int find_freq(const wstring& text, int start = 0);
void find_prefix_suffix_freqs(const wstring& text, vector<int>& prefix_freqs, vector<int>& suffix_freqs);
double right_information(const wstring& text);
set<int> get_text_ids(const wstring& text);
vector<pair<int, int> > get_texts_id_pos(const wstring& text);
#ifndef GCCXML
Node* find_node(const wstring& text, int start = 0);
set<int> get_text_ids(Node* node);
void get_text_ids(Node* node, set<int>& tids);
void get_text_ids(Node* node, vector<Node*>& tids);
vector<pair<int, int> > get_texts_id_pos(Node* node);
Node* find_node(const wstring& text, vector<int>& freqs);
vector<int> find_suffix_freqs(Node* node);
static int node_length(const Node* node);
inline wstring get_str(const Node* node);
void dec_freq(Node* node);
void remove_(int idx = 0);
#endif
protected:
#ifndef GCCXML
void build_(const wstring& text);
int shift_down(const wstring& text, int end_idx, Node*& active_node, Node*& next_node, int & active_length);
Node* split_edge(Node* active_node, Node* next_node, wchar_t first_char, wchar_t test_char,
int split_pos, int edge_length, int active_length);
void add_(const wstring & text);
void calc_freq();
int get_leaf_num(Node * node);
void inc_freq(Node * node);
#endif
public:
void write_result(const string & file);
void print();
wstring text(int id) const;
index_type min_text_id() const;
index_type max_text_id() const;
index_type text_id(int id) const;
#ifndef GCCXML
//void write_result(Node* node, int depth, std::wofstream & ofs);
void print(Node* node, int depth, int & leaf_freq);
#endif
};
}
#endif
