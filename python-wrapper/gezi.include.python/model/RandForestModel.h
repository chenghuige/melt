#ifndef  __RANDFORESTMODEL_H_
#define  __RANDFORESTMODEL_H_
#include "Model.h"
#include "Feature.h"
#include "Score.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
using namespace std;
#define RF_BUFFER_LENGTH 1024
typedef struct struct_rf_cls_tree_t
{
int* nodestatus;
int* splitid;
double* splitvalue;
int* ndstart;
int* ndcount;
int** cls;
int* lson;
int* rson;
int nodesize;
}
rf_cls_tree_t;
typedef struct struct_rfinfo
{
int tree_num;
int fea_num;
int data_num;
int sample_num;
int rand_fea_num;
int forest_type;
int cls_num;
char** cls_label;
int rf_min_node_size;
char train_filename[RF_BUFFER_LENGTH];
char model_filename[RF_BUFFER_LENGTH];
}
rfinfo;
typedef struct struct_rf_model_t
{
rf_cls_tree_t** cls_forest;
double* feature_average;
rfinfo infbox;
}
rf_model_t;
class RandForestModel : public Model
{
public:
RandForestModel(const char*, const char* infoPath);
virtual ~RandForestModel();
virtual int load(const char*);
virtual int init();
virtual int predict(Feature *, Score *);
virtual void finalize();
private:
bool has_colon(string item);
void fill_no_value_aver(double *x_test);
int rf_cls_predict(rf_model_t* rf_model, double *x_test, int& ypredict);
int rf_cls_predict_prob(rf_model_t* rf_model, double *x_test, int& ypredict, double &prob);
int load_rfinfo(rfinfo* pinfbox, FILE* model_fp);
rf_model_t* rf_load_model(const char* model_file);
void free_model(rf_model_t*& rf_model);
int rf_cls_tree_predict(double *x_test, rf_cls_tree_t *cls_tree, int cls_num, int& ypred);
int rf_load_cls_forest(FILE* model_fp, rf_model_t* rf_model);
rf_model_t*  rf_model;
};
#endif
