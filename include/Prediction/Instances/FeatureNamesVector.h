/**
 *  ==============================================================================
 *
 *          \file   Prediction/Instances/FeatureNamesVector.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-10-07 16:12:34.571144
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__INSTANCES__FEATURE_NAMES_VECTOR_H_
#define PREDICTION__INSTANCES__FEATURE_NAMES_VECTOR_H_

#include "common_util.h"

namespace gezi {

	inline string get_feature_name(const svec& featureNames, int index)
	{
		if (featureNames.empty())
		{
			return fmt::format("f{}", index);
		}
		return featureNames[index];
	}

	inline string get_feature_name(const svec* const featureNames, int index)
	{
		if (!featureNames || featureNames->empty())
		{
			return fmt::format("f{}", index);
		}
		return (*featureNames)[index];
	}

	class Predictor;
	class FeatureNamesVector
	{
	public:
		friend class Predictor;
		FeatureNamesVector()
			:_featureNames(make_shared<svec>())
		{

		}

		FeatureNamesVector(int numFeatures)
			:_numFeatures(numFeatures), _featureNames(make_shared<svec>())
		{

		}

		FeatureNamesVector(const svec& featureNames)
			:_numFeatures(0), _featureNames(make_shared<svec>(featureNames))
		{
		}

		FeatureNamesVector(svec&& featureNames)
			:_numFeatures(0), _featureNames(make_shared<svec>(move(featureNames)))
		{
		}

		typedef svec::iterator iterator;

		void push_back(string name)
		{
			_featureNames->push_back(name);
		}

		bool empty()
		{
			return size() == 0;
		}

		//注意 如果你需要虚拟feature的时候 这里是不显示的 for(string name : featureNames)
		iterator begin()
		{
			return _featureNames->begin();
		}

		iterator end()
		{
			return _featureNames->end();
		}

		//@TODO int not enough? vector []是 what？ size_t
		string operator[](int index) const
		{
			CHECK((_featureNames != nullptr));
			if (_featureNames->empty())
			{
				return fmt::format("f{}", index);
			}
			return (*_featureNames)[index];
		}
		
		size_t size() const
		{
			return std::max((size_t)_numFeatures, _featureNames->size());
		}

		void SetNumFeatures(int numFeatures)
		{
			_numFeatures = numFeatures;
		}

		bool operator == (const FeatureNamesVector& other)
		{
			return _numFeatures == other._numFeatures && *_featureNames == *other._featureNames;
		}

		friend class cereal::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			ar & CEREAL_NVP(_numFeatures);
			ar & CEREAL_NVP(_featureNames);
		}

	private:
		int _numFeatures = 0;
		shared_ptr<svec> _featureNames = nullptr; //采用指针因为这个数据结构使用基本是一次构造 多处读取使用
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__FEATURE_NAMES_VECTOR_H_
