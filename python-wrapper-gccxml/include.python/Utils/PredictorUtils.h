#ifndef UTILS__PREDICTOR_UTILS_H_
#define UTILS__PREDICTOR_UTILS_H_
#include "MLCore/Predictor.h"
#include "Testers/testers.h"
namespace gezi {
class PredictorUtils
{
public:
static TesterPtr GetTester(PredictionKind kind);
static TesterPtr GetRankerTester();
static TesterPtr GetClassifierTester();
static	TesterPtr GetTester(PredictorPtr predictor);
protected:
private:
};
}
#endif
