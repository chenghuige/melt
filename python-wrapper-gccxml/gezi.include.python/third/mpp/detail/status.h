#pragma once
#include "detail/decls.h"
#include <memory>
namespace mpi {
struct status
{
typedef std::unique_ptr<MPI_Status> mpi_status_ptr;
//status(status&& other);
inline endpoint source();
inline int count() const;
inline int tag() const;
inline int error() const;
friend class endpoint;
friend class request;
private:
//status(const comm& com, mpi_status_ptr&& s, const MPI_Datatype& dt);
status(const status& other) = delete;
status& operator=(const status& other) = delete;
comm&      	m_comm;
mpi_status_ptr		m_status;
MPI_Datatype  m_datatype;
};
}
#include "detail/endpoint.h"
namespace mpi {
inline endpoint status::source();
}
