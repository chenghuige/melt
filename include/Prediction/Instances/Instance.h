/**
 *  ==============================================================================
 *
 *          \file   Prediction/Instances/Instance.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-03-26 13:22:43.913034
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__INSTANCES__INSTANCE_H_
#define PREDICTION__INSTANCES__INSTANCE_H_

#include "common_util.h"
#include "Numeric/Vector/Vector.h"
namespace gezi {

	struct Instance
	{
	public:
		~Instance() = default;
		Instance() = default;
		Instance(Instance&&) = default;
		Instance& operator = (Instance&&) = default;
		Instance(const Instance&) = default;
		Instance& operator = (const Instance&) = default;

		typedef Vector::value_type value_type;
		typedef Vector::index_type index_type;

		Instance(int length)
			:features(length)
		{

		}

		size_t size() const
		{
			return features.size();
		}

		int FeatureNum() const
		{
			return features.Length();
		}

		int NumFeatures() const
		{
			return features.Length();
		}

		void SelectFeatures(const BitArray& includedFeatures)
		{
			features.ForEach([&includedFeatures](int index, Float& val)
			{
				if (!includedFeatures[index])
				{
					val = 0;
				}
			});
		}

		//这个是彻底去掉无用的特征并且用dense表示
		void SelectFeaturesAndCompact(ivec& featuresToKeep)
		{
			vector<Float>	newFeatures(featuresToKeep.size());
			for (size_t i = 0; i < featuresToKeep.size(); i++)
			{
				newFeatures[i] = features[featuresToKeep[i]];
			}
			features.ToDense(newFeatures);
		}

		Vector& Features()
		{
			return features;
		}

		bool IsDense() const
		{
			return features.IsDense();
		}

		bool IsSparse() const
		{
			return features.IsSparse();
		}

		bool IsPositive()
		{
			return label > 0;
		}

		bool IsNegative()
		{
			return label <= 0;
		}

		//wether label is unknown
		bool IsUnknown()
		{
			return std::isnan(label);
		}

		bool HasMissingFeatures()
		{
			return hasMissingFeatures;
		}

		value_type operator[](index_type index) const
		{
			return features[index];
		}

		value_type& operator[](index_type index)
		{
			return features[index];
		}


		friend class cereal::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			ar & CEREAL_NVP(label);
			ar & CEREAL_NVP(weight);
			ar & CEREAL_NVP(features);
			ar & CEREAL_NVP(hasMissingFeatures);
			ar & CEREAL_NVP(name);
			ar & CEREAL_NVP(names);
			ar & CEREAL_NVP(attributes);
			ar & CEREAL_NVP(groupKey);
			ar & CEREAL_NVP(metaData);
			ar & CEREAL_NVP(sparse);
			ar & CEREAL_NVP(normalized);
			ar & CEREAL_NVP(line);
		}
	public:
		//TODO size_t counter; 计数 第几个instance
		//------Evaluate相关的信息在基础的IsEvaluateAble中
		Float label = std::numeric_limits<double>::quiet_NaN();
		Float weight = 1.0;

		Vector features;
		bool hasMissingFeatures = false;

		string name;
		svec names;
		svec attributes;
		string groupKey; //for ranking instances or used in cv folder creationg as stratify key
		string metaData;
		bool sparse = false;
		bool normalized = false;
		string line; //for vw instance will store ori input line
	};
	typedef shared_ptr<Instance> InstancePtr;
	typedef vector<InstancePtr> ListInstances;
}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__INSTANCE_H_
