#ifndef P_L_S_A_TRAINER_H_
#define P_L_S_A_TRAINER_H_
#include "Matrix.h"
namespace gezi {
namespace plsa {
struct DocInfo
{
int numWords;
vector<pair<int, Float> > content;
};
typedef vector<pair<int, Float> > ContentVec;
class PLSATrainer
{
public:
PLSATrainer(int numTopics, int numWords);
void Initialize();
void Train(const vector<DocInfo>& docs, int numIters = 20);
void Save(string file, int maxTopicNum = 20);
//template<typename _Dict>
//void PrintTopic(int topicId, const _Dict& dict, ostream& ofs, int maxNum = 200);
public:
int NumTopics;
int NumWords;
int NumDocs;
protected:
private:
ufo::Matrix<Float> _pdz;
ufo::Matrix<Float> _pzw;
ufo::Matrix<Float> _pzwTemp;
vector<Float> _pzVec;
ufo::Matrix<Float> _pwz;
};
}
}
#endif
