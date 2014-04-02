/**
 *  ==============================================================================
 *
 *          \file   Prediction/Normalization/Normalizer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-01 17:07:28.184018
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__NORMALIZER_H_
#define PREDICTION__NORMALIZATION__NORMALIZER_H_
#include "common_util.h"
#include "Prediction/Instances/Instances.h"
namespace gezi {

	//@TODO 为了配合线上Feature类使用？ 改为模板类 或者线上Feature类改为继承Vector ?
	//倾向Feature类继承Vector 改用Vector写法分开index 和 value 并且用dense表示，自己增加名字域即可
	//dense表示只是dump feature 不方便 可以改写下 采用ForEachNonZero
	class Normalizer
	{
	public:
		Normalizer()
			:_range(_upper - _lower)
		{

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

		virtual void NormalizeCore(Vector& vec)
		{

		}

		template<typename Func>
		void Normalize(Vector& vec, Func func)
		{
			if (vec.IsDense())
			{
				NormalizeDense(vec, func);
			}
			else
			{
				NormalizeSparse(vec, func);
			}
		}

		template<typename Func>
		void NormalizeDense(Vector& vec, Func func)
		{
			vec.ForEachDense([&func](int index, double& value)
			{
				value = func(index, value);
			});
		}

	
		template<typename Func>
		void NormalizeSparse(Vector& vec, Func func)
		{
			Vector result(_featureNum);
			vec.ForEachAllSparse([&func, &result](int index, double value)
			{
				value = func(index, value);
				result.Add(index, value);
			});
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
		
		void Normalize(Instances& instances)
		{
			_featureNum = instances.FeatureNum();
			_featureNames = instances.FeatureNames();
			Begin();
			for (InstancePtr& instance : instances)
			{
				Process(instance->features);
			}
			Finalize();
#pragma omp parallel for //omp not work for foreach loop ? @TODO
			for (int i = 0; i < instances.Size(); i++)
			{
				Normalize(instances[i]->features);
			}
		}
	protected:
		int _featureNum;
		svec _featureNames;
		Float _lower = 0.0;
		Float _upper = 1.0;
		Float _range;
	private:
		// if feature is out of bounds, threshold at 0/1, or return values below 0 and above 1?
		bool _trunct = false; //@TODO here or in MinMaxNormalizer GuassianNormalzier need it?
	};

	typedef shared_ptr<Normalizer> NormalizerPtr;
}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__NORMALIZER_H_
