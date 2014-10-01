/**
 *  ==============================================================================
 *
 *          \file   Prediction/Calibrate/PAVCalibrator.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-08 17:34:37.774253
 *
 *  \Description: @TODO 验证和output 排序一致性 为什么auc结果有问题 包括naive
 *  ==============================================================================
 */

#ifndef PREDICTION__CALIBRATE__P_A_V_CALIBRATOR_H_
#define PREDICTION__CALIBRATE__P_A_V_CALIBRATOR_H_

#include "common_util.h"
#include "Prediction/Calibrate/Calibrator.h"
namespace gezi {

class PAVCalibrator : public CalibratorWrapper
{
public:
	struct Piece
	{
		Float minX = 0; // end of interval
		Float maxX = 0; // beginning of interval
		Float val = 0; // value of function in interval
		Float n = 0; // number of points/weight of interval

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
		/*	ar & minX;
			ar & maxX;
			ar & val;
			ar & n;*/

			ar & GEZI_SERIALIZATION_NVP(minX);
			ar & GEZI_SERIALIZATION_NVP(maxX);
			ar & GEZI_SERIALIZATION_NVP(val);
			ar & GEZI_SERIALIZATION_NVP(n);
		}
	};

	virtual void Load(string path) override
	{
		LoadSave::Load(path);
		serialize_util::load(*this, path);
	}

	virtual void Save(string path) override
	{
		serialize_util::save(*this, path);
	}

	virtual Float PredictProbability(Float score) override
	{
		Float prob = FindValue(score);
		if (prob < minToReturn)
			return minToReturn;
		if (prob > maxToReturn)
			return maxToReturn;
		return prob;
	}

	//@TODO what is this usage	?
	Float PredictLogOdds(Float score)
	{
		Float p = PredictProbability(score);
		return log(p / (1 - p));
	}

	virtual string Name() override
	{
		return "PAVCalibrator";
	}

protected:
	// build up the piecwise approximation
	// go through data in d_i.score sorted order for any out of order pairs (i.e. Target[i] > Target[i-1])
	// as an efficiency step do (Target[i] >= Target[i-1]) since this average will eventually be forced if there is a violator
	//  and interpolation will be done between segments when no violator
	virtual void TrainModel(CalibratorStore& data) override
	{
		for(CalibratorStore::Node& d_i : data.Nodes()) // this will iterate in sorted order
		{
			Piece curr;
			curr.maxX = d_i.score;
			curr.minX = d_i.score;
			curr.n = d_i.weight;
			curr.val = d_i.target;
			bool changed = true;
			int p = (int)piecewise.size();
			while (changed)
			{
				if (p == 0)
				{
					piecewise.emplace_back(curr);
					p++;
					changed = false;
				}
				else if ((piecewise[p - 1].maxX >= curr.minX) // equals can happen because of ties in score
					|| (curr.val <= piecewise[p - 1].val)) // adjacency violator?  (equals assumes we will interpolate between intervals later)
				{
					Float newW = piecewise[p - 1].n + curr.n;
					piecewise[p - 1].val = (piecewise[p - 1].val * piecewise[p - 1].n + curr.val * curr.n) / newW;
					piecewise[p - 1].n = newW;
					piecewise[p - 1].maxX = curr.maxX; // minX is the same as piecewise[p-1]
					curr = piecewise[p - 1];  // now pop and continue to check if changes need to be propagated back
					piecewise.pop_back();
					p--;
				}
				else
				{
					piecewise.emplace_back(curr);
					p++;
					changed = false;
				}
			}
		}

		VLOG(0) <<"PAV calibrator:  piecewise function approximation has " << piecewise.size() << " components.";
	}

	Float FindValue(Float score)
	{
		int P = piecewise.size();
		if (P == 0)
			return 0;
		if (score < piecewise[0].minX)
		{
			return piecewise[0].val;
			// tail off to zero exponentially
			// return Math.Exp(-(piecewise[0].minX-score)) * piecewise[0].val;
		}
		if (score > piecewise[P - 1].maxX)
		{
			return piecewise[P - 1].val;
			// tail off to one exponentially
			// return (1-Math.Exp(-(score - piecewise[P - 1].maxX)))   * (1 - piecewise[P - 1].val) + piecewise[P - 1].val;
		}
		int b = 0;
		int e = P - 1;
		int c = 0;
		bool found = false;
		while ((!found) && (b <= e))
		{
			c = b + e;
			if (c % 2 == 0)
				c /= 2;
			else
				c = (c - 1) / 2;
			// Console.Error.WriteLine("{0} {1} {2}", b, e, c);
			if (score >= piecewise[c].minX)
			{
				if (score <= piecewise[c].maxX)
				{
					found = true;
				}
				else
				{
					// search in latter half of array
					b = c + 1;
				}
			}
			else // in first half of array
				e = c - 1;
		}
		if (found)
			return piecewise[c].val;
		// Console.Error.WriteLine("l:{0} {1} {2} {3}", b, e, c, score);
		int p1 = 0, p2 = 0;
		if (b > c) // it occurs right after c
		{
			p1 = c;
			p2 = c + 1;
		}
		else if (e < c) // it occurs right before c
		{
			p1 = c - 1;
			p2 = c;
		}
		else
			THROW("Invariant violated in binary search.");
		// otherwise do interpolation
		Float slope = (piecewise[p2].val - piecewise[p1].val) / (piecewise[p2].minX - piecewise[p1].maxX);
		// compute y = m * (x - x_1) + y_1
		return slope * (score - piecewise[p1].maxX) + piecewise[p1].val;
	}

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
	/*	ar & boost::serialization::base_object<CalibratorWrapper>(*this);
		ar & piecewise;
		ar & minToReturn;
		ar & maxToReturn;*/
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(CalibratorWrapper);
		ar & GEZI_SERIALIZATION_NVP(piecewise);
		ar & GEZI_SERIALIZATION_NVP(minToReturn);
		ar & GEZI_SERIALIZATION_NVP(maxToReturn);
	}
protected:
private:
	vector<Piece> piecewise;
	Float minToReturn = EPSILON; // max predicted is 1 - min;
	Float maxToReturn = 1 - EPSILON; // max predicted is 1 - min;
};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__CALIBRATE__P_A_V_CALIBRATOR_H_
