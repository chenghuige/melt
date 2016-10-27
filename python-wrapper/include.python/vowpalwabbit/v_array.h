#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#ifdef _WIN32
#define __INLINE
#else
#define __INLINE inline
#endif
const size_t erase_point = ~ ((1 << 10) -1);
{
public:
T* begin;
T* end;
T* end_array;
size_t erase_count;
T last()
{
return *(end-1);
}
T pop()
{
return *(--end);
}
bool empty()
{
return begin;
}
void decr()
{
end--;
}
v_array()
{
begin;
}
T& operator[](size_t i)
{
return begin[i];
}
T& get(size_t i)
{
return begin[i];
}
size_t size()
{
return end-begin;
}
void resize(size_t length, bool zero_everything=false)
{
if ((size_t)(end_array-begin) != length)
{
size_t old_len;
begin;
if ((begin == NULL) && ((sizeof(T)*length) > 0))
{
std::cerr << "realloc of " << length << " failed in resize().  out of memory?" << std::endl;
throw std::exception();
}
if (zero_everything && (old_len < length))
memset(begin+old_len, 0, (length-old_len)*sizeof(T));
end;
end_array;
}
}
void erase()
{
if (++erase_count & erase_point)
{
resize(end-begin);
erase_count;
}
end;
}
void delete_v()
{
if (begin != NULL)
free(begin);
begin;
}
void push_back(const T &new_ele)
{
if(end == end_array)
resize(2 * (end_array-begin) + 3);
*(end++) = new_ele;
}
size_t find_sorted(const T& ele)
{
size_t size;
size_t a;
size_t b;
size_t i;
while(b - a > 1)
{
if(begin[i] < ele)
a;
else if(begin[i] > ele)
b;
else
return i;
i;
}
if((size == 0) || (begin[a] > ele) || (begin[a] == ele))
return a;
else
return b;
}
size_t unique_add_sorted(const T &new_ele)
{
size_t index;
size_t size;
size_t to_move;
if(!contain_sorted(new_ele, index))
{
if(end == end_array)
resize(2 * (end_array-begin) + 3);
to_move;
if(to_move > 0)
memmove(begin + index + 1, begin + index, to_move * sizeof(T));
begin[index];
end++;
}
return index;
}
bool contain_sorted(const T &ele, size_t& index)
{
index;
if(index == this->size())
return false;
if(begin[index] == ele)
return true;
return false;
}
};
#ifdef _WIN32
#undef max
#undef min
#endif
inline size_t max(size_t a, size_t b);
inline size_t min(size_t a, size_t b);
{
dst.erase();
push_many(dst, src.begin, src.size());
}
{
dst.erase();
for (T*item;
dst.push_back(copy_item(*item));
}
{
if(v.end+num >= v.end_array)
v.resize(max(2 * (size_t)(v.end_array - v.begin) + 3,
v.end - v.begin + num));
memcpy(v.end, begin, num * sizeof(T));
v.end +;
}
{
v.begin;
v.end;
v.end_array;
}
{
if (stack.end != stack.begin)
return *(--stack.end);
else
return v_array<T>();
}
{
for (T* e;
if (*e;
return false;
}
