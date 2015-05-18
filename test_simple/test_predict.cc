/**
 *  ==============================================================================
 *
 *          \file   test_predict.cc
 *
 *        \author   chenghuige
 *
 *          \date   2014-07-26 09:35:27.230220
 *
 *   \Description
 *
 *  ==============================================================================
 */

#include <iostream>
#include <stdio.h>

#define  MELT_NO_THIRD_PREDICTOR
#include "PredictorFactory.h"

using namespace std;

int main(int argc, char *argv[])
{
	using gezi::simple::Predictor;
	using gezi::simple::PredictorFactory;
	Predictor predictor = PredictorFactory::LoadPredictor("./model");

	{
		vector<int> indices;
		vector<double> values;

		double output = predictor.Output(indices, values);
		double probability = predictor.Predict(indices, values, output);
		
		cout << "output: " << output << endl;
		cout << "probability: " << probability << endl;
	}

	{
		vector<int> indices;
		vector<double> values;
		double output = 0;
		double probability = predictor.Predict(indices, values, output);

		cout << "output: " << output << endl;
		cout << "probability: " << probability << endl;
	}

	{
		vector<double> values(1024000, 0);

		double output = 0;
		double probability = predictor.Predict(values, output);

		cout << "output: " << output << endl;
		cout << "probability: " << probability << endl;
	}

	return 0;
}
