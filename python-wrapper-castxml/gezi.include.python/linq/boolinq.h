#pragma once
#include <set>
#include <list>
#include <deque>
#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <climits>
namespace boolinq
{
class EnumeratorEndException
{
}
;
template<typename T, typename S>
class Enumerator
{
std::function<T(S&)> _nextObject;
S _data;
public:
typedef T value_type;
Enumerator(std::function<T(S&)> nextObject, S data);
T nextObject();
};
//template<typename T, typename S>
//std::ostream & operator << (std::ostream & stream, Enumerator<T,S> enumerator);
template<typename TI, typename TC>
class IteratorContainerPair
{
std::function<TI(const TC &)> get_ti;
public:
TC second;
TI first;
IteratorContainerPair(const TC & tc, std::function<TI(const TC &)> get_ti);
IteratorContainerPair(const IteratorContainerPair<TI,TC> & pair);
};
enum BytesDirection
{
FirstToLast,
LastToFirst,
};
enum BitsDirection
{
HighToLow,
LowToHigh,
};
template<typename TE>
class LinqObj
{
typedef typename TE::value_type T;
static auto get_return_type(TFunc * func = NULL, TArg * arg1 = NULL)
-> decltype((*func)(*arg1));
static auto get_return_type(TFunc * func = NULL, T1Arg * arg1 = NULL, T2Arg * arg2 = NULL)
-> decltype((*func)(*arg1,*arg2));
public:
TE _enumerator;
typedef typename TE::value_type value_type;
LinqObj(TE enumerator);
T nextObject();
void foreach_i(std::function<void(T,int)> action) const;
void foreach(std::function<void(T)> action) const;
LinqObj<Enumerator<T,std::pair<TE,int> > > where_i(std::function<bool(T,int)> predicate) const;
LinqObj<Enumerator<T,std::pair<TE,int> > > where(std::function<bool(T)> predicate) const;
LinqObj<Enumerator<T,std::pair<TE,int> > > take(int count) const;
LinqObj<Enumerator<T,std::pair<TE,int> > > takeWhile_i(std::function<bool(T,int)> predicate) const;
LinqObj<Enumerator<T,std::pair<TE,int> > > takeWhile(std::function<bool(T)> predicate) const;
LinqObj<Enumerator<T,std::pair<TE,int> > > skip(int count) const;
LinqObj<Enumerator<T,std::pair<TE,int> > > skipWhile_i(std::function<bool(T,int)> predicate) const;
LinqObj<Enumerator<T,std::pair<TE,int> > > skipWhile(std::function<bool(T)> predicate) const;
template<typename TRet>
LinqObj<Enumerator<TRet,std::pair<TE,int> > > select_i(std::function<TRet(T,int)> transform) const;
template<typename TFunc>
LinqObj<Enumerator<decltype(get_return_type<TFunc,T,int>()),std::pair<TE,int> > > select_i(TFunc transform) const;
template<typename TRet>
LinqObj<Enumerator<TRet,std::pair<TE,int> > > select(std::function<TRet(T)> transform) const;
template<typename TFunc>
LinqObj<Enumerator<decltype(get_return_type<TFunc,T>()),std::pair<TE,int> > > select(TFunc transform) const;
template<typename TRet>
LinqObj<Enumerator<TRet,std::pair<TE,int> > > cast() const;
template<typename TRet>
LinqObj<Enumerator<T,std::pair<TE,std::set<TRet> > > > distinct(std::function<TRet(T)> transform) const;
template<typename TFunc>
LinqObj<Enumerator<T,std::pair<TE,std::set<decltype(get_return_type<TFunc,T>())> > > > distinct(TFunc transform) const;
LinqObj<Enumerator<T,std::pair<TE,std::set<T> > > > distinct() const;
protected:
template<typename T, typename TRet>
class transform_comparer
{
public:
std::function<TRet(T)> func;
transform_comparer(std::function<TRet(T)> func);
bool operator()(const T & a, const T & b) const;
};
public:
LinqObj<Enumerator<T,IteratorContainerPair<typename std::multiset<T,transform_comparer<T,TRet> >::iterator,
std::multiset<T,transform_comparer<T,TRet> > > > >
orderBy(std::function<TRet(T)> transform) const;
LinqObj<Enumerator<T,IteratorContainerPair<typename std::multiset<T,transform_comparer<T,decltype(get_return_type<TFunc,T>())> >::iterator,
std::multiset<T,transform_comparer<T,decltype(get_return_type<TFunc,T>())> > > > >
orderBy(TFunc transform) const;
LinqObj<Enumerator<T,IteratorContainerPair<typename std::multiset<T,transform_comparer<T,T> >::iterator,
std::multiset<T,transform_comparer<T,T> > > > > orderBy() const;
LinqObj<Enumerator<T,IteratorContainerPair<typename std::vector<T>::const_reverse_iterator,std::vector<T> > > > reverse() const;
template<typename TRet>
TRet aggregate(TRet start, std::function<TRet(TRet,T)> accumulate) const;
template<typename TRet>
TRet sum(std::function<TRet(T)> transform) const;
template<typename TFunc>
decltype(get_return_type<TFunc,T>()) sum(TFunc transform) const;
template<typename TRet>
TRet sum() const;
T sum() const;
template<typename TRet>
TRet avg(std::function<TRet(T)> transform) const;
template<typename TFunc>
decltype(get_return_type<TFunc,T>()) avg(TFunc transform) const;
template<typename TRet>
TRet avg() const;
T avg() const;
int count(std::function<bool(T)> predicate) const;
int count(const T & value) const;
int count() const;
bool any(std::function<bool(T)> predicate) const;
bool any() const;
bool all(std::function<bool(T)> predicate) const;
bool all() const;
bool contains(const T & value) const;
T elect(std::function<T(T,T)> accumulate) const;
template<typename TRet>
T max(std::function<TRet(T)> transform) const;
template<typename TFunc>
T max(TFunc transform) const;
T max() const;
template<typename TRet>
T min(std::function<TRet(T)> transform) const;
template<typename TFunc>
T min(TFunc transform) const;
T min() const;
T elementAt(int index) const;
T first(std::function<bool(T)> predicate) const;
T first() const;
T firstOrDefault(std::function<bool(T)> predicate);
T firstOrDefault() const;
T last(std::function<bool(T)> predicate) const;
T last() const;
T lastOrDefault(std::function<bool(T)> predicate) const;
T lastOrDefault() const;
template<typename TE2>
LinqObj<Enumerator<T,std::pair<bool,std::pair<TE,TE2> > > > concat(LinqObj<TE2> rhs) const;
std::vector<T> toVector() const;
std::set<T> toSet() const;
std::list<T> toList() const;
std::deque<T> toDeque() const;
LinqObj<Enumerator<int,std::pair<int,std::pair<TE,T> > > > bytes(BytesDirection direction = FirstToLast) const;
template<typename TRet>
LinqObj<Enumerator<TRet,TE> > unbytes(BytesDirection direction = FirstToLast) const;
LinqObj<Enumerator<int,std::pair<int,std::pair<LinqObj<Enumerator<int,std::pair<int,std::pair<TE,T> > > >,unsigned char> > > >
bits(BitsDirection direction = HighToLow, BytesDirection bytesDirection = FirstToLast) const;
LinqObj<Enumerator<unsigned char,TE> > unbits(BitsDirection direction = HighToLow) const;
template<typename TRet>
LinqObj<Enumerator<TRet,Enumerator<unsigned char,TE> > > unbits(BitsDirection direction = HighToLow, BytesDirection bytesDirection = FirstToLast) const;
//template<typename TE_>
//friend std::ostream & operator << (std::ostream & stream, LinqObj<TE_> linq);
};
//template<typename TE>
//std::ostream & operator << (std::ostream & stream, LinqObj<TE> linq);
template<typename T, typename TI>
LinqObj<Enumerator<T,TI> > from(TI begin, TI end);
template<typename T, typename TI>
LinqObj<Enumerator<T,std::pair<TI,int> > > from(TI begin, int length);
auto from(T (&array)[N])
-> decltype(from<T>(array, array + N))
{
return from<T>(array, array + N);
}
template<template<class,class> class TV, typename TT, typename TU>
LinqObj<Enumerator<TT,IteratorContainerPair<typename TV<TT,TU>::const_iterator,TV<TT,TU> > > > from(TV<TT,TU> & container);
template<typename T>
LinqObj<Enumerator<T,int> > repeat(T value, int count);
template<typename T>
LinqObj<Enumerator<T,std::pair<bool,T> > > range(T begin, T end, T step);
}
