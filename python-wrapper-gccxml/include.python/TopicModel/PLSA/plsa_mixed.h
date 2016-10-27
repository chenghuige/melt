#ifndef PLSA_MIXED_H_
#define PLSA_MIXED_H_
#include "plsa.h"
namespace plsa {
class MixModel : public Model
{
public:
MixModel(int z_num, int word_num, const std::vector<DP>& back_ground, DP beta = 0.8);
void init();
void run(int step = 1);
private:
std::vector<DP>& _back_ground;
vector<DP> _pwb;
DP _beta;
};
}
#endif
