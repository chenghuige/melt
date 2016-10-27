#ifndef PREDICTORS__LIB_S_V_M_PREDICTOR_H_
#define PREDICTORS__LIB_S_V_M_PREDICTOR_H_
#include "MLCore/Predictor.h"
class svm_model;
class svm_problem;
class svm_node;
class svm_parameter;
namespace gezi {
class LibSVMPredictor : public Predictor
{
public:
LibSVMPredictor();
LibSVMPredictor(svm_model* model_, svm_problem* probl_, svm_node* node_, svm_parameter* param_,
NormalizerPtr normalizer, CalibratorPtr calibrator,
const FeatureNamesVector& featureNames);
~LibSVMPredictor();
virtual string Name();
virtual bool Load_(string file);
virtual void Save_(string file);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
virtual Float Margin(Vector& features);
private:
svm_model* _model;
svm_problem* _prob;
svm_node* _xspace;
svm_parameter* _param;
};
}
#endif
