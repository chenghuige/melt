#ifndef RABIT_UTIL_H_
#define RABIT_UTIL_H_
#include "rabit.h"
#include "serialize_util.h"
#include "stl_util.h"
#include <vector>
namespace gezi
{
namespace op = rabit::op;
struct RabitObject
{
bool visited;
};
struct Rabit
{
Rabit(int argc, char *argv[]);
~Rabit();
//static bool& AllowDistribute();
inline static bool Choose(size_t i);
inline static bool SimpleChoose(size_t i);
static int GetWorldSize();
static int GetRank();
template<typename T>
static void SerializeBroadcast(T& data, int root);
template<typename T>
static void SerializeBroadcast(std::vector<T>& datas);
template<typename DType, void(*freduce)(DType &dst, const DType &src)>
static void Allreduce(DType* dest, size_t count);
template<typename DType, void(*freduce)(DType &dst, const DType &src)>
static void Allreduce(vector<DType>& vec);
template<typename DType, void(*freduce)(DType &dst, const DType &src)>
static void Allreduce(DType& dest);
template<typename OP, typename DType>
static void Allreduce(vector<DType>& vec,
void(*prepare_fun)(void *arg) = NULL,
void *prepare_arg = NULL);
template<typename OP, typename DType>
static void Allreduce(DType& data);
template<typename DType>
static void Broadcast(DType& data, int root);
template<typename DType>
static void Broadcast(vector<DType>& data, int root);
template<typename DType>
static void Allgather(vector<DType>& datas);
template<typename DType>
static vector<DType> Allgather(const DType& datas);
static void Broadcast(vector<bool>& data, int root);
};
#define  PARALLEL_CHOOSE(i) \
if (!Rabit::Choose(i)) \
continue
}
#endif
