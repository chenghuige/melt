#ifndef SORT_UTIL_H_
#define SORT_UTIL_H_
#include "vector_def.h"
namespace gezi {
struct CmpNode
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpNodeValue
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpNodeReverse
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpNodeReverseValue
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpNodeFirst
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpNodeReverseFirst
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpPairByFirst
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpPairBySecond
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpPairByFirstReverse
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpPairBySecondReverse
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpPairBySecondDesc
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct EqualPairByFirst
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct EqualPairBySecond
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct EqualNodeFirst
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct EqualNodeByID
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpNodeByID
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct EqualNodeByIndex
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
struct CmpNodeByIndex
{
template<typename _Node>
bool operator() (const _Node& left, const _Node& right);
};
template<typename ValueVec = vector<double>, typename IndexVec = vector<int> >
struct IndexCmper
{
const ValueVec* valueVec;
typedef typename IndexVec::value_type T;
IndexCmper();
IndexCmper(const ValueVec& valueVec_);
bool operator() (T left, T right);
};
template<typename ValueVec = vector<double>, typename IndexVec = vector<int> >
struct IndexReverseCmper
{
const ValueVec* valueVec;
typedef typename IndexVec::value_type T;
IndexReverseCmper();
IndexReverseCmper(const ValueVec& valueVec_);
bool operator() (T left, T right);
};
template<typename ValueVec, typename IndexVec, typename Func>
void sort(const ValueVec& valueVec, IndexVec& indexVec, Func func);
template<typename ValueVec, typename IndexVec>
void sort(const ValueVec& valueVec, IndexVec& indexVec);
template<typename ValueVec, typename IndexVec, typename Func>
void sort(const ValueVec& valueVec, IndexVec& indexVec, int maxLen, Func func);
template<typename ValueVec, typename IndexVec>
void sort(ValueVec& valueVec, IndexVec& indexVec, int maxLen);
template<typename Vec, typename Func>
void sort(Vec& vec, int maxLen, Func func);
template<typename Vec, typename Func>
void partial_sort(Vec& vec, int maxLen, Func func);
template<typename Vec>
void partial_sort(Vec& vec, int maxLen);
template<typename ValueVec>
void index_sort(const ValueVec& valueVec, vector<int>& indexVec);
template<typename ValueVec, typename Compare>
void index_sort(const ValueVec& valueVec, vector<int>& indexVec, Compare compare);
template<typename ValueVec>
void index_sort(const ValueVec& valueVec, vector<int>& indexVec, int maxLen);
template<typename ValueVec, typename Compare>
void index_sort(const ValueVec& valueVec, vector<int>& indexVec, Compare compare, int maxLen);
template<typename ValueVec>
vector<int> index_sort(const ValueVec& valueVec);
template<typename ValueVec, typename Compare>
vector<int> index_sort(const ValueVec& valueVec, Compare compare);
template<typename ValueVec>
vector<int> index_sort(const ValueVec& valueVec, int maxLen);
template<typename ValueVec, typename Compare>
vector<int> index_sort(const ValueVec& valueVec, Compare compare, int maxLen);
namespace ufo
{
template<typename Vec>
void sort(Vec& vec);
}
}
#endif
