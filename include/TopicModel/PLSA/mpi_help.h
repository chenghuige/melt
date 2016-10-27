/** 
 *  ==============================================================================
 * 
 *          \file   mpi_help.h
 *
 *        \author   chenghuige  
 *          
 *          \date   2011-08-05 22:21:19.652264
 *  
 *  \Description:
 *  ==============================================================================
 */

#ifndef MPI_HELP_H_
#define MPI_HELP_H_
#include <boost/mpi.hpp>

namespace gezi {
namespace mpi = boost::mpi;

////TODO ¿¼ÂÇÐ§ÂÊ
//template<typename _DestObj, typename _SrcObj, typename _Func>
//void reduce(mpi::communicator& world, _DestObj& dest, _SrcObj& src, _Func func, int stag, int id = 0)
//{
//    int num = world.size();
//    static int tag = stag;
//    if (world.rank() == 0)
//    {
//        for (int i = 1; i < num; i++)
//        {
//            world.recv(i, tag, src);
//            func(dest, src);
//        }
//    }
//    else
//    {
//        world.send(0, tag, src)
//    }
//    tag++;
//}
}
#endif  //----end of MPI_HELP_H_
