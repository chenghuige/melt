/**
 *  ==============================================================================
 *
 *          \file   InstanceParser.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-03-27 18:56:39.400107
 *
 *  \Description:
 *  ==============================================================================
 */

#include "Prediction/Instances/InstanceParser.h"
#include "common_util.h"

DEFINE_int32(label, -1, "");
DEFINE_int32(weight, -1, "");
DEFINE_string(name, "", ", seprated like 1,2,3, name filed will be shown in .inst.txt result file");
DEFINE_string(attr, "", "the same as nameIdx, attrIdx will be filterd to be ignored");
DEFINE_string(group, "", "groupsKeyIdx, these idx must be nameIdx or attrIdx, it will be used to group instances especailly for ranking usage, same group will be forced to be in the same fold for cv creation also");
DEFINE_bool(header, false, "no header by default");
DEFINE_string(sep, "tab", "or space or something like , ; etc.");
DEFINE_string(ncsep, "|", "contact names filed like pid|title|content 4003|good title|good content");
DEFINE_string(excl, "", "excl vs. incl determines whether features for the expression below are included or excluded. expression=[s:substringList | r:regexList | i:indexList | e:exactNameList]");
DEFINE_string(incl, "", "use excl will exlude those specified, use incl will only include those specified, use incl + excl means first incl then excl");
DEFINE_int32(libsvmSI, 1, "For non libsvm sparse input file the startIndex is 0, for default libsvm startIndex is 1, here will also allow 0 start libsvm");

DEFINE_bool(sparse, false, "keep sparse");
DEFINE_bool(dense, false, "keep dense");
DEFINE_double(spthre, 0.5, "sparsifyThre");

DECLARE_string(format);
DECLARE_string(rd);

namespace gezi {

	void InstanceParser::ParseArguments()
	{
		_args.labelIdx = FLAGS_label;
		_args.weightIdx = FLAGS_weight;
		_args.namesIdx = FLAGS_name;
		_args.attrsIdx = FLAGS_attr;
		_args.groupsIdx = FLAGS_group;
		_args.hasHeader = FLAGS_header;
		_args.sep = FLAGS_sep;
		_args.ncsep = FLAGS_ncsep;
		_args.excl = FLAGS_excl;
		_args.incl = FLAGS_incl;
		_args.keepSparse = FLAGS_sparse;
		_args.keepDense = FLAGS_dense;
		_args.sparsifyThre = FLAGS_spthre;
		_args.inputFormat = FLAGS_format;
		_args.resultDir = FLAGS_rd;
		_args.libsvmStartIndex = FLAGS_libsvmSI;
	}

}  //----end of namespace gezi

