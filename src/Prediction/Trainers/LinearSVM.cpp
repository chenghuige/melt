/**
*  ==============================================================================
*
*          \file   LinearSVM.cpp
*
*        \author   chenghuige
*
*          \date   2014-04-08 19:36:17.509808
*
*  \Description:
*  ==============================================================================
*/

#ifndef LINEAR_S_V_M_CPP_
#define LINEAR_S_V_M_CPP_
#include "common_util.h"
#include "Trainers/SVM/LinearSVM.h"

DECLARE_bool(calibrate);
DECLARE_string(calibrator);
DECLARE_uint64(rs);

DECLARE_bool(norm);
DECLARE_string(normalizer);

DEFINE_int32(iter, 50000, "numIterExamples: Number of iterations");
DEFINE_double(lr, 0.001, "lambda: learning rate");

namespace gezi {
	//@TODO 自动command 代码生成器
	void LinearSVM::ParseArgs()
	{
		_args.calibrateOutput = FLAGS_calibrate;
		_args.calibratorName = FLAGS_calibrator;

		_args.normalizeFeatures = FLAGS_norm;

		_args.normalizerName = FLAGS_normalizer;

		_args.randSeed = FLAGS_rs;

		_args.numIterations = FLAGS_iter;
		_args.lambda = FLAGS_lr;
	}

}  //----end of namespace gezi

#endif  //----end of LINEAR_S_V_M_CPP_
