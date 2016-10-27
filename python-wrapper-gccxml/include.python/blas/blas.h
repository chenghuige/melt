#ifndef BLAS_INCLUDE
#define BLAS_INCLUDE
typedef struct
{
float r, i;
}
fcomplex;
typedef struct
{
double r, i;
}
dcomplex;
typedef int blasbool;
#include "blasp.h"
#define FALSE 0
#define TRUE  1
#define MIN(a,b) ((a) <= (b) ? (a) : (b))
#define MAX(a,b) ((a) >= (b) ? (a) : (b))
#endif
