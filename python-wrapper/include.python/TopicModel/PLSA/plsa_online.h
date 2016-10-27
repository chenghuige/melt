#ifndef PLSA_ONLINE_H_
#define PLSA_ONLINE_H_
#include "inverted_index.h"
#include <vector>
#include <stdlib.h>
#include "matrix_help.h"
#include "common_help.h"
#include "debug_help.h"
#include "vec_calc.h"
namespace plsa {
namespace online {
using namespace inverted;
template<typename _Table = InvertedIndex<float> >
class TModel
{
public:
TModel(_Table& invert, const std::vector<float>& back_ground, float beta = 0.95);
void inference(const std::vector<std::pair<int, int> >& content_vec, std::vector<float>& pdz, int round = 20);
int znum();
private:
int _znum;
_Table& _pzw;
float _beta;
std::vector<float>& _back_ground;
};
typedef TModel<> Model;
}
}
#endif
