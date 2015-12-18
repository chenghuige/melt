/**
 *  ==============================================================================
 *
 *          \file   include/Prediction/Calibrate/SigmoidCalibrator.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-08 15:04:40.891903
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef INCLUDE__PREDICTION__CALIBRATE__SIGMOID_CALIBRATOR_H_
#define INCLUDE__PREDICTION__CALIBRATE__SIGMOID_CALIBRATOR_H_

#include "statistic_util.h"
#include "Prediction/Calibrate/Calibrator.h"
namespace gezi {

	//@TODO 测试结果正常 不过 貌似TLC 为什么有这样结果 ? 预测是- 概率确实0.9+ ？@FIXME
	//43060096782	1	0	-0.301788600113394	 0.938615051570983	0.0913944993702111
class SigmoidCalibrator : public CalibratorWrapper
{
public:

	SigmoidCalibrator() = default;

	SigmoidCalibrator(double a, double b)
		:paramA(a), paramB(b)
	{

	}

	virtual Float PredictProbability(Float output)
	{
		return sigmoid(output, paramA, paramB);
	}

	virtual string Name() override
	{
		return "Sigmoid/PlattCalibrator";
	}

	virtual bool Load(string path) override
	{
		bool ret = LoadSave::Load(path);
		if (!ret)
			return false;
		ret = serialize_util::load(*this, path);
		PVAL2(paramA, paramB);
		return ret;
	}

	virtual void Save(string path) override
	{
		LoadSave::Save(path);
		serialize_util::save(*this, path);
	}

	virtual void SaveXml(string path) override
	{
		LoadSave::SaveXml(path);
		serialize_util::save_xml(*this, path);
	}

	virtual void SaveJson(string path) override
	{
		LoadSave::SaveJson(path);
		serialize_util::save_json(*this, path);
	}

	virtual void SaveText(string file) override
	{
		LoadSave::SaveText(file);
		ofstream ofs(file);
		ofs << "CalibratorName=" << Name() << endl;
		ofs << "paramA=" << paramA << endl;
		ofs << "paramB=" << paramB << endl;
	}

	double ParamA() const
	{
		return paramA;
	}

	double ParamB() const
	{
		return paramB;
	}

protected:

	//@TODO understand
	// Adapted from John Platt's smox code.
	//
	// Use the Levenberg-Marquardt algorithm to fit a sigmoid to the output
	// of the SVM over the training set. The goodness of fit is measured via
	// the likelihood that the output data came from the probability produced
	// by the sigmoid.
	//     Parameters:
	//  out = output of SVM
	//  target = desired output
	//  len = length of training set
	//  prior[0/1] = number of examples in training set that are 0/1
	//  Results are put into A and B for use by probFunc above
	virtual void TrainModel(CalibratorStore& data) override
	{
		paramA = 0;
		paramB = 0;
		double prior0 = 0;
		double prior1 = 0;
		long N = 0;
		for(CalibratorStore::Node& d_i : data.Nodes())
		{
			auto weight = d_i.weight;
			if (d_i.target == 1)
				prior1 += weight;
			else
				prior0 += weight;
			N++;
		}
		if (N == 0)
			return;

		paramA = 0;
		// Initialize B to be the marginal probability of class
		// smoothed i.e. P(+ | x) = (N+ + 1) / (N + 2)
		paramB = log((prior0 + 1) / (prior1 + 1));

		// OK. We're going to maximize the likelihood of the output by
		// minimizing the cross-entropy of the output. Here's a
		// magic special hack: make the target of the cross-entropy function
		double hiTarget = (prior1 + 1) / (prior1 + 2);
		double loTarget = 1 / (prior0 + 2);

		double lambda = 0.001;
		double olderr = std::numeric_limits<double>::max() / 2;
		// array to store current estimate of probability of training points
		Fvec pp(N, 0);
		Float defValue = (Float)((prior1 + 1) / (prior0 + prior1 + 2));
		for (int i = 0; i < N; i++)
			pp[i] = defValue;

		int count = 0;

		// Don't go more than 100 iterations: LM is quadratically convergent, after all

		for (int it = 0; it < 100; it++)
		{
			double a = 0;
			double b = 0;
			double c = 0;
			double d = 0;
			double e = 0;
			// Loop over all points, computing Hessian of cross-entropy [a c; c b]
			// and gradient of cross-entropy [d e]

			int i = 0;
			for (CalibratorStore::Node& d_i : data.Nodes())
			{
				auto weight = d_i.weight;
				auto x = d_i.score;
				auto t = (d_i.target == 1 ? hiTarget : loTarget);
				auto p = pp[i];

				double deriv = p * (1 - p) * weight;
				double dd = (p - t) * weight;
				a += x * x * deriv;
				b += deriv;
				c += x * deriv;
				d += x * dd;
				e += dd;
				i++;
			}

			// If gradient is tiny, you're done
			if (d > -1e-9 && d < 1e-9 && e > -1e-9 && e < 1e-9)
			{
				break;
			}
			double err = 0;
			double oldA = paramA;
			double oldB = paramB;
			// Loop until you get a increase in the goodness of fit
			for (;;)
			{
				double det = (a + lambda) * (b + lambda) - c * c;

				if (det == 0.0)
				{
					lambda *= 10;
					continue;
				}
				// This is the Newton-Raphson step (with lambda as stabilizer)
				paramA = oldA + ((b + lambda) * d - c * e) / det;
				paramB = oldB + ((a + lambda) * e - c * d) / det;
				// Now, compute goodness of fit
				err = 0;

				i = 0;
				for (CalibratorStore::Node& d_i : data.Nodes())
				{
					auto y = (d_i.target == 1) ? d_i.score : -d_i.score;
					//@FIXME 这个地方是不是应该是 y,tlc可能是出错了? 不过感觉不需要label啊 同样的一堆output 只是因为label不同 就要映射结果不同吗？ 这里实际y没有用上 但是感觉应该只和output有关系 @TODO
					auto p = sigmoid(d_i.score, paramA, paramB); 
					auto t = (d_i.target == 1) ? hiTarget : loTarget;
					auto weight = d_i.weight;
					pp[i] = p;
					double logp = -200;
					double log1p = -200;
					if (p > 0.0)
						logp = log(p);
					if (p < 1.0)
						log1p = log(1 - p);
					err -= (t * logp + (1 - t) * log1p) * weight;

					i++;
				}

				// If goodness increased, you don't need so much stabilization
				if (err < olderr * (1.0 + 1e-7))
				{
					lambda *= 0.1;
					break;
				}
				// Oops. Goodness decreased. Newton-Raphson must be wigging out.
				// Increase stabilizer by factor of 10 and try again
				lambda *= 10;
				// If stabilizer is bigger than 1e6, just give up now.
				if (lambda >= 1e6)
					break;
			}

			// Check to see if goodness of fit has improved more than
			// a factor of about 1e-3 (either relative or absolute)
			// You've converged if this happens more than twice in a row
			double diff = err - olderr;

			double scale = 0.5 * (err + olderr + 1);
			if (diff > (-1e-3) * scale && diff < 1e-7 * scale)
				count++;
			else
				count = 0;
			olderr = err;
			if (count == 3)
				break;
		}
		Pval_2(paramA);
		Pval_2(paramB);
	}

	
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
	/*	ar & boost::serialization::base_object<CalibratorWrapper>(*this);
		ar & paramA;
		ar & paramB; */
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(CalibratorWrapper);
		ar & GEZI_SERIALIZATION_NVP(paramA);
		ar & GEZI_SERIALIZATION_NVP(paramB);
	}

private:
	double paramA = 0;
	double paramB = 0;

	// numbers taken from adpredict contest to give max or min probability
	const double POSINFINITY = -9.21; // positives are highly probable
	const double NEGINFINITY = 9.21; // negatives are highly probable

};

}  //----end of namespace gezi

CEREAL_REGISTER_TYPE(gezi::SigmoidCalibrator);
#endif  //----end of INCLUDE__PREDICTION__CALIBRATE__SIGMOID_CALIBRATOR_H_
