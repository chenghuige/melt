#ifndef MODEL__LINEAR_H_
#define MODEL__LINEAR_H_
#include "common_util.h"
#include "feature/Feature.h"
#include "statistic_util.h"
namespace gezi
{
class Linear
{
public:
Linear();
Linear(string modelPath);
void load(string modelPath);
double output(Feature& feature);
double Predict(Feature& feature);
private:
double _bias;
vector<double> _weights;
double _paramA;
double _paramB;
};
}
#endif
