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

		Instances(const HeaderSchema& schema_)
			:schema(schema_)
		{

		}

		void CopySchema(const HeaderSchema& schema_)
		{
			schema = schema_;
		}

		uint64 InstanceNum() const
		{
			return this->size();
		}

		uint64 Size() const
		{
			return this->size();
		}

		uint64 Count() const
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

		const svec& FeatureNames() const
		{
			return schema.featureNames;
		}

		svec& FeatureNames()
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

		void ShrinkData(double trainProportion, const RandomEngine& rng)
		{
			if (trainProportion >= 1.0)
			{
				return;
			}
			int removeSize = (int)((1.0 - trainProportion) * InstanceNum());
			int afterSize = InstanceNum() - removeSize;
			LOG(INFO) << format("Shrinking *thisset to %1 of original from %2 to %3") % trainProportion % InstanceNum() % afterSize;
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
			VLOG(level) << format(
				"Total instance num: %1% PostiveCount: %2% NegativeCount %3% PostiveRatio: %4%")
				% InstanceNum() % pcnt %
				(InstanceNum() - pcnt) % ((double)pcnt * 100 / InstanceNum());
			uint64 dcnt = DenseCount();
			VLOG(level) << format("DenseCount: %1% SparseCount: %2% DenseRatio: %3%") % dcnt % (InstanceNum() - dcnt) % ((double)dcnt * 100 / InstanceNum());
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
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__INSTANCES_H_
