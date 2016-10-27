#ifndef GEZI_COMMON_DEFINE_H_
#define GEZI_COMMON_DEFINE_H_
#if (!defined(GCCXML) && (__GNUC__ > 3 || defined(WIN32)))
#define IS_HIGH_COMPILER 1
#else
#define IS_HIGH_COMPILER 0
#endif
#if (!defined(GCCXML) && (__GNUC__ > 3 || defined(WIN32)))
#define IS_HIGH_COMPILER_NOGCCXML 1
#else
#define IS_HIGH_COMPILER_NOGCCXML 0
#endif
#if ((__GNUC__ > 3 || defined(WIN32)))
#define IS_HIGH_COMPILER_ 1
#else
#define IS_HIGH_COMPILER_ 0
#endif
#endif
