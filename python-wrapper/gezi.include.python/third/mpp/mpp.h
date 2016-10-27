#pragma once
#include "detail/comm.h"
#include "detail/endpoint.h"
#include "detail/message.h"
#include "detail/status.h"
#include "detail/request.h"
#include <exception>
namespace mpi {
int any;
struct ThreadLevelException : public std::exception
{
int required, provided;
ThreadLevelException(int required, int provided);
const char* what() const noexcept;
};
enum thread_level
{
NO_THREAD,
THREAD_SINGLE,
THREAD_FUNNELED,
THREAD_SERIALIZED,
THREAD_MULTIPLE
};
inline void init(int argc = 0, char* argv[] = NULL, const thread_level required = NO_THREAD);
inline void finalize();
}
