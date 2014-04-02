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
				//NormalizeDense(vec, func);
				NormalizeDenseFast(vec, func);
			}
			else
			{
				//NormalizeSparse(vec, func);
				NormalizeSparseFast(vec, func);
			}
		}

		//@TODO 如果按照tlc 去判断某些位置比如 offset 0 scale 1 不需要再func 速度能有多少提升 值得吗？
		//按照现有的数据规模 暂时不需要 norm 1.2w 200特征 2ms
		//如果修改 需要记录 所有需要scale位置到一个list 然后
		//需要两个list 做处理 主要是如果稀疏数据处理比较麻烦 类似两list求交集
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
			for (int index : _scaleIndices)
			{
				func(index, vec.Values()[index]);
			}
		}

		template<typename Func>
		void NormalizeSparseFast(Vector& vec, Func func)
		{
			Vector result(_featureNum);
			int len = _scaleIndices.size();
			int len2 = vec.Values().size();
			
			Float val;
			int index, index2;
			int i = 0, j = 0;
			for (; i < len && j < len2;)
			{
				index = _scaleIndices[i];
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
					j++;
				}
				for (；i < len；i++)
				{
					index = _scaleIndices[i];
					val = 0;
					func(index, ref(val));
					result.Add(index, val);
				}
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
			_featureNum = instances.FeatureNum();
			_featureNames = instances.FeatureNames();
			Begin();
			for (const InstancePtr& instance : instances)
			{
				Process(instance->features);
			}
			Finalize();
		}
		void Normalize(Instances& instances)
		{
			Prepare(instances);
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
		ivec _scaleIndices;
		// if feature is out of bounds, threshold at 0/1, or return values below 0 and above 1?
		bool _trunct = false; //@TODO here or in MinMaxNormalizer GuassianNormalzier need it?
	private:
		
	};

	typedef shared_ptr<Normalizer> NormalizerPtr;
}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__NORMALIZER_H_
