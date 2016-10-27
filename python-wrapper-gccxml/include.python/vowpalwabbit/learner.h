#pragma once
#include<iostream>
using namespace std;
struct vw;
void return_simple_example(vw& all, void*, example& ec);
namespace LEARNER
{
struct learner;
struct func_data
{
void* data;
learner* base;
void (*func)(void* data);
};
inline func_data tuple_dbf(void* data, learner* base, void (*func)(void* data));
struct learn_data
{
void* data;
learner* base;
void (*learn_f)(void* data, learner& base, example&);
void (*predict_f)(void* data, learner& base, example&);
void (*update_f)(void* data, learner& base, example&);
};
struct save_load_data
{
void* data;
learner* base;
void (*save_load_f)(void*, io_buf&, bool read, bool text);
};
struct finish_example_data
{
void* data;
learner* base;
void (*finish_example_f)(vw&, void* data, example&);
};
void generic_driver(vw* all);
inline void generic_sl(void*, io_buf&, bool, bool);
inline void generic_learner(void* data, learner& base, example&);
inline void generic_func(void* data);
const save_load_data generic_save_load_fd;
const learn_data generic_learn_fd;
const func_data generic_func_fd;
template<class R, void (*T)(R&, learner& base, example& ec)>
inline void tlearn(void* d, learner& base, example& ec);
template<class R, void (*T)(R&, io_buf& io, bool read, bool text)>
inline void tsl(void* d, io_buf& io, bool read, bool text);
template<class R, void (*T)(R&)>
inline void tfunc(void* d);
template<class R, void (*T)(vw& all, R&, example&)>
inline void tend_example(vw& all, void* d, example& ec);
template <class T, void (*learn)(T* data, learner& base, example&), void (*predict)(T* data, learner& base, example&)>
struct learn_helper
{
void (*learn_f)(void* data, learner& base, example&);
void (*predict_f)(void* data, learner& base, example&);
learn_helper();
};
struct learner
{
private:
func_data init_fd;
learn_data learn_fd;
finish_example_data finish_example_fd;
save_load_data save_load_fd;
func_data end_pass_fd;
func_data end_examples_fd;
func_data finisher_fd;
public:
size_t weights;
size_t increment;
inline void learn(example& ec, size_t i=0);
template <class T, void (*u)(T& data, learner& base, example&)>
inline void set_learn();
inline void predict(example& ec, size_t i=0);
template <class T, void (*u)(T& data, learner& base, example&)>
inline void set_predict();
inline void update(example& ec, size_t i=0);
template <class T, void (*u)(T& data, learner& base, example&)>
inline void set_update();
inline void save_load(io_buf& io, bool read, bool text);
template <class T, void (*sl)(T&, io_buf&, bool, bool)>
inline void set_save_load();
template <class T, void (*f)(T&)>
void set_finish();
inline void finish();
void end_pass();
template <class T, void (*f)(T&)>
void set_end_pass();
void end_examples();
template <class T, void (*f)(T&)>
void set_end_examples();
void init_driver();
template <class T, void (*f)(T&)>
void set_init_driver();
inline void finish_example(vw& all, example& ec);
template<class T, void (*f)(vw& all, T&, example&)>
void set_finish_example();
void driver(vw* all);
inline learner();
inline learner(void* dat, size_t params_per_weight);
inline learner(void *dat, learner* base, size_t ws = 1);
};
}
