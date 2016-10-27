#ifndef PREDICTION__INSTANCES__INSTANCES_H_
#define PREDICTION__INSTANCES__INSTANCES_H_
#include "common_util.h"
#include "Prediction/Instances/HeaderSchema.h"
#include "Prediction/Instances/Instance.h"
#include "random_util.h"
namespace gezi {
struct Instances : public ListInstances
{
public:
~Instances();
Instances();
//Instances(Instances&&);
//Instances& operator = (Instances&&);
Instances(const Instances&);
Instances& operator = (const Instances&);
explicit Instances(const HeaderSchema& schema_)
:schema(schema_)
{
}
void CopySchema(const HeaderSchema& schema_);
size_t InstanceNum() const;
size_t Size() const;
size_t Count() const;
int FeatureNum() const;
int NumFeatures() const;
const FeatureNamesVector& FeatureNames() const;
//Float& operator()(size_t row, size_t col);
const Float operator()(size_t row, size_t col) const;
FeatureNamesVector& FeatureNames();
bool HasHeader() const;
string HeaderStr() const;
void SetHeader(string header_, bool hasHeader_);
void Randomize(const RandomEngine& rng);
void ShrinkData(double trainProportion, const RandomEngine& rng);
void Add(const InstancePtr& instancePtr);
void PrintSummary(int level = 0) const;
uint64 PositiveCount() const;
uint64 NegativeCount() const;
uint64 SparseCount() const;
uint64 DenseCount() const;
void SetNormalized(bool norm = true);
bool IsNormalized() const;
bool IsRankingInstances() const;
bool IsBinaryClassificationInstances() const;
bool IsClassificationInstances() const;
bool IsMultiClassificationInstances() const;
bool IsRegressionInstances() const;
int NumClasses() const;
size_t NumGroups() const;
#ifndef GCCXML
typedef unordered_map<string, ListInstances> GroupMap;
GroupMap& GetGroups();
#endif
public:
HeaderSchema schema;
string name;
#ifndef GCCXML
GroupMap groups;
#endif
};
}
namespace cereal
{
template <class Archive> inline
void CEREAL_SAVE_FUNCTION_NAME(Archive & ar, gezi::Instances const & vector);
template <class Archive> inline
void CEREAL_LOAD_FUNCTION_NAME(Archive & ar, gezi::Instances & vector);
}
#endif
