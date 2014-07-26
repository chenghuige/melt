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
#include "Simple/PredictorFactory.h"
using namespace std;

int main(int argc, char *argv[])
{
	using gezi::simple::Predictor;
	using gezi::simple::PredictorFactory;
	Predictor predictor = PredictorFactory::LoadPredictor("./thread.model");
	
	int indices_[4] = { 1, 3, 5, 7 };
	double values_[4] = { 1.2, 3.1, 4.2, 1.1 };
	vector<int> indices(indices_, indices_ + 4);
	vector<double> values(values_, values_ + 4);

	double probability = predictor.Predict(indices, values);

	cout << "probability: " << probability << endl;

	return 0;
}
