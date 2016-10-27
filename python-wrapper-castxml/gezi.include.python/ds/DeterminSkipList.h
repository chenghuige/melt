#ifndef DETERMIN_SKIP_LIST_H_
#define DETERMIN_SKIP_LIST_H_
#include <iostream>
#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&); \
void operator=(const TypeName&)
#endif
namespace gezi {
template <typename ElemType>
class SkipNode
{
public:
template <typename T>  friend class DeterminSkipList;
SkipNode();
SkipNode(const ElemType &key_input, SkipNode *right_input = NULL,
SkipNode *down_input = NULL);
private:
DISALLOW_COPY_AND_ASSIGN(SkipNode);
ElemType key;
SkipNode *right;
SkipNode *down;
};
template <typename ElemType>
SkipNode<ElemType>::SkipNode() : right(NULL), down(NULL);
SkipNode<ElemType>::SkipNode(const ElemType& key_input, SkipNode *right_input,
SkipNode *down_input)
: key(key_input), right(right_input), down(down_input)
{
}
template <typename ElemType>
class DeterminSkipList
{
public:
DeterminSkipList(const ElemType &max, const ElemType &max_1);
~DeterminSkipList();
void Clear();
bool Search(const ElemType &value) const;
bool Insert(const ElemType &value);
bool Remove(const ElemType &value);
void Print() const;
bool IsValid() const;
private:
DISALLOW_COPY_AND_ASSIGN(DeterminSkipList);
void Init();
void ClearHelp(SkipNode<ElemType> *current);
SkipNode<ElemType> * SearchHelp(const ElemType &value) const;
void FindAndModifyRemoveHelp(const ElemType &value, const ElemType &other_value);
void LowerHeadRemoveHelp();
private:
SkipNode<ElemType> *head;
SkipNode<ElemType> *bottom;
SkipNode<ElemType> *tail;
ElemType Max;
ElemType Max_1;
};
DeterminSkipList<ElemType>::DeterminSkipList(const ElemType &max, const ElemType &max_1)
: head(NULL), bottom(NULL), tail(NULL), Max(max), Max_1(max_1)
{
Init();
}
template <typename ElemType>
DeterminSkipList<ElemType>::~DeterminSkipList();
template <typename ElemType>
void DeterminSkipList<ElemType>::Init();
template <typename ElemType>
void DeterminSkipList<ElemType>::Clear();
template <typename ElemType>
void DeterminSkipList<ElemType>::ClearHelp(SkipNode<ElemType> *current);
template <typename ElemType>
inline bool DeterminSkipList<ElemType>::Search(const ElemType &value) const;
SkipNode<ElemType> * DeterminSkipList<ElemType>::
SearchHelp(const ElemType &value) const;
template <typename ElemType>
bool DeterminSkipList<ElemType>::Insert(const ElemType &value);
template <typename ElemType>
void DeterminSkipList<ElemType>::FindAndModifyRemoveHelp(const ElemType &value, const ElemType &other_value);
template <typename ElemType>
void DeterminSkipList<ElemType>::LowerHeadRemoveHelp();
template <typename ElemType>
bool DeterminSkipList<ElemType>::Remove(const ElemType &value);
template <typename ElemType>
bool DeterminSkipList<ElemType>::IsValid() const;
template <typename ElemType>
void DeterminSkipList<ElemType>::Print() const;
}
#endif
#endif
