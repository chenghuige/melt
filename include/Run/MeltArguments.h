/**
 *  ==============================================================================
 *
 *          \file   Run/MeltArguments.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-03-31 09:02:40.483583
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef RUN__MELT_ARGUMENTS_H_
#define RUN__MELT_ARGUMENTS_H_
#include "common_util.h"
namespace gezi {

	struct MeltArguments
	{
		string command;
		string classifierName;
		string classifierSettings;
		int numFolds;
		int numRuns;
		int numThreads;
		int randSeed;
		string testDatafile;
		string datafile;
		string modelfile;
		string modelfileCode;
		string modelfileText;
		bool stratify;
		bool foldsSequential;
		double trainProportion;
	};

}  //----end of namespace gezi

#endif  //----end of RUN__MELT_ARGUMENTS_H_
