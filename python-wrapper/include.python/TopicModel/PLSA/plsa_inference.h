#ifndef PLSA_INFERENCE_H_
#define PLSA_INFERENCE_H_
#include "inverted_index.h"
#include <vector>
#include <stdlib.h>
#include "common_help.h"
#include "vec_calc.h"
#include "matrix_help.h"
namespace gezi
{
template<typename _Table >
class TPlsaBasicModel
{
public:
TPlsaBasicModel(_Table& invert);
template<typename T>
void inference(const std::vector<T>& content_vec, std::vector<float>& pdz, int round = 20);
int znum();
private:
int _znum;
_Table& _pzw;
};
template<typename _Table >
class TPlsaModel
{
public:
TPlsaModel(_Table& invert, int znum = 10000);
template<typename T>
void inference(const std::vector<T>& content_vec, std::vector<float>& pdz, int round = 20);
template<typename T>
void mix_inference(const std::vector<T>& content_vec, std::vector<float>& pdz, int round = 20);
int znum();
private:
int _znum;
_Table& _pwz;
};
typedef TPlsaBasicModel<inverted::InvertedIndex<float> > PlsaBasicModel;
typedef TPlsaModel<inverted::InvertedIndex<float> > PlsaModel;
}
#endif
