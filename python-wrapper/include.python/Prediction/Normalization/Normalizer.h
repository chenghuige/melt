#ifndef PREDICTION__NORMALIZATION__NORMALIZER_H_
#define PREDICTION__NORMALIZATION__NORMALIZER_H_
#include "common_util.h"
#include "Prediction/Instances/Instances.h"
#include "Numeric/Vector/vector_util.h"
namespace gezi {
class Normalizer : public LoadSave
{
public:
enum  NormType
{
NormType__enum__Affine,
NormType__enum__Bin,
};
virtual ~Normalizer();
Normalizer();
void ParseArgs();
virtual string Name();
virtual void Process(const Vector& vec);
template<typename _Vector>
void Normalize(_Vector& vec);
template<typename _Vector>
_Vector NormalizeCopy(const _Vector& vec);
#ifdef PYTHON_WRAPPER
void Normalize(Vector& vec);
Vector NormalizeCopy(const Vector& vec);
#endif
void Normalize(Instance& instance);
Instance NormalizeCopy(const Instance& instance);
InstancePtr NormalizeCopy(InstancePtr instance);
Instances NormalizeCopy(const Instances& instances);
void Normalize(InstancePtr instance);
virtual void Begin();
virtual void Finish();
void Prepare(const Instances& instances);
void RunNormalize(Instances& instances);
Instances RunNormalizeCopy(const Instances& instances);
void Normalize(Instances& instances);
bool Trunct() const;
void SetTrunct(bool trunct);
protected:
template<typename Func>
void Normalize(Vector& vec, Func func);
template<typename Func>
void NormalizeDense(Vector& vec, Func func);
template<typename Func>
void NormalizeSparse(Vector& vec, Func func);
template<typename Func>
void NormalizeDenseFast(Vector& vec, Func func);
template<typename Func, typename _Vector>
void NormalizeSparseFast(_Vector& vec, Func func);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
protected:
std::function<void(int, Float&)> _func;
NormType _normType;
int _numFeatures;
FeatureNamesVector _featureNames;
ivec _morphIndices;
ivec _shiftIndices;
bool _trunct;
uint64 _maxNormalizationExamples;
uint64 _numProcessedInstances;
private:
};
typedef shared_ptr<Normalizer> NormalizerPtr;
}
#endif
