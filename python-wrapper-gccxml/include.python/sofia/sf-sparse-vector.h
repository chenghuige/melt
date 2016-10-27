#ifndef SF_SPARSE_VECTOR_H__
#define SF_SPARSE_VECTOR_H__
#include <float.h>
#include <string>
#include <vector>
#define SF_UNDEFINED_VAL FLT_MAX
using std::string;
using std::vector;
struct FeatureValuePair
{
int id_;
float value_;
};
class SfSparseVector
{
public:
SfSparseVector(bool use_bias_term);
SfSparseVector(const char* in_string);
SfSparseVector(const char* in_string, bool use_bias_term);
SfSparseVector(const SfSparseVector& a, const SfSparseVector& b, float y);
string AsString() const;
inline int NumFeatures() const;
inline int FeatureAt(int i) const;
inline float ValueAt(int i) const;
void SetY(float new_y);
void SetA(float new_a);
void SetGroupId(const string& new_id);
void SetComment(const string& new_comment);
float GetY() const;
float GetA() const;
float GetSquaredNorm() const;
const string& GetGroupId() const;
const string& GetComment() const;
void PushPair (int id, float value);
void ClearFeatures();
private:
void AddToSquaredNorm(float addend);
void Init(const char* in_string);
void SetBias();
void NoBias();
void DieFormat(const string& reason);
vector<FeatureValuePair> features_;
float y_;
float a_;
float squared_norm_;
string group_id_;
string comment_;
};
#endif
