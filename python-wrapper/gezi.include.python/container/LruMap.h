#ifndef LRU_MAP_H_
#define LRU_AMP_H_
#include "common_util.h"
namespace gezi {
template<typename _Key, typename _Value,
template<class _Kty, class _Ty, typename...> class _Map = std::map>
class LruMap
{
public:
typedef _Key Key;
typedef _Value Value;
typedef _Map<Key, Value> Map;
typedef deque<Key> Deque;
typedef typename Map::iterator iterator;
typedef typename Map::const_iterator const_iterator;
LruMap();
LruMap(size_t capacity);
//LruMap(Map&& m, size_t capacity = 1024);
void set_capacity(size_t capacity);
pair<iterator, bool> insert(const pair<Key, Value>& node);
bool insert(const Key& item, const Value& value);
bool update(const Key& item, const Value& value);
bool empty();
const Value& operator [](const Key& item) const;
Value& operator [](const Key& key);
iterator find(const Key& key);
const_iterator find(const Key& key) const;
Value& value(const Key& key, bool& find);
bool count(const Key& item);
size_t size();
const Map& get_map() const;
Map& get_map();
Deque& get_queue();
void clear();
//iterator begin();
//iterator end();
protected:
private:
Map _map;
Deque _queue;
size_t _capacity;
};
using LruHashMap;
}
#endif
