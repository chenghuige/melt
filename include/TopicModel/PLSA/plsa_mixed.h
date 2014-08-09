/** 
 *  ==============================================================================
 * 
 *          \file   plsa_mixed.h
 *
 *        \author   chenghuige  
 *          
 *          \date   2011-08-02 19:33:22.161966
 *  
 *  \Description:   带back ground的plsa
 *  ==============================================================================
 */

#ifndef PLSA_MIXED_H_
#define PLSA_MIXED_H_

#include "plsa.h"
namespace plsa {

class MixModel : public Model
{
public:
    MixModel(int z_num, int word_num, const std::vector<DP>& back_ground, DP beta = 0.8)
    : Model(z_num, word_num), _back_ground(back_ground), _beta(beta)
    {

    }
    void init()
    {
        Model::init();
        _pwb.resize(_nword, 0); //节省时间，也可以每个doc开辟较小的空间，只按照该doc中出现的word
    }
    void run(int step = 1)
    {
        init();
        for (int i = 0; i < step; i++) //step
        {
            Pval(i);
            _pzw2.setConstant(_znum, _nword, 0); //TODO
            std::fill(_pz_vec.begin(), _pz_vec.end(), 0);
            for (int did = 0; did < _ndoc; did++) //doc
            {
                //                Pval(did);
                DP nword = _doc_vec[did].nword;
                ContentVec& vec = _doc_vec[did].content;
                int len = vec.size();
                //--------------------Estep for one doc
                //p(z_k|w,d)
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
                        else
                            _pwz(wid, zid) = 0;
                    }
                    DP up = _beta * _back_ground[wid];
                    DP down = up + (1 - _beta) * pw_d;
                    //                    _pwb[wid] = down ? up / down : 0;
                    if (down != 0)
                        _pwb[wid] = up / down;
                    else
                        _pwb[wid] = 0;
                    //                    if (wid == 158 || wid == 953582)
                    //                    {
                    //                        Pval(_pwb[wid]);
                    //                    }
                    //                    _pwb[wid] = v / (v + (1 - _beta) * pw_d);
                    //                    Pval(_pwb[wid]);
                }
                //-------------------Mstep for one doc
                //---p(z|d) and p(w|z) update,this will be updated after all doc processed in one step
                for (int zid = 0; zid < _znum; zid++)
                {
                    DP sum = 0;
                    for (int j = 0; j < len; j++) //word
                    {
                        int wid = vec[j].first;
                        DP weight = vec[j].second;
                        DP score = weight * _pwz(wid, zid) * (1 - _pwb[wid]); //float 可能会造成nan! fixme
                        sum += score;
                        _pzw2(zid, wid) += score;
                        //                        if (i == 10 && did == 1003 && zid == 0)
                        //                        {
                        //                            Pval(weight);
                        //                            Pval(wid);
                        //                            Pval(score);
                        //                            Pval(sum);
                        //                            Pval(_pwz(wid, zid));
                        //                            Pval(1 - _pwb[wid]);
                        //                            Pval(_pwb[wid]);
                        //                        }
                    }
                    _pz_vec[zid] += sum;
                    _pdz(did, zid) = sum / nword; //p(z|d) update
                    //                    if (zid == 0 && i == 10)
                    //                    {
                    //                        Pval(did);
                    //                        Pval(sum);
                    //                        Pval(_pz_vec[zid]);
                    //                    }
                }
            }
            //after every doc is processed, now finish p(w|z)
            for (int zid = 0; zid < _znum; zid++)
            {
                //                Pval(zid);
                //                Pval(_pdz(0, zid));
                DP down = _pz_vec[zid];
                for (int wid = 0; wid < _nword; wid++) //word
                {
                    if (down)
                        _pzw(zid, wid) = _pzw2(zid, wid) / down;
                    else
                        _pwz(zid, wid) = 0;
                    //                    if (wid == 158)
                    //                    {
                    //                        Pval(down);
                    //                        Pval(_pzw(zid, wid));
                    //                        Pval(_pzw2(zid, wid));
                    //                    }
                }
            }
        }
    }
private:
    const std::vector<DP>& _back_ground;
    vector<DP> _pwb; //长度大小为_nword
    DP _beta;
};

} //----end of namespace plsa

#endif  //----end of PLSA_MIXED_H_
