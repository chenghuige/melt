#ifndef OPENMP_UTIL_H_
#define OPENMP_UTIL_H_
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#define omp_get_num_procs() 1
#define omp_set_num_threads {}
#endif
#include <algorithm>
namespace gezi {
inline int get_num_threads();
inline int set_num_threads(int numThreads = 0, int reduce = 0);
}
#endif
