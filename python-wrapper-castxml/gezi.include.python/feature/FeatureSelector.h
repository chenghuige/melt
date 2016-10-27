#ifndef FEATURE_SELECTOR_H_
#define FEATURE_SELECTOR_H_
#include "Matrix.h"
#include "Identifer.h"
#include "Numeric/collocation.h"
#include "sort_util.h"
namespace gezi {
class FeatureSelector
{
public:
typedef boost::function<Float(int, int, int, uint64) > Func;
enum Strategy
{
MAX,
AVG,
SUM
};
FeatureSelector();
void init();
void initFunc();
void clearScore();
void clear();
inline int labelNum();
inline int minSupport();
inline int method();
inline int strategy();
inline FeatureSelector& labelNum(int labelNum);
inline FeatureSelector& method(collocation::Method method);
inline FeatureSelector& strategy(Strategy strategy);
inline FeatureSelector& minSupport(int minSupport);
void add(const vector<string>& words, int label);
void add(string doc, int label, string sep = "\t");
dmat& calc();
void save(string file, int idx = -1, int maxFeatureNum = -1);
void show(int maxFeatureNum = 1024, int idx = -1);
//void save(ostream& os, int maxFeatureNum, int idx);
void save_idf(string file);
void save_all(string dir = "result");
inline int featureNum();
inline int64 instanceNum();
private:
void add(const set<string>& words, int labelIdx);
void finalize();
void rank(int maxFeatureNum);
void rank(int index, int maxFeatureNum);
private:
imat _counts;
vector<int> _featureCounts;
vector<int> _classCounts;
vector<double> _classPriors;
int _labelNum;
int _featureNum;
int64 _instanceNum;
Func _func;
collocation::Method _method;
Strategy _strategy;
int _minSupport;
dmat _scores;
imat _ranks;
Identifer _identifer;
};
}
#endif
