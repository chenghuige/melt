#ifndef TIEBA_FEATURE_RSC_THREAD__RSC_THREAD_TEXT_SCORE_EXTRACTOR_H_
#define TIEBA_FEATURE_RSC_THREAD__RSC_THREAD_TEXT_SCORE_EXTRACTOR_H_
#include "MLCore/PredictorFactory.h"
#include "Wrapper/SharedPredictors.h"
#include "MLCore/TextPredictor.h"
#include "tieba/tieba_util.h"
namespace gezi {
namespace tieba {
namespace rsc {
class RscThreadTextScoreExtractor
{
public:
RscThreadTextScoreExtractor();
string name();
void Init();
enum  TextPredictMode
{
TextPredictMode__enum__titleContentSep,
TextPredictMode__enum__titleContentMerge,
};
double Predict(string title, string content, int offset = 0, TextPredictMode mode = TextPredictMode::titleContentSep);
double Predict(string title, int offset = 1);
PredictorPtr& GetPredictor(int offset);
DoubleIdentifer& GetIdentifer(int offset);
private:
int _ngram;
string _sep;
int _segType;
bool _normalize;
string _predictorPath[2];
string _identiferPath[2];
};
}
}
}
#endif
