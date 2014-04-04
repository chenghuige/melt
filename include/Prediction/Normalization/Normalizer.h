/**
 *  ==============================================================================
 *
 *          \file   Prediction/Normalization/Normalizer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-01 17:07:28.184018
 *
 *  \Description:   归一化到 [0,1]
 *    @TODO TLC由于考虑到StreamingIntances训练问题 是没有提供一个Normalizer直接norm所有的接口
 *          而是在训练中逐个process prepare然后逐个normalize
 *
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__NORMALIZER_H_
#define PREDICTION__NORMALIZATION__NORMALIZER_H_
#include "common_util.h"
#include "Prediction/Instances/Instances.h"
namespace gezi {

	class Normalizer
	{
	public:
		Normalizer() = default;

		//写入文本
		virtual void Save(string outfile)
		{

		}

		virtual void Load(string infile)
		{

		}

		virtual string Name()
		{
			return "Not specified";
		}

		/// Process next initialization example
		virtual void Process(const Vector& vec)
		{

		}

		//TLC 比较复杂 而且感觉有bug  不再做dense sparse再转换这里 
		//同时是norm之后覆盖原结果 如果需要 
		void Normalize(Vector& vec)
		{
			NormalizeCore(vec);
		}

		//核心norm 如何兼容Feature 1.Template For Normalzier class ? 2. Feature : public Vector add names field需要修改feature_util.h 重写Feature类
		//Feature类2个vector好于1个vector<Node> InverteIndex 需要用Node 方便存储
		virtual void NormalizeCore(Vector& vec)
		{

		}

		///norm框架
		//不是Fast后缀的是常规解法全部遍历 对于文本分类等特征数目多 数据稀疏速度较慢 主要用来验证Fast接口的正确性
		//采用Func 避免核心部分函数是虚函数
		template<typename Func>
		void Normalize(Vector& vec, Func func)
		{
			if (vec.IsDense())
			{
				//NormalizeDense(vec, func);
				NormalizeDenseFast(vec, func);
			}
			else
			{
				//NormalizeSparse(vec, func);
				NormalizeSparseFast(vec, func);
			}
		}

		template<typename Func>
		void NormalizeDense(Vector& vec, Func func)
		{
			vec.ForEachDense([&func](int index, Float& value)
			{
				func(index, ref(value));
			});
		}

		template<typename Func>
		void NormalizeSparse(Vector& vec, Func func)
		{
			Vector result(_featureNum);
			vec.ForEachAllSparse([&func, &result](int index, Float value)
			{
				Float val = value;
				func(index, ref(val));
				result.Add(index, val);
			});
			vec.Swap(result);
		}

		template<typename Func>
		void NormalizeDenseFast(Vector& vec, Func func)
		{
			for (int index : _morphIndices)
			{
				func(index, vec.Values()[index]);
			}
		}

		template<typename Func>
		void NormalizeSparseFast(Vector& vec, Func func)
		{
			Vector result(_featureNum);
			int len = _shiftIndices.size();
			int len2 = vec.Values().size();

			Float val;
			int index, index2;
			int i = 0, j = 0;
			for (; i < len && j < len2;)
			{
				index = _shiftIndices[i];
				index2 = vec.Indices()[j];
				if (index == index2)
				{
					val = vec.Values()[j];
					func(index, ref(val));
					result.Add(index, val);
					i++;
					j++;
				}
				else if (index < index2)
				{
					val = 0;
					func(index, ref(val));
					result.Add(index, val);
					i++;
				}
				else
				{
					val = vec.Values()[j];
					func(index2, ref(val));
					result.Add(index2, val);
					j++;
				}
			}
			for (; i < len; i++)
			{
				index = _shiftIndices[i];
				val = 0;
				func(index, ref(val));
				result.Add(index, val);
			}

			for (; j < len2; j++)
			{
				index2 = vec.Indices()[j];
				val = vec.Values()[j];
				func(index2, ref(val));
				result.Add(index2, val);
			}

			vec.Swap(result);
		}

		/// Begin iterating through initialization examples
		virtual void Begin()
		{

		}

		/// Finish processing initialization examples; ready to normalize
		virtual void Finalize()
		{

		}

		void Prepare(const Instances& instances)
		{
			Noticer nt("Normalize prepare");
			_featureNum = instances.FeatureNum();
			_featureNames = instances.FeatureNames();
			Begin();
			for (uint64 i = 0; i < instances.Size(); i++)
			{
				if (i == _uintmaxNormalizationExamples)
				{
					break;
				}
				Process(instances[i]->features);
			}
			Finalize();
		}

		//@TODO Load info or just test data normalize
		void PrepareAndNormalize(Instances& instances)
		{
			Prepare(instances);
			Normalize(instances);
		}
		void Normalize(Instances& instances)
		{
			Noticer nt("Normalize");
#pragma omp parallel for //omp not work for foreach loop ? @TODO
			for (uint64 i = 0; i < instances.Size(); i++)
			{
				Normalize(instances[i]->features);
			}
		}
	protected:
		int _featureNum;
		svec _featureNames;
		ivec _morphIndices;
		ivec _shiftIndices;
		//----------------------------args
		//:if feature is out of bounds, threshold at 0/1, or return values below 0 and above 1?
		bool _trunct = false; //@TODO here or in MinMaxNormalizer GuassianNormalzier need it?
		uint64 _uintmaxNormalizationExamples = 1000000;//numNorm:
	private:

	};

	typedef shared_ptr<Normalizer> NormalizerPtr;
}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__NORMALIZER_H_
