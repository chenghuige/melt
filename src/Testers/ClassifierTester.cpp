/**
 *  ==============================================================================
 *
 *          \file   ClassifierTester.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2016-06-18 22:41:48.947919
 *
 *  \Description:
 *  ==============================================================================
 */

#include "common_util.h"
#include "Testers/ClassifierTester.h"

//----------for binary classification
//DEFINE_bool(useProb, true, "useProbForClassfierTester: ");
DEFINE_bool(useLn, true, "For Tester useLn = false means use log2");
DEFINE_double(posThre, 0.5, "for binary classification > thre means judge it as positive otherwise judge it as negative");

namespace gezi {

	void ClassificationPrecisionRecall::ParseArgs()
	{
		useLn = FLAGS_useLn;
		posThre = FLAGS_posThre;
	}

	//void ClassificationAUC::ParseArgs()
	//{
	//	//useProbability = FLAGS_useProb;
	//}
}
