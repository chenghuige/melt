/**
 *  ==============================================================================
 *
 *          \file   Prediction/Normalization/AffineNormalizer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-04-01 17:07:57.638996
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef PREDICTION__NORMALIZATION__AFFINE_NORMALIZER_H_
#define PREDICTION__NORMALIZATION__AFFINE_NORMALIZER_H_
#include "Prediction/Normalization/Normalizer.h"
namespace gezi {

	class AffineNormalizer : public Normalizer
	{
	public:
		AffineNormalizer()
		{
			_func = [this](int index, Float& value)
			{
				if (_scales[index] <= 0)
				{//保持不变 Dense Sparse 保持逻辑一致 如果置为0 
					//需要AffineInit函数中shiftIndices增加scale <=0 且offset!=0的点
					//value = 0;
					return;
				}
				else if (_trunct)
				{
					if (value >= _offsets[index] + _scales[index])
						value = 1.0;
					else if (value <= _offsets[index])
						value = 0.0;
					else
						value = (value - _offsets[index]) / _scales[index];
				}
				else
				{
					value = (value - _offsets[index]) / _scales[index];
				}
			};
		}

		virtual void Load(string infile) override
		{
			svec lines = read_lines(infile);
			CHECK_GT(lines.size(), 0) << infile;
			int i = 0;
			CHECK_EQ(parse_string_param("NormalizerType=", lines[i++]), Name());
			_trunct = parse_bool_param("Trunct=", lines[i++]);
			_featureNum = parse_int_param("FeatureNum=", lines[i++]);
			_offsets.resize(_featureNum);
			_scales.resize(_featureNum);
			for (int j = 0; j < _featureNum; j++)
			{
				string offset, scale;
				split(lines[i], '\t', offset, scale);
				_offsets[j] = DOUBLE_PARSE(offset);
				_scales[j] = INT_PARSE(scale);
			}
			AffineInit();
		}

		virtual void Save(string outfile) override
		{
			ofstream ofs(outfile);
			ofs << "NormalizerType=" << Name() << endl;
			ofs << "Trunct=" << (int)_trunct << endl;
			ofs << "FeatureNum=" << _featureNum << endl;
			for (int i = 0; i < _featureNum; i++)
			{
				ofs << _offsets[i] << "\t" << _scales[i] << endl;
			}
		}

		virtual void Begin() override
		{
			_offsets.resize(_featureNum, 0);
			_scales.resize(_featureNum, 0);
		}

		virtual void Finalize() override
		{

		}

		void AffineInit()
		{
			for (int i = 0; i < _featureNum; i++)
			{
				if (_scales[i] <= 0)
				{ //按照TLC 如果是始终值一样 仍然维持原样 不scale 不置为0 @TODO
					//无效特征 始终是6的比如 还是6 不变成0 @TODO 需要置为0？
					VLOG(4) << "Feature " << i << " : " << _featureNames[i]
						<< " always take value " << _offsets[i];
				}
				else if (_offsets[i] != 0.0)
				{ //如果最小值是0 那么 所有的点都只需要morph不需要shift，同时如果是0值点 不需要变化,dense 使用morphIndices, sparse使用shiftIdices 就是求并集 非0 union 需要moph的0值点
					_shiftIndices.push_back(i);
					_morphIndices.push_back(i);
				}
				else if (_scales[i] != 1.0)
				{
					_morphIndices.push_back(i);
				} //like [0,1] 这样的所有点都不需要变化
				else if (_trunct)
				{ //如果要截断即使[0,1]也需要scale可能， 注意只可能会是在线部分用trunct 离线test部分？@TODO only test trunct ?
					_morphIndices.push_back(i);
				}
			}

			PVEC(_offsets);
			PVEC(_scales);
			PVEC(_morphIndices);
			PVEC(_shiftIndices);
		}

		virtual void NormalizeCore(Vector& vec) override
		{
			Normalize(vec, _func);
		}

	protected:
		Fvec _offsets;
		Fvec _scales;
	private:
		std::function<void(int, Float&)> _func;
	};

}  //----end of namespace gezi

#endif  //----end of PREDICTION__NORMALIZATION__AFFINE_NORMALIZER_H_
