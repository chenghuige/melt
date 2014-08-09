/** 
 *  ==============================================================================
 * 
 *          \file   plsa_mpi.h
 *
 *        \author   chenghuige  
 *          
 *          \date   2011-08-03 17:57:12.385474
 *  
 *  \Description:  TODO how can reduce use skeleton
 *                      how can non skeleon transport without large size limit
 *   gcc4 不要+ -std=c++0x否则和boost.mpi冲突
 *
 *  这个版本是WORK的，但是数据传输量较大，130W词，100TOPIC，2小时完成,plsav1 15
 *  ==============================================================================
 */

#ifndef PLSA_MPI_H_
#define PLSA_MPI_H_
#include <boost/mpi.hpp>
//#include <omp.h>
#include "plsa.h"
namespace plsa {
namespace mpi = boost::mpi;
using namespace std;
class MpiModel : public Model
{
public:
    MpiModel(int z_num, int word_num)
    : Model(z_num, word_num)
    {

    }
    void init(mpi::communicator& world)
    {
        //        srand(time(NULL));
        //        srand48(time(NULL));
        //init
        _ndoc = _doc_vec.size();
        LOG(INFO) << "The doc num for this node is " << _ndoc << endl;

        //        mpi::request reqs[world.size() - 1];
        if (world.rank() == 0)
            _pdz.setConstant(_ndoc, _znum, 0);
        broadcast(world, mpi::skeleton(_pdz), 0); //TODO
        mpi::content pdz_content = mpi::get_content(_pdz);
        if (world.rank() == 0)
        {
            Mat_ pdz;
            pdz.setConstant(_ndoc, _znum, 0);
            mpi::content pdz_content2 = mpi::get_content(pdz);
            for (int i = 0; i < _ndoc; i++)
            {
                DP sum = 0.0;
                for (int j = 0; j < _znum; j++)
                {
                    _pdz(i, j) = drand48() * drand48();
                    sum += _pdz(i, j);
                }
                for (int j = 0; j < _znum; j++)
                {
                    _pdz(i, j) /= sum;
                }
            }
            for (int l = 1; l < world.size(); l++)
            {
                for (int i = 0; i < _ndoc; i++)
                {
                    DP sum = 0.0;
                    for (int j = 0; j < _znum; j++)
                    {
                        pdz(i, j) = drand48() * drand48();
                        sum += pdz(i, j);
                    }
                    for (int j = 0; j < _znum; j++)
                    {
                        pdz(i, j) /= sum;
                    }
                }
                cout << "Send " << l << endl;
                //                reqs[l - 1] = world.isend(l, 0, pdz_content); //TODO skeleton
                world.send(l, 0, pdz_content2); //TODO non blocking
                cout << "After send" << l << endl;
            }
        }
        else
        {
            cout << "Recive " << world.rank() << endl;
            //            reqs[world.rank() - 1] = world.irecv(0, 0, pdz_content);
            //            world.recv(0, 0, _pdz);
            world.recv(0, 0, pdz_content);
            cout << "After recive " << world.rank() << endl;
        }
        if (world.rank() == 0)
        {
            _pzw.setConstant(_znum, _nword, 0);
            for (int i = 0; i < _znum; i++)
            {
                DP sum = 0.0;
                for (int j = 0; j < _nword; j++)
                {
                    _pzw(i, j) = drand48() * drand48();
                    sum += _pzw(i, j);
                }
                for (int j = 0; j < _nword; j++)
                {
                    _pzw(i, j) /= sum;
                }
            }
        }
        _pzw2.setConstant(_znum, _nword, 0);
        _pz_vec.resize(_znum, 0);
        _pwz.setConstant(_nword, _znum, 0);
    }
    void run(mpi::communicator& world, int step = 1)
    {
        init(world);
        broadcast(world, mpi::skeleton(_pzw), 0); //TODO
        mpi::content pzw_content = mpi::get_content(_pzw);
        //        broadcast(world, pzw_content, 0);
        broadcast(world, mpi::skeleton(_pzw2), 0); //TODO
        mpi::content pzw2_content = mpi::get_content(_pzw2);

        static int tag = 0;

        for (int i = 0; i < step; i++) //step
        {
            LOG(INFO) << "This is step " << i << endl;
            LOG(INFO) << "Begin broadcast pzw" << endl;
            broadcast(world, pzw_content, 0);
            //            broadcast(world, _pzw, 0);
            LOG(INFO) << "End broadcast pzw" << endl;

            //            string pzw_file = "_pzw" + TO_STRING(world.rank()) + ".ser";
            //            serialize::save(_pzw, pzw_file);
            //            string pdz_file = "_pdz" + TO_STRING(world.rank()) + ".ser";
            //            serialize::save(_pdz, pdz_file);

            _pzw2.setConstant(0); //TODO
            std::fill(_pz_vec.begin(), _pz_vec.end(), 0);
            for (int did = 0; did < _ndoc; did++) //doc  TODO  这个地方可以并行，用几个线程就开几个_pwz()
            {
                //                Pval(did);
                DP nword = _doc_vec[did].nword;
                if (nword < 1) //如果0个word那么该doc被忽略
                    continue;
                ContentVec & vec = _doc_vec[did].content;
                int len = vec.size();
                //--------------------Estep for one doc
                //p(z_k|w,d)
                //#pragma omp parallel for
                for (int j = 0; j < len; j++) //word
                {
                    int wid = vec[j].first;
                    //p(w,d)
                    DP pw_d = 0;
                    for (int zid = 0; zid < _znum; zid++)
                    {
                        pw_d += _pdz(did, zid) * _pzw(zid, wid);
                    }
                    for (int zid = 0; zid < _znum; zid++) //z topic
                    {
                        if (pw_d)
                            _pwz(wid, zid) = (_pdz(did, zid) * _pzw(zid, wid)) / pw_d;
                    }
                }
                //-------------------Mstep for one doc
                //---p(z|d) and p(w|z) update,this will be updated after all doc processed in one step
                //#pragma omp parallel for
                for (int zid = 0; zid < _znum; zid++)
                {
                    DP sum = 0;
                    for (int j = 0; j < len; j++) //word
                    {
                        int wid = vec[j].first;
                        DP weight = vec[j].second;
                        DP score = weight * _pwz(wid, zid);
                        sum += score;
                        _pzw2(zid, wid) += score;
                    }
                    _pz_vec[zid] += sum;
                    _pdz(did, zid) = sum / nword; //p(z|d) update
                }
            }

            LOG(INFO) << "Finish calc each doc in my node, begin transfer" << endl;
            reduce(world, _pz_vec, _pz_vec, std2::VecSum(), 0);
//            reduce(world, _pzw2, _pzw2, std2::MatrixSum(), 0); //TODO how can fix this?
            if (world.rank() == 0) //TODO write one general reduce yourself?
            {
                Mat_ pzw3;
                pzw3.setConstant(_znum, _nword, 0);
                mpi::content pzw3_content = mpi::get_content(pzw3);
                for (int i = 1; i < world.size(); i++)
                {
                    world.recv(i, tag, pzw3_content);
                    std2::MatrixSum()(_pzw2, pzw3);
                }
            }
            else
            {
                world.send(0, tag, pzw2_content);
            }
            tag++;
            LOG(INFO) << "Finish transfer pz_vec and pzw2" << endl;
            //after every doc is processed, now finish p(w|z)
            if (world.rank() == 0)
            {
                //#pragma omp parallel for
                for (int zid = 0; zid < _znum; zid++)
                {
                    DP down = _pz_vec[zid];
                    for (int wid = 0; wid < _nword; wid++) //word
                    {
                        if (down)
                            _pzw(zid, wid) = _pzw2(zid, wid) / down;
                    }
                }
            }

        }
    }
};

}

#endif  //----end of PLSA_MPI_H_
