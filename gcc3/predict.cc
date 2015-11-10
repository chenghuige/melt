/**
 *  ==============================================================================
 *
 *          \file   predict.cc
 *
 *        \author   chenghuige
 *
 *          \date   2015-05-19 09:50:13.709876
 *
 *  \Description:
 *
 *  ==============================================================================
 */

#include "GbdtPredictor.h"
#include <iostream>
using namespace std;

inline bool split(string input, const char sep, string& first, string& second, string& third)
{
	size_t index = input.find_first_of(sep);
	if (index == string::npos)
	{
		return false;
	}

	first = input.substr(0, index);
	index += 1;
	size_t index2 = input.find_first_of(sep, index);
	if (index2 == string::npos)
	{
		return false;
	}
	second = input.substr(index, index2 - index);

	third = input.substr(index2 + 1);
	return true;
}

vector<double> to_dvec(string input, const char sep)
{
	vector<double> vec;
	int preIndex = 0, index = 0;
	while (index < input.size())
	{
		index = input.find_first_of(sep, preIndex);
		vec.push_back(atof(input.substr(preIndex, index - preIndex).c_str()));
		preIndex = index + 1;
	}
	vec.push_back(atof(input.substr(preIndex).c_str()));
	return vec;
}

vector<melt::Feature> to_fvec(string input, const char sep)
{
	vector<melt::Feature> vec;
	int preIndex = 0, index = 0;
	int idx = 0;
	while (index < input.size())
	{
		index = input.find_first_of(sep, preIndex);
		double value = atof(input.substr(preIndex, index - preIndex).c_str());
		if (value != 0)
		{
			vec.push_back(melt::Feature(idx, value));
		}
		preIndex = index + 1;
		idx++;
	}
	double value = atof(input.substr(preIndex).c_str());
	if (value != 0)
	{
		vec.push_back(melt::Feature(idx, value));
	}
	return vec;
}

int _featureLength = 0;
void run()
{
	melt::GbdtPredictor predictor("./model");

	ifstream ifs("./data/test.txt");
	ofstream ofs("./predict.txt");
	string line;
	bool isHeader = true;
	while (getline(ifs, line))
	{
		if (isHeader)
		{
			isHeader = false;
			continue;
		}
		string id, label, features_;
		split(line, '\t', id, label, features_);

		vector<double> features = to_dvec(features_, '\t');
		_featureLength = features.size();
		double score = predictor.Predict(features);
		ofs << id << "\t" << label << "\t" << score << endl;
	}
}

double _nonEmptyFeatureLength = 0;
void run_sparse()
{
	melt::GbdtPredictor predictor("./model");

	ifstream ifs("./data/test.txt");
	ofstream ofs("./predict_sparse.txt");
	string line;
	bool isHeader = true;
	int numLines = 0;
	while (getline(ifs, line))
	{
		if (isHeader)
		{
			isHeader = false;
			continue;
		}
		string id, label, features_;
		split(line, '\t', id, label, features_);

		vector<melt::Feature> features = to_fvec(features_, '\t');
		double score = predictor.Predict(features);
		ofs << id << "\t" << label << "\t" << score << endl;
		numLines++;
		_nonEmptyFeatureLength += features.size();
	}
	_nonEmptyFeatureLength /= numLines;

	std::cout << "featureLength is " << _featureLength << std::endl;
	std::cout << "nonEmptyFeatureLength(avg) is " << _nonEmptyFeatureLength << std::endl;
}

int main(int argc, char *argv[])
{
	run();
	run_sparse();
	return 0;
}
