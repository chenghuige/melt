/**
 *  ==============================================================================
 *
 *          \file   RankerTester.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2016-06-18 22:41:54.932824
 *
 *  \Description:
 *  ==============================================================================
 */

#include "common_util.h"
#include "Testers/RankerTester.h"

//----------for rank
DEFINE_int32(dcg, 3, "dcgTruncationLevel | Max. truncation level for computing (N)DCG");
DEFINE_bool(msTest, true, "by default will use ms test strategy");
DEFINE_string(gains, "", "if not set will use {0,3,7,15,31} as ms test stratgey");
DEFINE_bool(excludeNoRelevant, false, "if set will exclude quries with all zero label docs");

namespace gezi {

	void RankingMetrics::ParseArgs()
	{
		if (!FLAGS_gains.empty())
		{
			gainMap = from(gezi::split(FLAGS_gains, ',')) >> select([](string gain) { return FLOAT_(gain); }) >> to_vector();
		}
		if (FLAGS_msTest)
		{
			useLn = true;
			if (FLAGS_gains.empty())
			{
				gainMap = { 0.0, 3.0, 7.0, 15.0, 31.0 };
			}
		}
		else
		{
			useLn = false;
			if (FLAGS_gains.empty())
			{
				gainMap = { 0.0, 1.0, 3.0, 7.0, 15.0 };
			}
		}
		excludeNoRelevant = FLAGS_excludeNoRelevant;
	}

}

