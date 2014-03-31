/**
 *  ==============================================================================
 *
 *          \file   Prediction/Instances/HeaderSchema.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-03-26 13:29:04.257629
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__INSTANCES__HEADER_SCHEMA_H_
#define PREDICTION__INSTANCES__HEADER_SCHEMA_H_

#include "common_util.h"
namespace gezi {

	enum class InstanceType
	{
		Dense = 0,
		Sparse
	};

	//所有header 以及其它非 instance内部数据的 整体信息 都在这里 Instances里面只要schema和data
	class HeaderSchema
	{
	public:
		~HeaderSchema() = default;
		HeaderSchema() = default;
		HeaderSchema(HeaderSchema&&) = default;
		HeaderSchema& operator = (HeaderSchema&&) = default;
		HeaderSchema(const HeaderSchema&) = default;
		HeaderSchema& operator = (const HeaderSchema&) = default;
	public:
		int FeatureNum()
		{
			return featureNames.size();
		}

		bool HasHeader() const
		{
			return hasHeader;
		}

		string HeaderStr() const
		{
			if (hasHeader)
			{
				return headerStr;
			}
			else
			{
				return "";
			}
		}

		void SetHeader(string header_, bool hasHeader_)
		{
			headerStr = header_;
			hasHeader = hasHeader_;
		}

		InstanceType GetInstanceType() const
		{
			return instanceType;
		}
	public:
		svec featureNames;
		svec attributeNames;
		svec tagNames;
		string headerStr;
		bool hasHeader = false;
		bool hasWeights = false;
		string groupKey;
		InstanceType instanceType;
		string instanceNameHeaderString = "Instance";
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__HEADER_SCHEMA_H_
