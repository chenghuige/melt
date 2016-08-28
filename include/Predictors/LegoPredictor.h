/**
 *  ==============================================================================
 *
 *          \file   Predictors/LegoPredictor.h
 *
 *        \author   chenghuige
 *
 *          \date   2016-01-07 14:28:58.603769
 *
 *  \Description:
 *  ==============================================================================
 */

#ifndef GEZI_PREDICTORS__LEGO_PREDICTOR_H_
#define GEZI_PREDICTORS__LEGO_PREDICTOR_H_

#include "MLCore/Predictor.h"
#include "liblego/lego.h"

namespace gezi {

	class LegoPredictor : public ProbabilityPredictor
	{
	public:
		//@TODO 虽然结果正确 但是python封装的看出线程也是起作用 但是即使全部线程使用也就是勉强和单线程版本速度一样
		//@TODO need virutal ?
		//	virtual vector<Float> BulkPredict(Vectors& featuresVector) override
		//	{
		//		vector<Float> results(featuresVector.size(), 0.0);
		//#pragma omp parallel for
		//		for (size_t i = 0; i < results.size(); i++)
		//		{
		//			//InitThread();
		//			results[i] = Predict(featuresVector[i]);
		//		}
		//		return results;
		//	}
		//
		virtual void InitThread() override
		{
			if (!isThreadInited())
			{
				tlr_ptr() = _net.register_thread();
				blobs() = _net.input_blobs(tlr_ptr());
				isThreadInited() = true;
			}
		}

		virtual bool Load(string path) override
		{
			bool ret = true;
			string netFile = path + "/net.prototxt";
			ret = _net.set_net_parameter_from_file(netFile.c_str());
			if (ret != 0)
			{
				return false;
			}

			string modelFile = path + "/model.bin";
			ret = _net.init(modelFile.c_str());
			if (ret != 0)
			{
				return false;
			}

			//@TODO 如果调用方其它的线程方式，可能需要再显示调用这个。。InitThread()
#pragma omp parallel
		{
			tlr_ptr() = _net.register_thread();
		}

		if (!tlr_ptr())
		{
			return false;
		}

#pragma omp parallel
		{
			blobs() = _net.input_blobs(tlr_ptr());
		}

		ret = LoadNormalizerAndCalibrator(path);
		return ret;
		}

		virtual	~LegoPredictor()
		{
#pragma omp parallel
		{
			_net.destroy_thread(tlr_ptr());
		}
		}

	protected:
		//@TODO should be const Vector& features
		virtual Float Margin(Vector& features) override
		{
			SetDataFromVector(features);
			_net.predict(tlr_ptr());
			return _net.result_blob(tlr_ptr())->data[1];
		}

	private:
		void SetDataFromVector(const Vector& features)
		{
			int idx = 0;
			if (blobs().size() == 2)
			{ // only index, label
				features.ForEachNonZero([&, this](int index, double value) {
					blobs()[0]->data[idx++] = index;
				});
				blobs()[0]->dim0 = idx;
			}
			else
			{// index, weight, label
				features.ForEachNonZero([&, this](int index, double value) {
					blobs()[0]->data[idx] = index;
					blobs()[1]->data[idx++] = value;
				});
				blobs()[0]->dim0 = idx;
				blobs()[1]->dim0 = idx;
			}
		}
	private:
		liblego::Net _net;

		static void*& tlr_ptr()
		{
			static thread_local void* _tlr_ptr;
			return _tlr_ptr;
		}

		static vector<liblego::Blob*>& blobs()
		{
			static thread_local vector<liblego::Blob*> _blobs;
			return _blobs;
		}

		static bool& isThreadInited()
		{
			static thread_local bool isThreadInited = false;
			return isThreadInited;
		}
	};

}  //----end of namespace gezi

#endif  //----end of GEZI_PREDICTORS__LEGO_PREDICTOR_H_
