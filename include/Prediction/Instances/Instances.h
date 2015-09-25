/**
 *  ==============================================================================
 *
 *          \file   Prediction/Instances/Instances.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-03-26 13:30:24.569456
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__INSTANCES__INSTANCES_H_
#define PREDICTION__INSTANCES__INSTANCES_H_
#include "common_util.h"
#include "Prediction/Instances/HeaderSchema.h"
#include "Prediction/Instances/Instance.h"
#include "random_util.h"

namespace gezi {

	//@TODO Clone() ?   copy on write ?
	struct Instances : public ListInstances
	{
	public:
		~Instances() = default;
		Instances() = default;
		Instances(Instances&&) = default;
		Instances& operator = (Instances&&) = default;
		Instances(const Instances&) = default;
		Instances& operator = (const Instances&) = default;

		//@TODO C++ 没有默认的 == 。。。
		//bool operator==(const Instance&) = default;

		explicit Instances(const HeaderSchema& schema_)
			:schema(schema_)
		{

		}

		void CopySchema(const HeaderSchema& schema_)
		{
			schema = schema_;
		}

		size_t InstanceNum() const
		{
			return this->size();
		}

		//注意不要有size()函数 因为本身public vector<> 否则会莫名hang掉
		size_t Size() const
		{
			return this->size();
		}

		size_t Count() const
		{
			return this->size();
		}

		int FeatureNum() const
		{
			return schema.FeatureNum();
		}

		int NumFeatures() const
		{
			return schema.NumFeatures();
		}

		const FeatureNamesVector& FeatureNames() const
		{
			return schema.featureNames;
		}

		Float& operator()(size_t row, size_t col)
		{
			return (*this)[row]->features[col];
		}

		const Float operator()(size_t row, size_t col) const
		{
			return (*this)[row]->features[col];
		}

		FeatureNamesVector& FeatureNames()
		{
			return schema.featureNames;
		}

		bool HasHeader() const
		{
			return schema.HasHeader();
		}

		string HeaderStr() const
		{
			return schema.HeaderStr();
		}

		void SetHeader(string header_, bool hasHeader_)
		{
			schema.SetHeader(header_, hasHeader_);
		}

		void Randomize(const RandomEngine& rng)
		{
			shuffle(*this, rng);
		}

		//原地Shrink
		void ShrinkData(double trainProportion, const RandomEngine& rng)
		{
			if (trainProportion >= 1.0)
			{
				return;
			}
			int removeSize = (int)((1.0 - trainProportion) * InstanceNum());
			int afterSize = InstanceNum() - removeSize;
			sample_reverse(*this, removeSize, rng);
			this->resize(afterSize);
		}

		void Add(const InstancePtr& instancePtr)
		{
			this->push_back(instancePtr);
		}

		void PrintSummary(int level = 0)
		{
			uint64 pcnt = PositiveCount();
			VLOG(level) << format("Total instance num: {} PostiveCount: {} NegativeCount {} PostiveRatio: {}%"
				, InstanceNum(), pcnt, (InstanceNum() - pcnt), ((double)pcnt * 100 / InstanceNum()));
			uint64 dcnt = DenseCount();
			VLOG(level) << format("DenseCount: {} SparseCount: {} DenseRatio: {}%", dcnt, (InstanceNum() - dcnt), ((double)dcnt * 100 / InstanceNum()));
		}

		uint64 PositiveCount()
		{
			return from(*this) >> where([](const InstancePtr& a) { return a->label > 0; })
				>> count();
		}

		uint64 NegativeCount()
		{
			return from(*this) >> where([](const InstancePtr& a) { return a->label <= 0; })
				>> count();
		}

		uint64 SparseCount()
		{
			return from(*this) >> where([](const InstancePtr& a) { return a->IsSparse(); })
				>> count();
		}

		uint64 DenseCount()
		{
			return from(*this) >> where([](const InstancePtr& a) { return a->IsDense(); })
				>> count();
		}

		void SetNormalized(bool norm = true)
		{
			schema.normalized = norm;
		}

		bool IsNormalized()
		{
			return schema.normalized == true;
		}

	public:
		HeaderSchema schema;
		string name;
	};

}  //----end of namespace gezi

namespace cereal
{
	template <class Archive> inline
		void CEREAL_SAVE_FUNCTION_NAME(Archive & ar, gezi::Instances const & vector)
	{
		ar(make_size_tag(static_cast<size_type>(vector.size()))); // number of elements
		for (auto && v : vector)
			ar(v);
		ar(vector.schema);
		ar(vector.name);
	}

	template <class Archive> inline
		void CEREAL_LOAD_FUNCTION_NAME(Archive & ar, gezi::Instances & vector)
	{
		size_type size;
		ar(make_size_tag(size));

		vector.resize(static_cast<std::size_t>(size));
		for (auto && v : vector)
			ar(v);
		ar(vector.schema);
		ar(vector.name);
	}
}

#endif  //----end of PREDICTION__INSTANCES__INSTANCES_H_
