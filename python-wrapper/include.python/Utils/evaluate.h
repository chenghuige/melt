#ifndef UTILS_EVALUATE_H_
#define UTILS_EVALUATE_H_
#include "evaluate_def.h"
#include "statistic_util.h"
namespace gezi {
namespace evaluate {
template<typename Vec>
inline Float auc(const vector<Float>& predictions, const Vec& instances, bool needSort = true);
template<typename Vec>
inline Float l1(const vector<Float>& predictions, const Vec& instances);
template<typename Vec>
inline Float l2(const vector<Float>& predictions, const Vec& instances);
template<typename Vec>
inline Float rmse(const vector<Float>& predictions, const Vec& instances);
template<typename Vec>
inline Float logloss(const vector<Float>& predictions, const Vec& instances, Float logTolerence = 30);
template<typename Vec>
inline Float logloss_output(const vector<Float>& predictions, const Vec& instances, Float beta = 2.0);
template<typename Vec>
inline Float exploss(const vector<Float>& predictions, const Vec& instances, Float beta = 1.0);
template<typename Vec>
inline Float gold_standard(const vector<Float>& predictions, const Vec& instances, Float thre = 0.5);
template<typename Vec>
inline Float hinge(const vector<Float>& predictions, const Vec& instances, Float margin = 1.0);
inline Float auc(const vector<Node>& results, bool needSort = true);
inline Float l1(vector<Node>& results);
inline Float l2(vector<Node>& results);
inline Float rmse(vector<Node>& results);
}
}
#endif
