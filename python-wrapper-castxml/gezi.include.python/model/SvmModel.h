#ifndef  __SVMMODEL_H_
#define  __SVMMODEL_H_
#include "Model.h"
typedef Feature::Node svm_node;
enum
{
C_SVC, NU_SVC, ONE_CLASS, EPSILON_SVR, NU_SVR
};
enum
{
LINEAR, POLY, RBF, SIGMOID, PRECOMPUTED
};
struct svm_parameter
{
int svm_type;
int kernel_type;
int degree;
double gamma;
double coef0;
double cache_size;
double eps;
double C;
int nr_weight;
int *weight_label;
double* weight;
double nu;
double p;
int shrinking;
int probability;
};
struct svm_model
{
struct svm_parameter param;
int nr_class;
int l;
svm_node **SV;
double one_class_lower_bound;
double one_class_upper_bound;
double **sv_coef;
double *rho;
double *probA;
double *probB;
int *label;
int *nSV;
int free_sv;
};
struct svm_model *svm_load_model(const char *model_file_name);
double svm_get_svr_probability(const struct svm_model *model);
double svm_predict_values(const struct svm_model *model, const svm_node *x, double* dec_values);
double svm_predict(const struct svm_model *model, const svm_node *x);
double svm_predict_probability(const struct svm_model *model, const svm_node *x, double* prob_estimates);
void svm_free_model_content(struct svm_model *model_ptr);
void svm_destroy_param(struct svm_parameter *param);
class SvmModel : public Model
{
public:
SvmModel(const char*, const char*);
virtual ~SvmModel();
virtual int load(const char*);
virtual int init();
virtual int predict(Feature *, Score *);
virtual void predict(Feature&, vector<double>&);
virtual void finalize();
private:
struct svm_model model_;
};
#endif
