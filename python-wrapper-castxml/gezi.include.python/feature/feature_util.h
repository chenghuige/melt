#ifndef FEATURE_UTIL_H_
#define FEATURE_UTIL_H_
#include "Feature.h"
#include "common_util.h"
namespace gezi
{
inline void write_template(const Feature& feature, string outfile);
inline void write_def(const Feature& feature, string outfile);
template<typename _Stream>
void debug_print(const Feature& feature, _Stream& out);
template<typename _Stream>
void debug_print(const Feature& feature, _Stream& out,
const vector<pair<double, double> >& normal_vec,
const vector<pair<double, double> >& spam_vec);
inline Feature to_feature(string feature_str_);
template<typename _Stream>
void write_arff_header(const Feature& feature, _Stream& ofs, string relation, string classes = "spam,normal");
template<typename _Stream>
void write_table_header(const Feature& feature, _Stream& ofs, string name = "id", string label = "label");
template<typename _Stream>
void write_ftable_header(const Feature& feature, _Stream& ofs, string name = "");
//inline void write_header(const Feature& feature, std::ostream& ofs);
inline void write_header(const Feature& feature, string file);
//inline void write_arff(const Feature& feature, string uid, string type, std::ostream& ofs);
//inline void write_libsvm(const Feature& feature, string label, std::ostream& ofs);
//inline void write_sparse(const Feature& feature, string label, ofstream& ofs, string name = "");
//inline void write_table(const Feature& feature, string label, ofstream& ofs, string name = "");
//inline void write_table_feature(const Feature& feature, ofstream& ofs);
template<typename Vec>
inline void add_mean_var(Feature* fe, const Vec& vec,
const string mean_name = "", const string var_name = "");
template<typename Vec>
inline void add_mean(Feature* fe, const Vec& vec,
const string mean_name = "");
template<typename Vec>
inline void add_var(Feature* fe, const Vec& vec,
const string var_name = "");
template<typename T>
inline void add_mean_var(Feature* fe, T begin, T end,
const string mean_name = "", const string var_name = "");
template<typename T>
inline void add_mean(Feature* fe, T begin, T end,
const string mean_name = "");
template<typename T>
inline void add_var(Feature* fe, T begin, T end,
const string var_name = "");
}
#endif
