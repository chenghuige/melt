#include <ds/traits.h>
#include "map_util.h"
#include "vector_def.h"
#include "common_def.h"
#include "serialize_util.h"
#include "ds/traits.h"
namespace gezi {
#ifdef GEZI_DATA_TRUE_INDICATOR
#ifndef GEZI_TRIE_INDEX_IS_VALUE
#define GEZI_TRIE_NAME Trie
#else
#define  GEZI_TRIE_NAME TrieDict_
#endif
#endif
#ifdef GEZI_DATA_FALSE_INDICATOR
#define GEZI_TRIE_NAME TrieSet_
#endif
template<typename Key,
typename Mapped,
template<class _Kty, class _Ty, typename...> class _Map = std::unordered_map>
class GEZI_TRIE_NAME
{
public:
typedef Key key_type;
typedef Mapped mapped_type;
typedef typename key_mapped_traits<Key, Mapped>::value_type value_type;
typedef typename key_mapped_traits<Key, Mapped>::iterator iterator;
typedef typename key_mapped_traits<Key, Mapped>::const_iterator const_iterator;
typedef typename key_type::value_type char_type;
#ifndef GEZI_TRIE_INDEX_IS_VALUE
typedef typename key_mapped_traits<Key, Mapped>::index_type index_type;
#else
typedef mapped_type index_type;
#endif
typedef size_t size_type;
struct Node;
typedef unique_ptr<Node> NodePtr;
typedef _Map<char_type, Node > Map;
typedef unique_ptr<Map> MapPtr;
enum
{
#ifdef GEZI_DATA_TRUE_INDICATOR
null_index = -1,
#else
null_index = 0,
#endif
};
struct Node
{
index_type index;
MapPtr next;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
pair<iterator, bool> insert(const value_type& value);
#ifdef GEZI_DATA_TRUE_INDICATOR
pair<iterator, bool> insert(const key_type& key, const mapped_type& mapped);
//pair<iterator, bool> insert(const key_type& key, mapped_type&& mapped);
//mapped_type& operator[](const key_type& key);
#endif
size_type count(const key_type& key) const;
size_type prefix_count(const key_type& key) const;
bool empty() const;
bool search(const key_type& key) const;
bool prefix_search(const key_type& key) const;
const Node* root() const;
static const Node* find(const Node* pnode, const key_type& key);
//iterator end() const;
iterator find(const key_type& key);
const_iterator find(const key_type& key) const;
size_type count(const Node* pnode) const;
size_type size() const;
void print() const;
void print(const Node* pnode, key_type key) const;
protected:
Node* insert_key(const key_type& key);
private:
Node _root;
#ifdef GEZI_DATA_TRUE_INDICATOR
#ifndef GEZI_TRIE_INDEX_IS_VALUE
vector<mapped_type> _mappedVec;
#endif
#endif
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
#ifdef GEZI_DATA_FALSE_INDICATOR
using TrieSet;
#endif
#ifdef GEZI_DATA_TRUE_INDICATOR
#ifdef GEZI_TRIE_INDEX_IS_VALUE
using TrieDict;
#endif
#endif
}
#undef GEZI_TRIE_NAME
