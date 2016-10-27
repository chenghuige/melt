#ifndef CACHED_FETCHER_H_
#define CACHED_FETCHER_H_
#include "common_util.h"
namespace gezi {
template<typename _Key, typename _Value,
template<class _Kty, class _Ty, typename...> class _Map = std::unordered_map>
class CachedFetcher
{
public:
typedef _Key Key;
typedef _Value Value;
typedef _Map<Key, Value> Map;
typedef typename Map::iterator iterator;
typedef typename Map::const_iterator const_iterator;
public:
CachedFetcher();
CachedFetcher(int capacity);
void set_capacity(int capacity);
void SetCapacity(int capacity);
template<typename Func>
Value GetValue(const Key& key, Func func);
template<typename Func>
vector<Value> GetValues(const vector<Key>& keys, Func func);
template<typename Func>
map<Key, Value> GetValuesMap(const vector<Key>& keys, Func func);
Map& GetMap();
void ClearCache();
int CacheSize() const;
protected:
private:
Map _map;
};
}
#endif
