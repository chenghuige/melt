#ifndef PYTHON_WRAPPER__PREDICTOR_H_
#define PYTHON_WRAPPER__PREDICTOR_H_
#include "common_def.h"
#include "Numeric/Vector/Vector.h"
namespace gezi {
namespace py {
class Predictor
{
public:
Float Output(Vector& features);
Float Predict(Vector& features);
Float Predict(Vector& features, Float& output);
void SaveJson(string file);
void SaveJson();
void Save(string path);
void Save();
public:
void* _predictor;
};
}
}
#endif
