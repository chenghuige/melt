#ifndef PREDICTION__NORMALIZATION__NORMALIZER_FACTORY_H_
#define PREDICTION__NORMALIZATION__NORMALIZER_FACTORY_H_
#include "Prediction/Normalization/Normalizer.h"
#include "Prediction/Normalization/MinMaxNormalizer.h"
#include "Prediction/Normalization/GaussianNormalizer.h"
#include "Prediction/Normalization/BinNormalizer.h"
namespace gezi {
class NormalizerFactory
{
public:
static NormalizerPtr CreateNormalizer(string name);
static NormalizerPtr CreateNormalizer(string name, string path);
static NormalizerPtr Load(string path);
static void Save(NormalizerPtr normalizer, string path);
protected:
private:
};
}
#endif
