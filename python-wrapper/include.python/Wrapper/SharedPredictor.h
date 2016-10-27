#ifndef WRAPPER__SHARED_PREDICTOR_H_
#define WRAPPER__SHARED_PREDICTOR_H_
#include "Wrapper/PredictorFactory.h"
#include "Wrapper/SharedPredictors.h"
namespace gezi {
class SharedPredictor
{
public:
//static PredictorPtr& Instance();
static void Init();
};
}
#endif
