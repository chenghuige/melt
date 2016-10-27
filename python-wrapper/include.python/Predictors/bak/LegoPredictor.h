#ifndef GEZI_PREDICTORS__LEGO_PREDICTOR_H_
#define GEZI_PREDICTORS__LEGO_PREDICTOR_H_
#include "MLCore/Predictor.h"
#include "liblego/lego.h"
namespace gezi {
class LegoPredictor : public ProbabilityPredictor
{
public:
virtual vector<Float> BulkPredict(vector<Vector>& featuresVector);
virtual bool Load(string path);
virtual	~LegoPredictor();
protected:
virtual Float Margin(Vector& features);
private:
void SetDataFromVector(const Vector& features);
private:
liblego::Net _net;
//static void*& tlr_ptr();
//static liblego::Blob*& blob();
};
}
#endif
