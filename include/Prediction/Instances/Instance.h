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

	Instance(int length)
		:features(length)
	{

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
		return label == -std::numeric_limits<double>::infinity();
	}

	bool HasMissingFeatures()
	{
		return hasMissingFeatures;
	}

	Vector features;
	bool hasMissingFeatures = false;
	Float label = -std::numeric_limits<double>::infinity();
	string name;
	svec names;
	svec attributes;
	string metaData;
	bool sparse = false;
	Float weight = 1.0;
	bool normalized = false;
};
typedef shared_ptr<Instance> InstancePtr;
typedef vector<InstancePtr> ListInstances;

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__INSTANCE_H_
