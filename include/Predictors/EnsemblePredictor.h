/**
 *  ==============================================================================
 *
 *          \file   Predictors/EnsemblePredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2015-04-17 22:12:39.554834
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__ENSEMBLE_PREDICTOR_H_
#define PREDICTORS__ENSEMBLE_PREDICTOR_H_
#include "MLCore/Predictor.h"
#include "MLCore/PredictorFactory.h"

namespace gezi {

	class EnsemblePredictor : public Predictor
	{
	public:
		EnsemblePredictor(vector<PredictorPtr>&& predictors, CalibratorPtr calibrator)
		{
			_predictors = move(predictors);
			_calibrator = calibrator;
		}
		EnsemblePredictor() = default;

		using Predictor::Predict;
		using Predictor::Output;
		//@TODO  Ã·π©const ∞Ê±æ
		virtual Float Predict(Vector& features) override
		{
			if (_calibrator != nullptr)
			{
				return Predict(Output(features));
			}
			else
			{
				double probability = 0;
#pragma omp parallel for reduction(+: probability)
				for (size_t i = 0; i < _predictors.size(); i++)
				{
					probability += _predictors[i]->Predict(features);
				}
				return probability / _predictors.size();
			}
		}

	protected:
		virtual Float Margin(Vector& features) override
		{
			Float out = 0;
#pragma omp parallel for reduction(+: out)
			for (size_t i = 0; i < _predictors.size(); i++)
			{
				out += _predictors[i]->Output(features);
			}
			return out / (Float)_predictors.size();
		}

		virtual string Name() override
		{
			return "ensemble";
		}

		virtual void SaveBin(string path) override
		{
			string numPredictorsFile = path + "/numPredictors.txt";
			write_file(_predictors.size(), numPredictorsFile);

			for (size_t i = 0; i < _predictors.size(); i++)
			{
				string mpath = format("{}/model{}", path, i);
				try_create_dir(mpath);
				_predictors[i]->Save(mpath);
			}
		}

		virtual void LoadBin(string path)
		{
			string numPredictorsFile = path + "/numPredictors.txt";
			int numPredictors;
			read_file(numPredictorsFile, numPredictors);
			_predictors.resize(numPredictors);
			for (size_t i = 0; i < _predictors.size(); i++)
			{
				string mpath = format("{}/model{}", path, i);
				_predictors[i] = PredictorFactory::LoadPredictor(mpath);
			}
		}

	protected:
		vector<PredictorPtr> _predictors;
	private:
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTORS__ENSEMBLE_PREDICTOR_H_
