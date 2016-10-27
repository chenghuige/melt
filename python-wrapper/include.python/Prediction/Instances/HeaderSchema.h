#ifndef PREDICTION__INSTANCES__HEADER_SCHEMA_H_
#define PREDICTION__INSTANCES__HEADER_SCHEMA_H_
#include "common_util.h"
#include "FeatureNamesVector.h"
namespace gezi
{
enum  FileFormat
{
FileFormat__enum__Unknown,
FileFormat__enum__Dense,
FileFormat__enum__Sparse,
FileFormat__enum__SparseNoLength,
FileFormat__enum__Text,
FileFormat__enum__LibSVM,
FileFormat__enum__Arff,
FileFormat__enum__VW,
FileFormat__enum__MallocRank,
};
enum  ColumnType
{
ColumnType__enum__Unknown,
ColumnType__enum__Feature,
ColumnType__enum__Name,
ColumnType__enum__Label,
ColumnType__enum__Weight,
ColumnType__enum__Attribute,
ColumnType__enum__Category,
ColumnType__enum__Text,
};
class HeaderSchema
{
public:
~HeaderSchema();
HeaderSchema();
//HeaderSchema(HeaderSchema&&);
//HeaderSchema& operator = (HeaderSchema&&);
HeaderSchema(const HeaderSchema&);
HeaderSchema& operator = (const HeaderSchema&);
bool operator==(const HeaderSchema& other) const;
public:
int FeatureNum() const;
int NumFeatures() const;
bool HasHeader() const;
string HeaderStr() const;
void SetHeader(string header_, bool hasHeader_);
FileFormat GetFileFormat() const;
protected:
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
public:
FeatureNamesVector featureNames;
svec attributeNames;
svec tagNames;
string headerStr;
vector<ColumnType> columnTypes;
bool hasHeader;
bool hasWeights;
svec groupKeys;
FileFormat fileFormat;
string instanceNameHeaderString;
bool normalized;
int numClasses;
};
}
#endif
