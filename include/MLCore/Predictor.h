/**
 *  ==============================================================================
 *
 *          \file   MLCore/Predictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-07 22:07:30.510777
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef M_L_CORE__PREDICTOR_H_
#define M_L_CORE__PREDICTOR_H_

#include "common_util.h"
#include "serialize_util.h"

#include "Prediction/Normalization/NormalizerFactory.h"
#include "Prediction/Calibrate/CalibratorFactory.h"
#include "Prediction/Instances/Instance.h"
#include "Prediction/Normalization/Normalizer.h"
#include "Prediction/Calibrate/Calibrator.h"
namespace gezi {

	//当前只是考虑 二分类模型
	//@TODO 多分类模型支持 重载 Fvec 或者Predict返回Fvec ?, Regression Rank等模型的支持
	//@TODO TLC c#的那种接口的设计 能够迁移到c++吗
	//var stronglyTypedPredictor = predictor as IPredictor<Instance, float>;
	class Predictor : public LoadSave
	{
	public:
		Predictor() = default;
		virtual ~Predictor() {}
		Predictor(NormalizerPtr normalizer, CalibratorPtr calibrator, const svec& featureNames)
			:_normalizer(normalizer), _calibrator(calibrator), _featureNames(featureNames)
		{

		}

		Predictor(NormalizerPtr normalizer, CalibratorPtr calibrator, svec&& featureNames)
			:_normalizer(normalizer), _calibrator(calibrator), _featureNames(featureNames)
		{

		}

		virtual string Name() override
		{
			return "Predictor";
		}

		string Path()
		{
			return _path;
		}

		void SetParam(string param)
		{
			_param = param;
		}

		string GetParam()
		{
			return _param;
		}

		//输出未经Calibrator矫正的数值 -n,+n 0表示分界 越高越倾向positive
		Float Output(Instance& instance)
		{
			return Output(instance.features);
		}
		Float Output(InstancePtr instance)
		{
			return Output(instance->features);
		}

		Float Output(Vector& features)
		{
			if (_normalizer != nullptr && !features.normalized)
			{
				if (!_normalizeCopy)
				{
					_normalizer->Normalize(features);
					return Margin(features);
				}
				else
				{
					Vector temp = _normalizer->NormalizeCopy(features);
					return Margin(temp);
				}
			}
			else
			{
				return Margin(features);
			}
		}


		Float Output(Fvec& values)
		{
			Vector features(values);
			return Output(features);
		}

		Float Output(ivec& indices, Fvec& values)
		{
			Vector features(indices, values);
			return Output(features);
		}

		//输出经Calibrator矫正的数值 [0,1], 输出值表示结果倾向positive的概率
		Float Predict(Instance& instance)
		{
			return Predict(instance.features);
		}

		Float Predict(Fvec& values)
		{
			Vector features(values);
			return Predict(features);
		}

		Float Predict(ivec& indices, Fvec& values)
		{
			Vector features(indices, values);
			return Predict(features);
		}

		Float Predict(InstancePtr instance)
		{
			return Predict(instance->features);
		}

		Float Predict(Vector& features)
		{
			return Predict(Output(features));
		}

		Float Predict(Instance& instance, Float& output)
		{
			return Predict(instance.features, output);
		}

		Float Predict(InstancePtr instance, Float& output)
		{
			return Predict(instance->features, output);
		}

		Float Predict(Vector& features, Float& output)
		{
			output = Output(features);
			return Predict(output);
		}

		Float Predict(Fvec& values, Float& output)
		{
			Vector features(values);
			return Predict(features, output);
		}

		Float Predict(ivec& indices, Fvec& values, Float& output)
		{
			Vector features(indices, values);
			return Predict(features, output);
		}

		Float Predict(Float output)
		{
			if (_calibrator != nullptr)
			{
				return _calibrator->PredictProbability(output);
			}
			else
			{
				return 1.0 / (1.0 + exp(-output));
			}
		}

		void SetNormalizeCopy(bool normalizeCopy = true)
		{
			_normalizeCopy = normalizeCopy;
		}

		virtual void Save(string path) override
		{
			LoadSave::Save(path);
			_path = path;
			try_create_dir(path);
			write_file(Name(), path + "/model.name.txt");
			write_file(_param, path + "/model.param.txt");
			SAVE_SHARED_PTR(_normalizer);
			SAVE_SHARED_PTR(_calibrator);
		}

		virtual void Load(string path) override
		{
			_path = path;
			_param = read_file(OBJ_NAME_PATH(_param));
			LoadSave::Load(path);
			string normalizerName = read_file(OBJ_NAME_PATH(_normalizer));
			if (!normalizerName.empty())
			{
				_normalizer = NormalizerFactory::CreateNormalizer(normalizerName, OBJ_PATH(_normalizer));
			}
			string calibratorName = read_file(OBJ_NAME_PATH(_calibrator));
			if (!calibratorName.empty())
			{
				_calibrator = CalibratorFactory::CreateCalibrator(calibratorName, OBJ_PATH(_calibrator));
			}
		}

		virtual void SaveText(string file) override
		{
			LoadSave::SaveText(file);
		}

		void SaveText()
		{
			SaveText(_path + "/model.txt");
			SAVE_SHARED_PTR_ASTEXT(_normalizer);
			SAVE_SHARED_PTR_ASTEXT(_calibrator);
		}

		NormalizerPtr GetNormalizer()
		{
			return _normalizer;
		}

		CalibratorPtr GetCalibrator()
		{
			return _calibrator;
		}

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			ar & _featureNames;
		}

	protected:
		virtual Float Margin(Vector& features)
		{
			return 0;
		}


	protected:
		bool _normalizeCopy = false;
		NormalizerPtr _normalizer = nullptr;
		CalibratorPtr _calibrator = nullptr;

		svec _featureNames;

		string _path;
		string _param;
	};
	typedef shared_ptr<Predictor> PredictorPtr;
	typedef vector<PredictorPtr> Predictors;
}  //----end of namespace gezi

#endif  //----end of M_L_CORE__PREDICTOR_H_
