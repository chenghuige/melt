#ifndef FEATURE_FEATURES_UTIL_H_
#define FEATURE_FEATURES_UTIL_H_
#include "feature/FeatureVector.h"
#include "string_util.h"
namespace gezi {
inline void write_template(const Features& features, string outfile);
inline void write_def(const Features& features, string outfile);
template<typename _Stream>
void debug_print(const Features& features, _Stream& out);
template<typename _Stream>
void debug_print(const Features& features, _Stream& out,
const vector<pair<double, double> >& normal_vec,
const vector<pair<double, double> >& spam_vec);
inline Vector to_features(string sparseFeatureStr);
template<typename _Stream>
void write_arff_header(const Features& features, _Stream& ofs, string relation = "table", string classes = "negative,positive");
template<typename _Stream>
void write_table_header(const Features& features, _Stream& ofs, string name = "id", string label = "label");
template<typename _Stream>
void write_ftable_header(const Features& features, _Stream& ofs, string name = "");
//inline void write_header(const Features& features, std::ostream& ofs);
inline void write_header(const Features& features, string file);
//inline void write_arff(const Features& features, string uid, string type, std::ostream& ofs);
//inline void write_libsvm(const Features& features, string label, std::ostream& ofs);
//template<typename T>
//inline void write_sparse(const Features& features, T label, ofstream& ofs);
//template<typename T, typename U>
//inline void write_sparse(const Features& features, T label, ofstream& ofs, U name);
//template<typename T>
//inline void write_table(const Features& features, T label, ofstream& ofs);
//template<typename T, typename U>
//inline void write_table(const Features& features, T label, ofstream& ofs, U name);
//inline void write_table_feature(const Features& features, ofstream& ofs);
template<typename IdVec, typename LabelVec, typename Func>
inline void write_features(const IdVec& ids, const LabelVec& labels, Func func,
string outFile, string idName = "id");
template<typename IdVec, typename LabelVec, typename Func>
inline void write_features(const IdVec& ids, const IdVec& ids2, const LabelVec& labels, Func func,
string outFile, string idName = "id");
template<typename Vec>
inline void add_mean_var(Features* fe, const Vec& vec,
const string mean_name = "", const string var_name = "");
template<typename Vec>
inline void add_mean(Features* fe, const Vec& vec,
const string mean_name = "");
template<typename Vec>
inline void add_var(Features* fe, const Vec& vec,
const string var_name = "");
template<typename T>
inline void add_mean_var(Features* fe, T begin, T end,
const string mean_name = "", const string var_name = "");
template<typename T>
inline void add_mean(Features* fe, T begin, T end,
const string mean_name = "");
template<typename T>
inline void add_var(Features* fe, T begin, T end,
const string var_name = "");
}
#endif
