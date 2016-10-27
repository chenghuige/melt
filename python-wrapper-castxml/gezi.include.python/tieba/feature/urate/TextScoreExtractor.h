#ifndef TIEBA_FEATURE_URATE__TEXT_SCORE_EXTRACTOR_H_
#define TIEBA_FEATURE_URATE__TEXT_SCORE_EXTRACTOR_H_
#include "tieba/feature/urate/UrateExtractor.h"
#include "MLCore/PredictorFactory.h"
#include "Wrapper/SharedPredictors.h"
#include "tieba/TextPredictor.h"
#include "tieba/tieba_util.h"
namespace gezi {
namespace tieba {
class TextScoreExtractor : public UrateExtractor
{
public:
TextScoreExtractor(string name = "TextScore", bool isRsc = false);
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
