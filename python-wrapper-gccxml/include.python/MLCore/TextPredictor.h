#ifndef M_L_CORE__TEXT_PREDICTOR_H_
#define M_L_CORE__TEXT_PREDICTOR_H_
#include "common_util.h"
#include "Segmentor.h"
#include "Identifer.h"
#include "tools/content_process.h"
#ifdef _DEBUG
#include "Predictors/LinearPredictor.h"
#include "feature/Features.h"
#endif
#include "Predictor.h"
namespace gezi {
class TextPredictor
{
public:
static void Prase(const svec& words_, map<int, double>& m, const DoubleIdentifer& identifer, int startIndex = 0,
int ngram = 3, int skip = 2, string sep = "\x01");
static double Predict(const svec& titleWords, const svec& contentWords, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01");
static double Predict(const svec& titleWords, const svec& contentWords, const DoubleIdentifer& identifer, const PredictorPtr& predictor, map<int, double>& idValMap,
int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01");
static double Predict(const svec& words, const DoubleIdentifer& identifer, const PredictorPtr& predictor, map<int, double>& idValMap,
int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01");
static double Predict(const svec& words, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01");
#ifndef NO_BAIDU_DEP
static double Predict(string title, string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01");
static double Predict(string title, string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor, map<int, double>& idValMap,
int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01");
static double Predict(string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01");
#endif
};
}
#endif
