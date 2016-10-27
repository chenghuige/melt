#pragma once
namespace CB_ALGS {
LEARNER::learner* setup(vw& all, po::variables_map& vm);
template <bool is_learn>
float get_cost_pred(vw& all, CB::cb_class* known_cost, example& ec, uint32_t index, uint32_t base);
}
