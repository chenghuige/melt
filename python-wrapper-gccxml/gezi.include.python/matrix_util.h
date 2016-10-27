#ifndef MATRIX_UTIL_H_
#define MATRIX_UTIL_H_
#include "common_def.h"
#include "Matrix.h"
#include "Eigen/Dense"
using namespace Eigen;
namespace gezi {
typedef Matrix< double, Dynamic, Dynamic > Mat;
typedef Matrix< double, Dynamic, Dynamic > DMat;
typedef Matrix< float, Dynamic, Dynamic > FlMat;
typedef Matrix< Float, Dynamic, Dynamic > FMat;
typedef Matrix< int, Dynamic, Dynamic > IMat;
typedef Matrix< double, Dynamic, 1 > Vec;
typedef Matrix< float, Dynamic, 1 > FlVec;
typedef Matrix< Float, Dynamic, 1 > FLVec;
typedef Matrix< int, Dynamic, 1 > IVec;
typedef Matrix< double, 1, Dynamic> RVec;
typedef Matrix< float, 1, Dynamic> FlRVec;
typedef Matrix< Float, 1, Dynamic> FRVec;
typedef Matrix< int, 1, Dynamic> IRVec;
typedef Matrix< double, 2, 2 > Mat2;
typedef Matrix< double, 3, 3 > Mat3;
typedef Matrix< double, 4, 4 > Mat4;
typedef Matrix< float, 2, 2 > FlMat2;
typedef Matrix< float, 3, 3 > FlMat3;
typedef Matrix< float, 4, 4 > FlMat4;
typedef Matrix< Float, 2, 2 > FMat2;
typedef Matrix< Float, 3, 3 > FMat3;
typedef Matrix< Float, 4, 4 > FMat4;
typedef Matrix< int, 2, 2 > IMat2;
typedef Matrix< int, 3, 3 > IMat3;
typedef Matrix< int, 4, 4 > IMat4;
typedef Matrix< double, 2, 1 > Vec2;
typedef Matrix< double, 3, 1 > Vec3;
typedef Matrix< double, 4, 1 > Vec4;
typedef Matrix< float, 2, 1 > FlVec2;
typedef Matrix< float, 3, 1 > FlVec3;
typedef Matrix< float, 4, 1 > FlVec4;
typedef Matrix< Float, 2, 1 > FVec2;
typedef Matrix< Float, 3, 1 > FVec3;
typedef Matrix< Float, 4, 1 > FVec4;
typedef Matrix< int, 2, 1 > IVec2;
typedef Matrix< int, 3, 1 > IVec3;
typedef Matrix< int, 4, 1 > IVec4;
}
#endif
