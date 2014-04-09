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
#include "Numeric/Vector/vector_util.h"
#include "feature/Feature.h" //@TODO remove
namespace gezi {

	class Normalizer
	{
	public:
		enum class NormType
		{
			Affine,
			Bin
		};
		Normalizer()
		{
			ParseArgs();
		}

		void ParseArgs()
		{

		}

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
		template<typename _Vector>
		void Normalize(_Vector& vec)
		{
			Normalize(vec, _func);
		}

		template<typename _Vector>
		_Vector NormalizeCopy(_Vector& vec)
		{
			_Vector temp = vec;
			Normalize(temp, _func);
			return temp;
		}

		void Normalize(Instance& instance)
		{
			Normalize(instance.features, _func);
		}

		Instance NormalizeCopy(const Instance& instance)
		{
			Instance temp = instance;
			Normalize(temp.features, _func);
			return temp;
		}

		InstancePtr NormalizeCopy(InstancePtr instance)
		{
			InstancePtr temp = make_shared<Instance>(*instance);
			Normalize(temp->features, _func); 
			return temp;
		}

		void Normalize(InstancePtr instance)
		{
			Normalize(instance->features, _func);
		}



		/// Begin iterating through initialization examples
		virtual void Begin()
		{

		}

		/// Finish processing initialization examples; ready to normalize
		virtual void Finish()
		{

		}

		void Prepare(const Instances& instances)
		{
			_numFeatures = instances.FeatureNum();
			_featureNames = instances.FeatureNames();
			Begin();
			uint64 len = min((uint64)instances.size(), (uint64)_maxNormalizationExamples);
			ProgressBar pb(Name() + " prepare", len);
			for (uint64 i = 0; i < len; i++)
			{
				pb.progress(i);
				Process(instances[i]->features);
			}
			Finish();
		}

		//@TODO Load info or just test data normalize
		void RunNormalize(Instances& instances)
		{
			Prepare(instances);
			Normalize(instances);
		}
		void Normalize(Instances& instances)
		{
			if (!instances.normalized)
			{
				Noticer nt("Normalize");
#pragma omp parallel for //omp not work for foreach loop ? @TODO
				for (uint64 i = 0; i < instances.Size(); i++)
				{
					Normalize(instances[i]->features);
				}
			}
			instances.normalized = true;
		}

		//@TODO move to MinMax ?
		bool Trunct() const
		{
			return _trunct;
		}

		//选择set而不是函数中Normalize(vec, trunct=true)选项 因为如果trunct=true就应该是对所有都是 
		//倾向于是Normalizer的内部属性 而不是外部灵活改变的
		void SetTrunct(bool trunct)
		{
			_trunct = trunct;
		}
	protected:
		///norm框架
		//不是Fast后缀的是常规解法全部遍历 对于文本分类等特征数目多 数据稀疏速度较慢 主要用来验证Fast接口的正确性
		//采用Func 避免核心部分函数是虚函数
		template<typename Func>
		void Normalize(Vector& vec, Func func)
		{
			if (!vec.normalized)
			{
				if (_normType == NormType::Affine)
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
				else
				{//bin norm @TODO其实不管affine bin 都使用apply(vec, _shiftIndices, func)也可以速度影响很小
					apply(vec, _shiftIndices, func);
				}
				vec.normalized = true;
			}
		}

		//@TODO remove 在线 都按照sparse处理 归一化
		template<typename Func>
		void Normalize(Feature& feature, Func func)
		{
			if (!feature.normalized)
			{
				NormalizeSparseFast(feature, func);
				feature.normalized = true;
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
			Vector result(_numFeatures);
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

		template<typename Func, typename _Vector>
		void NormalizeSparseFast(_Vector& vec, Func func)
		{
			apply_sparse(vec, _shiftIndices, func);
		}
	protected:
		int _numFeatures = 0;
		svec _featureNames;
		ivec _morphIndices; //只有AffineNormalizer才使用
		ivec _shiftIndices; //Affine,Bin都使用
		NormType _normType = NormType::Affine;
		std::function<void(int, Float&)> _func;

		uint64 _numProcessedInstances = 1; //处理的instance数目

		//----------------------------args begin
		//|if feature is out of bounds, threshold at 0/1, or return values below 0 and above 1?
		bool _trunct = false; //@TODO 似乎只有MinMax才可能越界吧
		uint64 _maxNormalizationExamples = 1000000;//numNorm|
		//-----------------------------args end
	private:

	};

	typedef shared_ptr<Normalizer> NormalizerPtr;
}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__NORMALIZER_H_
