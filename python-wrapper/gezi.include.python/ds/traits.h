#ifndef GEZI_DS_TRAITS_H_
#define GEZI_DS_TRAITS_H_
namespace gezi {
struct null_type
{
}
;
template<typename Key, typename Mapped>
struct key_mapped_traits
{
typedef pair<Key, Mapped> value_type;
typedef Mapped* iterator;
typedef const Mapped* const_iterator;
typedef int index_type;
};
template<typename Key>
struct key_mapped_traits < Key, null_type >
{
typedef Key value_type;
typedef void* iterator;
typedef void* const_iterator;
typedef bool index_type;
};
}
#endif
