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

		Instances(const HeaderSchema& schema_)
			:schema(schema_)
		{
			
		}

		void CopySchema(const HeaderSchema& schema_)
		{
			schema = schema_;
		}

		uint64 InstanceNum()
		{
			return this->size();
		}

		uint64 Size()
		{
			return this->size();
		}

		uint64 Count()
		{
			return this->size();
		}

		int FeatureNum() const
		{
			return schema.FeatureNum();
		}

		svec FeatureNames() const
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

		template<typename ValueVistor>
		void ForEach(ValueVistor visitor) const
		{
			for (const InstancePtr& inst : *this)
			{
				visitor(*inst);
			}
		}

		template<typename ValueVistor>
		void ForEach(ValueVistor visitor)
		{
			for (InstancePtr& inst : *this)
			{
				visitor(ref(*inst));
			}
		}

		string GetSummary()
		{
			uint64 pcnt = PositiveCount();
			return (format(
				"Total instance num: %1% PostiveCount: %2% NegativeCount %3% PostiveRatio: %4%")
				% InstanceNum() % pcnt % 
				(InstanceNum() - pcnt) % ((double) pcnt * 100/ InstanceNum())).str();
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

	public:
		HeaderSchema schema;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__INSTANCES_H_
