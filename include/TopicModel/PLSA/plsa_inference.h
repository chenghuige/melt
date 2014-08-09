/** 
 *  ==============================================================================
 * 
 *          \file   plsa_inference.h
 *
 *        \author   chenghuige  
 *          
 *          \date   2011-12-22 15:09:45.009434
 *  
 *  \Description:   不带背景信息的推断，输入支持浮点数
 *  ==============================================================================
 */

#ifndef PLSA_INFERENCE_H_
#define PLSA_INFERENCE_H_

#include "inverted_index.h"
#include <vector>
#include <stdlib.h>
#include "common_help.h"
#include "vec_calc.h"
#include "matrix_help.h"

namespace gezi
{

template<typename _Table >
class TPlsaBasicModel
{
public:

    /**
     * 输入是p(w|z)倒排,要求按照id排序
     */
    TPlsaBasicModel(_Table& invert)
    : _znum(invert.size()), _pzw(invert)
    {
    }

    template<typename T>
    void inference(const std::vector<T>& content_vec, std::vector<float>& pdz, int round = 20)
    {
        //--------------------------init
        pdz.clear();
        pdz.resize(_znum + 1, 0);

        int len = content_vec.size();
        float nword = 0;
        for (int i = 0; i < len; i++)
        {
            nword += content_vec[i].second;
        }

        //--------------------------init
        double sum = 0;
        for (size_t i = 0; i <= _znum; i++)
        {
            pdz[i] = 1.0 / _znum;
        }
        Fmat pwz = Fmat::Zero(len, _znum);
        //--------------------------infer
        for (int i = 0; i < round; i++)
        {
            //-----e-step calc pwz// p(z|w,d)
            for (int j = 0; j < len; j++) //word
            {
                int wid = content_vec[j].first;
                //p(w,d)
                float pw_d = 0;
                for (int zid = 0; zid < _znum; zid++)
                {
                    pw_d += pdz[zid] * _pzw(zid, wid);
                }
                for (int zid = 0; zid < _znum; zid++) //z topic
                {
                    if (pw_d) // /0危险。。。
                        pwz(j, zid) = (pdz[zid] * _pzw(zid, wid)) / pw_d;
                }
            }

            //-----m-step calc p(z|d)
            for (int zid = 0; zid < _znum; zid++) //topic
            {
                float up = 0;
                for (int j = 0; j < len; j++) //word
                {
                    int wid = content_vec[j].first;
                    float weight = content_vec[j].second;
                    up += weight * pwz(j, zid);
                }
                pdz[zid] = up / nword;
            }
        }
        
    }

    int znum()
    {
        return _znum;
    }
private:
    int _znum;
    _Table& _pzw;
};


//TODO word -> zid 倒排改为直接hash

template<typename _Table >
class TPlsaModel
{
public:

    /**
     * 输入是p(z|w)倒排
     */
    TPlsaModel(_Table& invert, int znum = 10000)
    : _znum(znum), _pwz(invert)
    {
    }

    /**
     * 在线推理fold_in，这里输入的p(z|w)是压缩截断的倒排，比如每个word只保留top 20的topic加快计算速度
     * @param content_vec
     * @param pdz
     * @param round
     */
    template<typename T>
    void inference(const std::vector<T>& content_vec, std::vector<float>& pdz, int round = 20)
    {
        //--------------------------init
        pdz.clear();
        pdz.resize(_znum + 1, 0);

        int len = content_vec.size();
        float nword = 0;
        for (int i = 0; i < len; i++)
        {
            nword += content_vec[i].second;
        }
        if (!nword)
        {
            return;
        }

        //--------------------------init
        double sum = 0;
        for (size_t i = 0; i <= _znum; i++)
        {
            pdz[i] = 1.0 / _znum;
        }
        Fmat pwz = Fmat::Zero(len, _znum);

        typedef typename _Table::Range Range;
        typedef typename _Table::iterator Iter;
        //--------------------------infer
        for (int i = 0; i < round; i++)
        {
            //-----e-step calc pwz// p(z|w,d)
            for (int j = 0; j < len; j++) //word
            {
                int wid = content_vec[j].first;
                //p(w,d)
                float pw_d = 0;

                Range range = _pwz.range(wid);

                for (Iter iter = range.first; iter != range.second; ++iter)
                {
                    pw_d += pdz[iter->first] * iter->second;
                }

                for (Iter iter = range.first; iter != range.second; ++iter)
                {
                    if (pw_d) // /0危险。。。
                        pwz(j, iter->first) = (pdz[iter->first] * iter->second) / pw_d;
                }

            }

            vector<float> tdz;
            tdz.resize(_znum + 1, 0);
            for (int j = 0; j < len; j++)
            {
                int wid = content_vec[j].first;
                Range range = _pwz.range(wid);
                for (Iter iter = range.first; iter != range.second; ++iter)
                {
                    tdz[iter->first] += content_vec[j].second * pwz(j, iter->first);
                }
            }

            for (int j = 0; j < _znum; j++)
            {
                pdz[j] = tdz[j] / nword; //FIXME nword == 0?
            }
        }

    }

    /**
     * 简单的词topic并集 推理
     * @return 
     */
    template<typename T>
    void mix_inference(const std::vector<T>& content_vec, std::vector<float>& pdz, int round = 20)
    {
        if (content_vec.empty())
        {
            return;
        }

        //--------------------------init
        pdz.clear();
        pdz.resize(_znum + 1, 0);

        int len = content_vec.size();
        double sum = 0, weight = 0;

        typedef typename _Table::Range Range;
        typedef typename _Table::iterator Iter;
        //--------------------------infer
        for (int j = 0; j < len; j++) //words
        {
            int wid = content_vec[j].first;
            Range range = _pwz.range(wid);

            for (Iter iter = range.first; iter != range.second; ++iter)
            {
                weight = iter->second * content_vec[j].second;
                sum += weight;
                pdz[iter->first] += weight;
            }
        }

        for (int j = 0; j < _znum; j++)
        {
            pdz[j] = pdz[j] / sum; //FIXME nword == 0?
        }
    }

    int znum()
    {
        return _znum;
    }

private:
    int _znum;
    _Table& _pwz;
};
typedef TPlsaBasicModel<inverted::InvertedIndex<float> > PlsaBasicModel;
typedef TPlsaModel<inverted::InvertedIndex<float> > PlsaModel;
} //----end of namespace gezi

#endif  //----end of PLSA_INFERENCE_H_
