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

	enum class PredictionKind
	{
		Unknown = 0,
		Custom = 1,
		BinaryClassification = 2,
		MultiClassClassification = 3,
		Regression = 4,
		MultiOutputRegression = 5,
		Ranking = 6,
		Recommendation = 7,
		// More to be added later.
		// When adding values, also add to PredictionKindMask.
	};

	//当前只是考虑 二分类模型
	//@TODO 多分类模型支持 重载 Fvec 或者Predict返回Fvec ?, Regression Rank等模型的支持
	//@TODO TLC c#的那种接口的设计 能够迁移到c++吗 c#的关键有一个  object Predict(object features);   public interface IPredictor<in TFeatures, out TResult> : IPredictor
	//TResult Predict(TFeatures features);
	//var stronglyTypedPredictor = predictor as IPredictor<Instance, float>;
	//dvec Predicts(const Vector&) 
	//double Predict(const Vector&, dvec&)
	class Predictor : public LoadSave
	{
	public:
		Predictor() = default;
		virtual ~Predictor() {}
		Predictor(NormalizerPtr normalizer, CalibratorPtr calibrator, const FeatureNamesVector& featureNames)
			:_normalizer(normalizer), _calibrator(calibrator), _featureNames(featureNames)
		{
		}

		virtual PredictionKind GetPredictionKind()
		{
			return PredictionKind::BinaryClassification;
		}

		virtual string Name() override
		{
			return "Predictor";
		}

		Predictor& SetPath(string path)
		{
			_path = path;
			return *this;
		}

		string Path()
		{
			return _path;
		}

		Predictor& SetParam(string param)
		{
			_param = param;
			return *this;
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
		
		//在Melt.h 统一使用虚函数接口  输入是 InstancePtr
		virtual Float Output(InstancePtr instance)
		{
			return Output(instance->features);
		}

		void Print(const Vector& features, std::ostream& ofs = std::cout)
		{
			features.ForEachNonZero([this, &ofs](int index, Float value)
			{
				ofs << index << "\t" << _featureNames[index] << "\t" << value << std::endl;
			});
		}

		map<string, Float> ToNamedFeatures(const Vector& features)
		{
			map<string, Float> namedFeatures;
			features.ForEachNonZero([this, &namedFeatures](int index, Float value)
			{
				namedFeatures[_featureNames[index]] = value;
			});
			return namedFeatures;
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

		virtual Float Predict(InstancePtr instance)
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

		virtual Float Predict(InstancePtr instance, Float& output)
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

		Float Predict(const map<int, double>& m)
		{
			Vector features(m);
			return Predict(features);
		}

		Float Predict(const map<int, double>& m, Float& output)
		{
			Vector features(m);
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

		Predictor& SetNormalizeCopy(bool normalizeCopy = true)
		{
			_normalizeCopy = normalizeCopy;
			return *this;
		}

		virtual void Save()
		{
			Save(_path);
		}

		virtual void Save(string path) override
		{
			LoadSave::Save(path);
			_path = path;
			try_create_dir(path);
			string modelFile = path + "/model.bin";
			Save_(modelFile);
			write_file(Name(), path + "/model.name.txt");
			write_file(_param, path + "/model.param.txt");
			SAVE_SHARED_PTR(_normalizer, path);
			SAVE_SHARED_PTR(_calibrator, path);
		}

		virtual void Save_(string file)
		{
			LOG(WARNING) << Name() << " currently not support saving model";
		}

		void LoadNormalizerAndCalibrator(string path)
		{
			if (loadNormalizerAndCalibrator())
			{
				//#ifdef NO_CEREAL
				string normalizerName = read_file(OBJ_NAME_PATH(_normalizer, path));
				if (!normalizerName.empty())
				{ //@TODO 理论上有了cereal序列化多态shared ptr机制 不再需要单独的通过路径载入这个函数
					_normalizer = NormalizerFactory::CreateNormalizer(normalizerName, OBJ_PATH(_normalizer, path));
				}
				string calibratorName = read_file(OBJ_NAME_PATH(_calibrator, path));
				if (!calibratorName.empty())
				{
					_calibrator = CalibratorFactory::CreateCalibrator(calibratorName, OBJ_PATH(_calibrator, path));
				}
				//#else 
				//			serialize_util::Load(_normalizer, OBJ_PATH(_normalizer, path));
				//			serialize_util::Load(_calibrator, OBJ_PATH(_calibrator, path));
				//#endif
			}
		}

		virtual void Load(string path) override
		{
			_path = path;
			_param = read_file(OBJ_NAME_PATH(_param, path));
			LoadSave::Load(path);
			string modelFile = path + "/model.bin";
			Load_(modelFile);
			LoadNormalizerAndCalibrator(path);
		}

		virtual void Load_(string file)
		{
			LOG(FATAL) << Name() << " currently not support loading model";
		}

		//注意不管是save xml还是save text 都不要单独使用 并且 都在Save 也就是存储二进制之后使用
		//xml和text都提供载入 目前 都是按照二进制载入 如果是其它的开源输出比如linear model格式可以先转LinearPredictor然后
		//Save 
		virtual void SaveXml(string file) override
		{
			LoadSave::SaveXml(file);
			SaveXml_(file);
			SaveXml_NormalizerAndCalibrator(_saveNormalizerText, _saveCalibratorText);
		}

		virtual void SaveXml_(string file)
		{
			LOG(WARNING) << Name() << " currently not support saving xml";
		}

		virtual void SaveJson(string file) override
		{
			LoadSave::SaveJson(file);
			SaveJson_(file);
			SaveJson_NormalizerAndCalibrator(_saveNormalizerText, _saveCalibratorText);
		}

		virtual void SaveJson_(string file)
		{
			LOG(WARNING) << Name() << " currently not support saving json";
		}

		virtual void SaveText(string file) override
		{
			LoadSave::SaveText(file);
			SaveText_(file);
			SaveText_NormalizerAndCalibrator(_saveNormalizerText, _saveCalibratorText);
		}

		virtual void SaveText_(string file)
		{
			LOG(WARNING) << Name() << " currently not support saving text format! Try SaveJson or SaveXml";
		}

		void SaveXml()
		{
			SaveXml(_path + "/model.xml");
		}

		void SaveJson()
		{
			SaveJson(_path + "/model.json");
		}

		void SaveText()
		{
			SaveText(_path + "/model.txt");
		}

		virtual void LoadText_(string file)
		{
			LOG(FATAL) << Name() << " currently not support loading text format!";
		}

		virtual void LoadText(string path) override
		{
			_path = path;
			_param = read_file(OBJ_NAME_PATH(_param, _path));
			LoadSave::LoadText(path);
			string modelFile = path + "/model.txt";
			LoadText_(modelFile);
			LoadNormalizerAndCalibrator(path);
		}

		NormalizerPtr& GetNormalizer()
		{
			return _normalizer;
		}

		CalibratorPtr& GetCalibrator()
		{
			return _calibrator;
		}

		Predictor& SetSaveNormalizerText(bool setSave = true)
		{
			_saveNormalizerText = setSave;
			return *this;
		}

		Predictor& SetSaveCalibratorText(bool setSave = true)
		{
			_saveCalibratorText = setSave;
			return *this;
		}

		static string ThirdModelName(string file)
		{
			return boost::replace_last_copy(file, ".bin", ".extra");
		}

		static bool& loadNormalizerAndCalibrator()
		{
			static bool _loadNormalizerAndCalibrator = true;
			return _loadNormalizerAndCalibrator;
		}

		friend class cereal::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			auto& numFeatures = _featureNames._numFeatures;
			ar & CEREAL_NVP(numFeatures);
			auto& featureNames = *_featureNames._featureNames;
			ar & CEREAL_NVP(featureNames);
			//ar & CEREAL_NVP(_featureNames);
		}

	protected:
		virtual Float Margin(Vector& features)
		{
			return 0;
		}

	private:
		void SaveText_NormalizerAndCalibrator(bool saveNormalizer = true, bool saveCalibrator = true)
		{
			if (saveNormalizer)
			{
				SAVE_SHARED_PTR_ASTEXT(_normalizer, _path);
			}
			if (saveCalibrator)
			{
				SAVE_SHARED_PTR_ASTEXT(_calibrator, _path);
			}
		}

		void SaveXml_NormalizerAndCalibrator(bool saveNormalizer = true, bool saveCalibrator = true)
		{
			if (saveNormalizer)
			{
				SAVE_SHARED_PTR_ASXML(_normalizer, _path);
			}
			if (saveCalibrator)
			{
				SAVE_SHARED_PTR_ASXML(_calibrator, _path);
			}
		}

		void SaveJson_NormalizerAndCalibrator(bool saveNormalizer = true, bool saveCalibrator = true)
		{
			if (saveNormalizer)
			{
				SAVE_SHARED_PTR_ASJSON(_normalizer, _path);
			}
			if (saveCalibrator)
			{
				SAVE_SHARED_PTR_ASJSON(_calibrator, _path);
			}
		}

	protected:
		bool _normalizeCopy = false;
		NormalizerPtr _normalizer = nullptr;
		CalibratorPtr _calibrator = nullptr;

		//svec _featureNames;
		FeatureNamesVector _featureNames;

		string _path;
		string _param;

	private:
		bool _saveNormalizerText = false; //是否输出文本格式 包括xml,json统一使用
		bool _saveCalibratorText = false;
	};

	typedef shared_ptr<Predictor> PredictorPtr;
	typedef vector<PredictorPtr> Predictors;
}  //----end of namespace gezi

#endif  //----end of M_L_CORE__PREDICTOR_H_
