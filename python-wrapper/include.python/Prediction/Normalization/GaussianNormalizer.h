#ifndef PREDICTION__NORMALIZATION__GAUSSIAN_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__GAUSSIAN_NORMALIZER_H_
#include "Prediction/Normalization/AffineNormalizer.h"
namespace gezi {
class GaussianNormalizer : public AffineNormalizer
{
public:
GaussianNormalizer();
GaussianNormalizer(string path);
virtual string Name();
virtual void Process(const Vector& vec);
virtual void Begin();
virtual void Finish();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
private:
};
}
//CEREAL_REGISTER_TYPE(gezi::GaussianNormalizer);
#endif
