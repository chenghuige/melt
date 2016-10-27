#ifndef UNIQUE_ADD_AND_COPY_H_
#define UNIQUE_ADD_AND_COPY_H_
namespace common_algorithm
{
inline _OutputIterator
inline _OutputIterator
unique_add_copy(_InputIterator __first, _InputIterator __last,
_OutputIterator __result);
_ForwardIterator
_ForwardIterator
__unique_add_copy(_InputIterator __first, _InputIterator __last,
_ForwardIterator __result,
forward_iterator_tag);
_OutputIterator
_OutputIterator
__unique_add_copy(_InputIterator __first, _InputIterator __last,
_OutputIterator __result,
output_iterator_tag);
};
#endif
