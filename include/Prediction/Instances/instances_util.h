/**
 *  ==============================================================================
 *
 *          \file   Prediction/Instances/instances_util.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-02 20:34:03.488226
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__INSTANCES_INSTANCES_UTIL_H_
#define PREDICTION__INSTANCES_INSTANCES_UTIL_H_

#include "InstanceParser.h"
namespace gezi {
	inline Instances create_instances(string infile)
	{
		InstanceParser parser;
		return parser.Parse(infile);
	}

	inline void write_dense(Instance& instance, HeaderSchema& schema, ofstream& ofs)
	{
		instance.features.MakeDense();
		size_t featureIdx = 0, nameIdx = 0, attributeIdx = 0;
		switch (schema.cloumnTypes[0])
		{
		case ColumnType::Feature:
			ofs << instance.features[featureIdx++];
			break;
		case ColumnType::Name:
			ofs << instance.names[nameIdx++];
			break;
		case ColumnType::Label:
			ofs << instance.label;
			break;
		case ColumnType::Weight:
			ofs << instance.weight;
			break;
		case ColumnType::Attribute:
			ofs << instance.attributes[attributeIdx++];
			break;
		default:
			break;
		}
		for (size_t i = 1; i < schema.cloumnTypes.size(); i++)
		{
			switch (schema.cloumnTypes[i])
			{
			case ColumnType::Feature:
				ofs << "\t" << instance.features[featureIdx++];
				break;
			case ColumnType::Name:
				ofs << "\t" << instance.names[nameIdx++];
				break;
			case ColumnType::Label:
				ofs << "\t" << instance.label;
				break;
			case ColumnType::Weight:
				ofs << "\t" << instance.weight;
				break;
			case ColumnType::Attribute:
				ofs << "\t" << instance.attributes[attributeIdx++];
				break;
			default:
				break;
			}
		}
		instance.features.Clear();
	}
	inline void write_dense(Instances& instances, string outfile)
	{
		ofstream ofs(outfile);
		if (instances.HasHeader())
		{
			ofs << instances.HeaderStr() << endl;
		}
		for (InstancePtr instance : instances)
		{
			write_dense(*instance, instances.schema, ofs);
		}
	}

	inline void write_sparse(Instance& instance, HeaderSchema& schema, ofstream& ofs)
	{
		instance.features.MakeSparse();
		size_t featureIdx = 0, nameIdx = 0, attributeIdx = 0;
		switch (schema.cloumnTypes[0])
		{
		case ColumnType::Feature:
			ofs << instance.features.indices[featureIdx++] << ":" << instance.features.values[featureIdx++];
			break;
		case ColumnType::Name:
			ofs << instance.names[nameIdx++];
			break;
		case ColumnType::Label:
			ofs << instance.label;
			break;
		case ColumnType::Weight:
			ofs << instance.weight;
			break;
		case ColumnType::Attribute:
			ofs << instance.attributes[attributeIdx++];
			break;
		default:
			break;
		}

		for (size_t i = 1; i < schema.cloumnTypes.size(); i++)
		{
			switch (schema.cloumnTypes[i])
			{
			case ColumnType::Feature:
				ofs << "\t" << instance.features.indices[featureIdx++] << ":" << instance.features.values[featureIdx++];
				break;
			case ColumnType::Name:
				ofs << "\t" << instance.names[nameIdx++];
				break;
			case ColumnType::Label:
				ofs << "\t" << instance.label;
				break;
			case ColumnType::Weight:
				ofs << "\t" << instance.weight;
				break;
			case ColumnType::Attribute:
				ofs << "\t" << instance.attributes[attributeIdx++];
				break;
			default:
				break;
			}
		}

		for (; featureIdx < instance.features.indices.size(); featureIdx++)
		{
			ofs << "\t" << instance.features.indices[featureIdx++] << ":" << instance.features.values[featureIdx++];
		}

		instance.features.Clear();
	}

	inline void write_sparse(Instances& instances, string outfile)
	{
		ofstream ofs(outfile);
		if (instances.HasHeader())
		{
			ofs << instances.HeaderStr() << endl;
		}
		for (InstancePtr instance : instances)
		{
			write_sparse(*instance, instances.schema, ofs);
		}
	}

	inline void write_text(Instances& instances, string outfile)
	{

	}

	inline void write_libsvm(Instances& instances, string outfile)
	{

	}

	inline void write_arff(Instances& instances, string outfile)
	{

	}

	inline void write(Instances& instances, string outfile, FileFormat format)
	{
		if (format == FileFormat::Unknown)
		{
			format = instances.schema.fileFormat;
		}

		switch (format)
		{
		case FileFormat::Dense:
			write_dense(instances, outfile);
			break;
		case  FileFormat::Sparse:
		case FileFormat::SparseNoLenth:
			write_sparse(instances, outfile);
			break;
		case FileFormat::Text:
			break;
		case  FileFormat::LibSVM:
			break;
		case FileFormat::Arff:
			break;
		default:
			break;
		}
	}

	inline void write(Instances& instances, string outfile)
	{
		write(instances, outfile, instances.schema.fileFormat);
	}
}  //----end of namespace gezi

#endif  //----end of PREDICTION__INSTANCES_INSTANCES_UTIL_H_
