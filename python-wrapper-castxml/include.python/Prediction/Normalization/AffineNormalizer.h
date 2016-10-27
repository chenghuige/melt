#ifndef PREDICTION__NORMALIZATION__AFFINE_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__AFFINE_NORMALIZER_H_
#include "Prediction/Normalization/Normalizer.h"
namespace gezi {
class AffineNormalizer : public Normalizer
{
public:
virtual ~AffineNormalizer();
AffineNormalizer();
virtual bool LoadText(string infile);
virtual void SaveText(string outfile);
virtual void Save(string path);
virtual bool Load(string path);
virtual void Begin();
virtual void Finish();
void AffineInit();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
Fvec _offsets;
Fvec _scales;
vector<uint64> _counts;
};
}
//CEREAL_REGISTER_TYPE(gezi::AffineNormalizer);
#endif
