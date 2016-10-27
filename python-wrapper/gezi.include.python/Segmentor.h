#ifndef SEGMENTOR_H_
#define SEGMENTOR_H_
#ifndef NO_BAIDU_DEP
#include "tagdict.h"
//extern const char* get_pos_str(unsigned int nPOS);
#endif
#ifndef NO_BAIDU_DEP
#include "scwdef.h"
#include "property.h"
#include "isegment.h"
#include "ipostag.h"
#include "ul_dict.h"
#endif
#include <glog/logging.h>
#include "debug_util.h"
#include <string>
#include <vector>
namespace gezi {
using std::vector;
using std::string;
#ifndef NO_BAIDU_DEP
struct SegHandle
{
static const int SEG_BUFF_SIZE = 20480;
SegHandle();
SegHandle(int bufsize);
void init(int buf_size_ = SEG_BUFF_SIZE);
void clear();
~SegHandle();
scw_out_t* pout;
token_t* tokens;
vector<token_t> token_vec;
int nresult;
int buf_size;
};
struct SegNode
{
string word;
int length;
int offset;
int weight;
SegNode();
SegNode(string word_, int length_, int offset_, int weight_);
};
static const int  SEG_USE_DEFAULT = 0;
static const int SEG_USE_POSTAG = 1;
static const int SEG_USE_SPLIT = 2;
static const int SEG_USE_TRIE = 4;
static const int SEG_USE_ALL = 255;
static const int SEG_MERGE_NEWWORD = SCW_OUT_WPCOMP | SCW_OUT_NEWWORD;
static const int SEG_WPCOMP = SCW_OUT_WPCOMP;
static const int SEG_NEWWORD = SCW_OUT_NEWWORD;
static const int SEG_BASIC = SCW_OUT_BASIC;
static const int SEG_HUMAN_NAME = SCW_OUT_HUMANNAME;
class Segmentor
{
public:
Segmentor(int seg_buff_size = SegHandle::SEG_BUFF_SIZE);
~Segmentor();
static void uninit();
static void Uninit();
Segmentor& set_flag(int flag_);
static void SetFlag(int flag_);
static void SetStrategy(int strategy_);
static bool init(string data_dir = "./data/wordseg", int type = SEG_USE_DEFAULT, string conf_path = "./conf/scw.conf", bool need_split_dict=false);
static bool Init(int seg_buff_size = SegHandle::SEG_BUFF_SIZE, string data_dir = "./data/wordseg", int type = SEG_USE_DEFAULT, string conf_path = "./conf/scw.conf", bool need_split_dict=false);
//static SegHandle& InitThread(int seg_buff_size = SegHandle::SEG_BUFF_SIZE);
static bool seg_words(string input, SegHandle& handle);
static int get_tokens(SegHandle& handle, int type = SEG_WPCOMP);
int get_tokens(int type = SEG_WPCOMP);
static vector<SegNode> get_segnodes(SegHandle& handle);
vector<SegNode> get_segnodes();
static bool segment(string input, SegHandle& handle, int type = SEG_WPCOMP);
static bool segment(string input, SegHandle& handle, vector<string>& result,
int type = SEG_WPCOMP);
static string segment(string input, SegHandle& handle, string sep, int type = SEG_WPCOMP);
vector<string> segment(string input, int type = SEG_WPCOMP);
static vector<string> Segment(string input, int type = SEG_WPCOMP);
static bool Segment_(string input, int type = SEG_WPCOMP);
bool segment(string input, vector<string>& result, int type = SEG_WPCOMP);
static bool Segment(string input, vector<string>& result, int type = SEG_WPCOMP);
string segment(string input, string sep, int type = SEG_WPCOMP);
static string Segment(string input, string sep, int type = SEG_WPCOMP);
bool segment(string input, vector<SegNode>& result, int type = SEG_WPCOMP);
static bool Segment(string input, vector<SegNode>& result, int type = SEG_WPCOMP);
SegHandle& get_handle();
//static SegHandle& handle(int buf_size = SegHandle::SEG_BUFF_SIZE);
private:
static bool init(const char* data_dir, int type = 0, const char* conf_path = "./conf/scw.conf", bool need_split_dict=false);
static int merge_newword(SegHandle& handle);
//static scw_worddict_t*& pwdict();
//static Sdict_search*& split_dict();
//static int& strategy();
//static int& flag(int flag_ = 0);
private:
SegHandle _handle;
};
#ifndef NO_BAIDU_DEP
inline void print_seg_result(const SegHandle& handle);
inline void print_seg_posttag_result(const gezi::SegHandle& handle);
inline void print_seg_result();
inline void print_seg_posttag_result();
#endif
#endif
}
#endif
