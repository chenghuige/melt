#ifndef PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_
#include "Prediction/Normalization/AffineNormalizer.h"
#include "conf_util.h"
namespace gezi {
class MinMaxNormalizer : public AffineNormalizer
{
public:
MinMaxNormalizer();
MinMaxNormalizer(string path);
virtual string Name();
virtual void Process(const Vector& vec);
void SetOffsetScale(int i, Float value);
virtual void Begin();
virtual void Finish();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
private:
bool _isFirst;
};
}
//CEREAL_REGISTER_TYPE(gezi::MinMaxNormalizer);
#endif
