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

		//@TODO 考虑对于RankingInstances的randomize by query
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

		void PrintSummary(int level = 0) const
		{
			uint64 pcnt = PositiveCount();
			VLOG(level) << format("Total instance num: {} PostiveCount: {} NegativeCount {} PostiveRatio: {}%"
				, InstanceNum(), pcnt, (InstanceNum() - pcnt), ((double)pcnt * 100 / InstanceNum()));
			uint64 dcnt = DenseCount();
			VLOG(level) << format("DenseCount: {} SparseCount: {} DenseRatio: {}%", dcnt, (InstanceNum() - dcnt), ((double)dcnt * 100 / InstanceNum()));
		}

		uint64 PositiveCount() const
		{
			return from(*this) >> where([](const InstancePtr& a) { return a->label > 0; })
				>> count();
		}

		uint64 NegativeCount() const
		{
			return from(*this) >> where([](const InstancePtr& a) { return a->label <= 0; })
				>> count();
		}

		uint64 SparseCount() const
		{
			return from(*this) >> where([](const InstancePtr& a) { return a->IsSparse(); })
				>> count();
		}

		uint64 DenseCount() const
		{
			return from(*this) >> where([](const InstancePtr& a) { return a->IsDense(); })
				>> count();
		}

		void SetNormalized(bool norm = true)
		{
			schema.normalized = norm;
		}

		bool IsNormalized() const
		{
			return schema.normalized == true;
		}

		bool IsRankingInstances() const
		{
			return !schema.groupKeys.empty();
		}

		bool IsBinaryClassificationInstances() const
		{
			return schema.groupKeys.empty() && schema.numClasses == 2;
		}

		bool IsClassificationInstances() const
		{
			return schema.groupKeys.empty() && schema.numClasses > 1;
		}

		bool IsMultiClassificationInstances() const
		{
			return schema.groupKeys.empty() && schema.numClasses > 2;
		}

		//通常意义的regression问题，拟合浮点数，但是 其实 1,2,3,4 这样的标注 除了可以rank，多分类之外  也可能用regression解决
		bool IsRegressionInstances() const
		{
			return schema.numClasses == -1;
		}

		int NumClasses() const
		{
			return schema.numClasses;
		}

		//for RankingInstances
		size_t NumGroups() const
		{
			return groups.size();
		}

#ifndef GCCXML
		typedef unordered_map<string, ListInstances> GroupMap;
		//对应RankingInstances 获取组信息
		GroupMap& GetGroups() 
		{
			//AutoTimer timer("GetGropus");
			if (groups.empty())
			{
				for (InstancePtr instance : *this)
				{
					string groupName = instance->groupKey;
					groups[groupName].push_back(instance);
				}
			}
			return groups;
		}
#endif
	public:
		HeaderSchema schema;
		string name;
#ifndef GCCXML
		GroupMap groups;
#endif
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
