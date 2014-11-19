#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=/opt/compiler/gcc-4.8.2/bin/g++
CXX=/opt/compiler/gcc-4.8.2/bin/g++
CXXFLAGS=-g \
  -O4 \
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
  -Wno-unused-local-typedefs
CFLAGS=-g \
  -O4 \
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
  -Wno-unused-local-typedefs
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\"
INCPATH=-I./ \
  -I./include/ \
  -I./include/vowpalwabbit/ \
  -I./include/sofia/
DEP_INCPATH=-I../../../../../app/search/sep/anti-spam/gezi \
  -I../../../../../app/search/sep/anti-spam/gezi/include \
  -I../../../../../app/search/sep/anti-spam/gezi/output \
  -I../../../../../app/search/sep/anti-spam/gezi/output/include \
  -I../../../../../com/btest/gtest \
  -I../../../../../com/btest/gtest/include \
  -I../../../../../com/btest/gtest/output \
  -I../../../../../com/btest/gtest/output/include \
  -I../../../../../lib2-64/bsl \
  -I../../../../../lib2-64/bsl/include \
  -I../../../../../lib2-64/bsl/output \
  -I../../../../../lib2-64/bsl/output/include \
  -I../../../../../lib2-64/ccode \
  -I../../../../../lib2-64/ccode/include \
  -I../../../../../lib2-64/ccode/output \
  -I../../../../../lib2-64/ccode/output/include \
  -I../../../../../lib2-64/dict \
  -I../../../../../lib2-64/dict/include \
  -I../../../../../lib2-64/dict/output \
  -I../../../../../lib2-64/dict/output/include \
  -I../../../../../lib2-64/libcrf \
  -I../../../../../lib2-64/libcrf/include \
  -I../../../../../lib2-64/libcrf/output \
  -I../../../../../lib2-64/libcrf/output/include \
  -I../../../../../lib2-64/others-ex \
  -I../../../../../lib2-64/others-ex/include \
  -I../../../../../lib2-64/others-ex/output \
  -I../../../../../lib2-64/others-ex/output/include \
  -I../../../../../lib2-64/postag \
  -I../../../../../lib2-64/postag/include \
  -I../../../../../lib2-64/postag/output \
  -I../../../../../lib2-64/postag/output/include \
  -I../../../../../lib2-64/ullib \
  -I../../../../../lib2-64/ullib/include \
  -I../../../../../lib2-64/ullib/output \
  -I../../../../../lib2-64/ullib/output/include \
  -I../../../../../lib2-64/wordseg \
  -I../../../../../lib2-64/wordseg/include \
  -I../../../../../lib2-64/wordseg/output \
  -I../../../../../lib2-64/wordseg/output/include \
  -I../../../../../ps/se/toolchain \
  -I../../../../../ps/se/toolchain/include \
  -I../../../../../ps/se/toolchain/output \
  -I../../../../../ps/se/toolchain/output/include \
  -I../../../../../public/comlog-plugin \
  -I../../../../../public/comlog-plugin/include \
  -I../../../../../public/comlog-plugin/output \
  -I../../../../../public/comlog-plugin/output/include \
  -I../../../../../public/configure \
  -I../../../../../public/configure/include \
  -I../../../../../public/configure/output \
  -I../../../../../public/configure/output/include \
  -I../../../../../public/connectpool \
  -I../../../../../public/connectpool/include \
  -I../../../../../public/connectpool/output \
  -I../../../../../public/connectpool/output/include \
  -I../../../../../public/odict \
  -I../../../../../public/odict/include \
  -I../../../../../public/odict/output \
  -I../../../../../public/odict/output/include \
  -I../../../../../public/spreg \
  -I../../../../../public/spreg/include \
  -I../../../../../public/spreg/output \
  -I../../../../../public/spreg/output/include \
  -I../../../../../public/uconv \
  -I../../../../../public/uconv/include \
  -I../../../../../public/uconv/output \
  -I../../../../../public/uconv/output/include \
  -I../../../../../quality/autotest/reportlib/cpp \
  -I../../../../../quality/autotest/reportlib/cpp/include \
  -I../../../../../quality/autotest/reportlib/cpp/output \
  -I../../../../../quality/autotest/reportlib/cpp/output/include \
  -I../../../../../third-64/boost \
  -I../../../../../third-64/boost/include \
  -I../../../../../third-64/boost/output \
  -I../../../../../third-64/boost/output/include \
  -I../../../../../third-64/gflags \
  -I../../../../../third-64/gflags/include \
  -I../../../../../third-64/gflags/output \
  -I../../../../../third-64/gflags/output/include \
  -I../../../../../third-64/glog \
  -I../../../../../third-64/glog/include \
  -I../../../../../third-64/glog/output \
  -I../../../../../third-64/glog/output/include \
  -I../../../../../third-64/libcurl \
  -I../../../../../third-64/libcurl/include \
  -I../../../../../third-64/libcurl/output \
  -I../../../../../third-64/libcurl/output/include \
  -I../../../../../third-64/pcre \
  -I../../../../../third-64/pcre/include \
  -I../../../../../third-64/pcre/output \
  -I../../../../../third-64/pcre/output/include \
  -I../../../../../third-64/tcmalloc \
  -I../../../../../third-64/tcmalloc/include \
  -I../../../../../third-64/tcmalloc/output \
  -I../../../../../third-64/tcmalloc/output/include

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=43998f79f810c11691b150e21ab053b9  COMAKE


.PHONY:all
all:comake2_makefile_check libmelt.a libmelt_predict.a 
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
	rm -rf libmelt.a
	rm -rf ./output/lib/libmelt.a
	rm -rf libmelt_predict.a
	rm -rf ./output/lib/libmelt_predict.a
	rm -rf src/Wrapper/melt_PredictorFactory.o
	rm -rf src/Prediction/Instances/melt_InstanceParser.o
	rm -rf src/Run/melt_Melt.o
	rm -rf src/Testers/melt_ClassifierTester.o
	rm -rf src/Prediction/Normalization/melt_BinNormalizer.o
	rm -rf src/vowpalwabbit/melt_accumulate.o
	rm -rf src/vowpalwabbit/melt_active.o
	rm -rf src/vowpalwabbit/melt_active_interactor.o
	rm -rf src/vowpalwabbit/melt_allreduce.o
	rm -rf src/vowpalwabbit/melt_autolink.o
	rm -rf src/vowpalwabbit/melt_bfgs.o
	rm -rf src/vowpalwabbit/melt_binary.o
	rm -rf src/vowpalwabbit/melt_bs.o
	rm -rf src/vowpalwabbit/melt_cache.o
	rm -rf src/vowpalwabbit/melt_cb.o
	rm -rf src/vowpalwabbit/melt_cb_algs.o
	rm -rf src/vowpalwabbit/melt_cbify.o
	rm -rf src/vowpalwabbit/melt_cost_sensitive.o
	rm -rf src/vowpalwabbit/melt_csoaa.o
	rm -rf src/vowpalwabbit/melt_ect.o
	rm -rf src/vowpalwabbit/melt_example.o
	rm -rf src/vowpalwabbit/melt_gd.o
	rm -rf src/vowpalwabbit/melt_gd_mf.o
	rm -rf src/vowpalwabbit/melt_global_data.o
	rm -rf src/vowpalwabbit/melt_hash.o
	rm -rf src/vowpalwabbit/melt_io_buf.o
	rm -rf src/vowpalwabbit/melt_kernel_svm.o
	rm -rf src/vowpalwabbit/melt_lda_core.o
	rm -rf src/vowpalwabbit/melt_learner.o
	rm -rf src/vowpalwabbit/melt_log_multi.o
	rm -rf src/vowpalwabbit/melt_loss_functions.o
	rm -rf src/vowpalwabbit/melt_lrq.o
	rm -rf src/vowpalwabbit/melt_main.o
	rm -rf src/vowpalwabbit/melt_memory.o
	rm -rf src/vowpalwabbit/melt_mf.o
	rm -rf src/vowpalwabbit/melt_multiclass.o
	rm -rf src/vowpalwabbit/melt_network.o
	rm -rf src/vowpalwabbit/melt_nn.o
	rm -rf src/vowpalwabbit/melt_noop.o
	rm -rf src/vowpalwabbit/melt_oaa.o
	rm -rf src/vowpalwabbit/melt_parse_args.o
	rm -rf src/vowpalwabbit/melt_parse_example.o
	rm -rf src/vowpalwabbit/melt_parse_primitives.o
	rm -rf src/vowpalwabbit/melt_parse_regressor.o
	rm -rf src/vowpalwabbit/melt_parser.o
	rm -rf src/vowpalwabbit/melt_print.o
	rm -rf src/vowpalwabbit/melt_rand48.o
	rm -rf src/vowpalwabbit/melt_scorer.o
	rm -rf src/vowpalwabbit/melt_search.o
	rm -rf src/vowpalwabbit/melt_search_dep_parser.o
	rm -rf src/vowpalwabbit/melt_search_entityrelationtask.o
	rm -rf src/vowpalwabbit/melt_search_hooktask.o
	rm -rf src/vowpalwabbit/melt_search_multiclasstask.o
	rm -rf src/vowpalwabbit/melt_search_sequencetask.o
	rm -rf src/vowpalwabbit/melt_sender.o
	rm -rf src/vowpalwabbit/melt_simple_label.o
	rm -rf src/vowpalwabbit/melt_stagewise_poly.o
	rm -rf src/vowpalwabbit/melt_topk.o
	rm -rf src/vowpalwabbit/melt_unique_sort.o
	rm -rf src/sofia/melt_sf-data-set.o
	rm -rf src/sofia/melt_sf-data-set_test.o
	rm -rf src/sofia/melt_sf-hash-inline.o
	rm -rf src/sofia/melt_sf-hash-inline_test.o
	rm -rf src/sofia/melt_sf-hash-weight-vector.o
	rm -rf src/sofia/melt_sf-sparse-vector.o
	rm -rf src/sofia/melt_sf-sparse-vector_test.o
	rm -rf src/sofia/melt_sf-weight-vector.o
	rm -rf src/sofia/melt_sf-weight-vector_test.o
	rm -rf src/sofia/melt_simple-cmd-line-helper_test.o
	rm -rf src/sofia/melt_sofia-ml-methods.o
	rm -rf src/sofia/melt_sofia-ml-methods_test.o
	rm -rf src/sofia/melt_sofia-ml.o
	rm -rf src/Simple/melt_predict_Predictor.o
	rm -rf src/Simple/melt_predict_PredictorFactory.o

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

libmelt.a:src/Wrapper/melt_PredictorFactory.o \
  src/Prediction/Instances/melt_InstanceParser.o \
  src/Run/melt_Melt.o \
  src/Testers/melt_ClassifierTester.o \
  src/Prediction/Normalization/melt_BinNormalizer.o \
  src/vowpalwabbit/melt_accumulate.o \
  src/vowpalwabbit/melt_active.o \
  src/vowpalwabbit/melt_active_interactor.o \
  src/vowpalwabbit/melt_allreduce.o \
  src/vowpalwabbit/melt_autolink.o \
  src/vowpalwabbit/melt_bfgs.o \
  src/vowpalwabbit/melt_binary.o \
  src/vowpalwabbit/melt_bs.o \
  src/vowpalwabbit/melt_cache.o \
  src/vowpalwabbit/melt_cb.o \
  src/vowpalwabbit/melt_cb_algs.o \
  src/vowpalwabbit/melt_cbify.o \
  src/vowpalwabbit/melt_cost_sensitive.o \
  src/vowpalwabbit/melt_csoaa.o \
  src/vowpalwabbit/melt_ect.o \
  src/vowpalwabbit/melt_example.o \
  src/vowpalwabbit/melt_gd.o \
  src/vowpalwabbit/melt_gd_mf.o \
  src/vowpalwabbit/melt_global_data.o \
  src/vowpalwabbit/melt_hash.o \
  src/vowpalwabbit/melt_io_buf.o \
  src/vowpalwabbit/melt_kernel_svm.o \
  src/vowpalwabbit/melt_lda_core.o \
  src/vowpalwabbit/melt_learner.o \
  src/vowpalwabbit/melt_log_multi.o \
  src/vowpalwabbit/melt_loss_functions.o \
  src/vowpalwabbit/melt_lrq.o \
  src/vowpalwabbit/melt_main.o \
  src/vowpalwabbit/melt_memory.o \
  src/vowpalwabbit/melt_mf.o \
  src/vowpalwabbit/melt_multiclass.o \
  src/vowpalwabbit/melt_network.o \
  src/vowpalwabbit/melt_nn.o \
  src/vowpalwabbit/melt_noop.o \
  src/vowpalwabbit/melt_oaa.o \
  src/vowpalwabbit/melt_parse_args.o \
  src/vowpalwabbit/melt_parse_example.o \
  src/vowpalwabbit/melt_parse_primitives.o \
  src/vowpalwabbit/melt_parse_regressor.o \
  src/vowpalwabbit/melt_parser.o \
  src/vowpalwabbit/melt_print.o \
  src/vowpalwabbit/melt_rand48.o \
  src/vowpalwabbit/melt_scorer.o \
  src/vowpalwabbit/melt_search.o \
  src/vowpalwabbit/melt_search_dep_parser.o \
  src/vowpalwabbit/melt_search_entityrelationtask.o \
  src/vowpalwabbit/melt_search_hooktask.o \
  src/vowpalwabbit/melt_search_multiclasstask.o \
  src/vowpalwabbit/melt_search_sequencetask.o \
  src/vowpalwabbit/melt_sender.o \
  src/vowpalwabbit/melt_simple_label.o \
  src/vowpalwabbit/melt_stagewise_poly.o \
  src/vowpalwabbit/melt_topk.o \
  src/vowpalwabbit/melt_unique_sort.o \
  src/sofia/melt_sf-data-set.o \
  src/sofia/melt_sf-data-set_test.o \
  src/sofia/melt_sf-hash-inline.o \
  src/sofia/melt_sf-hash-inline_test.o \
  src/sofia/melt_sf-hash-weight-vector.o \
  src/sofia/melt_sf-sparse-vector.o \
  src/sofia/melt_sf-sparse-vector_test.o \
  src/sofia/melt_sf-weight-vector.o \
  src/sofia/melt_sf-weight-vector_test.o \
  src/sofia/melt_simple-cmd-line-helper_test.o \
  src/sofia/melt_sofia-ml-methods.o \
  src/sofia/melt_sofia-ml-methods_test.o \
  src/sofia/melt_sofia-ml.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibmelt.a[0m']"
	ar crs libmelt.a src/Wrapper/melt_PredictorFactory.o \
  src/Prediction/Instances/melt_InstanceParser.o \
  src/Run/melt_Melt.o \
  src/Testers/melt_ClassifierTester.o \
  src/Prediction/Normalization/melt_BinNormalizer.o \
  src/vowpalwabbit/melt_accumulate.o \
  src/vowpalwabbit/melt_active.o \
  src/vowpalwabbit/melt_active_interactor.o \
  src/vowpalwabbit/melt_allreduce.o \
  src/vowpalwabbit/melt_autolink.o \
  src/vowpalwabbit/melt_bfgs.o \
  src/vowpalwabbit/melt_binary.o \
  src/vowpalwabbit/melt_bs.o \
  src/vowpalwabbit/melt_cache.o \
  src/vowpalwabbit/melt_cb.o \
  src/vowpalwabbit/melt_cb_algs.o \
  src/vowpalwabbit/melt_cbify.o \
  src/vowpalwabbit/melt_cost_sensitive.o \
  src/vowpalwabbit/melt_csoaa.o \
  src/vowpalwabbit/melt_ect.o \
  src/vowpalwabbit/melt_example.o \
  src/vowpalwabbit/melt_gd.o \
  src/vowpalwabbit/melt_gd_mf.o \
  src/vowpalwabbit/melt_global_data.o \
  src/vowpalwabbit/melt_hash.o \
  src/vowpalwabbit/melt_io_buf.o \
  src/vowpalwabbit/melt_kernel_svm.o \
  src/vowpalwabbit/melt_lda_core.o \
  src/vowpalwabbit/melt_learner.o \
  src/vowpalwabbit/melt_log_multi.o \
  src/vowpalwabbit/melt_loss_functions.o \
  src/vowpalwabbit/melt_lrq.o \
  src/vowpalwabbit/melt_main.o \
  src/vowpalwabbit/melt_memory.o \
  src/vowpalwabbit/melt_mf.o \
  src/vowpalwabbit/melt_multiclass.o \
  src/vowpalwabbit/melt_network.o \
  src/vowpalwabbit/melt_nn.o \
  src/vowpalwabbit/melt_noop.o \
  src/vowpalwabbit/melt_oaa.o \
  src/vowpalwabbit/melt_parse_args.o \
  src/vowpalwabbit/melt_parse_example.o \
  src/vowpalwabbit/melt_parse_primitives.o \
  src/vowpalwabbit/melt_parse_regressor.o \
  src/vowpalwabbit/melt_parser.o \
  src/vowpalwabbit/melt_print.o \
  src/vowpalwabbit/melt_rand48.o \
  src/vowpalwabbit/melt_scorer.o \
  src/vowpalwabbit/melt_search.o \
  src/vowpalwabbit/melt_search_dep_parser.o \
  src/vowpalwabbit/melt_search_entityrelationtask.o \
  src/vowpalwabbit/melt_search_hooktask.o \
  src/vowpalwabbit/melt_search_multiclasstask.o \
  src/vowpalwabbit/melt_search_sequencetask.o \
  src/vowpalwabbit/melt_sender.o \
  src/vowpalwabbit/melt_simple_label.o \
  src/vowpalwabbit/melt_stagewise_poly.o \
  src/vowpalwabbit/melt_topk.o \
  src/vowpalwabbit/melt_unique_sort.o \
  src/sofia/melt_sf-data-set.o \
  src/sofia/melt_sf-data-set_test.o \
  src/sofia/melt_sf-hash-inline.o \
  src/sofia/melt_sf-hash-inline_test.o \
  src/sofia/melt_sf-hash-weight-vector.o \
  src/sofia/melt_sf-sparse-vector.o \
  src/sofia/melt_sf-sparse-vector_test.o \
  src/sofia/melt_sf-weight-vector.o \
  src/sofia/melt_sf-weight-vector_test.o \
  src/sofia/melt_simple-cmd-line-helper_test.o \
  src/sofia/melt_sofia-ml-methods.o \
  src/sofia/melt_sofia-ml-methods_test.o \
  src/sofia/melt_sofia-ml.o
	mkdir -p ./output/lib
	cp -f --link libmelt.a ./output/lib

libmelt_predict.a:src/Simple/melt_predict_Predictor.o \
  src/Simple/melt_predict_PredictorFactory.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibmelt_predict.a[0m']"
	ar crs libmelt_predict.a src/Simple/melt_predict_Predictor.o \
  src/Simple/melt_predict_PredictorFactory.o
	mkdir -p ./output/lib
	cp -f --link libmelt_predict.a ./output/lib

src/Wrapper/melt_PredictorFactory.o:src/Wrapper/PredictorFactory.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Wrapper/melt_PredictorFactory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/Wrapper/melt_PredictorFactory.o src/Wrapper/PredictorFactory.cpp

src/Prediction/Instances/melt_InstanceParser.o:src/Prediction/Instances/InstanceParser.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Prediction/Instances/melt_InstanceParser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/Prediction/Instances/melt_InstanceParser.o src/Prediction/Instances/InstanceParser.cpp

src/Run/melt_Melt.o:src/Run/Melt.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Run/melt_Melt.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/Run/melt_Melt.o src/Run/Melt.cpp

src/Testers/melt_ClassifierTester.o:src/Testers/ClassifierTester.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Testers/melt_ClassifierTester.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/Testers/melt_ClassifierTester.o src/Testers/ClassifierTester.cpp

src/Prediction/Normalization/melt_BinNormalizer.o:src/Prediction/Normalization/BinNormalizer.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Prediction/Normalization/melt_BinNormalizer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/Prediction/Normalization/melt_BinNormalizer.o src/Prediction/Normalization/BinNormalizer.cpp

src/vowpalwabbit/melt_accumulate.o:src/vowpalwabbit/accumulate.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_accumulate.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_accumulate.o src/vowpalwabbit/accumulate.cc

src/vowpalwabbit/melt_active.o:src/vowpalwabbit/active.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_active.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_active.o src/vowpalwabbit/active.cc

src/vowpalwabbit/melt_active_interactor.o:src/vowpalwabbit/active_interactor.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_active_interactor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_active_interactor.o src/vowpalwabbit/active_interactor.cc

src/vowpalwabbit/melt_allreduce.o:src/vowpalwabbit/allreduce.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_allreduce.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_allreduce.o src/vowpalwabbit/allreduce.cc

src/vowpalwabbit/melt_autolink.o:src/vowpalwabbit/autolink.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_autolink.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_autolink.o src/vowpalwabbit/autolink.cc

src/vowpalwabbit/melt_bfgs.o:src/vowpalwabbit/bfgs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_bfgs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_bfgs.o src/vowpalwabbit/bfgs.cc

src/vowpalwabbit/melt_binary.o:src/vowpalwabbit/binary.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_binary.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_binary.o src/vowpalwabbit/binary.cc

src/vowpalwabbit/melt_bs.o:src/vowpalwabbit/bs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_bs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_bs.o src/vowpalwabbit/bs.cc

src/vowpalwabbit/melt_cache.o:src/vowpalwabbit/cache.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_cache.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_cache.o src/vowpalwabbit/cache.cc

src/vowpalwabbit/melt_cb.o:src/vowpalwabbit/cb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_cb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_cb.o src/vowpalwabbit/cb.cc

src/vowpalwabbit/melt_cb_algs.o:src/vowpalwabbit/cb_algs.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_cb_algs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_cb_algs.o src/vowpalwabbit/cb_algs.cc

src/vowpalwabbit/melt_cbify.o:src/vowpalwabbit/cbify.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_cbify.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_cbify.o src/vowpalwabbit/cbify.cc

src/vowpalwabbit/melt_cost_sensitive.o:src/vowpalwabbit/cost_sensitive.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_cost_sensitive.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_cost_sensitive.o src/vowpalwabbit/cost_sensitive.cc

src/vowpalwabbit/melt_csoaa.o:src/vowpalwabbit/csoaa.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_csoaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_csoaa.o src/vowpalwabbit/csoaa.cc

src/vowpalwabbit/melt_ect.o:src/vowpalwabbit/ect.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_ect.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_ect.o src/vowpalwabbit/ect.cc

src/vowpalwabbit/melt_example.o:src/vowpalwabbit/example.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_example.o src/vowpalwabbit/example.cc

src/vowpalwabbit/melt_gd.o:src/vowpalwabbit/gd.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_gd.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_gd.o src/vowpalwabbit/gd.cc

src/vowpalwabbit/melt_gd_mf.o:src/vowpalwabbit/gd_mf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_gd_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_gd_mf.o src/vowpalwabbit/gd_mf.cc

src/vowpalwabbit/melt_global_data.o:src/vowpalwabbit/global_data.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_global_data.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_global_data.o src/vowpalwabbit/global_data.cc

src/vowpalwabbit/melt_hash.o:src/vowpalwabbit/hash.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_hash.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_hash.o src/vowpalwabbit/hash.cc

src/vowpalwabbit/melt_io_buf.o:src/vowpalwabbit/io_buf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_io_buf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_io_buf.o src/vowpalwabbit/io_buf.cc

src/vowpalwabbit/melt_kernel_svm.o:src/vowpalwabbit/kernel_svm.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_kernel_svm.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_kernel_svm.o src/vowpalwabbit/kernel_svm.cc

src/vowpalwabbit/melt_lda_core.o:src/vowpalwabbit/lda_core.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_lda_core.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_lda_core.o src/vowpalwabbit/lda_core.cc

src/vowpalwabbit/melt_learner.o:src/vowpalwabbit/learner.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_learner.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_learner.o src/vowpalwabbit/learner.cc

src/vowpalwabbit/melt_log_multi.o:src/vowpalwabbit/log_multi.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_log_multi.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_log_multi.o src/vowpalwabbit/log_multi.cc

src/vowpalwabbit/melt_loss_functions.o:src/vowpalwabbit/loss_functions.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_loss_functions.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_loss_functions.o src/vowpalwabbit/loss_functions.cc

src/vowpalwabbit/melt_lrq.o:src/vowpalwabbit/lrq.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_lrq.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_lrq.o src/vowpalwabbit/lrq.cc

src/vowpalwabbit/melt_main.o:src/vowpalwabbit/main.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_main.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_main.o src/vowpalwabbit/main.cc

src/vowpalwabbit/melt_memory.o:src/vowpalwabbit/memory.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_memory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_memory.o src/vowpalwabbit/memory.cc

src/vowpalwabbit/melt_mf.o:src/vowpalwabbit/mf.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_mf.o src/vowpalwabbit/mf.cc

src/vowpalwabbit/melt_multiclass.o:src/vowpalwabbit/multiclass.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_multiclass.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_multiclass.o src/vowpalwabbit/multiclass.cc

src/vowpalwabbit/melt_network.o:src/vowpalwabbit/network.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_network.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_network.o src/vowpalwabbit/network.cc

src/vowpalwabbit/melt_nn.o:src/vowpalwabbit/nn.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_nn.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_nn.o src/vowpalwabbit/nn.cc

src/vowpalwabbit/melt_noop.o:src/vowpalwabbit/noop.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_noop.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_noop.o src/vowpalwabbit/noop.cc

src/vowpalwabbit/melt_oaa.o:src/vowpalwabbit/oaa.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_oaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_oaa.o src/vowpalwabbit/oaa.cc

src/vowpalwabbit/melt_parse_args.o:src/vowpalwabbit/parse_args.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_parse_args.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_parse_args.o src/vowpalwabbit/parse_args.cc

src/vowpalwabbit/melt_parse_example.o:src/vowpalwabbit/parse_example.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_parse_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_parse_example.o src/vowpalwabbit/parse_example.cc

src/vowpalwabbit/melt_parse_primitives.o:src/vowpalwabbit/parse_primitives.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_parse_primitives.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_parse_primitives.o src/vowpalwabbit/parse_primitives.cc

src/vowpalwabbit/melt_parse_regressor.o:src/vowpalwabbit/parse_regressor.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_parse_regressor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_parse_regressor.o src/vowpalwabbit/parse_regressor.cc

src/vowpalwabbit/melt_parser.o:src/vowpalwabbit/parser.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_parser.o src/vowpalwabbit/parser.cc

src/vowpalwabbit/melt_print.o:src/vowpalwabbit/print.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_print.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_print.o src/vowpalwabbit/print.cc

src/vowpalwabbit/melt_rand48.o:src/vowpalwabbit/rand48.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_rand48.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_rand48.o src/vowpalwabbit/rand48.cc

src/vowpalwabbit/melt_scorer.o:src/vowpalwabbit/scorer.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_scorer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_scorer.o src/vowpalwabbit/scorer.cc

src/vowpalwabbit/melt_search.o:src/vowpalwabbit/search.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_search.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_search.o src/vowpalwabbit/search.cc

src/vowpalwabbit/melt_search_dep_parser.o:src/vowpalwabbit/search_dep_parser.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_search_dep_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_search_dep_parser.o src/vowpalwabbit/search_dep_parser.cc

src/vowpalwabbit/melt_search_entityrelationtask.o:src/vowpalwabbit/search_entityrelationtask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_search_entityrelationtask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_search_entityrelationtask.o src/vowpalwabbit/search_entityrelationtask.cc

src/vowpalwabbit/melt_search_hooktask.o:src/vowpalwabbit/search_hooktask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_search_hooktask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_search_hooktask.o src/vowpalwabbit/search_hooktask.cc

src/vowpalwabbit/melt_search_multiclasstask.o:src/vowpalwabbit/search_multiclasstask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_search_multiclasstask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_search_multiclasstask.o src/vowpalwabbit/search_multiclasstask.cc

src/vowpalwabbit/melt_search_sequencetask.o:src/vowpalwabbit/search_sequencetask.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_search_sequencetask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_search_sequencetask.o src/vowpalwabbit/search_sequencetask.cc

src/vowpalwabbit/melt_sender.o:src/vowpalwabbit/sender.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_sender.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_sender.o src/vowpalwabbit/sender.cc

src/vowpalwabbit/melt_simple_label.o:src/vowpalwabbit/simple_label.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_simple_label.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_simple_label.o src/vowpalwabbit/simple_label.cc

src/vowpalwabbit/melt_stagewise_poly.o:src/vowpalwabbit/stagewise_poly.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_stagewise_poly.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_stagewise_poly.o src/vowpalwabbit/stagewise_poly.cc

src/vowpalwabbit/melt_topk.o:src/vowpalwabbit/topk.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_topk.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_topk.o src/vowpalwabbit/topk.cc

src/vowpalwabbit/melt_unique_sort.o:src/vowpalwabbit/unique_sort.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/melt_unique_sort.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/melt_unique_sort.o src/vowpalwabbit/unique_sort.cc

src/sofia/melt_sf-data-set.o:src/sofia/sf-data-set.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sf-data-set.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sf-data-set.o src/sofia/sf-data-set.cc

src/sofia/melt_sf-data-set_test.o:src/sofia/sf-data-set_test.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sf-data-set_test.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sf-data-set_test.o src/sofia/sf-data-set_test.cc

src/sofia/melt_sf-hash-inline.o:src/sofia/sf-hash-inline.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sf-hash-inline.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sf-hash-inline.o src/sofia/sf-hash-inline.cc

src/sofia/melt_sf-hash-inline_test.o:src/sofia/sf-hash-inline_test.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sf-hash-inline_test.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sf-hash-inline_test.o src/sofia/sf-hash-inline_test.cc

src/sofia/melt_sf-hash-weight-vector.o:src/sofia/sf-hash-weight-vector.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sf-hash-weight-vector.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sf-hash-weight-vector.o src/sofia/sf-hash-weight-vector.cc

src/sofia/melt_sf-sparse-vector.o:src/sofia/sf-sparse-vector.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sf-sparse-vector.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sf-sparse-vector.o src/sofia/sf-sparse-vector.cc

src/sofia/melt_sf-sparse-vector_test.o:src/sofia/sf-sparse-vector_test.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sf-sparse-vector_test.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sf-sparse-vector_test.o src/sofia/sf-sparse-vector_test.cc

src/sofia/melt_sf-weight-vector.o:src/sofia/sf-weight-vector.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sf-weight-vector.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sf-weight-vector.o src/sofia/sf-weight-vector.cc

src/sofia/melt_sf-weight-vector_test.o:src/sofia/sf-weight-vector_test.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sf-weight-vector_test.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sf-weight-vector_test.o src/sofia/sf-weight-vector_test.cc

src/sofia/melt_simple-cmd-line-helper_test.o:src/sofia/simple-cmd-line-helper_test.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_simple-cmd-line-helper_test.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_simple-cmd-line-helper_test.o src/sofia/simple-cmd-line-helper_test.cc

src/sofia/melt_sofia-ml-methods.o:src/sofia/sofia-ml-methods.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sofia-ml-methods.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sofia-ml-methods.o src/sofia/sofia-ml-methods.cc

src/sofia/melt_sofia-ml-methods_test.o:src/sofia/sofia-ml-methods_test.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sofia-ml-methods_test.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sofia-ml-methods_test.o src/sofia/sofia-ml-methods_test.cc

src/sofia/melt_sofia-ml.o:src/sofia/sofia-ml.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/melt_sofia-ml.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/melt_sofia-ml.o src/sofia/sofia-ml.cc

src/Simple/melt_predict_Predictor.o:src/Simple/Predictor.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Simple/melt_predict_Predictor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/Simple/melt_predict_Predictor.o src/Simple/Predictor.cpp

src/Simple/melt_predict_PredictorFactory.o:src/Simple/PredictorFactory.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Simple/melt_predict_PredictorFactory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/Simple/melt_predict_PredictorFactory.o src/Simple/PredictorFactory.cpp

endif #ifeq ($(shell uname -m),x86_64)


