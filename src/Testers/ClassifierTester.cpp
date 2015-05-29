/**
 *  ==============================================================================
 *
 *          \file   ClassifierTester.cpp
 *
 *        \author   chenghuige
 *
 *          \date   2014-11-14 06:49:38.144760
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef CLASSIFIER_TESTER_CPP_
#define CLASSIFIER_TESTER_CPP_

#include "common_util.h"
#include "Testers/ClassifierTester.h"

DEFINE_bool(useProb, true, "useProbForClassfierTester: ");
DEFINE_bool(useLn, true, "For Classifier Tester useLn = false means use log2");

namespace gezi {

	void ClassificationPrecisionRecall::ParseArgs()
	{
		useLn = FLAGS_useLn;
	}

	void ClassificationAUC::ParseArgs()
	{
		useProbability = FLAGS_useProb;
	}

}

#endif  //----end of CLASSIFIER_TESTER_CPP_
