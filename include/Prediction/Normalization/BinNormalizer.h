/**
 *  ==============================================================================
 *
 *          \file   Prediction/Normalization/BinNormalizer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-01 17:08:46.005841
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__BIN_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__BIN_NORMALIZER_H_
#include "Matrix.h"
#include "Prediction/Normalization/Normalizer.h"
namespace gezi {

	class BinNormalizer : public Normalizer
	{
	public:
		BinNormalizer()
			£º_normType(NormType::Bin)
		{
				_func = [this](int index, Float& value)
				{
					if (_included[index])
					{
						auto iter = lower_bound(binUpperBounds[index].begin(), binUpperBounds[index].end(), value);
						if (iter != binUpperBounds[index].end())
							value = binValues[i][iter - binUpperBounds.begin()];
						else
							THROW("input value is larger than the biggest number in array");
					}
				};
		}

		virtual void Begin() override
		{
			_included.resize(_numFeatures, true);
			binUpperBounds.resize(_numFeatures);
			values.resize(_numFeatures);
		}

		virtual void Process(const Vector& vec) override
		{
			vec.ForEachAll([this](int idx, Float val) { values[idx].push_back(val); });
		}

		virtual void Finish() override
		{
			init(binValues, _numFeatures, numBins);
			for (int i = 0; i < _numFeatures; i++)
				for (int j = 0; j < numBins; j++)
					binValues[i][j] = (Float)j / numBins;

			// pre-compute the normalization range for each feature
			for (int i = 0; i < _numFeatures; i++)
			{
				binUpperBounds[i] = find_bins(values[i], numBins);
				if (binUpperBounds[i][0] == binUpperBounds[i].back())
					_included[i] = false;
				else if (binUpperBounds[i][0] < 0)
					_shiftIndices.push_back(i);

				// reclaculate bin values if too few
				if ((int)binUpperBounds[i].size() < numBins)
				{
					int numBinsActual = binUpperBounds[i].size();
					binValues[i].resize(numBinsActual, 0);

					for (int j = 0; j < numBinsActual; j++)
						binValues[i][j] = (Float)j / (numBinsActual - 1);
				}
			}
		}

	protected:
	private:
		//------------args begin
		int numBins = 1000; //n|Max number of bins
		//------------args end

		// min/max values and ranges for all features
		Fmat binUpperBounds;
		Fmat binValues;
		Fmat values; //no need to serialize

		BitArray _included;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__BIN_NORMALIZER_H_
