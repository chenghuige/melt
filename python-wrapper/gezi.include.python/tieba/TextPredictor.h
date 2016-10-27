#ifndef TIEBA_TEXT_PREDICTOR_H_
#define TIEBA_TEXT_PREDICTOR_H_
#include "MLCore/TextPredictor.h"
#include "tools/content_process.h"
#include "tieba/tieba_util.h"
#include "string_util.h"
namespace gezi {
namespace tieba {
class TextPredictor
{
public:
static string filter_content(string content);
static double Predict(string title, string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01");
static double Predict(string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01");
protected:
private:
};
}
}
#endif
