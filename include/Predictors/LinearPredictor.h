/**
 *  ==============================================================================
 *
 *          \file   Predictors/LinearPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-07 21:50:18.354006
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTORS__LINEAR_PREDICTOR_H_
#define PREDICTORS__LINEAR_PREDICTOR_H_

#include "MLCore/Predictor.h"
namespace gezi {

	class LinearPredictor : public Predictor
	{
	public:
		LinearPredictor() = default;

		//训练器中使用构造
		LinearPredictor(const Vector& weights, Float bias,
			NormalizerPtr normalizer, CalibratorPtr calibrator,
			const FeatureNamesVector& featureNames,
			string name = "")
			:Predictor(normalizer, calibrator, featureNames),
			_weights(weights), _bias(bias),
			_name(name)
		{

		}

		LinearPredictor(string path)
		{

		}

		virtual string Name() override
		{
			return _name;
		}

		virtual void Save_(string file) override
		{
			_weights.MakeSparse();
			serialize_util::save(*this, file);
		}

		virtual void SaveXml_(string file) override
		{
			_weights.MakeSparse();
			serialize_util::save_xml(*this, file);
		}

		virtual void SaveJson_(string file) override
		{
			_weights.MakeSparse();
			serialize_util::save_json(*this, file);
		}

		virtual void Load_(string file) override
		{
			serialize_util::load(*this, file);
			_weights.MakeDense();
		}

		//SaveText是可选的 如果要使用 务必先调用Save 因为加载至使用Load
		virtual void SaveText_(string file) override
		{
			ofstream ofs(file);
			ofs << "ModelName=" << Name() << endl;
			ofs << "FeatureNum=" << _weights.size() << endl;
			ofs << -1 << "\t" << "Bias" << "\t" << _bias << endl;
			_weights.ForEachNonZero([&ofs, this](int index, Float value)
			{
				ofs << index << "\t" << _featureNames[index] << "\t" << value << endl;
			});
		}

		virtual void LoadText_(string file) override
		{
			ifstream ifs(file);
			string line;
			{
				getline(ifs, line);
				_name = parse_string_param("ModelName=", line);
			}
			{
				getline(ifs, line);
				int numFeatures = parse_int_param("FeatureNum=", line);
				_weights.resize(numFeatures, 0);
				_weights.SetLength(numFeatures);
			}
			{
				getline(ifs, line);
				_bias = DOUBLE(split(line, '\t').back());
			}
			while (getline(ifs, line))
			{
				auto parts = split(line, '\t');
				_weights[INT(parts[0])] = DOUBLE(parts.back());
			}
		}

		virtual string ToFeaturesGainSummary(int topNum = 0) override
		{
			return ToFeaturesGainSummary_(_weights, topNum);
		}

		virtual void SaveFeaturesGain(int topNum = 0) override
		{
			gezi::Noticer noticer("SaveFeaturesGain", 0);
			ofstream ofs(_path + "/model.featureGain.txt");
			_weights.MakeSparse();
			int maxLen = (topNum == 0 || topNum > _weights.values.size()) ? _weights.values.size() : topNum;
			PVAL(maxLen);
			ivec indexVec = gezi::index_sort(_weights.values, [](Vector::value_type l, Vector::value_type r) { return abs(l) > abs(r); }, maxLen);
			PVEC(indexVec);
			for (int i = 0; i < maxLen; i++)
			{
				int idx = _weights.IsSparse() ? _weights.indices[indexVec[i]] : indexVec[i];
				ofs << setiosflags(ios::left) << setfill(' ') << setw(100)
					<< STR(i) + ":" + _featureNames[idx]
					<< _weights.values[indexVec[i]] << endl;
			}
		}

		friend class cereal::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
			ar & CEREAL_BASE_OBJECT_NVP(Predictor);
			ar & CEREAL_NVP(_weights);
			ar & CEREAL_NVP(_bias);
		}

	protected:
		virtual Float Margin(Vector& features) override
		{
			//Pval2(_weights.Length(), features.Length());
			return _bias + dot(_weights, features);
		}
	private:
		Vector _weights;
		Float _bias;

		string _name = "LinearPredictor";
	};

}  //----end of namespace gezi
CEREAL_REGISTER_TYPE(gezi::LinearPredictor);
#endif  //----end of PREDICTORS__LINEAR_PREDICTOR_H_
