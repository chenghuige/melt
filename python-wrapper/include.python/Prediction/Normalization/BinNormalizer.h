#ifndef PREDICTION__NORMALIZATION__BIN_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__BIN_NORMALIZER_H_
#include "common_util.h"
#include "Matrix.h"
#include "Prediction/Normalization/Normalizer.h"
#include "Numeric/BinFinder.h"
namespace gezi {
class BinNormalizer : public Normalizer
{
public:
BinNormalizer();
#ifndef MELT_ONLINE
void ParseArgs();
#else
void ParseArgs();
#endif
BinNormalizer(string path);
virtual bool Load(string path);
virtual void Save(string path);
virtual string Name();
virtual void Begin();
virtual void Process(const Vector& vec);
virtual void Finish();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
const Fmat& BinUpperBounds() const;
public:
int maxBins;
Fmat binUpperBounds;
private:
Fmat binValues;
Fmat values;
BitArray _included;
};
}
//CEREAL_REGISTER_TYPE(gezi::BinNormalizer);
#endif
