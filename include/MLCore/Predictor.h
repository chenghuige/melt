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
	class Predictor
	{
	public:
		Predictor() = default;
		virtual ~Predictor() {}
		Predictor(NormalizerPtr normalizer, CalibratorPtr calibrator)
			:_normalizer(normalizer), _calibrator(calibrator)
		{

		}
		virtual string Name() 
		{
			return "Predictor";
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

		//输出经Calibrator矫正的数值 [0,1], 输出值表示结果倾向positive的概率
		Float Predict(Instance& instance)
		{
			return Predict(instance.features);
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

		Float Predict(Float output)
		{
			if (_calibrator != nullptr)
			{
				return _calibrator->PredictProbability(output);
			}
			else
			{
				THROW("calibrator is nullptr");
			}
		}

		void SetNormalizeCopy(bool normalizeCopy = true)
		{
			_normalizeCopy = normalizeCopy;
		}

		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
		}

		virtual void Save(string path)
		{
			VLOG(0) << "Save " << Name() << " to folder " << path;
			_path = path;
			try_create_dir(path);
			write_file(Name(), path + "/model.name.txt");
			SAVE_SHARED_PTR(_normalizer);
			SAVE_SHARED_PTR(_calibrator);
		}

		virtual void Load(string path)
		{
			VLOG(0) << Name() << " load from " << path;
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

		//SaveText是可选的 如果要使用 务必先调用Save 因为加载至使用Load
		virtual void SaveText(string file)
		{
			VLOG(0) << Name() << " save as text to " << file;
		}

		void SaveText()
		{
			SaveText(_path + "/model.txt");
			SAVE_SHARED_PTR_ASTEXT(_normalizer);
			SAVE_SHARED_PTR_ASTEXT(_calibrator);
		}

	protected:
		virtual Float Margin(const Vector& features)
		{
			return 0;
		}
	protected:
		bool _normalizeCopy = false;
		NormalizerPtr _normalizer = nullptr;
		CalibratorPtr _calibrator = nullptr;

		string _path;
	};
	typedef shared_ptr<Predictor> PredictorPtr;
}  //----end of namespace gezi

#endif  //----end of M_L_CORE__PREDICTOR_H_
