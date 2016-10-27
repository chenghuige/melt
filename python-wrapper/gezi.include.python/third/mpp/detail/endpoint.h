#pragma once
#include "detail/decls.h"
#define OVERLOAD_SEND(name, impl) \
template <class MsgType> \
inline endpoint& name(msg_impl<MsgType>&& m) { \
return name##_impl(impl, std::move(m)); \
} \
template <class MsgType> \
inline endpoint& name(const msg_impl<MsgType>& m) { \
return name(std::move(m)); \
} \
template <class RawType> \
inline endpoint& name(const RawType& m) { \
return name( std::move( msg_impl<const RawType>(m) ) ); \
}
namespace mpi {
class endpoint
{
int 		m_rank;
comm& 	m_comm;
typedef int (*send_ptr)(void*,int,MPI_Datatype,int,int,MPI_Comm);
endpoint(const endpoint& other) = delete;
endpoint& operator=(const endpoint& other) = delete;
public:
endpoint(const int& rank, const comm& com);
//endpoint(endpoint&& other);
//template <class MsgType>
//inline endpoint& send_impl(const send_ptr& func, msg_impl<MsgType>&& m);
OVERLOAD_SEND(send, MPI_Send)
OVERLOAD_SEND(ssend, MPI_Ssend)
OVERLOAD_SEND(rsend, MPI_Rsend)
//template <class MsgType>
//inline request<MsgType> isend(msg_impl<MsgType>&& m);
template <class MsgType>
inline request<MsgType> isend(const msg_impl<MsgType>& m);
template <class RawMsg>
inline request<const RawMsg> isend(const RawMsg& m);
//template <class MsgType>
//inline endpoint& operator<<(msg_impl<MsgType>&& m);
template <class MsgType>
inline endpoint& operator<<(const msg_impl<MsgType>& m);
template <class RawType>
inline endpoint& operator<<(const RawType& m);
template <class RawType>
inline status operator>>(RawType& m);
//template <class MsgType>
//inline status operator>>(msg_impl<MsgType>&& m);
//template <class MsgType>
//inline request<MsgType> operator>(msg_impl<MsgType>&& m);
template <class RawType>
inline request<RawType> operator>(RawType& m);
inline const int& rank() const;
};
}
#include "detail/comm.h"
namespace mpi {
//template <class MsgType>
//inline endpoint& endpoint::send_impl(const send_ptr& func, msg_impl<MsgType>&& m);
//template <class MsgType>
//inline request<MsgType> endpoint::isend(msg_impl<MsgType>&& m);
//template <class MsgType>
//inline request<MsgType> endpoint::operator>(msg_impl<MsgType>&& m);
}
#include "detail/status.h"
namespace mpi {
template <class RawType>
inline status endpoint::operator>>(RawType& m);
//template <class MsgType>
//inline status endpoint::operator>>(msg_impl<MsgType>&& m);
}
