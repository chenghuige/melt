/**
 *  ==============================================================================
 *
 *          \file   PLSATrainer.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-08-09 21:48:13.537936
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef P_L_S_A_TRAINER_H_
#define P_L_S_A_TRAINER_H_

#include "Matrix.h"
namespace gezi {
	namespace plsa {
		struct DocInfo
		{
			int numWords = 0;
			vector<pair<int, Float> > content;
		};

		typedef vector<pair<int, Float> > ContentVec;
		class PLSATrainer
		{
		public:
			PLSATrainer(int numTopics, int numWords)
				:NumTopics(numTopics), NumWords(numWords)
			{

			}

			void Initialize()
			{
				Pval3(NumWords, NumDocs, NumTopics);
				_pdz.resize(NumDocs, NumWords, 0);
				_pzw.resize(NumTopics, NumWords, 0);
				for (int docId = 0; docId < NumDocs; docId++)
				{
					Float sum = 0.0;
					for (int topicId = 0; topicId < NumTopics; topicId++)
					{
						_pdz(docId, topicId) = drand48() * drand48();
						sum += _pdz(docId, topicId);
					}
					for (int topicId = 0; topicId < NumTopics; topicId++)
					{
						_pdz(docId, topicId) /= sum;
					}
				}
				for (int topicId = 0; topicId < NumTopics; topicId++)
				{
					Float sum = 0.0;
					for (int wordId = 0; wordId < NumWords; wordId++)
					{
						_pzw(topicId, wordId) = drand48() * drand48();
						sum += _pzw(topicId, wordId);
					}
					for (int wordId = 0; wordId < NumWords; wordId++)
					{
						_pzw(topicId, wordId) /= sum;
					}
				}
				_pzwTemp.resize(NumTopics, NumWords, 0);
				_pzVec.resize(NumTopics, 0);
				_pwz.resize(NumWords, NumTopics, 0);
			}

			void Train(const vector<DocInfo>& docs, int iterNum = 20)
			{
				NumDocs = docs.size();
				Initialize();

				ProgressBar pb(iterNum);
				for (int iter = 0; iter < iterNum; iter++)
				{
					++pb;
					_pzwTemp.zeroset();
					gezi::zeroset(_pzVec);
					for (int docId = 0; docId < NumDocs; docId++) //doc
					{
						//                Pval(did);
						Float numWords = docs[docId].numWords;
						const ContentVec& contents = docs[docId].content;
						int numUniqeWords = contents.size();
						//如果0个word那么该doc被忽略,另外短文本不会迭代超过文本word数目
						if (numWords < 1 || numUniqeWords == iter)
							continue;
						
						//--------------------Estep for one doc
						//p(z_k|w,d)
						for (int i = 0; i < numUniqeWords; i++) //word
						{
							int wordId = contents[i].first;
							//p(w,d)
							Float pwd = 0;
							for (int topicId = 0; topicId < NumTopics; topicId++)
							{
								pwd += _pdz(docId, topicId) * _pzw(topicId, wordId);
							}
							for (int topicId = 0; topicId < NumTopics; topicId++) //z topic
							{
								if (pwd)
									_pwz(wordId, topicId) = (_pdz(docId, topicId) * _pzw(topicId, wordId)) / pwd;
							}
						}
						//-------------------Mstep for one doc
						//---p(z|d) and p(w|z) update,this will be updated after all doc processed in one step
						for (int topicId = 0; topicId < NumTopics; topicId++)
						{
							Float sum = 0;
							for (int i = 0; i < numUniqeWords; i++) //word
							{
								int wordId = contents[i].first;
								Float weight = contents[i].second;
								Float score = weight * _pwz(wordId, topicId);
								sum += score;
								_pzwTemp(topicId, wordId) += score;
							}
							//Pval(sum);
							_pzVec[topicId] += sum;
							_pdz(docId, topicId) = sum / numWords; //p(z|d) update
						}
					}
					//after every doc is processed, now finish p(w|z)
					for (int topicId = 0; topicId < NumTopics; topicId++)
					{
						for (int wordId = 0; wordId < NumWords; wordId++) //word
						{
							if (_pzVec[topicId])
								_pzw(topicId, wordId) = _pzwTemp(topicId, wordId) / _pzVec[topicId];
						}
					}
				}
			}

			//保存pzw(p(w|z)即可，但是是按照word-> topic1 topic 这样形式保存 也可看做p(z|w)
			//为了解析速度 每个word默认只保存top 20的主题 @TODO 是否稀疏表示 按照倒排方式保存
			//有的word 可能只有几个主题 甚至没有 如果分值很小过滤掉
			void Save(string file, int maxTopicNum = 20)
			{
				serialize_util::save(_pzw, file);
			}
			/**
			* 展示某个topic id下面的top 20的支撑词
			*/
			template<typename _Dict>
			void PrintTopic(int topicId, const _Dict& dict, ostream& ofs, int maxNum = 200)
			{
				int len = std::min(NumWords, maxNum);

				vector<pair<int, Float> > vec;
				for (int i = 0; i < NumWords; i++)
				{
					vec.push_back(make_pair(i, _pzw(topicId, i)));
				}
				std::partial_sort(vec.begin(), vec.begin() + maxNum, vec.end(), [](const pair<int, Float>& l, const pair<int, Float>& r) { return l.second > r.second; });
				for (int i = 0; i < len; i++)
				{
					ofs << dict.key(vec[i].first) << vec[i].second << endl;
				}
			}

		public:
			int NumTopics;
			int NumWords;
			int NumDocs;
		protected:
		private:
			ufo::Matrix<Float> _pdz; //p(z|d)
			ufo::Matrix<Float> _pzw; //p(w|z)
			ufo::Matrix<Float> _pzwTemp; //在MPI版本中这个是要传递的
			vector<Float> _pzVec; //长度大小为NumTopics
			ufo::Matrix<Float> _pwz; ///Estep p(z|d,w) 每个doc都需要 为了节省空间各个doc复用 所以doc间不能并行
		};
	} //----end of namespace plsa
}  //----end of namespace gezi

#endif  //----end of P_L_S_A_TRAINER_H_
