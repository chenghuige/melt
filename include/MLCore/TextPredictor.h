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
		static void Prase(const svec& words_, map<int, double>& m, const DoubleIdentifer& identifer, int startIndex = 0,
			int ngram = 3, int skip = 2, string sep = "\x01")
		{
			svec words = get_words(words_, ngram, sep);
			get_skip_bigram(words_, words, skip, sep);
			for (string word : words)
			{
				int id = identifer.id(word);
				if (id != identifer.null_id())
				{
					m[id + startIndex] += identifer.value(id);
				}
			}
		}

		//same  word will be of different id in title or in content
		static double Predict(const svec& titleWords, const svec& contentWords, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
			int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			int wordNum = identifer.size();
			map<int, double> m; //确保按key排序

			Prase(titleWords, m, identifer, 0, ngram, skip, sep);

			Prase(contentWords, m, identifer, wordNum, ngram, skip, sep);

			double score = predictor->Predict(m);

#ifdef _DEBUG
			Pval(gezi::join(titleWords, "/"));
			Pval(gezi::join(contentWords, "/"));
			Vector fe(m);

			CHECK((predictor->_normalizer != nullptr));
			PVAL(fe.str());
			predictor->_normalizer->Normalize(fe);
			PVAL(fe.str());
		
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
			double output = predictor->Output(fe);
			Pval(output);
			Pval(predictor->Predict(fe));
#endif
			return score;
		}

		///Predict and output idValMap for debug
		static double Predict(const svec& titleWords, const svec& contentWords, const DoubleIdentifer& identifer, const PredictorPtr& predictor, map<int, double>& idValMap,
			int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			int wordNum = identifer.size();

			Prase(titleWords, idValMap, identifer, 0, ngram, skip, sep);

			Prase(contentWords, idValMap, identifer, wordNum, ngram, skip, sep);

			double score = predictor->Predict(idValMap);

			return score;
		}

		static double Predict(const svec& words, const DoubleIdentifer& identifer, const PredictorPtr& predictor, map<int, double>& idValMap,
			int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			int wordNum = identifer.size();

			Prase(words, idValMap, identifer, 0, ngram, skip, sep);

			double score = predictor->Predict(idValMap);

			return score;
		}

		
		static double Predict(const svec& words, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
			int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			int wordNum = identifer.size();
			map<int, double> m; //确保按key排序
			PVAL(gezi::join(words, "/"));
			Prase(words, m, identifer, 0, ngram, skip, sep);

			double score = predictor->Predict(m);
#ifdef _DEBUG
			Pval(gezi::join(words, "/"));
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
			int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			Segmentor::Init(); //最好还是外部Init好 这里为了安全仍然保有

			svec titleWords = Segmentor::Segment(title, segType);
			svec contentWords = Segmentor::Segment(content, segType);
			return Predict(titleWords, contentWords, identifer, predictor, 
				segType, ngram, skip, sep);
		}

		static double Predict(string title, string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor, map<int, double>& idValMap,
			int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			Segmentor::Init(); //最好还是外部Init好 这里为了安全仍然保有

			svec titleWords = Segmentor::Segment(title, segType);
			svec contentWords = Segmentor::Segment(content, segType);
			return Predict(titleWords, contentWords, identifer, predictor, idValMap,
				segType, ngram, skip, sep);
		}

		static double Predict(string content, const DoubleIdentifer& identifer, const PredictorPtr& predictor,
			int segType = SEG_BASIC, int ngram = 3, int skip = 2, string sep = "\x01")
		{
			Segmentor::Init();
			svec words = Segmentor::Segment(content, segType);
			return Predict(words, identifer, predictor, segType, ngram, skip, sep);
		}
#endif // !NO_BAIDU_DEP
	};


}  //----end of namespace gezi

#endif  //----end of M_L_CORE__TEXT_PREDICTOR_H_
