/**
 *  ==============================================================================
 *
 *          \file   MLCore/TextPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-09-18 07:40:25.137278
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef M_L_CORE__TEXT_PREDICTOR_H_
#define M_L_CORE__TEXT_PREDICTOR_H_
#include "common_util.h"
#include "Segmentor.h"
namespace gezi {

class TextPredictor 
{
public:
	static void Prase(svec& words_, map<int, double>& m, const DoubleIdentifer& identifer, int startIndex = 0, int ngram = 3, string sep = "$#$")
	{
		svec words = get_words(words_, ngram, sep);
		get_skip_bigram(words_, words, 2, sep);
		for (string word : words)
		{
			int id = identifer.id(word);
			if (id != identifer.null_id())
			{
				m[id + startIndex] += identifer.value(id);
			}
		}
	}

	static double Predict(string title, string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
		int segType = SEG_BASIC, int ngram = 3, string sep = "$#$")
	{
		int wordNum = identifer.size();
		map<int, double> m; //确保按key排序
		Segmentor::Init();
		svec twords = Segmentor::Segment(title, segType);
		Prase(twords, m, identifer, 0);

		svec cwords = Segmentor::Segment(content, segType);
		Prase(cwords, m, identifer, wordNum);

		double score = predictor->Predict(m);
		return score;
	}

	static double Predict(string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor, 
		int segType = SEG_BASIC, int ngram = 3, string sep = "$#$")
	{
		int wordNum = identifer.size();
		map<int, double> m; //确保按key排序
		Segmentor::Init();
		svec words = Segmentor::Segment(content, segType);
		Prase(words, m, identifer, 0);

		double score = predictor->Predict(m);
		return score;
	}
};

}  //----end of namespace gezi

#endif  //----end of M_L_CORE__TEXT_PREDICTOR_H_
