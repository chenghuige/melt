#ifndef LRU_SET_H_
#define LRU_SET_H_
#include "common_util.h"
namespace gezi {
template<typename Key, template<class _Kty, typename...> class _Set = std::set>
class LruSet
{
public:
typedef _Set<Key> Set;
LruSet(int maxNum);
LruSet();
void set_capacity(int maxNum);
bool empty() const;
bool insert(const Key& item);
bool count(const Key& item) const;
int size() const;
int capacity() const;
protected:
private:
Set _set;
deque<Key> _queue;
int _capacity;
};
using LruHashSet;
}
#endif
