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
#include "Identifer.h"
#include "tools/content_process.h"
#ifdef _DEBUG
#include "Predictors/LinearPredictor.h"
#include "feature/Features.h"
#endif
#include "Predictor.h"

namespace gezi {

	class TextPredictor
	{
	public:
		static void Prase(svec& words_, map<int, double>& m, const DoubleIdentifer& identifer, int startIndex = 0,
			int ngram = 3, int skip = 2, string sep = "\x01", bool hasPic = false, bool hasUrl = false, bool hasAt = false)
		{
			svec words = get_words(words_, ngram, sep);
			get_skip_bigram(words_, words, skip, sep);
			for (string word : words)
			{
				int id = identifer.id(word);
				if (id != identifer.null_id())
				{
					m[id + startIndex] += identifer.value(id);
					if (hasPic)
					{
						id = identifer.id(format("{}{}{}", word, sep, "<pic>"));
						if (id != identifer.null_id())
						{
							m[id + startIndex] += identifer.value(id);
						}
					}
					if (hasUrl)
					{
						id = identifer.id(format("{}{}{}", word, sep, "<url>"));
						if (id != identifer.null_id())
						{
							m[id + startIndex] += identifer.value(id);
						}
					}
					if (hasAt)
					{
						id = identifer.id(format("{}{}{}", word, sep, "<at>"));
						if (id != identifer.null_id())
						{
							m[id + startIndex] += identifer.value(id);
						}
					}
				}
			}
		}

		static double Predict(const svec& titleWords, const svec& contentWords, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
			int segType = SEG_BASIC, bool useMedia = false, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			int wordNum = identifer.size();
			map<int, double> m; //确保按key排序

			bool hasPic = false, hasUrl = false, hasAt = false;
			if (useMedia)
			{
				hasPic = gezi::contains_pic(content);
				hasUrl = gezi::contains_url(content);
				hasAt = gezi::contains_at(content);
			}
			Prase(titleWords, m, identifer, 0, ngram, skip, sep, hasPic, hasUrl, hasAt);

			Prase(contentWords, m, identifer, wordNum, ngram, skip, sep, hasPic, hasUrl, hasAt);

			double score = predictor->Predict(m);

#ifdef _DEBUG
			Pval(gezi::join(twords, "$#$"));
			Pval(gezi::join(cwords, "$#$"));
			Vector fe(m);
			PVAL(fe.str());
			predictor->_normalizer->Normalize(fe);
			Vector& weights = dynamic_pointer_cast<LinearPredictor>(predictor)->_weights;
			double total = 0;
			vector<pair<string, double> > sortedByGain;
			map<string, double> m_;
			fe.ForEach([&](int index, double value)
			{
				if (weights[index] != 0)
				{
					string key = index < identifer.size() ? "t:" + identifer.key(index) : "c:" + identifer.key(index - identifer.size());
					m_[format("{}\t{}\t{}\t{}", index, key, value, weights[index])] = value * weights[index];
					//Pval5(index, key, value, weights[index], (value * weights[index]));
					total += value * weights[index];
				}
			});
			sort_map_by_absvalue_reverse(m_, sortedByGain);
			for (auto item : sortedByGain)
			{
				LOG(INFO) << item.first << "\t" << item.second;
			}
			total += dynamic_pointer_cast<LinearPredictor>(predictor)->_bias;
			Pval(total);
#endif
			return score;
		}
		
		static double Predict(const svec& words, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
			int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			int wordNum = identifer.size();
			map<int, double> m; //确保按key排序
			PVAL(gezi::join(words, "$#$"));
			Prase(words, m, identifer, 0, ngram, skip, sep);

			double score = predictor->Predict(m);
#ifdef _DEBUG
			Pval(gezi::join(words, "$#$"));
			Vector fe(m);
			PVAL(fe.str());
			predictor->_normalizer->Normalize(fe);
			Vector& weights = dynamic_pointer_cast<LinearPredictor>(predictor)->_weights;
			double total = 0;
			vector<pair<string, double> > sortedByGain;
			map<string, double> m_;
			fe.ForEach([&](int index, double value)
			{
				if (weights[index] != 0)
				{
					string key = index < identifer.size() ? "t:" + identifer.key(index) : "c:" + identifer.key(index - identifer.size());
					m_[format("{}\t{}\t{}\t{}", index, key, value, weights[index])] = value * weights[index];
					//Pval5(index, key, value, weights[index], (value * weights[index]));
					total += value * weights[index];
				}
			});
			sort_map_by_absvalue_reverse(m_, sortedByGain);
			for (auto item : sortedByGain)
			{
				LOG(INFO) << item.first << "\t" << item.second;
			}
			total += dynamic_pointer_cast<LinearPredictor>(predictor)->_bias;
			Pval3(total, predictor->Output(m), predictor->Predict(m));
#endif
			return score;
		}
#ifndef NO_BAIDU_DEP

		static double Predict(string title, string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
			int segType = SEG_BASIC, bool useMedia = false, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			Segmentor::Init(); //最好还是外部Init好 这里为了安全仍然保有

			svec titleWords = Segmentor::Segment(title, segType);
			svec contentWords = Segmentor::Segment(content, segType);
			return Predict(titleWords, contentWords, identifer, predictor, 
				segType, useMedia, ngram, skip, sep);
		}

		static double Predict(string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
			int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			map<int, double> m; //确保按key排序
			Segmentor::Init();
			svec words = Segmentor::Segment(content, segType);
			return Predict(words, identifer, predictor, segType, ngram, skip, sep);
		}
#endif // !NO_BAIDU_DEP
	};


}  //----end of namespace gezi

#endif  //----end of M_L_CORE__TEXT_PREDICTOR_H_
