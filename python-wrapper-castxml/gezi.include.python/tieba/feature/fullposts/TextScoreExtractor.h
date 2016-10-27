#ifndef TIEBA_FEATURE_FULLPOSTS__TEXT_SCORE_EXTRACTOR_H_
#define TIEBA_FEATURE_FULLPOSTS__TEXT_SCORE_EXTRACTOR_H_
#include "MLCore/PredictorFactory.h"
#include "Wrapper/SharedPredictors.h"
#include "tieba/TextPredictor.h"
#include "tieba/tieba_util.h"
#include "FullPostsExtractor.h"
namespace gezi {
namespace tieba {
class FPTextScoreExtractor : public FullPostsExtractor
{
public:
FPTextScoreExtractor(string name = "FPTextScore", bool isRsc = false);
void Init();
double Predict(string title, string content, int offset);
double Predict(string title, string content);
virtual void extract();
protected:
private:
//static mutex& theMutex();
PredictorPtr& GetPredictor(int offset);
DoubleIdentifer& GetIdentifer(int offset);
private:
int _ngram;
int _skip;
string _sep;
int _segType;
int _maxLen;
bool _normalize;
bool _addNorm;
bool _useMedia;
bool _isRsc;
string _predictorPath[2];
string _identiferPath[2];
};
}
}
#endif
