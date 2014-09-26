/**
 *  ==============================================================================
 *
 *          \file   PLSAModel.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-08-05 17:04:00.599864
 *
 *  \Description:
 p(zk|w, d) = p(zk|d)p(w|zk)
 PK
 k0=1 p(zk0 |d)p(w|zk0 )

 p(zk|di) =
 P
 w
 c(w, di)p(zk|di
 , w)
 P
 w
 c(w, di)
 k = 1..K, di ∈ C
 p(wj|zk) =
 P
 d
 c(wj, d)p(zk|d, wj)
 P
 d
 P
 w
 c(w, d)p(zk|d, w)
 k = 1..K, wj ∈ V

 http://luxinxin.is-programmer.com/user_files/luxinxin/File/plsanote.pdf
 *  ==============================================================================
 */

#ifndef P_L_S_A_MODEL_H_
#define P_L_S_A_MODEL_H_
#include "common_util.h"
#include "Matrix.h"
namespace gezi {
	namespace plsa {

		class PLSAModel
		{
		public:
		
			PLSAModel()
			{

			}
			PLSAModel(string file)
			{
				Load(file);
			}

			void Load(string file)
			{
				serialize_util::load(_pzw, file);
				NumTopics = _pzw.rows();
				Pval(NumTopics);
			}

			//@TODO 算法改为使用iterator模式的 这样map输入不需要转换
			//template<typename Iter>
			//vector<Float> Inference(Iter begin, Iter end, int numIters = 20)
			//{
			//	Fvec pdz(NumTopics, 1.0 / NumTopics); //P(z|d)

			//	int numUniqeWords = std::distance(begin, end);
			//	Float numWords = 0;
			//	for (int iter = 0; iter < numUniqeWords; iter++)
			//	{
			//		numWords += (begin + iter)->second;
			//	}
			//	if (!numWords)
			//	{
			//		return pdz;
			//	}

			//	//--------------------------init
			//	//Float sum = 0;
			//	ufo::Matrix<Float> pwz(numUniqeWords, NumTopics, 0);

			//	//--------------------------infer
			//	for (int iter = 0; iter < numIters; iter++)
			//	{
			//		//-----e-step calc pwz// p(z|w,d)
			//		//for (int i = 0; i < numUniqeWords; i++) //word
			//		for (Iter it = begin, i = 0; it != end; ++it, i++)
			//		{
			//			int wordId = it->first;
			//			//p(w,d)
			//			Float pwd = 0;

			//			for (int topicId = 0; topicId < NumTopics; topicId++)
			//			{
			//				pwd += pdz[topicId] * _pzw(topicId, wordId);
			//			}

			//			for (int topicId = 0; topicId < NumTopics; topicId++) //z topic
			//			{
			//				if (pwd)
			//					pwz(i, topicId) = (pdz[topicId] * _pzw(topicId, wordId)) / pwd;
			//			}
			//		}

			//		vector<Float> tdz;
			//		tdz.resize(NumTopics, 0);
			//		for (int i = 0; i < numUniqeWords; i++)
			//		{
			//			Iter now = begin + i;
			//			int wordId = now->first;
			//			Float weight = now->second;

			//			for (int topicId = 0; topicId < NumTopics; topicId++)
			//			{
			//				tdz[topicId] += weight * pwz(i, topicId);
			//			}
			//		}

			//		for (int topicId = 0; topicId < NumTopics; topicId++)
			//		{
			//			pdz[topicId] = tdz[topicId] / numWords; //FIXME nword == 0?
			//		}
			//	}

			//	return pdz;
			//}

			/*template<typename Container>
			vector<Float> Inference(const Container& contents, int numIters = 20)
			{
				return Inference(contents.begin(), contents.end(), numIters);
			}*/

			template<typename Key, typename Value>
			vector<Float> Inference(const map<Key, Value>& contents, int numIters = 20)
			{
				/*vector<pair<Key, Value> > vec = from(contents) >> to_vector();*/ //std::pair<const int, double>  可恶的const

				auto vec = from(contents) >> to_vector();
				return Inference(vec);
			}
			/**
			* 在线推理fold_in，这里输入的p(z|w)是压缩截断的倒排，比如每个word只保留top 20的topic加快计算速度
			* @param content_vec
			* @param pdz
			* @param round
			*/
			template<typename T>
			vector<Float> Inference(const std::vector<T>& contents, int numIters = 20)
			{
				Fvec pdz(NumTopics, 1.0 / NumTopics); //P(z|d)

				int numUniqeWords = contents.size();
				Float numWords = 0;
				for (int iter = 0; iter < numUniqeWords; iter++)
				{
					numWords += contents[iter].second;
				}
				if (!numWords)
				{
					return pdz;
				}

				//--------------------------init
				//Float sum = 0;
				ufo::Matrix<Float> pwz(numUniqeWords, NumTopics, 0);

				//--------------------------infer
				for (int iter = 0; iter < numIters; iter++)
				{
					//-----e-step calc pwz// p(z|w,d)
					for (int i = 0; i < numUniqeWords; i++) //word
					{
						int wordId = contents[i].first;
						//p(w,d)
						Float pwd = 0;

						for (int topicId = 0; topicId < NumTopics; topicId++)
						{
							pwd += pdz[topicId] * _pzw(topicId, wordId);
						}
					
						for (int topicId = 0; topicId < NumTopics; topicId++) //z topic
						{
							if (pwd)
								pwz(i, topicId) = (pdz[topicId] * _pzw(topicId, wordId)) / pwd;
						}
					}

					vector<Float> tdz;
					tdz.resize(NumTopics, 0);
					for (int i = 0; i < numUniqeWords; i++)
					{
						int wordId = contents[i].first;
						Float weight = contents[i].second;

						for (int topicId = 0; topicId < NumTopics; topicId++)
						{
							tdz[topicId] += weight * pwz(i, topicId);
						}
					}

					for (int topicId = 0; topicId < NumTopics; topicId++)
					{
						pdz[topicId] = tdz[topicId] / numWords; //FIXME nword == 0?
					}
				}

				return pdz;
			}

		public:
			int NumTopics;
		protected:
		private:
			ufo::Matrix<Float> _pzw; //p(w|z)
		};
	} //----end of namespace plsa
}  //----end of namespace gezi

#endif  //----end of P_L_S_A_MODEL_H_
