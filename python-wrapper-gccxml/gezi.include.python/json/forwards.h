#ifndef JSON_FORWARDS_H_INCLUDED
# define JSON_FORWARDS_H_INCLUDED
#if !defined(JSON_IS_AMALGAMATION)
# include "config.h"
#endif
namespace Json {
class FastWriter;
class StyledWriter;
class Reader;
class Features;
typedef unsigned int ArrayIndex;
class StaticString;
class Path;
class PathArgument;
class Value;
class ValueIteratorBase;
class ValueIterator;
class ValueConstIterator;
#ifdef JSON_VALUE_USE_INTERNAL_MAP
class ValueMapAllocator;
class ValueInternalLink;
class ValueInternalArray;
class ValueInternalMap;
#endif
}
#endif
