/**
 *  ==============================================================================
 *
 *          \file   Prediction/Normalization/MinMaxNormalizer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-02 10:30:54.515916
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_

#include "Prediction/Normalization/AffineNormalizer.h"
#include "conf_util.h"
namespace gezi {

	class MinMaxNormalizer : public AffineNormalizer
	{
	public:
		MinMaxNormalizer() = default;
		MinMaxNormalizer(string infile)
		{//通过文本载入Normalzier
			AffineNormalizer::Load(infile); //@FIXME构造函数调用虚函数? 
		}

		virtual string Name() override
		{
			return "MinMaxNormalizer";
		}

		virtual void Process(const Vector& vec) override
		{
			if (_isFirst)
			{
				vec.ForEachAll([this](int i, Float value)
				{
					_offsets[i] = value;
					_scales[i] = value;
				});
				_isFirst = false;
			}
			else
			{ //set lower and upper bound for each i
				///理论上只有比如 -13 0  0  0 后面都是 0 或者都是 -5 -4 -3 这样 那么最大值没有取到实际的 0
				//或者比如 3 4 5 ... 最小值没有取到实际的 0  貌似TLC这个地方有问题 没有特殊处理？
				vec.ForEach([this](int i, Float value)
				{
					_counts[i]++;
					this->SetOffsetScale(i, value); //need this->
				});
			}
			_numProcessedInstances++;
		}

		//@TODO lambda里面再调用这个不行 那么直接把这个类成员函数 传给ForEach?
		void SetOffsetScale(int i, Float value)
		{
			if (value < _offsets[i])
			{
				_offsets[i] = value;
			}
			if (value > _scales[i])
			{
				_scales[i] = value;
			}
		}
		virtual void Begin() override
		{
			AffineNormalizer::Begin();
			_counts.resize(_numFeatures, 1);
		}
		virtual void Finish() override
		{
			for (size_t i = 0; i < _numFeatures; i++)
			{
				if (_counts[i] != _numProcessedInstances)
				{ //这个特征在prepare的所有instance中 存在0值, TLC没有做这个 应该是bug 部分归一后没有到[0,1]可能
					/*		if (0 < _offsets[i] || 0 > _scales[i])
							{
							Pval5(i, _offsets[i], _scales[i], _counts[i], _total);
							}*/
					SetOffsetScale(i, 0);
				}
				_scales[i] -= _offsets[i];
			}
			AffineInit();
			_counts.clear();
		}

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			ar & boost::serialization::base_object<Normalizer>(*this);
			ar & boost::serialization::base_object<AffineNormalizer>(*this);
		}
	protected:
	private:
		bool _isFirst = true;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__MIN_MAX_NORMALIZER_H_
