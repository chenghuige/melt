#ifndef PLSA_H_
#define PLSA_H_
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "common_help.h"
#include "matrix.h"
#include "debug_help.h"
#include "inverted_index_printer.h"
#include <stdlib.h>
namespace plsa {
using std::string;
using std::vector;
typedef float DP;
typedef vector<std::pair<int, DP> > ContentVec;
typedef std2::Matrix< DP> Mat_;
struct DocInfo
{
DP nword;
ContentVec content;
};
class Model
{
public:
Model(int z_num, int word_num);
bool init_doc(const string& file, int max_num);
void init_doc_dir(const string& dir, int max_num = std::numeric_limits<int>::max());
void init();
void run(int step = 1);
template<typename _Dict>
void print_topic(int zid, const _Dict& dict, int max_num = 200);
protected:
int _znum;
vector<DocInfo> _doc_vec;
int _ndoc;
int _nword;
Mat_ _pdz;
Mat_ _pzw;
Mat_ _pzw2;
vector<DP> _pz_vec;
Mat_ _pwz;
};
}
#endif
