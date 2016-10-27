#ifndef PYTHON_WRAPPER__PREDICTOR_FACTORY_H_
#define PYTHON_WRAPPER__PREDICTOR_FACTORY_H_
#include "PythonWrapper/Predictor.h"
namespace gezi {
namespace py {
class PredictorFactory
{
public:
static Predictor LoadPredictor(string path);
static Predictor LoadTextPredictor(string path);
};
}
}
#endif
