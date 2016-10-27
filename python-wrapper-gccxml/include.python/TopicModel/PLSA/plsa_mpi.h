#ifndef PLSA_MPI_H_
#define PLSA_MPI_H_
#include <boost/mpi.hpp>
#include "plsa.h"
namespace plsa {
namespace mpi = boost::mpi;
using namespace std;
class MpiModel : public Model
{
public:
MpiModel(int z_num, int word_num);
void init(mpi::communicator& world);
void run(mpi::communicator& world, int step = 1);
};
}
#endif
