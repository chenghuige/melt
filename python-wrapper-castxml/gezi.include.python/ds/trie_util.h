#ifndef GEZI_DS_TRIE_UTIL_H_
#define GEZI_DS_TRIE_UTIL_H_
namespace gezi {
namespace trie {
template <class Map>
typename Map::mapped_type get_default(
const Map& map, const typename Map::key_type& key,
const typename Map::mapped_type& dflt =
typename Map::mapped_type());
}
}
#endif
