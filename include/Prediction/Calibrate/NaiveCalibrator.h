/**
 *  ==============================================================================
 *
 *          \file   Prediction/Calibrate/NaiveCalibrator.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-08 18:37:22.547705
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__CALIBRATE__NAIVE_CALIBRATOR_H_
#define PREDICTION__CALIBRATE__NAIVE_CALIBRATOR_H_

#include "Prediction/Calibrate/Calibrator.h"
namespace gezi {

	//@FIXME 好像结果也不对 第2个output 大 但是概率值却小  但是TLC输出貌似也存在这个问题@TODO
	//应该是正确的基本AUC结果一致 本身算法存在问题应该
	//1	1.96331	0.9
	//1	2.56318	0.866667
	//0	0.0373289	0.473684
class NaiveCalibrator : public Calibrator
{
public:
	/// Done training; set the variables to whatever is needed.
	virtual void FinishTraining() override
	{
		Initialize();
	}

	virtual void Load(string path) override
	{
		LoadSave::Load(path);
		serialize_util::load(*this, path);
	}

	virtual void Save(string path) override
	{
		serialize_util::save(*this, path);
	}

	virtual string Name() override
	{
		return "NaiveCalibrator";
	}

	/// Given a classifier output, produce the probability
	virtual Float PredictProbability(Float output) override
	{
		int binIdx = GetBinIdx(output);
		return binProbs[binIdx];
	}

	/// Training calibrators:  provide the classifier output and the class label
	virtual void ProcessTrainingExample(Float output, bool clicked, Float weight) override
	{
		//AP todo proper weighting here
		if (clicked)
		{
			cMargins.push_back(output);
		}
		else
		{
			ncMargins.push_back(output);
		}
	}

private:
	// get the bin for a given output
	int GetBinIdx(Float output)
	{
		int binIdx = (int)((output - _min) / binSize);
		if (binIdx >= numBins)
			binIdx = numBins - 1;
		if (binIdx < 0)
			binIdx = 0;
		return binIdx;
	}

	/// Compute the cached values of means and standard deviations
	void Initialize()
	{
		Fvec& cOutputs = cMargins;
		Float minC = ufo::min(cOutputs);
		Float maxC = ufo::max(cOutputs);

		Fvec& ncOutputs = ncMargins;
		Float minNC = ufo::min(ncOutputs);
		Float maxNC = ufo::max(ncOutputs);

		_min = (minC < minNC) ? minC : minNC;
		_max = (maxC > maxNC) ? maxC : maxNC;
		binSize = (_max - _min) / numBins;

		Fvec cBins(numBins, 0);
		Fvec ncBins(numBins, 0);
		for(Float xi : cOutputs)
		{
			int binIdx = GetBinIdx(xi);
			cBins[binIdx]++;
		}

		for(Float xi : ncOutputs)
		{
			int binIdx = GetBinIdx(xi);
			ncBins[binIdx]++;
		}

		binProbs.resize(numBins, 0);
		for (int i = 0; i < numBins; i++)
		{
			if (cBins[i] + ncBins[i] == 0)
				binProbs[i] = 0;
			else
				binProbs[i] = cBins[i] / (cBins[i] + ncBins[i]);
		}

		// sanity check
		Fvec cP(cOutputs.size(), 0);
		Fvec ncP(ncOutputs.size(), 0);
		for (size_t i = 0; i < cOutputs.size(); i++)
			cP[i] = PredictProbability(cOutputs[i]);
		for (size_t i = 0; i < cOutputs.size(); i++)
			ncP[i] = PredictProbability(ncOutputs[i]);
	}

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
	/*	ar & boost::serialization::base_object<Calibrator>(*this);
		ar & cMargins;
		ar & ncMargins;
		ar & numBins;
		ar & binSize;
		ar & _min;
		ar & _max;
		ar & binProbs;*/

		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Calibrator);
		ar & GEZI_SERIALIZATION_NVP(cMargins);
		ar & GEZI_SERIALIZATION_NVP(ncMargins);
		ar & GEZI_SERIALIZATION_NVP(numBins);
		ar & GEZI_SERIALIZATION_NVP(binSize);
		ar & GEZI_SERIALIZATION_NVP(_min);
		ar & GEZI_SERIALIZATION_NVP(_max);
		ar & GEZI_SERIALIZATION_NVP(binProbs);
	}

protected:
private:
	Fvec cMargins;
	Fvec ncMargins;

	int numBins = 200;
	Float binSize = 0;
	Float _min = std::numeric_limits<Float>::max();
	Float _max = std::numeric_limits<Float>::min();
	Fvec binProbs;
};
}  //----end of namespace gezi

#endif  //----end of PREDICTION__CALIBRATE__NAIVE_CALIBRATOR_H_
