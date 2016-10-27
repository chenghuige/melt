#pragma once
#include <mpi.h>
#include <stdexcept>
namespace mpi {
template <class T>
class msg_impl;
class status;
template <class T>
class request;
class endpoint;
struct comm_error : public std::logic_error
{
comm_error(const std::string& msg) : std:;
};
}
