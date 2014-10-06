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
			:_normalizer(normalizer), _calibrator(calibrator), _featureNames(featureNames),
			_numFeatures(_featureNames.size())
		{

		}

		Predictor(NormalizerPtr normalizer, CalibratorPtr calibrator, svec&& featureNames)
			:_normalizer(normalizer), _calibrator(calibrator), _featureNames(featureNames),
			_numFeatures(_featureNames.size())
		{

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
		Float Output(InstancePtr instance)
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
			ChangeForSave();
			LoadSave::Save(path);
			_path = path;
			try_create_dir(path);
			string modelFile = path + "/model.bin";
			Save_(modelFile);
			write_file(Name(), path + "/model.name.txt");
			write_file(_param, path + "/model.param.txt");
			SAVE_SHARED_PTR(_normalizer, path);
			SAVE_SHARED_PTR(_calibrator, path);
			ChangeForLoad();
		}

		virtual void Save_(string file)
		{
			VLOG(0) << Name() << " currently not support saving model";
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
			ChangeForLoad();
			LoadNormalizerAndCalibrator(path);
		}

		virtual void Load_(string file)
		{
			VLOG(0) << Name() << " currently not support loading model";
		}

		//注意不管是save xml还是save text 都不要单独使用 并且 都在Save 也就是存储二进制之后使用
		//xml和text都提供载入 目前 都是按照二进制载入 如果是其它的开源输出比如linear model格式可以先转LinearPredictor然后
		//Save 
		virtual void SaveXml(string file) override
		{
			ChangeForSave();
			LoadSave::SaveXml(file);
			SaveXml_(file);
			ChangeForLoad();
			SaveXml_NormalizerAndCalibrator(_saveNormalizerText, _saveCalibratorText);
		}

		virtual void SaveXml_(string file)
		{
			VLOG(0) << Name() << " currently not support saving xml";
		}

		virtual void SaveJson(string file) override
		{
			ChangeForSave();
			LoadSave::SaveJson(file);
			SaveJson_(file);
			ChangeForLoad();
			SaveJson_NormalizerAndCalibrator(_saveNormalizerText, _saveCalibratorText);
		}

		virtual void SaveJson_(string file)
		{
			VLOG(0) << Name() << " currently not support saving json";
		}

		virtual void SaveText(string file) override
		{
			LoadSave::SaveText(file);
			SaveText_(file);
			SaveText_NormalizerAndCalibrator(_saveNormalizerText, _saveCalibratorText);
		}

		virtual void SaveText_(string file)
		{
			VLOG(0) << Name() << " currently not support saving text format! Try SaveJson or SaveXml";
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
			VLOG(0) << Name() << " currently not support loading text format!";
		}

		virtual void LoadText(string path) override
		{
			ChangeForLoad();
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

		Predictor& SetNumFeatures(int numFeatures)
		{
			_numFeatures = numFeatures;
			return *this;
		}

		int GetNumFeatures()
		{
			return _numFeatures;
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

		static bool& loadNormalizerAndCalibrator()
		{
			static bool _loadNormalizerAndCalibrator = true;
			return _loadNormalizerAndCalibrator;
		}


		friend class cereal::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			ar & CEREAL_NVP(_numFeatures);
			//@TODO 这个加入名字无意义特征数目巨大 是一个时空浪费
			//由子类决定是否打印输出名字？ 或者特殊处理f0 f1这种不进行输出时候的序列化 输入时候序列化自动恢复成f0,f1的样子
			ar & CEREAL_NVP(_featureNames);
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

		void ChangeForSave()
		{
			CHECK_GT(_featureNames.size(), 0);
			if (_numFeatures > 1000 && _featureNames[0] == "f0" && _featureNames[999] == "f999")
			{
				_tempFeatureNames.swap(_featureNames);
			}
		}
	protected:
		void ChangeForLoad()
		{
			if (_featureNames.empty())
			{
				if (_tempFeatureNames.empty())
				{
					CreateFakeFeatureNames();
				}
				else
				{
					_featureNames.swap(_tempFeatureNames);
				}
			}
		}

		void CreateFakeFeatureNames()
		{
			for (int i = 0; i < _numFeatures; i++)
			{
				_featureNames.push_back("f" + STR(i));
			}
		}

	protected:
		bool _normalizeCopy = false;
		NormalizerPtr _normalizer = nullptr;
		CalibratorPtr _calibrator = nullptr;

		svec _featureNames;
		svec _tempFeatureNames;
		int _numFeatures = 0; //@TODO maybe uint int64 .. 暂时只处理int范围内的特征 文本分类会不会超过。。

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
