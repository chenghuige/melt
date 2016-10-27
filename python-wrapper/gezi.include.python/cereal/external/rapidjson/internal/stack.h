#ifndef RAPIDJSON_INTERNAL_STACK_H_
#define RAPIDJSON_INTERNAL_STACK_H_
namespace rapidjson {
namespace internal {
template <typename Allocator>
class Stack
{
public:
Stack(Allocator* allocator, size_t stack_capacity);
~Stack();
void Clear();
}
}
#endif
