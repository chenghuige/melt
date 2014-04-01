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

DEFINE_int32(labelIdx, -1, "");
DEFINE_int32(weightIdx, -1, "");
DEFINE_string(nameIdx, "", ", seprated like 1,2,3, name filed will be shown in .inst.txt result file");
DEFINE_string(attrIdx, "", "the same as nameIdx, attrIdx will be filed to be ignored");
DEFINE_bool(header, false, "no header by default");
DEFINE_string(sep, "tab", "or space or something like , ; etc.");
DEFINE_string(ncsep, "|", "contact names filed like pid|title|content 4003|good title|good content");
DEFINE_string(excl, "", "excl vs. incl determines whether features for the expression below are included or excluded. expression=[s:substringList | r:regexList | i:indexList | e:exactNameList]");
DEFINE_string(incl, "", "use excl will exlude those specified, use incl will only include those specified, use incl + excl means first incl then excl");
DEFINE_bool(sparse, false, "keep sparse");
DEFINE_bool(dense, false, "keep dense");

namespace gezi {

	void InstanceParser::ParseArguments()
	{
		_args.labelIdx = FLAGS_labelIdx;
		_args.weightIdx = FLAGS_weightIdx;
		_args.namesIdx = FLAGS_nameIdx;
		_args.attrsIdx = FLAGS_attrIdx;
		_args.hasHeader = FLAGS_header;
		_args.sep = FLAGS_sep;
		_args.ncsep = FLAGS_ncsep;
		_args.excl = FLAGS_excl;
		_args.incl = FLAGS_incl;
		_args.keepSparse = FLAGS_sparse;
		_args.keepDense = FLAGS_dense;
	}

}  //----end of namespace gezi

