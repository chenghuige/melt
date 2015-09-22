#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=g++
CXX=g++
CXXFLAGS=-g \
  -O3 \
  -msse2 \
  -pipe \
  -W \
  -Wall \
  -fPIC \
  -DHAVE_NETINET_IN_H \
  -Wno-unused-parameter \
  -Wno-deprecated \
  -std=c++11 \
  -fpermissive \
  -Wno-write-strings \
  -Wno-literal-suffix \
  -Wno-unused-local-typedefs \
  -fopenmp
CFLAGS=-g \
  -O3 \
  -msse2 \
  -pipe \
  -W \
  -Wall \
  -fPIC \
  -DHAVE_NETINET_IN_H \
  -Wno-unused-parameter \
  -Wno-deprecated \
  -std=c++11 \
  -fpermissive \
  -Wno-write-strings \
  -Wno-literal-suffix \
  -Wno-unused-local-typedefs \
  -fopenmp
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\"
INCPATH=-I../ \
  -I../include/ \
  -I../include/vowpalwabbit/ \
  -I../include/sofia/
DEP_INCPATH=-I../../../../../../app/search/sep/anti-spam/gezi \
  -I../../../../../../app/search/sep/anti-spam/gezi/include \
  -I../../../../../../app/search/sep/anti-spam/gezi/output \
  -I../../../../../../app/search/sep/anti-spam/gezi/output/include \
  -I../../../../../../app/search/sep/anti-spam/gezi/third \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/include \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/output \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/output/include \
  -I../../../../../../app/search/sep/anti-spam/melt-train \
  -I../../../../../../app/search/sep/anti-spam/melt-train/include \
  -I../../../../../../app/search/sep/anti-spam/melt-train/output \
  -I../../../../../../app/search/sep/anti-spam/melt-train/output/include \
  -I../../../../../../com/btest/gtest \
  -I../../../../../../com/btest/gtest/include \
  -I../../../../../../com/btest/gtest/output \
  -I../../../../../../com/btest/gtest/output/include \
  -I../../../../../../lib2-64/bsl \
  -I../../../../../../lib2-64/bsl/include \
  -I../../../../../../lib2-64/bsl/output \
  -I../../../../../../lib2-64/bsl/output/include \
  -I../../../../../../lib2-64/ccode \
  -I../../../../../../lib2-64/ccode/include \
  -I../../../../../../lib2-64/ccode/output \
  -I../../../../../../lib2-64/ccode/output/include \
  -I../../../../../../lib2-64/dict \
  -I../../../../../../lib2-64/dict/include \
  -I../../../../../../lib2-64/dict/output \
  -I../../../../../../lib2-64/dict/output/include \
  -I../../../../../../lib2-64/libcrf \
  -I../../../../../../lib2-64/libcrf/include \
  -I../../../../../../lib2-64/libcrf/output \
  -I../../../../../../lib2-64/libcrf/output/include \
  -I../../../../../../lib2-64/others-ex \
  -I../../../../../../lib2-64/others-ex/include \
  -I../../../../../../lib2-64/others-ex/output \
  -I../../../../../../lib2-64/others-ex/output/include \
  -I../../../../../../lib2-64/postag \
  -I../../../../../../lib2-64/postag/include \
  -I../../../../../../lib2-64/postag/output \
  -I../../../../../../lib2-64/postag/output/include \
  -I../../../../../../lib2-64/ullib \
  -I../../../../../../lib2-64/ullib/include \
  -I../../../../../../lib2-64/ullib/output \
  -I../../../../../../lib2-64/ullib/output/include \
  -I../../../../../../lib2-64/wordseg \
  -I../../../../../../lib2-64/wordseg/include \
  -I../../../../../../lib2-64/wordseg/output \
  -I../../../../../../lib2-64/wordseg/output/include \
  -I../../../../../../ps/se/toolchain \
  -I../../../../../../ps/se/toolchain/include \
  -I../../../../../../ps/se/toolchain/output \
  -I../../../../../../ps/se/toolchain/output/include \
  -I../../../../../../public/comlog-plugin \
  -I../../../../../../public/comlog-plugin/include \
  -I../../../../../../public/comlog-plugin/output \
  -I../../../../../../public/comlog-plugin/output/include \
  -I../../../../../../public/configure \
  -I../../../../../../public/configure/include \
  -I../../../../../../public/configure/output \
  -I../../../../../../public/configure/output/include \
  -I../../../../../../public/connectpool \
  -I../../../../../../public/connectpool/include \
  -I../../../../../../public/connectpool/output \
  -I../../../../../../public/connectpool/output/include \
  -I../../../../../../public/odict \
  -I../../../../../../public/odict/include \
  -I../../../../../../public/odict/output \
  -I../../../../../../public/odict/output/include \
  -I../../../../../../public/spreg \
  -I../../../../../../public/spreg/include \
  -I../../../../../../public/spreg/output \
  -I../../../../../../public/spreg/output/include \
  -I../../../../../../public/uconv \
  -I../../../../../../public/uconv/include \
  -I../../../../../../public/uconv/output \
  -I../../../../../../public/uconv/output/include \
  -I../../../../../../quality/autotest/reportlib/cpp \
  -I../../../../../../quality/autotest/reportlib/cpp/include \
  -I../../../../../../quality/autotest/reportlib/cpp/output \
  -I../../../../../../quality/autotest/reportlib/cpp/output/include \
  -I../../../../../../third-64/boost \
  -I../../../../../../third-64/boost/include \
  -I../../../../../../third-64/boost/output \
  -I../../../../../../third-64/boost/output/include \
  -I../../../../../../third-64/gflags \
  -I../../../../../../third-64/gflags/include \
  -I../../../../../../third-64/gflags/output \
  -I../../../../../../third-64/gflags/output/include \
  -I../../../../../../third-64/glog \
  -I../../../../../../third-64/glog/include \
  -I../../../../../../third-64/glog/output \
  -I../../../../../../third-64/glog/output/include \
  -I../../../../../../third-64/gtest \
  -I../../../../../../third-64/gtest/include \
  -I../../../../../../third-64/gtest/output \
  -I../../../../../../third-64/gtest/output/include \
  -I../../../../../../third-64/libcurl \
  -I../../../../../../third-64/libcurl/include \
  -I../../../../../../third-64/libcurl/output \
  -I../../../../../../third-64/libcurl/output/include \
  -I../../../../../../third-64/pcre \
  -I../../../../../../third-64/pcre/include \
  -I../../../../../../third-64/pcre/output \
  -I../../../../../../third-64/pcre/output/include \
  -I../../../../../../third-64/tcmalloc \
  -I../../../../../../third-64/tcmalloc/include \
  -I../../../../../../third-64/tcmalloc/output \
  -I../../../../../../third-64/tcmalloc/output/include \
  -I../../../../../../third-64/zlib \
  -I../../../../../../third-64/zlib/include \
  -I../../../../../../third-64/zlib/output \
  -I../../../../../../third-64/zlib/output/include

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=3dc18f5fef6a1a867a66635016b38ee7  COMAKE


.PHONY:all
all:comake2_makefile_check calibrate predict gbdt4gcc3 gbdt_predict bin_sampling melt melt.debug vw vw.debug 
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:comake2_makefile_check
comake2_makefile_check:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcomake2_makefile_check[0m']"
	#in case of error, update 'Makefile' by 'comake2'
	@echo "$(COMAKE_MD5)">comake2.md5
	@md5sum -c --status comake2.md5
	@rm -f comake2.md5

.PHONY:ccpclean
ccpclean:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mccpclean[0m']"
	@echo "make ccpclean done"

.PHONY:clean
clean:ccpclean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf calibrate
	rm -rf ./output/bin/calibrate
	rm -rf predict
	rm -rf ./output/bin/predict
	rm -rf gbdt4gcc3
	rm -rf ./output/bin/gbdt4gcc3
	rm -rf gbdt_predict
	rm -rf ./output/bin/gbdt_predict
	rm -rf bin_sampling
	rm -rf ./output/bin/bin_sampling
	rm -rf melt
	rm -rf ./output/bin/melt
	rm -rf melt.debug
	rm -rf ./output/bin/melt.debug
	rm -rf vw
	rm -rf ./output/bin/vw
	rm -rf vw.debug
	rm -rf ./output/bin/vw.debug
	rm -rf calibrate_calibrate.o
	rm -rf predict_predict.o
	rm -rf gbdt4gcc3_gbdt4gcc3.o
	rm -rf gbdt_predict_gbdt_predict.o
	rm -rf bin_sampling_bin_sampling.o
	rm -rf melt_melt.o
	rm -rf ../src/Wrapper/melt_PredictorFactory.o
	rm -rf ../src/Testers/melt_ClassifierTester.o
	rm -rf ../src/Prediction/Normalization/melt_BinNormalizer.o
	rm -rf ../src/Predictors/melt_LibSVMPredictor.o
	rm -rf ../src/Predictors/melt_VWPredictor.o
	rm -rf melt.debug_melt.o
	rm -rf ../src/Wrapper/melt.debug_PredictorFactory.o
	rm -rf ../src/Testers/melt.debug_ClassifierTester.o
	rm -rf ../src/Prediction/Normalization/melt.debug_BinNormalizer.o
	rm -rf ../src/Predictors/melt.debug_LibSVMPredictor.o
	rm -rf ../src/Predictors/melt.debug_VWPredictor.o
	rm -rf ../src/vowpalwabbit/melt.debug_accumulate.o
	rm -rf ../src/vowpalwabbit/melt.debug_active.o
	rm -rf ../src/vowpalwabbit/melt.debug_allreduce.o
	rm -rf ../src/vowpalwabbit/melt.debug_autolink.o
	rm -rf ../src/vowpalwabbit/melt.debug_bfgs.o
	rm -rf ../src/vowpalwabbit/melt.debug_binary.o
	rm -rf ../src/vowpalwabbit/melt.debug_bs.o
	rm -rf ../src/vowpalwabbit/melt.debug_cache.o
	rm -rf ../src/vowpalwabbit/melt.debug_cb.o
	rm -rf ../src/vowpalwabbit/melt.debug_cb_algs.o
	rm -rf ../src/vowpalwabbit/melt.debug_cbify.o
	rm -rf ../src/vowpalwabbit/melt.debug_cost_sensitive.o
	rm -rf ../src/vowpalwabbit/melt.debug_csoaa.o
	rm -rf ../src/vowpalwabbit/melt.debug_ect.o
	rm -rf ../src/vowpalwabbit/melt.debug_example.o
	rm -rf ../src/vowpalwabbit/melt.debug_gd.o
	rm -rf ../src/vowpalwabbit/melt.debug_gd_mf.o
	rm -rf ../src/vowpalwabbit/melt.debug_global_data.o
	rm -rf ../src/vowpalwabbit/melt.debug_hash.o
	rm -rf ../src/vowpalwabbit/melt.debug_io_buf.o
	rm -rf ../src/vowpalwabbit/melt.debug_kernel_svm.o
	rm -rf ../src/vowpalwabbit/melt.debug_lda_core.o
	rm -rf ../src/vowpalwabbit/melt.debug_learner.o
	rm -rf ../src/vowpalwabbit/melt.debug_log_multi.o
	rm -rf ../src/vowpalwabbit/melt.debug_loss_functions.o
	rm -rf ../src/vowpalwabbit/melt.debug_lrq.o
	rm -rf ../src/vowpalwabbit/melt.debug_memory.o
	rm -rf ../src/vowpalwabbit/melt.debug_mf.o
	rm -rf ../src/vowpalwabbit/melt.debug_multiclass.o
	rm -rf ../src/vowpalwabbit/melt.debug_network.o
	rm -rf ../src/vowpalwabbit/melt.debug_nn.o
	rm -rf ../src/vowpalwabbit/melt.debug_noop.o
	rm -rf ../src/vowpalwabbit/melt.debug_oaa.o
	rm -rf ../src/vowpalwabbit/melt.debug_parse_args.o
	rm -rf ../src/vowpalwabbit/melt.debug_parse_example.o
	rm -rf ../src/vowpalwabbit/melt.debug_parse_primitives.o
	rm -rf ../src/vowpalwabbit/melt.debug_parse_regressor.o
	rm -rf ../src/vowpalwabbit/melt.debug_parser.o
	rm -rf ../src/vowpalwabbit/melt.debug_print.o
	rm -rf ../src/vowpalwabbit/melt.debug_rand48.o
	rm -rf ../src/vowpalwabbit/melt.debug_scorer.o
	rm -rf ../src/vowpalwabbit/melt.debug_search.o
	rm -rf ../src/vowpalwabbit/melt.debug_search_dep_parser.o
	rm -rf ../src/vowpalwabbit/melt.debug_search_entityrelationtask.o
	rm -rf ../src/vowpalwabbit/melt.debug_search_hooktask.o
	rm -rf ../src/vowpalwabbit/melt.debug_search_multiclasstask.o
	rm -rf ../src/vowpalwabbit/melt.debug_search_sequencetask.o
	rm -rf ../src/vowpalwabbit/melt.debug_sender.o
	rm -rf ../src/vowpalwabbit/melt.debug_simple_label.o
	rm -rf ../src/vowpalwabbit/melt.debug_stagewise_poly.o
	rm -rf ../src/vowpalwabbit/melt.debug_topk.o
	rm -rf ../src/vowpalwabbit/melt.debug_unique_sort.o
	rm -rf vw_vw.o
	rm -rf ../src/Wrapper/vw_PredictorFactory.o
	rm -rf ../src/Testers/vw_ClassifierTester.o
	rm -rf ../src/Prediction/Normalization/vw_BinNormalizer.o
	rm -rf ../src/Predictors/vw_LibSVMPredictor.o
	rm -rf ../src/Predictors/vw_VWPredictor.o
	rm -rf ../src/vowpalwabbit/vw_accumulate.o
	rm -rf ../src/vowpalwabbit/vw_active.o
	rm -rf ../src/vowpalwabbit/vw_allreduce.o
	rm -rf ../src/vowpalwabbit/vw_autolink.o
	rm -rf ../src/vowpalwabbit/vw_bfgs.o
	rm -rf ../src/vowpalwabbit/vw_binary.o
	rm -rf ../src/vowpalwabbit/vw_bs.o
	rm -rf ../src/vowpalwabbit/vw_cache.o
	rm -rf ../src/vowpalwabbit/vw_cb.o
	rm -rf ../src/vowpalwabbit/vw_cb_algs.o
	rm -rf ../src/vowpalwabbit/vw_cbify.o
	rm -rf ../src/vowpalwabbit/vw_cost_sensitive.o
	rm -rf ../src/vowpalwabbit/vw_csoaa.o
	rm -rf ../src/vowpalwabbit/vw_ect.o
	rm -rf ../src/vowpalwabbit/vw_example.o
	rm -rf ../src/vowpalwabbit/vw_gd.o
	rm -rf ../src/vowpalwabbit/vw_gd_mf.o
	rm -rf ../src/vowpalwabbit/vw_global_data.o
	rm -rf ../src/vowpalwabbit/vw_hash.o
	rm -rf ../src/vowpalwabbit/vw_io_buf.o
	rm -rf ../src/vowpalwabbit/vw_kernel_svm.o
	rm -rf ../src/vowpalwabbit/vw_lda_core.o
	rm -rf ../src/vowpalwabbit/vw_learner.o
	rm -rf ../src/vowpalwabbit/vw_log_multi.o
	rm -rf ../src/vowpalwabbit/vw_loss_functions.o
	rm -rf ../src/vowpalwabbit/vw_lrq.o
	rm -rf ../src/vowpalwabbit/vw_memory.o
	rm -rf ../src/vowpalwabbit/vw_mf.o
	rm -rf ../src/vowpalwabbit/vw_multiclass.o
	rm -rf ../src/vowpalwabbit/vw_network.o
	rm -rf ../src/vowpalwabbit/vw_nn.o
	rm -rf ../src/vowpalwabbit/vw_noop.o
	rm -rf ../src/vowpalwabbit/vw_oaa.o
	rm -rf ../src/vowpalwabbit/vw_parse_args.o
	rm -rf ../src/vowpalwabbit/vw_parse_example.o
	rm -rf ../src/vowpalwabbit/vw_parse_primitives.o
	rm -rf ../src/vowpalwabbit/vw_parse_regressor.o
	rm -rf ../src/vowpalwabbit/vw_parser.o
	rm -rf ../src/vowpalwabbit/vw_print.o
	rm -rf ../src/vowpalwabbit/vw_rand48.o
	rm -rf ../src/vowpalwabbit/vw_scorer.o
	rm -rf ../src/vowpalwabbit/vw_search.o
	rm -rf ../src/vowpalwabbit/vw_search_dep_parser.o
	rm -rf ../src/vowpalwabbit/vw_search_entityrelationtask.o
	rm -rf ../src/vowpalwabbit/vw_search_hooktask.o
	rm -rf ../src/vowpalwabbit/vw_search_multiclasstask.o
	rm -rf ../src/vowpalwabbit/vw_search_sequencetask.o
	rm -rf ../src/vowpalwabbit/vw_sender.o
	rm -rf ../src/vowpalwabbit/vw_simple_label.o
	rm -rf ../src/vowpalwabbit/vw_stagewise_poly.o
	rm -rf ../src/vowpalwabbit/vw_topk.o
	rm -rf ../src/vowpalwabbit/vw_unique_sort.o
	rm -rf vw.debug_vw.o
	rm -rf ../src/vowpalwabbit/vw.debug_accumulate.o
	rm -rf ../src/vowpalwabbit/vw.debug_active.o
	rm -rf ../src/vowpalwabbit/vw.debug_allreduce.o
	rm -rf ../src/vowpalwabbit/vw.debug_autolink.o
	rm -rf ../src/vowpalwabbit/vw.debug_bfgs.o
	rm -rf ../src/vowpalwabbit/vw.debug_binary.o
	rm -rf ../src/vowpalwabbit/vw.debug_bs.o
	rm -rf ../src/vowpalwabbit/vw.debug_cache.o
	rm -rf ../src/vowpalwabbit/vw.debug_cb.o
	rm -rf ../src/vowpalwabbit/vw.debug_cb_algs.o
	rm -rf ../src/vowpalwabbit/vw.debug_cbify.o
	rm -rf ../src/vowpalwabbit/vw.debug_cost_sensitive.o
	rm -rf ../src/vowpalwabbit/vw.debug_csoaa.o
	rm -rf ../src/vowpalwabbit/vw.debug_ect.o
	rm -rf ../src/vowpalwabbit/vw.debug_example.o
	rm -rf ../src/vowpalwabbit/vw.debug_gd.o
	rm -rf ../src/vowpalwabbit/vw.debug_gd_mf.o
	rm -rf ../src/vowpalwabbit/vw.debug_global_data.o
	rm -rf ../src/vowpalwabbit/vw.debug_hash.o
	rm -rf ../src/vowpalwabbit/vw.debug_io_buf.o
	rm -rf ../src/vowpalwabbit/vw.debug_kernel_svm.o
	rm -rf ../src/vowpalwabbit/vw.debug_lda_core.o
	rm -rf ../src/vowpalwabbit/vw.debug_learner.o
	rm -rf ../src/vowpalwabbit/vw.debug_log_multi.o
	rm -rf ../src/vowpalwabbit/vw.debug_loss_functions.o
	rm -rf ../src/vowpalwabbit/vw.debug_lrq.o
	rm -rf ../src/vowpalwabbit/vw.debug_memory.o
	rm -rf ../src/vowpalwabbit/vw.debug_mf.o
	rm -rf ../src/vowpalwabbit/vw.debug_multiclass.o
	rm -rf ../src/vowpalwabbit/vw.debug_network.o
	rm -rf ../src/vowpalwabbit/vw.debug_nn.o
	rm -rf ../src/vowpalwabbit/vw.debug_noop.o
	rm -rf ../src/vowpalwabbit/vw.debug_oaa.o
	rm -rf ../src/vowpalwabbit/vw.debug_parse_args.o
	rm -rf ../src/vowpalwabbit/vw.debug_parse_example.o
	rm -rf ../src/vowpalwabbit/vw.debug_parse_primitives.o
	rm -rf ../src/vowpalwabbit/vw.debug_parse_regressor.o
	rm -rf ../src/vowpalwabbit/vw.debug_parser.o
	rm -rf ../src/vowpalwabbit/vw.debug_print.o
	rm -rf ../src/vowpalwabbit/vw.debug_rand48.o
	rm -rf ../src/vowpalwabbit/vw.debug_scorer.o
	rm -rf ../src/vowpalwabbit/vw.debug_search.o
	rm -rf ../src/vowpalwabbit/vw.debug_search_dep_parser.o
	rm -rf ../src/vowpalwabbit/vw.debug_search_entityrelationtask.o
	rm -rf ../src/vowpalwabbit/vw.debug_search_hooktask.o
	rm -rf ../src/vowpalwabbit/vw.debug_search_multiclasstask.o
	rm -rf ../src/vowpalwabbit/vw.debug_search_sequencetask.o
	rm -rf ../src/vowpalwabbit/vw.debug_sender.o
	rm -rf ../src/vowpalwabbit/vw.debug_simple_label.o
	rm -rf ../src/vowpalwabbit/vw.debug_stagewise_poly.o
	rm -rf ../src/vowpalwabbit/vw.debug_topk.o
	rm -rf ../src/vowpalwabbit/vw.debug_unique_sort.o

.PHONY:dist
dist:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdist[0m']"
	tar czvf output.tar.gz output
	@echo "make dist done"

.PHONY:distclean
distclean:clean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdistclean[0m']"
	rm -f output.tar.gz
	@echo "make distclean done"

.PHONY:love
love:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlove[0m']"
	@echo "make love done"

calibrate:calibrate_calibrate.o \
  ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcalibrate[0m']"
	$(CXX) calibrate_calibrate.o -Xlinker "-(" ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../../../lib2-64/ccode/lib/libulccode.a \
  ../../../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../../../lib2-64/libcrf/lib/libcrf.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../../../third-64/boost/lib/libboost_atomic.a \
  ../../../../../../third-64/boost/lib/libboost_chrono.a \
  ../../../../../../third-64/boost/lib/libboost_container.a \
  ../../../../../../third-64/boost/lib/libboost_context.a \
  ../../../../../../third-64/boost/lib/libboost_coroutine.a \
  ../../../../../../third-64/boost/lib/libboost_date_time.a \
  ../../../../../../third-64/boost/lib/libboost_exception.a \
  ../../../../../../third-64/boost/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost/lib/libboost_graph.a \
  ../../../../../../third-64/boost/lib/libboost_locale.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost/lib/libboost_mpi.a \
  ../../../../../../third-64/boost/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_program_options.a \
  ../../../../../../third-64/boost/lib/libboost_python.a \
  ../../../../../../third-64/boost/lib/libboost_random.a \
  ../../../../../../third-64/boost/lib/libboost_regex.a \
  ../../../../../../third-64/boost/lib/libboost_serialization.a \
  ../../../../../../third-64/boost/lib/libboost_signals.a \
  ../../../../../../third-64/boost/lib/libboost_system.a \
  ../../../../../../third-64/boost/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_thread.a \
  ../../../../../../third-64/boost/lib/libboost_timer.a \
  ../../../../../../third-64/boost/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost/lib/libboost_wave.a \
  ../../../../../../third-64/boost/lib/libboost_wserialization.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/gtest/lib/libgtest.a \
  ../../../../../../third-64/gtest/lib/libgtest_main.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -rdynamic \
  -lgomp -Xlinker "-)" -o calibrate
	mkdir -p ./output/bin
	cp -f --link calibrate ./output/bin

predict:predict_predict.o \
  ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mpredict[0m']"
	$(CXX) predict_predict.o -Xlinker "-(" ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../../../lib2-64/ccode/lib/libulccode.a \
  ../../../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../../../lib2-64/libcrf/lib/libcrf.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../../../third-64/boost/lib/libboost_atomic.a \
  ../../../../../../third-64/boost/lib/libboost_chrono.a \
  ../../../../../../third-64/boost/lib/libboost_container.a \
  ../../../../../../third-64/boost/lib/libboost_context.a \
  ../../../../../../third-64/boost/lib/libboost_coroutine.a \
  ../../../../../../third-64/boost/lib/libboost_date_time.a \
  ../../../../../../third-64/boost/lib/libboost_exception.a \
  ../../../../../../third-64/boost/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost/lib/libboost_graph.a \
  ../../../../../../third-64/boost/lib/libboost_locale.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost/lib/libboost_mpi.a \
  ../../../../../../third-64/boost/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_program_options.a \
  ../../../../../../third-64/boost/lib/libboost_python.a \
  ../../../../../../third-64/boost/lib/libboost_random.a \
  ../../../../../../third-64/boost/lib/libboost_regex.a \
  ../../../../../../third-64/boost/lib/libboost_serialization.a \
  ../../../../../../third-64/boost/lib/libboost_signals.a \
  ../../../../../../third-64/boost/lib/libboost_system.a \
  ../../../../../../third-64/boost/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_thread.a \
  ../../../../../../third-64/boost/lib/libboost_timer.a \
  ../../../../../../third-64/boost/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost/lib/libboost_wave.a \
  ../../../../../../third-64/boost/lib/libboost_wserialization.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/gtest/lib/libgtest.a \
  ../../../../../../third-64/gtest/lib/libgtest_main.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -rdynamic \
  -lgomp -Xlinker "-)" -o predict
	mkdir -p ./output/bin
	cp -f --link predict ./output/bin

gbdt4gcc3:gbdt4gcc3_gbdt4gcc3.o \
  ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgbdt4gcc3[0m']"
	$(CXX) gbdt4gcc3_gbdt4gcc3.o -Xlinker "-(" ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../../../lib2-64/ccode/lib/libulccode.a \
  ../../../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../../../lib2-64/libcrf/lib/libcrf.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../../../third-64/boost/lib/libboost_atomic.a \
  ../../../../../../third-64/boost/lib/libboost_chrono.a \
  ../../../../../../third-64/boost/lib/libboost_container.a \
  ../../../../../../third-64/boost/lib/libboost_context.a \
  ../../../../../../third-64/boost/lib/libboost_coroutine.a \
  ../../../../../../third-64/boost/lib/libboost_date_time.a \
  ../../../../../../third-64/boost/lib/libboost_exception.a \
  ../../../../../../third-64/boost/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost/lib/libboost_graph.a \
  ../../../../../../third-64/boost/lib/libboost_locale.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost/lib/libboost_mpi.a \
  ../../../../../../third-64/boost/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_program_options.a \
  ../../../../../../third-64/boost/lib/libboost_python.a \
  ../../../../../../third-64/boost/lib/libboost_random.a \
  ../../../../../../third-64/boost/lib/libboost_regex.a \
  ../../../../../../third-64/boost/lib/libboost_serialization.a \
  ../../../../../../third-64/boost/lib/libboost_signals.a \
  ../../../../../../third-64/boost/lib/libboost_system.a \
  ../../../../../../third-64/boost/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_thread.a \
  ../../../../../../third-64/boost/lib/libboost_timer.a \
  ../../../../../../third-64/boost/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost/lib/libboost_wave.a \
  ../../../../../../third-64/boost/lib/libboost_wserialization.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/gtest/lib/libgtest.a \
  ../../../../../../third-64/gtest/lib/libgtest_main.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -rdynamic \
  -lgomp -Xlinker "-)" -o gbdt4gcc3
	mkdir -p ./output/bin
	cp -f --link gbdt4gcc3 ./output/bin

gbdt_predict:gbdt_predict_gbdt_predict.o \
  ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgbdt_predict[0m']"
	$(CXX) gbdt_predict_gbdt_predict.o -Xlinker "-(" ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../../../lib2-64/ccode/lib/libulccode.a \
  ../../../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../../../lib2-64/libcrf/lib/libcrf.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../../../third-64/boost/lib/libboost_atomic.a \
  ../../../../../../third-64/boost/lib/libboost_chrono.a \
  ../../../../../../third-64/boost/lib/libboost_container.a \
  ../../../../../../third-64/boost/lib/libboost_context.a \
  ../../../../../../third-64/boost/lib/libboost_coroutine.a \
  ../../../../../../third-64/boost/lib/libboost_date_time.a \
  ../../../../../../third-64/boost/lib/libboost_exception.a \
  ../../../../../../third-64/boost/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost/lib/libboost_graph.a \
  ../../../../../../third-64/boost/lib/libboost_locale.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost/lib/libboost_mpi.a \
  ../../../../../../third-64/boost/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_program_options.a \
  ../../../../../../third-64/boost/lib/libboost_python.a \
  ../../../../../../third-64/boost/lib/libboost_random.a \
  ../../../../../../third-64/boost/lib/libboost_regex.a \
  ../../../../../../third-64/boost/lib/libboost_serialization.a \
  ../../../../../../third-64/boost/lib/libboost_signals.a \
  ../../../../../../third-64/boost/lib/libboost_system.a \
  ../../../../../../third-64/boost/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_thread.a \
  ../../../../../../third-64/boost/lib/libboost_timer.a \
  ../../../../../../third-64/boost/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost/lib/libboost_wave.a \
  ../../../../../../third-64/boost/lib/libboost_wserialization.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/gtest/lib/libgtest.a \
  ../../../../../../third-64/gtest/lib/libgtest_main.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -rdynamic \
  -lgomp -Xlinker "-)" -o gbdt_predict
	mkdir -p ./output/bin
	cp -f --link gbdt_predict ./output/bin

bin_sampling:bin_sampling_bin_sampling.o \
  ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mbin_sampling[0m']"
	$(CXX) bin_sampling_bin_sampling.o -Xlinker "-(" ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../../../lib2-64/ccode/lib/libulccode.a \
  ../../../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../../../lib2-64/libcrf/lib/libcrf.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../../../third-64/boost/lib/libboost_atomic.a \
  ../../../../../../third-64/boost/lib/libboost_chrono.a \
  ../../../../../../third-64/boost/lib/libboost_container.a \
  ../../../../../../third-64/boost/lib/libboost_context.a \
  ../../../../../../third-64/boost/lib/libboost_coroutine.a \
  ../../../../../../third-64/boost/lib/libboost_date_time.a \
  ../../../../../../third-64/boost/lib/libboost_exception.a \
  ../../../../../../third-64/boost/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost/lib/libboost_graph.a \
  ../../../../../../third-64/boost/lib/libboost_locale.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost/lib/libboost_mpi.a \
  ../../../../../../third-64/boost/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_program_options.a \
  ../../../../../../third-64/boost/lib/libboost_python.a \
  ../../../../../../third-64/boost/lib/libboost_random.a \
  ../../../../../../third-64/boost/lib/libboost_regex.a \
  ../../../../../../third-64/boost/lib/libboost_serialization.a \
  ../../../../../../third-64/boost/lib/libboost_signals.a \
  ../../../../../../third-64/boost/lib/libboost_system.a \
  ../../../../../../third-64/boost/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_thread.a \
  ../../../../../../third-64/boost/lib/libboost_timer.a \
  ../../../../../../third-64/boost/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost/lib/libboost_wave.a \
  ../../../../../../third-64/boost/lib/libboost_wserialization.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/gtest/lib/libgtest.a \
  ../../../../../../third-64/gtest/lib/libgtest_main.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -rdynamic \
  -lgomp -Xlinker "-)" -o bin_sampling
	mkdir -p ./output/bin
	cp -f --link bin_sampling ./output/bin

melt:melt_melt.o \
  ../src/Wrapper/melt_PredictorFactory.o \
  ../src/Testers/melt_ClassifierTester.o \
  ../src/Prediction/Normalization/melt_BinNormalizer.o \
  ../src/Predictors/melt_LibSVMPredictor.o \
  ../src/Predictors/melt_VWPredictor.o \
  ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mmelt[0m']"
	$(CXX) melt_melt.o \
  ../src/Wrapper/melt_PredictorFactory.o \
  ../src/Testers/melt_ClassifierTester.o \
  ../src/Prediction/Normalization/melt_BinNormalizer.o \
  ../src/Predictors/melt_LibSVMPredictor.o \
  ../src/Predictors/melt_VWPredictor.o -Xlinker "-(" ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../../../lib2-64/ccode/lib/libulccode.a \
  ../../../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../../../lib2-64/libcrf/lib/libcrf.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../../../third-64/boost/lib/libboost_atomic.a \
  ../../../../../../third-64/boost/lib/libboost_chrono.a \
  ../../../../../../third-64/boost/lib/libboost_container.a \
  ../../../../../../third-64/boost/lib/libboost_context.a \
  ../../../../../../third-64/boost/lib/libboost_coroutine.a \
  ../../../../../../third-64/boost/lib/libboost_date_time.a \
  ../../../../../../third-64/boost/lib/libboost_exception.a \
  ../../../../../../third-64/boost/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost/lib/libboost_graph.a \
  ../../../../../../third-64/boost/lib/libboost_locale.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost/lib/libboost_mpi.a \
  ../../../../../../third-64/boost/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_program_options.a \
  ../../../../../../third-64/boost/lib/libboost_python.a \
  ../../../../../../third-64/boost/lib/libboost_random.a \
  ../../../../../../third-64/boost/lib/libboost_regex.a \
  ../../../../../../third-64/boost/lib/libboost_serialization.a \
  ../../../../../../third-64/boost/lib/libboost_signals.a \
  ../../../../../../third-64/boost/lib/libboost_system.a \
  ../../../../../../third-64/boost/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_thread.a \
  ../../../../../../third-64/boost/lib/libboost_timer.a \
  ../../../../../../third-64/boost/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost/lib/libboost_wave.a \
  ../../../../../../third-64/boost/lib/libboost_wserialization.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/gtest/lib/libgtest.a \
  ../../../../../../third-64/gtest/lib/libgtest_main.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -rdynamic \
  -lgomp -Xlinker "-)" -o melt
	mkdir -p ./output/bin
	cp -f --link melt ./output/bin

melt.debug:melt.debug_melt.o \
  ../src/Wrapper/melt.debug_PredictorFactory.o \
  ../src/Testers/melt.debug_ClassifierTester.o \
  ../src/Prediction/Normalization/melt.debug_BinNormalizer.o \
  ../src/Predictors/melt.debug_LibSVMPredictor.o \
  ../src/Predictors/melt.debug_VWPredictor.o \
  ../src/vowpalwabbit/melt.debug_accumulate.o \
  ../src/vowpalwabbit/melt.debug_active.o \
  ../src/vowpalwabbit/melt.debug_allreduce.o \
  ../src/vowpalwabbit/melt.debug_autolink.o \
  ../src/vowpalwabbit/melt.debug_bfgs.o \
  ../src/vowpalwabbit/melt.debug_binary.o \
  ../src/vowpalwabbit/melt.debug_bs.o \
  ../src/vowpalwabbit/melt.debug_cache.o \
  ../src/vowpalwabbit/melt.debug_cb.o \
  ../src/vowpalwabbit/melt.debug_cb_algs.o \
  ../src/vowpalwabbit/melt.debug_cbify.o \
  ../src/vowpalwabbit/melt.debug_cost_sensitive.o \
  ../src/vowpalwabbit/melt.debug_csoaa.o \
  ../src/vowpalwabbit/melt.debug_ect.o \
  ../src/vowpalwabbit/melt.debug_example.o \
  ../src/vowpalwabbit/melt.debug_gd.o \
  ../src/vowpalwabbit/melt.debug_gd_mf.o \
  ../src/vowpalwabbit/melt.debug_global_data.o \
  ../src/vowpalwabbit/melt.debug_hash.o \
  ../src/vowpalwabbit/melt.debug_io_buf.o \
  ../src/vowpalwabbit/melt.debug_kernel_svm.o \
  ../src/vowpalwabbit/melt.debug_lda_core.o \
  ../src/vowpalwabbit/melt.debug_learner.o \
  ../src/vowpalwabbit/melt.debug_log_multi.o \
  ../src/vowpalwabbit/melt.debug_loss_functions.o \
  ../src/vowpalwabbit/melt.debug_lrq.o \
  ../src/vowpalwabbit/melt.debug_memory.o \
  ../src/vowpalwabbit/melt.debug_mf.o \
  ../src/vowpalwabbit/melt.debug_multiclass.o \
  ../src/vowpalwabbit/melt.debug_network.o \
  ../src/vowpalwabbit/melt.debug_nn.o \
  ../src/vowpalwabbit/melt.debug_noop.o \
  ../src/vowpalwabbit/melt.debug_oaa.o \
  ../src/vowpalwabbit/melt.debug_parse_args.o \
  ../src/vowpalwabbit/melt.debug_parse_example.o \
  ../src/vowpalwabbit/melt.debug_parse_primitives.o \
  ../src/vowpalwabbit/melt.debug_parse_regressor.o \
  ../src/vowpalwabbit/melt.debug_parser.o \
  ../src/vowpalwabbit/melt.debug_print.o \
  ../src/vowpalwabbit/melt.debug_rand48.o \
  ../src/vowpalwabbit/melt.debug_scorer.o \
  ../src/vowpalwabbit/melt.debug_search.o \
  ../src/vowpalwabbit/melt.debug_search_dep_parser.o \
  ../src/vowpalwabbit/melt.debug_search_entityrelationtask.o \
  ../src/vowpalwabbit/melt.debug_search_hooktask.o \
  ../src/vowpalwabbit/melt.debug_search_multiclasstask.o \
  ../src/vowpalwabbit/melt.debug_search_sequencetask.o \
  ../src/vowpalwabbit/melt.debug_sender.o \
  ../src/vowpalwabbit/melt.debug_simple_label.o \
  ../src/vowpalwabbit/melt.debug_stagewise_poly.o \
  ../src/vowpalwabbit/melt.debug_topk.o \
  ../src/vowpalwabbit/melt.debug_unique_sort.o \
  ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mmelt.debug[0m']"
	$(CXX) melt.debug_melt.o \
  ../src/Wrapper/melt.debug_PredictorFactory.o \
  ../src/Testers/melt.debug_ClassifierTester.o \
  ../src/Prediction/Normalization/melt.debug_BinNormalizer.o \
  ../src/Predictors/melt.debug_LibSVMPredictor.o \
  ../src/Predictors/melt.debug_VWPredictor.o \
  ../src/vowpalwabbit/melt.debug_accumulate.o \
  ../src/vowpalwabbit/melt.debug_active.o \
  ../src/vowpalwabbit/melt.debug_allreduce.o \
  ../src/vowpalwabbit/melt.debug_autolink.o \
  ../src/vowpalwabbit/melt.debug_bfgs.o \
  ../src/vowpalwabbit/melt.debug_binary.o \
  ../src/vowpalwabbit/melt.debug_bs.o \
  ../src/vowpalwabbit/melt.debug_cache.o \
  ../src/vowpalwabbit/melt.debug_cb.o \
  ../src/vowpalwabbit/melt.debug_cb_algs.o \
  ../src/vowpalwabbit/melt.debug_cbify.o \
  ../src/vowpalwabbit/melt.debug_cost_sensitive.o \
  ../src/vowpalwabbit/melt.debug_csoaa.o \
  ../src/vowpalwabbit/melt.debug_ect.o \
  ../src/vowpalwabbit/melt.debug_example.o \
  ../src/vowpalwabbit/melt.debug_gd.o \
  ../src/vowpalwabbit/melt.debug_gd_mf.o \
  ../src/vowpalwabbit/melt.debug_global_data.o \
  ../src/vowpalwabbit/melt.debug_hash.o \
  ../src/vowpalwabbit/melt.debug_io_buf.o \
  ../src/vowpalwabbit/melt.debug_kernel_svm.o \
  ../src/vowpalwabbit/melt.debug_lda_core.o \
  ../src/vowpalwabbit/melt.debug_learner.o \
  ../src/vowpalwabbit/melt.debug_log_multi.o \
  ../src/vowpalwabbit/melt.debug_loss_functions.o \
  ../src/vowpalwabbit/melt.debug_lrq.o \
  ../src/vowpalwabbit/melt.debug_memory.o \
  ../src/vowpalwabbit/melt.debug_mf.o \
  ../src/vowpalwabbit/melt.debug_multiclass.o \
  ../src/vowpalwabbit/melt.debug_network.o \
  ../src/vowpalwabbit/melt.debug_nn.o \
  ../src/vowpalwabbit/melt.debug_noop.o \
  ../src/vowpalwabbit/melt.debug_oaa.o \
  ../src/vowpalwabbit/melt.debug_parse_args.o \
  ../src/vowpalwabbit/melt.debug_parse_example.o \
  ../src/vowpalwabbit/melt.debug_parse_primitives.o \
  ../src/vowpalwabbit/melt.debug_parse_regressor.o \
  ../src/vowpalwabbit/melt.debug_parser.o \
  ../src/vowpalwabbit/melt.debug_print.o \
  ../src/vowpalwabbit/melt.debug_rand48.o \
  ../src/vowpalwabbit/melt.debug_scorer.o \
  ../src/vowpalwabbit/melt.debug_search.o \
  ../src/vowpalwabbit/melt.debug_search_dep_parser.o \
  ../src/vowpalwabbit/melt.debug_search_entityrelationtask.o \
  ../src/vowpalwabbit/melt.debug_search_hooktask.o \
  ../src/vowpalwabbit/melt.debug_search_multiclasstask.o \
  ../src/vowpalwabbit/melt.debug_search_sequencetask.o \
  ../src/vowpalwabbit/melt.debug_sender.o \
  ../src/vowpalwabbit/melt.debug_simple_label.o \
  ../src/vowpalwabbit/melt.debug_stagewise_poly.o \
  ../src/vowpalwabbit/melt.debug_topk.o \
  ../src/vowpalwabbit/melt.debug_unique_sort.o -Xlinker "-(" ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../../../lib2-64/ccode/lib/libulccode.a \
  ../../../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../../../lib2-64/libcrf/lib/libcrf.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../../../third-64/boost/lib/libboost_atomic.a \
  ../../../../../../third-64/boost/lib/libboost_chrono.a \
  ../../../../../../third-64/boost/lib/libboost_container.a \
  ../../../../../../third-64/boost/lib/libboost_context.a \
  ../../../../../../third-64/boost/lib/libboost_coroutine.a \
  ../../../../../../third-64/boost/lib/libboost_date_time.a \
  ../../../../../../third-64/boost/lib/libboost_exception.a \
  ../../../../../../third-64/boost/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost/lib/libboost_graph.a \
  ../../../../../../third-64/boost/lib/libboost_locale.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost/lib/libboost_mpi.a \
  ../../../../../../third-64/boost/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_program_options.a \
  ../../../../../../third-64/boost/lib/libboost_python.a \
  ../../../../../../third-64/boost/lib/libboost_random.a \
  ../../../../../../third-64/boost/lib/libboost_regex.a \
  ../../../../../../third-64/boost/lib/libboost_serialization.a \
  ../../../../../../third-64/boost/lib/libboost_signals.a \
  ../../../../../../third-64/boost/lib/libboost_system.a \
  ../../../../../../third-64/boost/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_thread.a \
  ../../../../../../third-64/boost/lib/libboost_timer.a \
  ../../../../../../third-64/boost/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost/lib/libboost_wave.a \
  ../../../../../../third-64/boost/lib/libboost_wserialization.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/gtest/lib/libgtest.a \
  ../../../../../../third-64/gtest/lib/libgtest_main.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -rdynamic \
  -lgomp -Xlinker "-)" -o melt.debug
	mkdir -p ./output/bin
	cp -f --link melt.debug ./output/bin

vw:vw_vw.o \
  ../src/Wrapper/vw_PredictorFactory.o \
  ../src/Testers/vw_ClassifierTester.o \
  ../src/Prediction/Normalization/vw_BinNormalizer.o \
  ../src/Predictors/vw_LibSVMPredictor.o \
  ../src/Predictors/vw_VWPredictor.o \
  ../src/vowpalwabbit/vw_accumulate.o \
  ../src/vowpalwabbit/vw_active.o \
  ../src/vowpalwabbit/vw_allreduce.o \
  ../src/vowpalwabbit/vw_autolink.o \
  ../src/vowpalwabbit/vw_bfgs.o \
  ../src/vowpalwabbit/vw_binary.o \
  ../src/vowpalwabbit/vw_bs.o \
  ../src/vowpalwabbit/vw_cache.o \
  ../src/vowpalwabbit/vw_cb.o \
  ../src/vowpalwabbit/vw_cb_algs.o \
  ../src/vowpalwabbit/vw_cbify.o \
  ../src/vowpalwabbit/vw_cost_sensitive.o \
  ../src/vowpalwabbit/vw_csoaa.o \
  ../src/vowpalwabbit/vw_ect.o \
  ../src/vowpalwabbit/vw_example.o \
  ../src/vowpalwabbit/vw_gd.o \
  ../src/vowpalwabbit/vw_gd_mf.o \
  ../src/vowpalwabbit/vw_global_data.o \
  ../src/vowpalwabbit/vw_hash.o \
  ../src/vowpalwabbit/vw_io_buf.o \
  ../src/vowpalwabbit/vw_kernel_svm.o \
  ../src/vowpalwabbit/vw_lda_core.o \
  ../src/vowpalwabbit/vw_learner.o \
  ../src/vowpalwabbit/vw_log_multi.o \
  ../src/vowpalwabbit/vw_loss_functions.o \
  ../src/vowpalwabbit/vw_lrq.o \
  ../src/vowpalwabbit/vw_memory.o \
  ../src/vowpalwabbit/vw_mf.o \
  ../src/vowpalwabbit/vw_multiclass.o \
  ../src/vowpalwabbit/vw_network.o \
  ../src/vowpalwabbit/vw_nn.o \
  ../src/vowpalwabbit/vw_noop.o \
  ../src/vowpalwabbit/vw_oaa.o \
  ../src/vowpalwabbit/vw_parse_args.o \
  ../src/vowpalwabbit/vw_parse_example.o \
  ../src/vowpalwabbit/vw_parse_primitives.o \
  ../src/vowpalwabbit/vw_parse_regressor.o \
  ../src/vowpalwabbit/vw_parser.o \
  ../src/vowpalwabbit/vw_print.o \
  ../src/vowpalwabbit/vw_rand48.o \
  ../src/vowpalwabbit/vw_scorer.o \
  ../src/vowpalwabbit/vw_search.o \
  ../src/vowpalwabbit/vw_search_dep_parser.o \
  ../src/vowpalwabbit/vw_search_entityrelationtask.o \
  ../src/vowpalwabbit/vw_search_hooktask.o \
  ../src/vowpalwabbit/vw_search_multiclasstask.o \
  ../src/vowpalwabbit/vw_search_sequencetask.o \
  ../src/vowpalwabbit/vw_sender.o \
  ../src/vowpalwabbit/vw_simple_label.o \
  ../src/vowpalwabbit/vw_stagewise_poly.o \
  ../src/vowpalwabbit/vw_topk.o \
  ../src/vowpalwabbit/vw_unique_sort.o \
  ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mvw[0m']"
	$(CXX) vw_vw.o \
  ../src/Wrapper/vw_PredictorFactory.o \
  ../src/Testers/vw_ClassifierTester.o \
  ../src/Prediction/Normalization/vw_BinNormalizer.o \
  ../src/Predictors/vw_LibSVMPredictor.o \
  ../src/Predictors/vw_VWPredictor.o \
  ../src/vowpalwabbit/vw_accumulate.o \
  ../src/vowpalwabbit/vw_active.o \
  ../src/vowpalwabbit/vw_allreduce.o \
  ../src/vowpalwabbit/vw_autolink.o \
  ../src/vowpalwabbit/vw_bfgs.o \
  ../src/vowpalwabbit/vw_binary.o \
  ../src/vowpalwabbit/vw_bs.o \
  ../src/vowpalwabbit/vw_cache.o \
  ../src/vowpalwabbit/vw_cb.o \
  ../src/vowpalwabbit/vw_cb_algs.o \
  ../src/vowpalwabbit/vw_cbify.o \
  ../src/vowpalwabbit/vw_cost_sensitive.o \
  ../src/vowpalwabbit/vw_csoaa.o \
  ../src/vowpalwabbit/vw_ect.o \
  ../src/vowpalwabbit/vw_example.o \
  ../src/vowpalwabbit/vw_gd.o \
  ../src/vowpalwabbit/vw_gd_mf.o \
  ../src/vowpalwabbit/vw_global_data.o \
  ../src/vowpalwabbit/vw_hash.o \
  ../src/vowpalwabbit/vw_io_buf.o \
  ../src/vowpalwabbit/vw_kernel_svm.o \
  ../src/vowpalwabbit/vw_lda_core.o \
  ../src/vowpalwabbit/vw_learner.o \
  ../src/vowpalwabbit/vw_log_multi.o \
  ../src/vowpalwabbit/vw_loss_functions.o \
  ../src/vowpalwabbit/vw_lrq.o \
  ../src/vowpalwabbit/vw_memory.o \
  ../src/vowpalwabbit/vw_mf.o \
  ../src/vowpalwabbit/vw_multiclass.o \
  ../src/vowpalwabbit/vw_network.o \
  ../src/vowpalwabbit/vw_nn.o \
  ../src/vowpalwabbit/vw_noop.o \
  ../src/vowpalwabbit/vw_oaa.o \
  ../src/vowpalwabbit/vw_parse_args.o \
  ../src/vowpalwabbit/vw_parse_example.o \
  ../src/vowpalwabbit/vw_parse_primitives.o \
  ../src/vowpalwabbit/vw_parse_regressor.o \
  ../src/vowpalwabbit/vw_parser.o \
  ../src/vowpalwabbit/vw_print.o \
  ../src/vowpalwabbit/vw_rand48.o \
  ../src/vowpalwabbit/vw_scorer.o \
  ../src/vowpalwabbit/vw_search.o \
  ../src/vowpalwabbit/vw_search_dep_parser.o \
  ../src/vowpalwabbit/vw_search_entityrelationtask.o \
  ../src/vowpalwabbit/vw_search_hooktask.o \
  ../src/vowpalwabbit/vw_search_multiclasstask.o \
  ../src/vowpalwabbit/vw_search_sequencetask.o \
  ../src/vowpalwabbit/vw_sender.o \
  ../src/vowpalwabbit/vw_simple_label.o \
  ../src/vowpalwabbit/vw_stagewise_poly.o \
  ../src/vowpalwabbit/vw_topk.o \
  ../src/vowpalwabbit/vw_unique_sort.o -Xlinker "-(" ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../../../lib2-64/ccode/lib/libulccode.a \
  ../../../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../../../lib2-64/libcrf/lib/libcrf.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../../../third-64/boost/lib/libboost_atomic.a \
  ../../../../../../third-64/boost/lib/libboost_chrono.a \
  ../../../../../../third-64/boost/lib/libboost_container.a \
  ../../../../../../third-64/boost/lib/libboost_context.a \
  ../../../../../../third-64/boost/lib/libboost_coroutine.a \
  ../../../../../../third-64/boost/lib/libboost_date_time.a \
  ../../../../../../third-64/boost/lib/libboost_exception.a \
  ../../../../../../third-64/boost/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost/lib/libboost_graph.a \
  ../../../../../../third-64/boost/lib/libboost_locale.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost/lib/libboost_mpi.a \
  ../../../../../../third-64/boost/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_program_options.a \
  ../../../../../../third-64/boost/lib/libboost_python.a \
  ../../../../../../third-64/boost/lib/libboost_random.a \
  ../../../../../../third-64/boost/lib/libboost_regex.a \
  ../../../../../../third-64/boost/lib/libboost_serialization.a \
  ../../../../../../third-64/boost/lib/libboost_signals.a \
  ../../../../../../third-64/boost/lib/libboost_system.a \
  ../../../../../../third-64/boost/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_thread.a \
  ../../../../../../third-64/boost/lib/libboost_timer.a \
  ../../../../../../third-64/boost/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost/lib/libboost_wave.a \
  ../../../../../../third-64/boost/lib/libboost_wserialization.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/gtest/lib/libgtest.a \
  ../../../../../../third-64/gtest/lib/libgtest_main.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -rdynamic \
  -lgomp -Xlinker "-)" -o vw
	mkdir -p ./output/bin
	cp -f --link vw ./output/bin

vw.debug:vw.debug_vw.o \
  ../src/vowpalwabbit/vw.debug_accumulate.o \
  ../src/vowpalwabbit/vw.debug_active.o \
  ../src/vowpalwabbit/vw.debug_allreduce.o \
  ../src/vowpalwabbit/vw.debug_autolink.o \
  ../src/vowpalwabbit/vw.debug_bfgs.o \
  ../src/vowpalwabbit/vw.debug_binary.o \
  ../src/vowpalwabbit/vw.debug_bs.o \
  ../src/vowpalwabbit/vw.debug_cache.o \
  ../src/vowpalwabbit/vw.debug_cb.o \
  ../src/vowpalwabbit/vw.debug_cb_algs.o \
  ../src/vowpalwabbit/vw.debug_cbify.o \
  ../src/vowpalwabbit/vw.debug_cost_sensitive.o \
  ../src/vowpalwabbit/vw.debug_csoaa.o \
  ../src/vowpalwabbit/vw.debug_ect.o \
  ../src/vowpalwabbit/vw.debug_example.o \
  ../src/vowpalwabbit/vw.debug_gd.o \
  ../src/vowpalwabbit/vw.debug_gd_mf.o \
  ../src/vowpalwabbit/vw.debug_global_data.o \
  ../src/vowpalwabbit/vw.debug_hash.o \
  ../src/vowpalwabbit/vw.debug_io_buf.o \
  ../src/vowpalwabbit/vw.debug_kernel_svm.o \
  ../src/vowpalwabbit/vw.debug_lda_core.o \
  ../src/vowpalwabbit/vw.debug_learner.o \
  ../src/vowpalwabbit/vw.debug_log_multi.o \
  ../src/vowpalwabbit/vw.debug_loss_functions.o \
  ../src/vowpalwabbit/vw.debug_lrq.o \
  ../src/vowpalwabbit/vw.debug_memory.o \
  ../src/vowpalwabbit/vw.debug_mf.o \
  ../src/vowpalwabbit/vw.debug_multiclass.o \
  ../src/vowpalwabbit/vw.debug_network.o \
  ../src/vowpalwabbit/vw.debug_nn.o \
  ../src/vowpalwabbit/vw.debug_noop.o \
  ../src/vowpalwabbit/vw.debug_oaa.o \
  ../src/vowpalwabbit/vw.debug_parse_args.o \
  ../src/vowpalwabbit/vw.debug_parse_example.o \
  ../src/vowpalwabbit/vw.debug_parse_primitives.o \
  ../src/vowpalwabbit/vw.debug_parse_regressor.o \
  ../src/vowpalwabbit/vw.debug_parser.o \
  ../src/vowpalwabbit/vw.debug_print.o \
  ../src/vowpalwabbit/vw.debug_rand48.o \
  ../src/vowpalwabbit/vw.debug_scorer.o \
  ../src/vowpalwabbit/vw.debug_search.o \
  ../src/vowpalwabbit/vw.debug_search_dep_parser.o \
  ../src/vowpalwabbit/vw.debug_search_entityrelationtask.o \
  ../src/vowpalwabbit/vw.debug_search_hooktask.o \
  ../src/vowpalwabbit/vw.debug_search_multiclasstask.o \
  ../src/vowpalwabbit/vw.debug_search_sequencetask.o \
  ../src/vowpalwabbit/vw.debug_sender.o \
  ../src/vowpalwabbit/vw.debug_simple_label.o \
  ../src/vowpalwabbit/vw.debug_stagewise_poly.o \
  ../src/vowpalwabbit/vw.debug_topk.o \
  ../src/vowpalwabbit/vw.debug_unique_sort.o \
  ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mvw.debug[0m']"
	$(CXX) vw.debug_vw.o \
  ../src/vowpalwabbit/vw.debug_accumulate.o \
  ../src/vowpalwabbit/vw.debug_active.o \
  ../src/vowpalwabbit/vw.debug_allreduce.o \
  ../src/vowpalwabbit/vw.debug_autolink.o \
  ../src/vowpalwabbit/vw.debug_bfgs.o \
  ../src/vowpalwabbit/vw.debug_binary.o \
  ../src/vowpalwabbit/vw.debug_bs.o \
  ../src/vowpalwabbit/vw.debug_cache.o \
  ../src/vowpalwabbit/vw.debug_cb.o \
  ../src/vowpalwabbit/vw.debug_cb_algs.o \
  ../src/vowpalwabbit/vw.debug_cbify.o \
  ../src/vowpalwabbit/vw.debug_cost_sensitive.o \
  ../src/vowpalwabbit/vw.debug_csoaa.o \
  ../src/vowpalwabbit/vw.debug_ect.o \
  ../src/vowpalwabbit/vw.debug_example.o \
  ../src/vowpalwabbit/vw.debug_gd.o \
  ../src/vowpalwabbit/vw.debug_gd_mf.o \
  ../src/vowpalwabbit/vw.debug_global_data.o \
  ../src/vowpalwabbit/vw.debug_hash.o \
  ../src/vowpalwabbit/vw.debug_io_buf.o \
  ../src/vowpalwabbit/vw.debug_kernel_svm.o \
  ../src/vowpalwabbit/vw.debug_lda_core.o \
  ../src/vowpalwabbit/vw.debug_learner.o \
  ../src/vowpalwabbit/vw.debug_log_multi.o \
  ../src/vowpalwabbit/vw.debug_loss_functions.o \
  ../src/vowpalwabbit/vw.debug_lrq.o \
  ../src/vowpalwabbit/vw.debug_memory.o \
  ../src/vowpalwabbit/vw.debug_mf.o \
  ../src/vowpalwabbit/vw.debug_multiclass.o \
  ../src/vowpalwabbit/vw.debug_network.o \
  ../src/vowpalwabbit/vw.debug_nn.o \
  ../src/vowpalwabbit/vw.debug_noop.o \
  ../src/vowpalwabbit/vw.debug_oaa.o \
  ../src/vowpalwabbit/vw.debug_parse_args.o \
  ../src/vowpalwabbit/vw.debug_parse_example.o \
  ../src/vowpalwabbit/vw.debug_parse_primitives.o \
  ../src/vowpalwabbit/vw.debug_parse_regressor.o \
  ../src/vowpalwabbit/vw.debug_parser.o \
  ../src/vowpalwabbit/vw.debug_print.o \
  ../src/vowpalwabbit/vw.debug_rand48.o \
  ../src/vowpalwabbit/vw.debug_scorer.o \
  ../src/vowpalwabbit/vw.debug_search.o \
  ../src/vowpalwabbit/vw.debug_search_dep_parser.o \
  ../src/vowpalwabbit/vw.debug_search_entityrelationtask.o \
  ../src/vowpalwabbit/vw.debug_search_hooktask.o \
  ../src/vowpalwabbit/vw.debug_search_multiclasstask.o \
  ../src/vowpalwabbit/vw.debug_search_sequencetask.o \
  ../src/vowpalwabbit/vw.debug_sender.o \
  ../src/vowpalwabbit/vw.debug_simple_label.o \
  ../src/vowpalwabbit/vw.debug_stagewise_poly.o \
  ../src/vowpalwabbit/vw.debug_topk.o \
  ../src/vowpalwabbit/vw.debug_unique_sort.o -Xlinker "-(" ../libmelt.a \
  ../libsofia.a \
  ../libvw.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libsofia.a \
  ../libblas.a \
  ../liblinear.a \
  ../libsvm.a \
  ../libvw.a ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../../../lib2-64/ccode/lib/libulccode.a \
  ../../../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../../../lib2-64/libcrf/lib/libcrf.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../../../third-64/boost/lib/libboost_atomic.a \
  ../../../../../../third-64/boost/lib/libboost_chrono.a \
  ../../../../../../third-64/boost/lib/libboost_container.a \
  ../../../../../../third-64/boost/lib/libboost_context.a \
  ../../../../../../third-64/boost/lib/libboost_coroutine.a \
  ../../../../../../third-64/boost/lib/libboost_date_time.a \
  ../../../../../../third-64/boost/lib/libboost_exception.a \
  ../../../../../../third-64/boost/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost/lib/libboost_graph.a \
  ../../../../../../third-64/boost/lib/libboost_locale.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost/lib/libboost_mpi.a \
  ../../../../../../third-64/boost/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_program_options.a \
  ../../../../../../third-64/boost/lib/libboost_python.a \
  ../../../../../../third-64/boost/lib/libboost_random.a \
  ../../../../../../third-64/boost/lib/libboost_regex.a \
  ../../../../../../third-64/boost/lib/libboost_serialization.a \
  ../../../../../../third-64/boost/lib/libboost_signals.a \
  ../../../../../../third-64/boost/lib/libboost_system.a \
  ../../../../../../third-64/boost/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost/lib/libboost_thread.a \
  ../../../../../../third-64/boost/lib/libboost_timer.a \
  ../../../../../../third-64/boost/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost/lib/libboost_wave.a \
  ../../../../../../third-64/boost/lib/libboost_wserialization.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/gtest/lib/libgtest.a \
  ../../../../../../third-64/gtest/lib/libgtest_main.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -ldl \
  -rdynamic \
  -lgomp -Xlinker "-)" -o vw.debug
	mkdir -p ./output/bin
	cp -f --link vw.debug ./output/bin

calibrate_calibrate.o:calibrate.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcalibrate_calibrate.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o calibrate_calibrate.o calibrate.cc

predict_predict.o:predict.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mpredict_predict.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o predict_predict.o predict.cc

gbdt4gcc3_gbdt4gcc3.o:gbdt4gcc3.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgbdt4gcc3_gbdt4gcc3.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o gbdt4gcc3_gbdt4gcc3.o gbdt4gcc3.cc

gbdt_predict_gbdt_predict.o:gbdt_predict.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgbdt_predict_gbdt_predict.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o gbdt_predict_gbdt_predict.o gbdt_predict.cc

bin_sampling_bin_sampling.o:bin_sampling.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mbin_sampling_bin_sampling.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o bin_sampling_bin_sampling.o bin_sampling.cc

melt_melt.o:melt.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mmelt_melt.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o melt_melt.o melt.cc

../src/Wrapper/melt_PredictorFactory.o:../src/Wrapper/PredictorFactory.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Wrapper/melt_PredictorFactory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Wrapper/melt_PredictorFactory.o ../src/Wrapper/PredictorFactory.cpp

../src/Testers/melt_ClassifierTester.o:../src/Testers/ClassifierTester.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Testers/melt_ClassifierTester.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Testers/melt_ClassifierTester.o ../src/Testers/ClassifierTester.cpp

../src/Prediction/Normalization/melt_BinNormalizer.o:../src/Prediction/Normalization/BinNormalizer.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Prediction/Normalization/melt_BinNormalizer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Prediction/Normalization/melt_BinNormalizer.o ../src/Prediction/Normalization/BinNormalizer.cpp

../src/Predictors/melt_LibSVMPredictor.o:../src/Predictors/LibSVMPredictor.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Predictors/melt_LibSVMPredictor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Predictors/melt_LibSVMPredictor.o ../src/Predictors/LibSVMPredictor.cpp

../src/Predictors/melt_VWPredictor.o:../src/Predictors/VWPredictor.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Predictors/melt_VWPredictor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Predictors/melt_VWPredictor.o ../src/Predictors/VWPredictor.cpp

melt.debug_melt.o:melt.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mmelt.debug_melt.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o melt.debug_melt.o melt.cc

../src/Wrapper/melt.debug_PredictorFactory.o:../src/Wrapper/PredictorFactory.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Wrapper/melt.debug_PredictorFactory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/Wrapper/melt.debug_PredictorFactory.o ../src/Wrapper/PredictorFactory.cpp

../src/Testers/melt.debug_ClassifierTester.o:../src/Testers/ClassifierTester.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Testers/melt.debug_ClassifierTester.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/Testers/melt.debug_ClassifierTester.o ../src/Testers/ClassifierTester.cpp

../src/Prediction/Normalization/melt.debug_BinNormalizer.o:../src/Prediction/Normalization/BinNormalizer.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Prediction/Normalization/melt.debug_BinNormalizer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/Prediction/Normalization/melt.debug_BinNormalizer.o ../src/Prediction/Normalization/BinNormalizer.cpp

../src/Predictors/melt.debug_LibSVMPredictor.o:../src/Predictors/LibSVMPredictor.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Predictors/melt.debug_LibSVMPredictor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/Predictors/melt.debug_LibSVMPredictor.o ../src/Predictors/LibSVMPredictor.cpp

../src/Predictors/melt.debug_VWPredictor.o:../src/Predictors/VWPredictor.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Predictors/melt.debug_VWPredictor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/Predictors/melt.debug_VWPredictor.o ../src/Predictors/VWPredictor.cpp

../src/vowpalwabbit/melt.debug_accumulate.o:../src/vowpalwabbit/accumulate.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_accumulate.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_accumulate.o ../src/vowpalwabbit/accumulate.cc

../src/vowpalwabbit/melt.debug_active.o:../src/vowpalwabbit/active.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_active.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_active.o ../src/vowpalwabbit/active.cc

../src/vowpalwabbit/melt.debug_allreduce.o:../src/vowpalwabbit/allreduce.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_allreduce.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_allreduce.o ../src/vowpalwabbit/allreduce.cc

../src/vowpalwabbit/melt.debug_autolink.o:../src/vowpalwabbit/autolink.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_autolink.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_autolink.o ../src/vowpalwabbit/autolink.cc

../src/vowpalwabbit/melt.debug_bfgs.o:../src/vowpalwabbit/bfgs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_bfgs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_bfgs.o ../src/vowpalwabbit/bfgs.cc

../src/vowpalwabbit/melt.debug_binary.o:../src/vowpalwabbit/binary.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_binary.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_binary.o ../src/vowpalwabbit/binary.cc

../src/vowpalwabbit/melt.debug_bs.o:../src/vowpalwabbit/bs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_bs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_bs.o ../src/vowpalwabbit/bs.cc

../src/vowpalwabbit/melt.debug_cache.o:../src/vowpalwabbit/cache.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_cache.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_cache.o ../src/vowpalwabbit/cache.cc

../src/vowpalwabbit/melt.debug_cb.o:../src/vowpalwabbit/cb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_cb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_cb.o ../src/vowpalwabbit/cb.cc

../src/vowpalwabbit/melt.debug_cb_algs.o:../src/vowpalwabbit/cb_algs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_cb_algs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_cb_algs.o ../src/vowpalwabbit/cb_algs.cc

../src/vowpalwabbit/melt.debug_cbify.o:../src/vowpalwabbit/cbify.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_cbify.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_cbify.o ../src/vowpalwabbit/cbify.cc

../src/vowpalwabbit/melt.debug_cost_sensitive.o:../src/vowpalwabbit/cost_sensitive.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_cost_sensitive.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_cost_sensitive.o ../src/vowpalwabbit/cost_sensitive.cc

../src/vowpalwabbit/melt.debug_csoaa.o:../src/vowpalwabbit/csoaa.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_csoaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_csoaa.o ../src/vowpalwabbit/csoaa.cc

../src/vowpalwabbit/melt.debug_ect.o:../src/vowpalwabbit/ect.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_ect.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_ect.o ../src/vowpalwabbit/ect.cc

../src/vowpalwabbit/melt.debug_example.o:../src/vowpalwabbit/example.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_example.o ../src/vowpalwabbit/example.cc

../src/vowpalwabbit/melt.debug_gd.o:../src/vowpalwabbit/gd.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_gd.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_gd.o ../src/vowpalwabbit/gd.cc

../src/vowpalwabbit/melt.debug_gd_mf.o:../src/vowpalwabbit/gd_mf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_gd_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_gd_mf.o ../src/vowpalwabbit/gd_mf.cc

../src/vowpalwabbit/melt.debug_global_data.o:../src/vowpalwabbit/global_data.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_global_data.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_global_data.o ../src/vowpalwabbit/global_data.cc

../src/vowpalwabbit/melt.debug_hash.o:../src/vowpalwabbit/hash.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_hash.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_hash.o ../src/vowpalwabbit/hash.cc

../src/vowpalwabbit/melt.debug_io_buf.o:../src/vowpalwabbit/io_buf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_io_buf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_io_buf.o ../src/vowpalwabbit/io_buf.cc

../src/vowpalwabbit/melt.debug_kernel_svm.o:../src/vowpalwabbit/kernel_svm.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_kernel_svm.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_kernel_svm.o ../src/vowpalwabbit/kernel_svm.cc

../src/vowpalwabbit/melt.debug_lda_core.o:../src/vowpalwabbit/lda_core.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_lda_core.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_lda_core.o ../src/vowpalwabbit/lda_core.cc

../src/vowpalwabbit/melt.debug_learner.o:../src/vowpalwabbit/learner.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_learner.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_learner.o ../src/vowpalwabbit/learner.cc

../src/vowpalwabbit/melt.debug_log_multi.o:../src/vowpalwabbit/log_multi.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_log_multi.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_log_multi.o ../src/vowpalwabbit/log_multi.cc

../src/vowpalwabbit/melt.debug_loss_functions.o:../src/vowpalwabbit/loss_functions.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_loss_functions.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_loss_functions.o ../src/vowpalwabbit/loss_functions.cc

../src/vowpalwabbit/melt.debug_lrq.o:../src/vowpalwabbit/lrq.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_lrq.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_lrq.o ../src/vowpalwabbit/lrq.cc

../src/vowpalwabbit/melt.debug_memory.o:../src/vowpalwabbit/memory.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_memory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_memory.o ../src/vowpalwabbit/memory.cc

../src/vowpalwabbit/melt.debug_mf.o:../src/vowpalwabbit/mf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_mf.o ../src/vowpalwabbit/mf.cc

../src/vowpalwabbit/melt.debug_multiclass.o:../src/vowpalwabbit/multiclass.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_multiclass.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_multiclass.o ../src/vowpalwabbit/multiclass.cc

../src/vowpalwabbit/melt.debug_network.o:../src/vowpalwabbit/network.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_network.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_network.o ../src/vowpalwabbit/network.cc

../src/vowpalwabbit/melt.debug_nn.o:../src/vowpalwabbit/nn.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_nn.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_nn.o ../src/vowpalwabbit/nn.cc

../src/vowpalwabbit/melt.debug_noop.o:../src/vowpalwabbit/noop.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_noop.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_noop.o ../src/vowpalwabbit/noop.cc

../src/vowpalwabbit/melt.debug_oaa.o:../src/vowpalwabbit/oaa.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_oaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_oaa.o ../src/vowpalwabbit/oaa.cc

../src/vowpalwabbit/melt.debug_parse_args.o:../src/vowpalwabbit/parse_args.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_parse_args.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_parse_args.o ../src/vowpalwabbit/parse_args.cc

../src/vowpalwabbit/melt.debug_parse_example.o:../src/vowpalwabbit/parse_example.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_parse_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_parse_example.o ../src/vowpalwabbit/parse_example.cc

../src/vowpalwabbit/melt.debug_parse_primitives.o:../src/vowpalwabbit/parse_primitives.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_parse_primitives.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_parse_primitives.o ../src/vowpalwabbit/parse_primitives.cc

../src/vowpalwabbit/melt.debug_parse_regressor.o:../src/vowpalwabbit/parse_regressor.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_parse_regressor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_parse_regressor.o ../src/vowpalwabbit/parse_regressor.cc

../src/vowpalwabbit/melt.debug_parser.o:../src/vowpalwabbit/parser.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_parser.o ../src/vowpalwabbit/parser.cc

../src/vowpalwabbit/melt.debug_print.o:../src/vowpalwabbit/print.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_print.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_print.o ../src/vowpalwabbit/print.cc

../src/vowpalwabbit/melt.debug_rand48.o:../src/vowpalwabbit/rand48.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_rand48.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_rand48.o ../src/vowpalwabbit/rand48.cc

../src/vowpalwabbit/melt.debug_scorer.o:../src/vowpalwabbit/scorer.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_scorer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_scorer.o ../src/vowpalwabbit/scorer.cc

../src/vowpalwabbit/melt.debug_search.o:../src/vowpalwabbit/search.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_search.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_search.o ../src/vowpalwabbit/search.cc

../src/vowpalwabbit/melt.debug_search_dep_parser.o:../src/vowpalwabbit/search_dep_parser.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_search_dep_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_search_dep_parser.o ../src/vowpalwabbit/search_dep_parser.cc

../src/vowpalwabbit/melt.debug_search_entityrelationtask.o:../src/vowpalwabbit/search_entityrelationtask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_search_entityrelationtask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_search_entityrelationtask.o ../src/vowpalwabbit/search_entityrelationtask.cc

../src/vowpalwabbit/melt.debug_search_hooktask.o:../src/vowpalwabbit/search_hooktask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_search_hooktask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_search_hooktask.o ../src/vowpalwabbit/search_hooktask.cc

../src/vowpalwabbit/melt.debug_search_multiclasstask.o:../src/vowpalwabbit/search_multiclasstask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_search_multiclasstask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_search_multiclasstask.o ../src/vowpalwabbit/search_multiclasstask.cc

../src/vowpalwabbit/melt.debug_search_sequencetask.o:../src/vowpalwabbit/search_sequencetask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_search_sequencetask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_search_sequencetask.o ../src/vowpalwabbit/search_sequencetask.cc

../src/vowpalwabbit/melt.debug_sender.o:../src/vowpalwabbit/sender.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_sender.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_sender.o ../src/vowpalwabbit/sender.cc

../src/vowpalwabbit/melt.debug_simple_label.o:../src/vowpalwabbit/simple_label.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_simple_label.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_simple_label.o ../src/vowpalwabbit/simple_label.cc

../src/vowpalwabbit/melt.debug_stagewise_poly.o:../src/vowpalwabbit/stagewise_poly.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_stagewise_poly.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_stagewise_poly.o ../src/vowpalwabbit/stagewise_poly.cc

../src/vowpalwabbit/melt.debug_topk.o:../src/vowpalwabbit/topk.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_topk.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_topk.o ../src/vowpalwabbit/topk.cc

../src/vowpalwabbit/melt.debug_unique_sort.o:../src/vowpalwabbit/unique_sort.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/melt.debug_unique_sort.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/melt.debug_unique_sort.o ../src/vowpalwabbit/unique_sort.cc

vw_vw.o:vw.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mvw_vw.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o vw_vw.o vw.cc

../src/Wrapper/vw_PredictorFactory.o:../src/Wrapper/PredictorFactory.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Wrapper/vw_PredictorFactory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Wrapper/vw_PredictorFactory.o ../src/Wrapper/PredictorFactory.cpp

../src/Testers/vw_ClassifierTester.o:../src/Testers/ClassifierTester.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Testers/vw_ClassifierTester.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Testers/vw_ClassifierTester.o ../src/Testers/ClassifierTester.cpp

../src/Prediction/Normalization/vw_BinNormalizer.o:../src/Prediction/Normalization/BinNormalizer.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Prediction/Normalization/vw_BinNormalizer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Prediction/Normalization/vw_BinNormalizer.o ../src/Prediction/Normalization/BinNormalizer.cpp

../src/Predictors/vw_LibSVMPredictor.o:../src/Predictors/LibSVMPredictor.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Predictors/vw_LibSVMPredictor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Predictors/vw_LibSVMPredictor.o ../src/Predictors/LibSVMPredictor.cpp

../src/Predictors/vw_VWPredictor.o:../src/Predictors/VWPredictor.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/Predictors/vw_VWPredictor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/Predictors/vw_VWPredictor.o ../src/Predictors/VWPredictor.cpp

../src/vowpalwabbit/vw_accumulate.o:../src/vowpalwabbit/accumulate.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_accumulate.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_accumulate.o ../src/vowpalwabbit/accumulate.cc

../src/vowpalwabbit/vw_active.o:../src/vowpalwabbit/active.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_active.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_active.o ../src/vowpalwabbit/active.cc

../src/vowpalwabbit/vw_allreduce.o:../src/vowpalwabbit/allreduce.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_allreduce.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_allreduce.o ../src/vowpalwabbit/allreduce.cc

../src/vowpalwabbit/vw_autolink.o:../src/vowpalwabbit/autolink.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_autolink.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_autolink.o ../src/vowpalwabbit/autolink.cc

../src/vowpalwabbit/vw_bfgs.o:../src/vowpalwabbit/bfgs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_bfgs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_bfgs.o ../src/vowpalwabbit/bfgs.cc

../src/vowpalwabbit/vw_binary.o:../src/vowpalwabbit/binary.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_binary.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_binary.o ../src/vowpalwabbit/binary.cc

../src/vowpalwabbit/vw_bs.o:../src/vowpalwabbit/bs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_bs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_bs.o ../src/vowpalwabbit/bs.cc

../src/vowpalwabbit/vw_cache.o:../src/vowpalwabbit/cache.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_cache.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_cache.o ../src/vowpalwabbit/cache.cc

../src/vowpalwabbit/vw_cb.o:../src/vowpalwabbit/cb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_cb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_cb.o ../src/vowpalwabbit/cb.cc

../src/vowpalwabbit/vw_cb_algs.o:../src/vowpalwabbit/cb_algs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_cb_algs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_cb_algs.o ../src/vowpalwabbit/cb_algs.cc

../src/vowpalwabbit/vw_cbify.o:../src/vowpalwabbit/cbify.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_cbify.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_cbify.o ../src/vowpalwabbit/cbify.cc

../src/vowpalwabbit/vw_cost_sensitive.o:../src/vowpalwabbit/cost_sensitive.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_cost_sensitive.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_cost_sensitive.o ../src/vowpalwabbit/cost_sensitive.cc

../src/vowpalwabbit/vw_csoaa.o:../src/vowpalwabbit/csoaa.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_csoaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_csoaa.o ../src/vowpalwabbit/csoaa.cc

../src/vowpalwabbit/vw_ect.o:../src/vowpalwabbit/ect.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_ect.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_ect.o ../src/vowpalwabbit/ect.cc

../src/vowpalwabbit/vw_example.o:../src/vowpalwabbit/example.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_example.o ../src/vowpalwabbit/example.cc

../src/vowpalwabbit/vw_gd.o:../src/vowpalwabbit/gd.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_gd.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_gd.o ../src/vowpalwabbit/gd.cc

../src/vowpalwabbit/vw_gd_mf.o:../src/vowpalwabbit/gd_mf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_gd_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_gd_mf.o ../src/vowpalwabbit/gd_mf.cc

../src/vowpalwabbit/vw_global_data.o:../src/vowpalwabbit/global_data.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_global_data.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_global_data.o ../src/vowpalwabbit/global_data.cc

../src/vowpalwabbit/vw_hash.o:../src/vowpalwabbit/hash.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_hash.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_hash.o ../src/vowpalwabbit/hash.cc

../src/vowpalwabbit/vw_io_buf.o:../src/vowpalwabbit/io_buf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_io_buf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_io_buf.o ../src/vowpalwabbit/io_buf.cc

../src/vowpalwabbit/vw_kernel_svm.o:../src/vowpalwabbit/kernel_svm.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_kernel_svm.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_kernel_svm.o ../src/vowpalwabbit/kernel_svm.cc

../src/vowpalwabbit/vw_lda_core.o:../src/vowpalwabbit/lda_core.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_lda_core.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_lda_core.o ../src/vowpalwabbit/lda_core.cc

../src/vowpalwabbit/vw_learner.o:../src/vowpalwabbit/learner.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_learner.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_learner.o ../src/vowpalwabbit/learner.cc

../src/vowpalwabbit/vw_log_multi.o:../src/vowpalwabbit/log_multi.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_log_multi.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_log_multi.o ../src/vowpalwabbit/log_multi.cc

../src/vowpalwabbit/vw_loss_functions.o:../src/vowpalwabbit/loss_functions.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_loss_functions.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_loss_functions.o ../src/vowpalwabbit/loss_functions.cc

../src/vowpalwabbit/vw_lrq.o:../src/vowpalwabbit/lrq.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_lrq.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_lrq.o ../src/vowpalwabbit/lrq.cc

../src/vowpalwabbit/vw_memory.o:../src/vowpalwabbit/memory.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_memory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_memory.o ../src/vowpalwabbit/memory.cc

../src/vowpalwabbit/vw_mf.o:../src/vowpalwabbit/mf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_mf.o ../src/vowpalwabbit/mf.cc

../src/vowpalwabbit/vw_multiclass.o:../src/vowpalwabbit/multiclass.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_multiclass.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_multiclass.o ../src/vowpalwabbit/multiclass.cc

../src/vowpalwabbit/vw_network.o:../src/vowpalwabbit/network.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_network.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_network.o ../src/vowpalwabbit/network.cc

../src/vowpalwabbit/vw_nn.o:../src/vowpalwabbit/nn.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_nn.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_nn.o ../src/vowpalwabbit/nn.cc

../src/vowpalwabbit/vw_noop.o:../src/vowpalwabbit/noop.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_noop.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_noop.o ../src/vowpalwabbit/noop.cc

../src/vowpalwabbit/vw_oaa.o:../src/vowpalwabbit/oaa.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_oaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_oaa.o ../src/vowpalwabbit/oaa.cc

../src/vowpalwabbit/vw_parse_args.o:../src/vowpalwabbit/parse_args.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_parse_args.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_parse_args.o ../src/vowpalwabbit/parse_args.cc

../src/vowpalwabbit/vw_parse_example.o:../src/vowpalwabbit/parse_example.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_parse_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_parse_example.o ../src/vowpalwabbit/parse_example.cc

../src/vowpalwabbit/vw_parse_primitives.o:../src/vowpalwabbit/parse_primitives.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_parse_primitives.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_parse_primitives.o ../src/vowpalwabbit/parse_primitives.cc

../src/vowpalwabbit/vw_parse_regressor.o:../src/vowpalwabbit/parse_regressor.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_parse_regressor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_parse_regressor.o ../src/vowpalwabbit/parse_regressor.cc

../src/vowpalwabbit/vw_parser.o:../src/vowpalwabbit/parser.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_parser.o ../src/vowpalwabbit/parser.cc

../src/vowpalwabbit/vw_print.o:../src/vowpalwabbit/print.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_print.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_print.o ../src/vowpalwabbit/print.cc

../src/vowpalwabbit/vw_rand48.o:../src/vowpalwabbit/rand48.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_rand48.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_rand48.o ../src/vowpalwabbit/rand48.cc

../src/vowpalwabbit/vw_scorer.o:../src/vowpalwabbit/scorer.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_scorer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_scorer.o ../src/vowpalwabbit/scorer.cc

../src/vowpalwabbit/vw_search.o:../src/vowpalwabbit/search.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_search.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_search.o ../src/vowpalwabbit/search.cc

../src/vowpalwabbit/vw_search_dep_parser.o:../src/vowpalwabbit/search_dep_parser.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_search_dep_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_search_dep_parser.o ../src/vowpalwabbit/search_dep_parser.cc

../src/vowpalwabbit/vw_search_entityrelationtask.o:../src/vowpalwabbit/search_entityrelationtask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_search_entityrelationtask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_search_entityrelationtask.o ../src/vowpalwabbit/search_entityrelationtask.cc

../src/vowpalwabbit/vw_search_hooktask.o:../src/vowpalwabbit/search_hooktask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_search_hooktask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_search_hooktask.o ../src/vowpalwabbit/search_hooktask.cc

../src/vowpalwabbit/vw_search_multiclasstask.o:../src/vowpalwabbit/search_multiclasstask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_search_multiclasstask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_search_multiclasstask.o ../src/vowpalwabbit/search_multiclasstask.cc

../src/vowpalwabbit/vw_search_sequencetask.o:../src/vowpalwabbit/search_sequencetask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_search_sequencetask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_search_sequencetask.o ../src/vowpalwabbit/search_sequencetask.cc

../src/vowpalwabbit/vw_sender.o:../src/vowpalwabbit/sender.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_sender.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_sender.o ../src/vowpalwabbit/sender.cc

../src/vowpalwabbit/vw_simple_label.o:../src/vowpalwabbit/simple_label.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_simple_label.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_simple_label.o ../src/vowpalwabbit/simple_label.cc

../src/vowpalwabbit/vw_stagewise_poly.o:../src/vowpalwabbit/stagewise_poly.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_stagewise_poly.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_stagewise_poly.o ../src/vowpalwabbit/stagewise_poly.cc

../src/vowpalwabbit/vw_topk.o:../src/vowpalwabbit/topk.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_topk.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_topk.o ../src/vowpalwabbit/topk.cc

../src/vowpalwabbit/vw_unique_sort.o:../src/vowpalwabbit/unique_sort.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw_unique_sort.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ../src/vowpalwabbit/vw_unique_sort.o ../src/vowpalwabbit/unique_sort.cc

vw.debug_vw.o:vw.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mvw.debug_vw.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o vw.debug_vw.o vw.cc

../src/vowpalwabbit/vw.debug_accumulate.o:../src/vowpalwabbit/accumulate.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_accumulate.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_accumulate.o ../src/vowpalwabbit/accumulate.cc

../src/vowpalwabbit/vw.debug_active.o:../src/vowpalwabbit/active.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_active.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_active.o ../src/vowpalwabbit/active.cc

../src/vowpalwabbit/vw.debug_allreduce.o:../src/vowpalwabbit/allreduce.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_allreduce.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_allreduce.o ../src/vowpalwabbit/allreduce.cc

../src/vowpalwabbit/vw.debug_autolink.o:../src/vowpalwabbit/autolink.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_autolink.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_autolink.o ../src/vowpalwabbit/autolink.cc

../src/vowpalwabbit/vw.debug_bfgs.o:../src/vowpalwabbit/bfgs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_bfgs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_bfgs.o ../src/vowpalwabbit/bfgs.cc

../src/vowpalwabbit/vw.debug_binary.o:../src/vowpalwabbit/binary.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_binary.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_binary.o ../src/vowpalwabbit/binary.cc

../src/vowpalwabbit/vw.debug_bs.o:../src/vowpalwabbit/bs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_bs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_bs.o ../src/vowpalwabbit/bs.cc

../src/vowpalwabbit/vw.debug_cache.o:../src/vowpalwabbit/cache.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_cache.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_cache.o ../src/vowpalwabbit/cache.cc

../src/vowpalwabbit/vw.debug_cb.o:../src/vowpalwabbit/cb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_cb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_cb.o ../src/vowpalwabbit/cb.cc

../src/vowpalwabbit/vw.debug_cb_algs.o:../src/vowpalwabbit/cb_algs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_cb_algs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_cb_algs.o ../src/vowpalwabbit/cb_algs.cc

../src/vowpalwabbit/vw.debug_cbify.o:../src/vowpalwabbit/cbify.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_cbify.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_cbify.o ../src/vowpalwabbit/cbify.cc

../src/vowpalwabbit/vw.debug_cost_sensitive.o:../src/vowpalwabbit/cost_sensitive.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_cost_sensitive.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_cost_sensitive.o ../src/vowpalwabbit/cost_sensitive.cc

../src/vowpalwabbit/vw.debug_csoaa.o:../src/vowpalwabbit/csoaa.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_csoaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_csoaa.o ../src/vowpalwabbit/csoaa.cc

../src/vowpalwabbit/vw.debug_ect.o:../src/vowpalwabbit/ect.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_ect.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_ect.o ../src/vowpalwabbit/ect.cc

../src/vowpalwabbit/vw.debug_example.o:../src/vowpalwabbit/example.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_example.o ../src/vowpalwabbit/example.cc

../src/vowpalwabbit/vw.debug_gd.o:../src/vowpalwabbit/gd.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_gd.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_gd.o ../src/vowpalwabbit/gd.cc

../src/vowpalwabbit/vw.debug_gd_mf.o:../src/vowpalwabbit/gd_mf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_gd_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_gd_mf.o ../src/vowpalwabbit/gd_mf.cc

../src/vowpalwabbit/vw.debug_global_data.o:../src/vowpalwabbit/global_data.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_global_data.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_global_data.o ../src/vowpalwabbit/global_data.cc

../src/vowpalwabbit/vw.debug_hash.o:../src/vowpalwabbit/hash.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_hash.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_hash.o ../src/vowpalwabbit/hash.cc

../src/vowpalwabbit/vw.debug_io_buf.o:../src/vowpalwabbit/io_buf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_io_buf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_io_buf.o ../src/vowpalwabbit/io_buf.cc

../src/vowpalwabbit/vw.debug_kernel_svm.o:../src/vowpalwabbit/kernel_svm.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_kernel_svm.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_kernel_svm.o ../src/vowpalwabbit/kernel_svm.cc

../src/vowpalwabbit/vw.debug_lda_core.o:../src/vowpalwabbit/lda_core.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_lda_core.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_lda_core.o ../src/vowpalwabbit/lda_core.cc

../src/vowpalwabbit/vw.debug_learner.o:../src/vowpalwabbit/learner.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_learner.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_learner.o ../src/vowpalwabbit/learner.cc

../src/vowpalwabbit/vw.debug_log_multi.o:../src/vowpalwabbit/log_multi.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_log_multi.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_log_multi.o ../src/vowpalwabbit/log_multi.cc

../src/vowpalwabbit/vw.debug_loss_functions.o:../src/vowpalwabbit/loss_functions.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_loss_functions.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_loss_functions.o ../src/vowpalwabbit/loss_functions.cc

../src/vowpalwabbit/vw.debug_lrq.o:../src/vowpalwabbit/lrq.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_lrq.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_lrq.o ../src/vowpalwabbit/lrq.cc

../src/vowpalwabbit/vw.debug_memory.o:../src/vowpalwabbit/memory.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_memory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_memory.o ../src/vowpalwabbit/memory.cc

../src/vowpalwabbit/vw.debug_mf.o:../src/vowpalwabbit/mf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_mf.o ../src/vowpalwabbit/mf.cc

../src/vowpalwabbit/vw.debug_multiclass.o:../src/vowpalwabbit/multiclass.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_multiclass.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_multiclass.o ../src/vowpalwabbit/multiclass.cc

../src/vowpalwabbit/vw.debug_network.o:../src/vowpalwabbit/network.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_network.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_network.o ../src/vowpalwabbit/network.cc

../src/vowpalwabbit/vw.debug_nn.o:../src/vowpalwabbit/nn.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_nn.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_nn.o ../src/vowpalwabbit/nn.cc

../src/vowpalwabbit/vw.debug_noop.o:../src/vowpalwabbit/noop.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_noop.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_noop.o ../src/vowpalwabbit/noop.cc

../src/vowpalwabbit/vw.debug_oaa.o:../src/vowpalwabbit/oaa.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_oaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_oaa.o ../src/vowpalwabbit/oaa.cc

../src/vowpalwabbit/vw.debug_parse_args.o:../src/vowpalwabbit/parse_args.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_parse_args.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_parse_args.o ../src/vowpalwabbit/parse_args.cc

../src/vowpalwabbit/vw.debug_parse_example.o:../src/vowpalwabbit/parse_example.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_parse_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_parse_example.o ../src/vowpalwabbit/parse_example.cc

../src/vowpalwabbit/vw.debug_parse_primitives.o:../src/vowpalwabbit/parse_primitives.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_parse_primitives.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_parse_primitives.o ../src/vowpalwabbit/parse_primitives.cc

../src/vowpalwabbit/vw.debug_parse_regressor.o:../src/vowpalwabbit/parse_regressor.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_parse_regressor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_parse_regressor.o ../src/vowpalwabbit/parse_regressor.cc

../src/vowpalwabbit/vw.debug_parser.o:../src/vowpalwabbit/parser.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_parser.o ../src/vowpalwabbit/parser.cc

../src/vowpalwabbit/vw.debug_print.o:../src/vowpalwabbit/print.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_print.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_print.o ../src/vowpalwabbit/print.cc

../src/vowpalwabbit/vw.debug_rand48.o:../src/vowpalwabbit/rand48.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_rand48.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_rand48.o ../src/vowpalwabbit/rand48.cc

../src/vowpalwabbit/vw.debug_scorer.o:../src/vowpalwabbit/scorer.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_scorer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_scorer.o ../src/vowpalwabbit/scorer.cc

../src/vowpalwabbit/vw.debug_search.o:../src/vowpalwabbit/search.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_search.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_search.o ../src/vowpalwabbit/search.cc

../src/vowpalwabbit/vw.debug_search_dep_parser.o:../src/vowpalwabbit/search_dep_parser.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_search_dep_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_search_dep_parser.o ../src/vowpalwabbit/search_dep_parser.cc

../src/vowpalwabbit/vw.debug_search_entityrelationtask.o:../src/vowpalwabbit/search_entityrelationtask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_search_entityrelationtask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_search_entityrelationtask.o ../src/vowpalwabbit/search_entityrelationtask.cc

../src/vowpalwabbit/vw.debug_search_hooktask.o:../src/vowpalwabbit/search_hooktask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_search_hooktask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_search_hooktask.o ../src/vowpalwabbit/search_hooktask.cc

../src/vowpalwabbit/vw.debug_search_multiclasstask.o:../src/vowpalwabbit/search_multiclasstask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_search_multiclasstask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_search_multiclasstask.o ../src/vowpalwabbit/search_multiclasstask.cc

../src/vowpalwabbit/vw.debug_search_sequencetask.o:../src/vowpalwabbit/search_sequencetask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_search_sequencetask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_search_sequencetask.o ../src/vowpalwabbit/search_sequencetask.cc

../src/vowpalwabbit/vw.debug_sender.o:../src/vowpalwabbit/sender.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_sender.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_sender.o ../src/vowpalwabbit/sender.cc

../src/vowpalwabbit/vw.debug_simple_label.o:../src/vowpalwabbit/simple_label.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_simple_label.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_simple_label.o ../src/vowpalwabbit/simple_label.cc

../src/vowpalwabbit/vw.debug_stagewise_poly.o:../src/vowpalwabbit/stagewise_poly.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_stagewise_poly.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_stagewise_poly.o ../src/vowpalwabbit/stagewise_poly.cc

../src/vowpalwabbit/vw.debug_topk.o:../src/vowpalwabbit/topk.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_topk.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_topk.o ../src/vowpalwabbit/topk.cc

../src/vowpalwabbit/vw.debug_unique_sort.o:../src/vowpalwabbit/unique_sort.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m../src/vowpalwabbit/vw.debug_unique_sort.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O0 $(CXXFLAGS)  -o ../src/vowpalwabbit/vw.debug_unique_sort.o ../src/vowpalwabbit/unique_sort.cc

endif #ifeq ($(shell uname -m),x86_64)


