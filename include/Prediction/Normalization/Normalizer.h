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
 *    @TODO 有的时候比如大部分是0 但是很多特征可能分布是 [-X,X]这种情况下 归一化到 [-1,1]比较好， 0 不变
 *
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__NORMALIZER_H_
#define PREDICTION__NORMALIZATION__NORMALIZER_H_

#include "common_util.h"
#include "Prediction/Instances/Instances.h"
#include "Numeric/Vector/vector_util.h"
namespace gezi {

	class Normalizer : public LoadSave
	{
	public:
		enum class NormType
		{
			Affine,
			Bin
		};
		virtual ~Normalizer() { }
		Normalizer()
		{
			ParseArgs();
		}

		void ParseArgs()
		{

		}

		virtual string Name() override
		{
			return "Normalizer";
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
			if (!temp.normalized)
			{
				Normalize(temp.features, _func);
				temp.normalized = true;
			}
			return temp;
		}

		InstancePtr NormalizeCopy(InstancePtr instance)
		{
			InstancePtr temp = make_shared<Instance>(*instance);
			if (!temp->normalized)
			{
				Normalize(temp->features, _func);
				temp->normalized = true;
			}
			return temp;
		}

		//@TODO can not be const Instances&
		Instances NormalizeCopy(Instances& instances)  
		{
			Instances newInstances = instances;
#pragma omp parallel for 
			for (uint64 i = 0; i < instances.Size(); i++)
			{
				newInstances[i] = NormalizeCopy(newInstances[i]);
				newInstances[i]->normalized = true;
			}
			newInstances.SetNormalized();
			return newInstances;
		}

		void Normalize(InstancePtr instance)
		{
			if (!instance->normalized)
			{
				Normalize(instance->features, _func);
				instance->normalized = true;
			}
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
				++pb;
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

		Instances RunNormalizeCopy(Instances& instances)
		{
			Prepare(instances);
			Instances newInstances = NormalizeCopy(instances);
			return newInstances;
		}

		void Normalize(Instances& instances)
		{
			if (!instances.IsNormalized())
			{
				Noticer nt("Normalize");
#pragma omp parallel for //omp not work for foreach loop ? @TODO
				for (uint64 i = 0; i < instances.Size(); i++)
				{
					Normalize(instances[i]->features);
					instances[i]->normalized = true;
				}
			}
			instances.SetNormalized();
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

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			/*		ar & _numFeatures;
					ar & _featureNames;
					ar & _morphIndices;
					ar & _shiftIndices;
					ar & _normType;
					ar & _trunct;*/
			ar & GEZI_SERIALIZATION_NVP(_normType);
			ar & GEZI_SERIALIZATION_NVP(_numFeatures);
			ar & GEZI_SERIALIZATION_NVP(_featureNames);
			ar & GEZI_SERIALIZATION_NVP(_morphIndices);
			ar & GEZI_SERIALIZATION_NVP(_shiftIndices);
			ar & GEZI_SERIALIZATION_NVP(_trunct);
		}

	protected:
		std::function<void(int, Float&)> _func;

		//-seralize
		NormType _normType = NormType::Affine;
		int _numFeatures = 0;
		FeatureNamesVector _featureNames;
		ivec _morphIndices; //只有AffineNormalizer才使用
		ivec _shiftIndices; //Affine,Bin都使用
		//----------------------------args begin
		//|if feature is out of bounds, threshold at 0/1, or return values below 0 and above 1?
		//bool _trunct = false; //@TODO 似乎只有MinMax才可能越界吧
		bool _trunct = true;

		uint64 _maxNormalizationExamples = 1000000;//numNorm|
		//-----------------------------args end
		uint64 _numProcessedInstances = 1; //处理的instance数目
	private:

	};
	typedef shared_ptr<Normalizer> NormalizerPtr;
}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__NORMALIZER_H_
