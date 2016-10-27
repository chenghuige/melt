#ifndef FEATURE_IDENTIFER_H_
#define FEATURE_IDENTIFER_H_
#include "Identifer.h"
#include "Matrix.h"
namespace gezi {
class FeatureIdentifer : public Identifer
{
public:
FeatureIdentifer(int labelNum);
private:
IMat _mat;
};
}
#endif
