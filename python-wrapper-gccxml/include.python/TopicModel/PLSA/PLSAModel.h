#ifndef P_L_S_A_MODEL_H_
#define P_L_S_A_MODEL_H_
#include "common_util.h"
#include "Matrix.h"
namespace gezi {
namespace plsa {
class PLSAModel
{
public:
PLSAModel();
PLSAModel(string file);
void Load(string file);
template<typename Key, typename Value>
vector<Float> Inference(const map<Key, Value>& contents, int numIters = 20);
template<typename T>
vector<Float> Inference(const std::vector<T>& contents, int numIters = 20);
public:
int NumTopics;
protected:
private:
ufo::Matrix<Float> _pzw;
};
}
}
#endif
