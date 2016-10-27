#pragma once
#include "detail/decls.h"
#include "detail/status.h"
namespace mpi {
template <class T>
class request
{
comm&     			m_comm;
MPI_Request 				m_req;
msg_impl<T>					m_msg;
std::unique_ptr<status> 	m_status;
int 		 				done;
public:
//request(const comm& com, MPI_Request req, msg_impl<T>&& msg);
//request(request<T>&& other);
void cancel();
inline const T& get();
inline status getStatus();
inline bool isDone();
};
}
