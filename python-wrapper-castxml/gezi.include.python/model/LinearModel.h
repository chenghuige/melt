#ifndef  __LINEARMODEL_H_
#define  __LINEARMODEL_H_
#include "Model.h"
#include "Feature.h"
#include "Score.h"
using gezi::fnode_t;
enum
{
L2R_LR, L2R_L2LOSS_SVC_DUAL, L2R_L2LOSS_SVC, L2R_L1LOSS_SVC_DUAL, MCSVM_CS, L1R_L2LOSS_SVC, L1R_LR, L2R_LR_DUAL
}
;
typedef struct model_
{
int solver_type;
int nr_class;
int nr_feature;
int *label;
double bias;
double *w;
}
model_t;
class LinearModel : public Model
{
public:
LinearModel(const char*, const char* infoPath);
virtual ~LinearModel();
virtual int load(const char*);
virtual int init();
virtual int predict(Feature *, Score *);
virtual void finalize();
private:
int predict_values(const vector<fnode_t> &, double *);
int predict_probability(const vector<fnode_t> &, double*);
model_t model_;
int wcnt_;
};
#endif
