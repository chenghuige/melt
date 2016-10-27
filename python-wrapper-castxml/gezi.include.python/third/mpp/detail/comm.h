#pragma once
#include "detail/decls.h"
namespace mpi {
class comm
{
MPI_Comm m_comm;
bool 	 m_initialized;
int 	 m_comm_size;
int 	 m_rank;
comm(MPI_Comm comm);
inline void check_init();
public:
static comm world;
inline int rank();
inline int rank() const;
inline int size();
inline int size() const;
const MPI_Comm& mpi_comm() const;
inline endpoint operator()( const int& rank_id ) const;
};
comm comm::world = comm(MPI_COMM_WORLD);
}
#include "detail/endpoint.h"
namespace mpi {
inline endpoint comm::operator()(const int& rank_id) const;
}
