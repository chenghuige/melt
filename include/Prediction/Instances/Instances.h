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
	struct Instances
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
			return data.size();
		}

		uint64 Size()
		{
			return data.size();
		}

		uint64 Count()
		{
			return data.size();
		}

		int FeatureNum() const
		{
			return schema.FeatureNum();
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
			shuffle(data, rng);
		}

		void ShrinkData(double trainProportion, const RandomEngine& rng)
		{
			if (trainProportion >= 1.0)
			{
				return;
			}
			int removeSize = (int)((1.0 - trainProportion) * InstanceNum());
			int afterSize = InstanceNum() - removeSize;
			LOG(INFO) << format("Shrinking dataset to %1 of original from %2 to %3") % trainProportion % InstanceNum() % afterSize;
			sample_reverse(data, removeSize, rng);
			data.resize(afterSize);
		}

		void Add(const InstancePtr& instancePtr)
		{
			data.push_back(instancePtr);
		}

		template<typename ValueVistor>
		void ForEach(ValueVistor visitor) const
		{
			for (const InstancePtr& inst : data)
			{
				visitor(*inst);
			}
		}

		template<typename ValueVistor>
		void ForEach(ValueVistor visitor)
		{
			for (InstancePtr& inst : data)
			{
				visitor(ref(*inst));
			}
		}

		ListInstances& Data()
		{
			return data;
		}

		const ListInstances& Data() const
		{
			return data;
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
			return from(data) >> where([](const InstancePtr& a) { return a->label > 0; })
				>> count();
		}

		uint64 NegativeCount()
		{
			return from(data) >> where([](const InstancePtr& a) { return a->label <= 0; })
				>> count();
		}

		const InstancePtr& operator[](uint64 index) const
		{
			return data[index];
		}

	public:
		HeaderSchema schema;
		ListInstances data;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__INSTANCES_H_
