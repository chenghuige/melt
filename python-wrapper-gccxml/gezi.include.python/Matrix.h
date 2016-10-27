#ifndef MATRIX_H_
#define MATRIX_H_
#include "common_def.h"
#include "serialize_util.h"
namespace gezi {
namespace ufo {
template<typename T>
class Matrix
{
public:
Matrix();
Matrix(int rows, int cols);
Matrix(int rows, int cols, T defaultValue);
inline void resize(int rows, int cols);
inline void resize(int rows, int cols, T defaultValue);
void zeroset();
void set_zero();
inline const T& operator()(int rowIdx, int colIdx) const;
//inline  T& operator()(int rowIdx, int colIdx);
vector<vector<T> >& mat();
//vector<T>& operator[](int index);
inline int rows();
inline int cols();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
private:
vector<vector<T> > _mat;
int _nrow;
int _ncol;
};
}
template<typename T>
inline void init(vector<vector<T> >& mat, int rows, int cols, T value);
template<typename T>
inline void init(vector<vector<T> >& mat, int rows, int cols);
typedef vector<vector<int> > imat;
typedef vector<vector<float> > fmat;
typedef vector<vector<Float> > Fmat;
typedef vector<vector<double> > dmat;
}
#endif
