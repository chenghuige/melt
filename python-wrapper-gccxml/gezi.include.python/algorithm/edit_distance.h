#ifndef _EDIT_DISTANCE_H
#define _EDIT_DISTANCE_H
#include <string>
#include <algorithm>
using std::string;
class EditDistanceHelp
{
private:
struct ArrayData
{
int dist;
int pre_x;
int pre_y;
};
public:
int CalcPath(const string &s1, const string &s2, string &rs1, string &rs2);
void StoreResult(ArrayData **array, int index_x, int index_y,
const string &s1, const string &s2,
string &rs1, string &rs2);
static inline int EditDistance(string s1, string s2);
template<typename T>
static inline int EditDistance(const T& s1, const T& s2);
template<typename T>
static inline int MaxDiffNum(T s1, T s2);
private:
static inline void SetArrayData(ArrayData &a, int dist, int pre_x, int pre_y);
};
#endif
