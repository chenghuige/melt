#ifndef SIMPLE__PREDICTOR_FACTORY_H_
#define SIMPLE__PREDICTOR_FACTORY_H_
#include <string>
#include "Simple/Predictor.h"
namespace gezi {
namespace simple {
class PredictorFactory
{
public:
static Predictor LoadPredictor(std::string path);
};
}
}
#endif
