#pragma once
#ifdef __FreeBSD__
#include <sys/socket.h>
#endif
#include "example.h"
#include "parse_regressor.h"
#include "parser.h"
#include "v_array.h"
#include "constant.h"
namespace GD{
void print_result(int f, float res, v_array<char> tag);
void print_audit_features(regressor &reg, example& ec, size_t offset);
float finalize_prediction(shared_data* sd, float ret);
void print_audit_features(vw&, example& ec);
void train_one_example(regressor& r, example* ex);
void train_offset_example(regressor& r, example* ex, size_t offset);
void compute_update(example* ec);
void offset_train(regressor &reg, example* &ec, float update, size_t offset);
void train_one_example_single_thread(regressor& r, example* ex);
LEARNER::learner* setup(vw& all, po::variables_map& vm);
void save_load_regressor(vw& all, io_buf& model_file, bool read, bool text);
void output_and_account_example(example* ec);
template <class R, void (*T)(R&, const float, float&)>
inline void foreach_feature(weight* weight_vector, size_t weight_mask, feature* begin, feature* end, R& dat, uint32_t offset=0, float mult=1.);
template <class R, void (*T)(R&, float, uint32_t)>
void foreach_feature(weight* weight_vector, size_t weight_mask, feature* begin, feature* end, R&dat, uint32_t offset=0, float mult=1.);
template <class R, class S, void (*T)(R&, float, S)>
inline void foreach_feature(vw& all, example& ec, R& dat);
template <class R, void (*T)(R&, float, float&)>
inline void foreach_feature(vw& all, example& ec, R& dat);
inline void vec_add(float& p, const float fx, float& fw);
inline float inline_predict(vw& all, example& ec);
}
