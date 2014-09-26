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
namespace gezi
{
	//默认支持的格式对应的 输入 输出 Instances 的文本格式
	//对应其它支持的模式比如text, libsvm 采用命令行设置确认
	enum class FileFormat
	{
		Unknown = 0,
		Dense,
		Sparse,  // 1230 1:3
		SparseNoLenth, // 1:3
		Text,
		LibSVM,
		Arff
	};

	enum class ColumnType
	{
		Unknown = 0,
		Feature,
		Name,
		Label,
		Weight,
		Attribute,
		Category,  //暂不支持
		Text       //暂不支持
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
		//bool operator==(const HeaderSchema&) const = default;
		//很遗憾 没有默认的
		bool operator==(const HeaderSchema& other) const
		{
			if (fileFormat == FileFormat::LibSVM && other.fileFormat == FileFormat::LibSVM)
			{
				return true;
			}
			
			return featureNames == other.featureNames && tagNames == other.tagNames;
		}
	public:
		int FeatureNum() const
		{
			return featureNames.size();
		}

		int NumFeatures() const
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

		FileFormat GetFileFormat() const
		{
			return fileFormat;
		}
	public:
		svec featureNames;
		svec attributeNames;
		svec tagNames;
		string headerStr;
		vector<ColumnType> cloumnTypes; //for writting instances
		bool hasHeader = false;
		bool hasWeights = false;
		string groupKey;
		FileFormat fileFormat = FileFormat::Unknown;
		string instanceNameHeaderString = "Instance";
		bool normalized = false;
		int numClasses = 2; //有几个分类 默认2分类 如果< 0则表示regression等非分类问题
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES__HEADER_SCHEMA_H_
