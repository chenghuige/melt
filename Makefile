#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=/opt/compiler/gcc-4.8.2/bin/g++
CXX=/opt/compiler/gcc-4.8.2/bin/g++
CXXFLAGS=-g \
  -O3 \
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
  -fopenmp \
  -mfpmath=sse \
  -msse \
  -msse2 \
  -msse3
CFLAGS=-g \
  -O3 \
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
  -fopenmp \
  -mfpmath=sse \
  -msse \
  -msse2 \
  -msse3
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\"
INCPATH=-I./ \
  -I./include/ \
  -I./include/vowpalwabbit/ \
  -I./include/sofia/ \
  -I./include/blas/ \
  -I./include/liblinear/ \
  -I./include/libsvm/
DEP_INCPATH=-I../../../../../app/search/sep/anti-spam/gezi \
  -I../../../../../app/search/sep/anti-spam/gezi/include \
  -I../../../../../app/search/sep/anti-spam/gezi/output \
  -I../../../../../app/search/sep/anti-spam/gezi/output/include \
  -I../../../../../app/search/sep/anti-spam/gezi/third \
  -I../../../../../app/search/sep/anti-spam/gezi/third/include \
  -I../../../../../app/search/sep/anti-spam/gezi/third/output \
  -I../../../../../app/search/sep/anti-spam/gezi/third/output/include \
  -I../../../../../baidu/nlp-dnn/liblego \
  -I../../../../../baidu/nlp-dnn/liblego/include \
  -I../../../../../baidu/nlp-dnn/liblego/output \
  -I../../../../../baidu/nlp-dnn/liblego/output/include \
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
  -I../../../../../third-64/pcre \
  -I../../../../../third-64/pcre/include \
  -I../../../../../third-64/pcre/output \
  -I../../../../../third-64/pcre/output/include \
  -I../../../../../third-64/protobuf \
  -I../../../../../third-64/protobuf/include \
  -I../../../../../third-64/protobuf/output \
  -I../../../../../third-64/protobuf/output/include \
  -I../../../../../third-64/tcmalloc \
  -I../../../../../third-64/tcmalloc/include \
  -I../../../../../third-64/tcmalloc/output \
  -I../../../../../third-64/tcmalloc/output/include \
  -I../../../../../third-64/zlib \
  -I../../../../../third-64/zlib/include \
  -I../../../../../third-64/zlib/output \
  -I../../../../../third-64/zlib/output/include

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=512cbef19b4a5c59a19507ee89735a5d  COMAKE


.PHONY:all
all:comake2_makefile_check libvw.a libsofia.a libblas.a liblinear.a libsvm.a libmelt.a 
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
	rm -rf libvw.a
	rm -rf ./output/lib/libvw.a
	rm -rf libsofia.a
	rm -rf ./output/lib/libsofia.a
	rm -rf libblas.a
	rm -rf ./output/lib/libblas.a
	rm -rf liblinear.a
	rm -rf ./output/lib/liblinear.a
	rm -rf libsvm.a
	rm -rf ./output/lib/libsvm.a
	rm -rf libmelt.a
	rm -rf ./output/lib/libmelt.a
	rm -rf src/vowpalwabbit/vw_accumulate.o
	rm -rf src/vowpalwabbit/vw_active.o
	rm -rf src/vowpalwabbit/vw_allreduce.o
	rm -rf src/vowpalwabbit/vw_autolink.o
	rm -rf src/vowpalwabbit/vw_bfgs.o
	rm -rf src/vowpalwabbit/vw_binary.o
	rm -rf src/vowpalwabbit/vw_bs.o
	rm -rf src/vowpalwabbit/vw_cache.o
	rm -rf src/vowpalwabbit/vw_cb.o
	rm -rf src/vowpalwabbit/vw_cb_algs.o
	rm -rf src/vowpalwabbit/vw_cbify.o
	rm -rf src/vowpalwabbit/vw_cost_sensitive.o
	rm -rf src/vowpalwabbit/vw_csoaa.o
	rm -rf src/vowpalwabbit/vw_ect.o
	rm -rf src/vowpalwabbit/vw_example.o
	rm -rf src/vowpalwabbit/vw_gd.o
	rm -rf src/vowpalwabbit/vw_gd_mf.o
	rm -rf src/vowpalwabbit/vw_global_data.o
	rm -rf src/vowpalwabbit/vw_hash.o
	rm -rf src/vowpalwabbit/vw_io_buf.o
	rm -rf src/vowpalwabbit/vw_kernel_svm.o
	rm -rf src/vowpalwabbit/vw_lda_core.o
	rm -rf src/vowpalwabbit/vw_learner.o
	rm -rf src/vowpalwabbit/vw_log_multi.o
	rm -rf src/vowpalwabbit/vw_loss_functions.o
	rm -rf src/vowpalwabbit/vw_lrq.o
	rm -rf src/vowpalwabbit/vw_memory.o
	rm -rf src/vowpalwabbit/vw_mf.o
	rm -rf src/vowpalwabbit/vw_multiclass.o
	rm -rf src/vowpalwabbit/vw_network.o
	rm -rf src/vowpalwabbit/vw_nn.o
	rm -rf src/vowpalwabbit/vw_noop.o
	rm -rf src/vowpalwabbit/vw_oaa.o
	rm -rf src/vowpalwabbit/vw_parse_args.o
	rm -rf src/vowpalwabbit/vw_parse_example.o
	rm -rf src/vowpalwabbit/vw_parse_primitives.o
	rm -rf src/vowpalwabbit/vw_parse_regressor.o
	rm -rf src/vowpalwabbit/vw_parser.o
	rm -rf src/vowpalwabbit/vw_print.o
	rm -rf src/vowpalwabbit/vw_rand48.o
	rm -rf src/vowpalwabbit/vw_scorer.o
	rm -rf src/vowpalwabbit/vw_search.o
	rm -rf src/vowpalwabbit/vw_search_dep_parser.o
	rm -rf src/vowpalwabbit/vw_search_entityrelationtask.o
	rm -rf src/vowpalwabbit/vw_search_hooktask.o
	rm -rf src/vowpalwabbit/vw_search_multiclasstask.o
	rm -rf src/vowpalwabbit/vw_search_sequencetask.o
	rm -rf src/vowpalwabbit/vw_sender.o
	rm -rf src/vowpalwabbit/vw_simple_label.o
	rm -rf src/vowpalwabbit/vw_stagewise_poly.o
	rm -rf src/vowpalwabbit/vw_topk.o
	rm -rf src/vowpalwabbit/vw_unique_sort.o
	rm -rf src/sofia/sofia_sf-data-set.o
	rm -rf src/sofia/sofia_sf-hash-inline.o
	rm -rf src/sofia/sofia_sf-hash-weight-vector.o
	rm -rf src/sofia/sofia_sf-sparse-vector.o
	rm -rf src/sofia/sofia_sf-weight-vector.o
	rm -rf src/sofia/sofia_sofia-ml-methods.o
	rm -rf src/blas/blas_daxpy.o
	rm -rf src/blas/blas_ddot.o
	rm -rf src/blas/blas_dnrm2.o
	rm -rf src/blas/blas_dscal.o
	rm -rf src/liblinear/linear_linear.o
	rm -rf src/liblinear/linear_tron.o
	rm -rf src/libsvm/svm_svm.o
	rm -rf src/Testers/melt_ClassifierTester.o
	rm -rf src/Prediction/Normalization/melt_BinNormalizer.o
	rm -rf src/Predictors/melt_LibSVMPredictor.o
	rm -rf src/Predictors/melt_VWPredictor.o
	rm -rf src/MLCore/melt_PredictoryFactory.o
	rm -rf src/Wrapper/melt_PredictorFactory.o

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

libvw.a:src/vowpalwabbit/vw_accumulate.o \
  src/vowpalwabbit/vw_active.o \
  src/vowpalwabbit/vw_allreduce.o \
  src/vowpalwabbit/vw_autolink.o \
  src/vowpalwabbit/vw_bfgs.o \
  src/vowpalwabbit/vw_binary.o \
  src/vowpalwabbit/vw_bs.o \
  src/vowpalwabbit/vw_cache.o \
  src/vowpalwabbit/vw_cb.o \
  src/vowpalwabbit/vw_cb_algs.o \
  src/vowpalwabbit/vw_cbify.o \
  src/vowpalwabbit/vw_cost_sensitive.o \
  src/vowpalwabbit/vw_csoaa.o \
  src/vowpalwabbit/vw_ect.o \
  src/vowpalwabbit/vw_example.o \
  src/vowpalwabbit/vw_gd.o \
  src/vowpalwabbit/vw_gd_mf.o \
  src/vowpalwabbit/vw_global_data.o \
  src/vowpalwabbit/vw_hash.o \
  src/vowpalwabbit/vw_io_buf.o \
  src/vowpalwabbit/vw_kernel_svm.o \
  src/vowpalwabbit/vw_lda_core.o \
  src/vowpalwabbit/vw_learner.o \
  src/vowpalwabbit/vw_log_multi.o \
  src/vowpalwabbit/vw_loss_functions.o \
  src/vowpalwabbit/vw_lrq.o \
  src/vowpalwabbit/vw_memory.o \
  src/vowpalwabbit/vw_mf.o \
  src/vowpalwabbit/vw_multiclass.o \
  src/vowpalwabbit/vw_network.o \
  src/vowpalwabbit/vw_nn.o \
  src/vowpalwabbit/vw_noop.o \
  src/vowpalwabbit/vw_oaa.o \
  src/vowpalwabbit/vw_parse_args.o \
  src/vowpalwabbit/vw_parse_example.o \
  src/vowpalwabbit/vw_parse_primitives.o \
  src/vowpalwabbit/vw_parse_regressor.o \
  src/vowpalwabbit/vw_parser.o \
  src/vowpalwabbit/vw_print.o \
  src/vowpalwabbit/vw_rand48.o \
  src/vowpalwabbit/vw_scorer.o \
  src/vowpalwabbit/vw_search.o \
  src/vowpalwabbit/vw_search_dep_parser.o \
  src/vowpalwabbit/vw_search_entityrelationtask.o \
  src/vowpalwabbit/vw_search_hooktask.o \
  src/vowpalwabbit/vw_search_multiclasstask.o \
  src/vowpalwabbit/vw_search_sequencetask.o \
  src/vowpalwabbit/vw_sender.o \
  src/vowpalwabbit/vw_simple_label.o \
  src/vowpalwabbit/vw_stagewise_poly.o \
  src/vowpalwabbit/vw_topk.o \
  src/vowpalwabbit/vw_unique_sort.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibvw.a[0m']"
	ar crs libvw.a src/vowpalwabbit/vw_accumulate.o \
  src/vowpalwabbit/vw_active.o \
  src/vowpalwabbit/vw_allreduce.o \
  src/vowpalwabbit/vw_autolink.o \
  src/vowpalwabbit/vw_bfgs.o \
  src/vowpalwabbit/vw_binary.o \
  src/vowpalwabbit/vw_bs.o \
  src/vowpalwabbit/vw_cache.o \
  src/vowpalwabbit/vw_cb.o \
  src/vowpalwabbit/vw_cb_algs.o \
  src/vowpalwabbit/vw_cbify.o \
  src/vowpalwabbit/vw_cost_sensitive.o \
  src/vowpalwabbit/vw_csoaa.o \
  src/vowpalwabbit/vw_ect.o \
  src/vowpalwabbit/vw_example.o \
  src/vowpalwabbit/vw_gd.o \
  src/vowpalwabbit/vw_gd_mf.o \
  src/vowpalwabbit/vw_global_data.o \
  src/vowpalwabbit/vw_hash.o \
  src/vowpalwabbit/vw_io_buf.o \
  src/vowpalwabbit/vw_kernel_svm.o \
  src/vowpalwabbit/vw_lda_core.o \
  src/vowpalwabbit/vw_learner.o \
  src/vowpalwabbit/vw_log_multi.o \
  src/vowpalwabbit/vw_loss_functions.o \
  src/vowpalwabbit/vw_lrq.o \
  src/vowpalwabbit/vw_memory.o \
  src/vowpalwabbit/vw_mf.o \
  src/vowpalwabbit/vw_multiclass.o \
  src/vowpalwabbit/vw_network.o \
  src/vowpalwabbit/vw_nn.o \
  src/vowpalwabbit/vw_noop.o \
  src/vowpalwabbit/vw_oaa.o \
  src/vowpalwabbit/vw_parse_args.o \
  src/vowpalwabbit/vw_parse_example.o \
  src/vowpalwabbit/vw_parse_primitives.o \
  src/vowpalwabbit/vw_parse_regressor.o \
  src/vowpalwabbit/vw_parser.o \
  src/vowpalwabbit/vw_print.o \
  src/vowpalwabbit/vw_rand48.o \
  src/vowpalwabbit/vw_scorer.o \
  src/vowpalwabbit/vw_search.o \
  src/vowpalwabbit/vw_search_dep_parser.o \
  src/vowpalwabbit/vw_search_entityrelationtask.o \
  src/vowpalwabbit/vw_search_hooktask.o \
  src/vowpalwabbit/vw_search_multiclasstask.o \
  src/vowpalwabbit/vw_search_sequencetask.o \
  src/vowpalwabbit/vw_sender.o \
  src/vowpalwabbit/vw_simple_label.o \
  src/vowpalwabbit/vw_stagewise_poly.o \
  src/vowpalwabbit/vw_topk.o \
  src/vowpalwabbit/vw_unique_sort.o
	mkdir -p ./output/lib
	cp -f --link libvw.a ./output/lib

libsofia.a:src/sofia/sofia_sf-data-set.o \
  src/sofia/sofia_sf-hash-inline.o \
  src/sofia/sofia_sf-hash-weight-vector.o \
  src/sofia/sofia_sf-sparse-vector.o \
  src/sofia/sofia_sf-weight-vector.o \
  src/sofia/sofia_sofia-ml-methods.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibsofia.a[0m']"
	ar crs libsofia.a src/sofia/sofia_sf-data-set.o \
  src/sofia/sofia_sf-hash-inline.o \
  src/sofia/sofia_sf-hash-weight-vector.o \
  src/sofia/sofia_sf-sparse-vector.o \
  src/sofia/sofia_sf-weight-vector.o \
  src/sofia/sofia_sofia-ml-methods.o
	mkdir -p ./output/lib
	cp -f --link libsofia.a ./output/lib

libblas.a:src/blas/blas_daxpy.o \
  src/blas/blas_ddot.o \
  src/blas/blas_dnrm2.o \
  src/blas/blas_dscal.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibblas.a[0m']"
	ar crs libblas.a src/blas/blas_daxpy.o \
  src/blas/blas_ddot.o \
  src/blas/blas_dnrm2.o \
  src/blas/blas_dscal.o
	mkdir -p ./output/lib
	cp -f --link libblas.a ./output/lib

liblinear.a:src/liblinear/linear_linear.o \
  src/liblinear/linear_tron.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mliblinear.a[0m']"
	ar crs liblinear.a src/liblinear/linear_linear.o \
  src/liblinear/linear_tron.o
	mkdir -p ./output/lib
	cp -f --link liblinear.a ./output/lib

libsvm.a:src/libsvm/svm_svm.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibsvm.a[0m']"
	ar crs libsvm.a src/libsvm/svm_svm.o
	mkdir -p ./output/lib
	cp -f --link libsvm.a ./output/lib

libmelt.a:src/Testers/melt_ClassifierTester.o \
  src/Prediction/Normalization/melt_BinNormalizer.o \
  src/Predictors/melt_LibSVMPredictor.o \
  src/Predictors/melt_VWPredictor.o \
  src/MLCore/melt_PredictoryFactory.o \
  src/Wrapper/melt_PredictorFactory.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibmelt.a[0m']"
	ar crs libmelt.a src/Testers/melt_ClassifierTester.o \
  src/Prediction/Normalization/melt_BinNormalizer.o \
  src/Predictors/melt_LibSVMPredictor.o \
  src/Predictors/melt_VWPredictor.o \
  src/MLCore/melt_PredictoryFactory.o \
  src/Wrapper/melt_PredictorFactory.o
	mkdir -p ./output/lib
	cp -f --link libmelt.a ./output/lib

src/vowpalwabbit/vw_accumulate.o:src/vowpalwabbit/accumulate.cc \
  include/vowpalwabbit/accumulate.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_accumulate.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_accumulate.o src/vowpalwabbit/accumulate.cc

src/vowpalwabbit/vw_active.o:src/vowpalwabbit/active.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/rand48.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_active.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_active.o src/vowpalwabbit/active.cc

src/vowpalwabbit/vw_allreduce.o:src/vowpalwabbit/allreduce.cc \
  include/vowpalwabbit/allreduce.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_allreduce.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_allreduce.o src/vowpalwabbit/allreduce.cc

src/vowpalwabbit/vw_autolink.o:src/vowpalwabbit/autolink.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_autolink.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_autolink.o src/vowpalwabbit/autolink.cc

src/vowpalwabbit/vw_bfgs.o:src/vowpalwabbit/bfgs.cc \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/accumulate.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_bfgs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_bfgs.o src/vowpalwabbit/bfgs.cc

src/vowpalwabbit/vw_binary.o:src/vowpalwabbit/binary.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/multiclass.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_binary.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_binary.o src/vowpalwabbit/binary.cc

src/vowpalwabbit/vw_bs.o:src/vowpalwabbit/bs.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/rand48.h \
  include/vowpalwabbit/bs.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_bs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_bs.o src/vowpalwabbit/bs.cc

src/vowpalwabbit/vw_cache.o:src/vowpalwabbit/cache.cc \
  include/vowpalwabbit/cache.h \
  include/vowpalwabbit/parse_example.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/unique_sort.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_cache.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_cache.o src/vowpalwabbit/cache.cc

src/vowpalwabbit/vw_cb.o:src/vowpalwabbit/cb.cc \
  include/vowpalwabbit/cost_sensitive.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/parse_args.h \
  include/vowpalwabbit/cb.h \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/parse_example.h \
  include/vowpalwabbit/parse_regressor.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_cb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_cb.o src/vowpalwabbit/cb.cc

src/vowpalwabbit/vw_cb_algs.o:src/vowpalwabbit/cb_algs.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/cost_sensitive.h \
  include/vowpalwabbit/parse_args.h \
  include/vowpalwabbit/cb.h \
  include/vowpalwabbit/cb_algs.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_cb_algs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_cb_algs.o src/vowpalwabbit/cb_algs.cc

src/vowpalwabbit/vw_cbify.o:src/vowpalwabbit/cbify.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/cost_sensitive.h \
  include/vowpalwabbit/parse_args.h \
  include/vowpalwabbit/cb.h \
  include/vowpalwabbit/cb_algs.h \
  include/vowpalwabbit/rand48.h \
  include/vowpalwabbit/bs.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_cbify.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_cbify.o src/vowpalwabbit/cbify.cc

src/vowpalwabbit/vw_cost_sensitive.o:src/vowpalwabbit/cost_sensitive.cc \
  include/vowpalwabbit/cost_sensitive.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/parse_args.h \
  include/vowpalwabbit/parse_example.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/constant.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_cost_sensitive.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_cost_sensitive.o src/vowpalwabbit/cost_sensitive.cc

src/vowpalwabbit/vw_csoaa.o:src/vowpalwabbit/csoaa.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/cost_sensitive.h \
  include/vowpalwabbit/parse_args.h \
  include/vowpalwabbit/v_hashmap.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_csoaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_csoaa.o src/vowpalwabbit/csoaa.cc

src/vowpalwabbit/vw_ect.o:src/vowpalwabbit/ect.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/multiclass.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_ect.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_ect.o src/vowpalwabbit/ect.cc

src/vowpalwabbit/vw_example.o:src/vowpalwabbit/example.cc \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_example.o src/vowpalwabbit/example.cc

src/vowpalwabbit/vw_gd.o:src/vowpalwabbit/gd.cc \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/accumulate.h \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_gd.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_gd.o src/vowpalwabbit/gd.cc

src/vowpalwabbit/vw_gd_mf.o:src/vowpalwabbit/gd_mf.cc \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/rand48.h \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_gd_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_gd_mf.o src/vowpalwabbit/gd_mf.cc

src/vowpalwabbit/vw_global_data.o:src/vowpalwabbit/global_data.cc \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_global_data.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_global_data.o src/vowpalwabbit/global_data.cc

src/vowpalwabbit/vw_hash.o:src/vowpalwabbit/hash.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_hash.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_hash.o src/vowpalwabbit/hash.cc

src/vowpalwabbit/vw_io_buf.o:src/vowpalwabbit/io_buf.cc \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_io_buf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_io_buf.o src/vowpalwabbit/io_buf.cc

src/vowpalwabbit/vw_kernel_svm.o:src/vowpalwabbit/kernel_svm.cc \
  include/vowpalwabbit/parse_example.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/kernel_svm.h \
  include/vowpalwabbit/cache.h \
  include/vowpalwabbit/accumulate.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_kernel_svm.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_kernel_svm.o src/vowpalwabbit/kernel_svm.cc

src/vowpalwabbit/vw_lda_core.o:src/vowpalwabbit/lda_core.cc \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/rand48.h \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_lda_core.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_lda_core.o src/vowpalwabbit/lda_core.cc

src/vowpalwabbit/vw_learner.o:src/vowpalwabbit/learner.cc \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_learner.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_learner.o src/vowpalwabbit/learner.cc

src/vowpalwabbit/vw_log_multi.o:src/vowpalwabbit/log_multi.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/multiclass.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_log_multi.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_log_multi.o src/vowpalwabbit/log_multi.cc

src/vowpalwabbit/vw_loss_functions.o:src/vowpalwabbit/loss_functions.cc \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_loss_functions.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_loss_functions.o src/vowpalwabbit/loss_functions.cc

src/vowpalwabbit/vw_lrq.o:src/vowpalwabbit/lrq.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/rand48.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_lrq.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_lrq.o src/vowpalwabbit/lrq.cc

src/vowpalwabbit/vw_memory.o:src/vowpalwabbit/memory.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_memory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_memory.o src/vowpalwabbit/memory.cc

src/vowpalwabbit/vw_mf.o:src/vowpalwabbit/mf.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/rand48.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_mf.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_mf.o src/vowpalwabbit/mf.cc

src/vowpalwabbit/vw_multiclass.o:src/vowpalwabbit/multiclass.cc \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_multiclass.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_multiclass.o src/vowpalwabbit/multiclass.cc

src/vowpalwabbit/vw_network.o:src/vowpalwabbit/network.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_network.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_network.o src/vowpalwabbit/network.cc

src/vowpalwabbit/vw_nn.o:src/vowpalwabbit/nn.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/rand48.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_nn.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_nn.o src/vowpalwabbit/nn.cc

src/vowpalwabbit/vw_noop.o:src/vowpalwabbit/noop.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_noop.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_noop.o src/vowpalwabbit/noop.cc

src/vowpalwabbit/vw_oaa.o:src/vowpalwabbit/oaa.cc \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_oaa.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_oaa.o src/vowpalwabbit/oaa.cc

src/vowpalwabbit/vw_parse_args.o:src/vowpalwabbit/parse_args.cc \
  include/vowpalwabbit/cache.h \
  include/vowpalwabbit/parse_example.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/parse_args.h \
  include/vowpalwabbit/sender.h \
  include/vowpalwabbit/network.h \
  include/vowpalwabbit/nn.h \
  include/vowpalwabbit/cbify.h \
  include/vowpalwabbit/oaa.h \
  include/vowpalwabbit/rand48.h \
  include/vowpalwabbit/bs.h \
  include/vowpalwabbit/topk.h \
  include/vowpalwabbit/v_hashmap.h \
  include/vowpalwabbit/ect.h \
  include/vowpalwabbit/csoaa.h \
  include/vowpalwabbit/cb.h \
  include/vowpalwabbit/cb_algs.h \
  include/vowpalwabbit/scorer.h \
  include/vowpalwabbit/search.h \
  include/vowpalwabbit/bfgs.h \
  include/vowpalwabbit/lda_core.h \
  include/vowpalwabbit/noop.h \
  include/vowpalwabbit/print.h \
  include/vowpalwabbit/gd_mf.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/mf.h \
  include/vowpalwabbit/binary.h \
  include/vowpalwabbit/lrq.h \
  include/vowpalwabbit/autolink.h \
  include/vowpalwabbit/log_multi.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/stagewise_poly.h \
  include/vowpalwabbit/active.h \
  include/vowpalwabbit/kernel_svm.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_parse_args.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_parse_args.o src/vowpalwabbit/parse_args.cc

src/vowpalwabbit/vw_parse_example.o:src/vowpalwabbit/parse_example.cc \
  include/vowpalwabbit/parse_example.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/cache.h \
  include/vowpalwabbit/unique_sort.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_parse_example.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_parse_example.o src/vowpalwabbit/parse_example.cc

src/vowpalwabbit/vw_parse_primitives.o:src/vowpalwabbit/parse_primitives.cc \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_parse_primitives.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_parse_primitives.o src/vowpalwabbit/parse_primitives.cc

src/vowpalwabbit/vw_parse_regressor.o:src/vowpalwabbit/parse_regressor.cc \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/rand48.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_parse_regressor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_parse_regressor.o src/vowpalwabbit/parse_regressor.cc

src/vowpalwabbit/vw_parser.o:src/vowpalwabbit/parser.cc \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/parse_example.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/cache.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/unique_sort.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_parser.o src/vowpalwabbit/parser.cc

src/vowpalwabbit/vw_print.o:src/vowpalwabbit/print.cc \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_print.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_print.o src/vowpalwabbit/print.cc

src/vowpalwabbit/vw_rand48.o:src/vowpalwabbit/rand48.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_rand48.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_rand48.o src/vowpalwabbit/rand48.cc

src/vowpalwabbit/vw_scorer.o:src/vowpalwabbit/scorer.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_scorer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_scorer.o src/vowpalwabbit/scorer.cc

src/vowpalwabbit/vw_search.o:src/vowpalwabbit/search.cc \
  include/vowpalwabbit/search.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/v_hashmap.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/rand48.h \
  include/vowpalwabbit/cost_sensitive.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/parse_args.h \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/cb.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/search_sequencetask.h \
  include/vowpalwabbit/search_multiclasstask.h \
  include/vowpalwabbit/search_dep_parser.h \
  include/vowpalwabbit/search_entityrelationtask.h \
  include/vowpalwabbit/search_hooktask.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_search.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_search.o src/vowpalwabbit/search.cc

src/vowpalwabbit/vw_search_dep_parser.o:src/vowpalwabbit/search_dep_parser.cc \
  include/vowpalwabbit/search_dep_parser.h \
  include/vowpalwabbit/search.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/ezexample.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_search_dep_parser.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_search_dep_parser.o src/vowpalwabbit/search_dep_parser.cc

src/vowpalwabbit/vw_search_entityrelationtask.o:src/vowpalwabbit/search_entityrelationtask.cc \
  include/vowpalwabbit/search_entityrelationtask.h \
  include/vowpalwabbit/search.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/cost_sensitive.h \
  include/vowpalwabbit/parse_args.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_search_entityrelationtask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_search_entityrelationtask.o src/vowpalwabbit/search_entityrelationtask.cc

src/vowpalwabbit/vw_search_hooktask.o:src/vowpalwabbit/search_hooktask.cc \
  include/vowpalwabbit/search_hooktask.h \
  include/vowpalwabbit/search.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_search_hooktask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_search_hooktask.o src/vowpalwabbit/search_hooktask.cc

src/vowpalwabbit/vw_search_multiclasstask.o:src/vowpalwabbit/search_multiclasstask.cc \
  include/vowpalwabbit/search_multiclasstask.h \
  include/vowpalwabbit/search.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/memory.h \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/ezexample.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_search_multiclasstask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_search_multiclasstask.o src/vowpalwabbit/search_multiclasstask.cc

src/vowpalwabbit/vw_search_sequencetask.o:src/vowpalwabbit/search_sequencetask.cc \
  include/vowpalwabbit/search_sequencetask.h \
  include/vowpalwabbit/search.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/multiclass.h \
  include/vowpalwabbit/cost_sensitive.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/parse_args.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_search_sequencetask.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_search_sequencetask.o src/vowpalwabbit/search_sequencetask.cc

src/vowpalwabbit/vw_sender.o:src/vowpalwabbit/sender.cc \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/cache.h \
  include/vowpalwabbit/parse_example.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/network.h \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_sender.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_sender.o src/vowpalwabbit/sender.cc

src/vowpalwabbit/vw_simple_label.o:src/vowpalwabbit/simple_label.cc \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/cache.h \
  include/vowpalwabbit/parse_example.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/rand48.h \
  include/vowpalwabbit/accumulate.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_simple_label.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_simple_label.o src/vowpalwabbit/simple_label.cc

src/vowpalwabbit/vw_stagewise_poly.o:src/vowpalwabbit/stagewise_poly.cc \
  include/vowpalwabbit/gd.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_regressor.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/constant.h \
  include/vowpalwabbit/rand48.h \
  include/vowpalwabbit/accumulate.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_stagewise_poly.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_stagewise_poly.o src/vowpalwabbit/stagewise_poly.cc

src/vowpalwabbit/vw_topk.o:src/vowpalwabbit/topk.cc \
  include/vowpalwabbit/reductions.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/memory.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_topk.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_topk.o src/vowpalwabbit/topk.cc

src/vowpalwabbit/vw_unique_sort.o:src/vowpalwabbit/unique_sort.cc \
  include/vowpalwabbit/unique_sort.h \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/vowpalwabbit/vw_unique_sort.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/vowpalwabbit/vw_unique_sort.o src/vowpalwabbit/unique_sort.cc

src/sofia/sofia_sf-data-set.o:src/sofia/sf-data-set.cc \
  include/sofia/sf-data-set.h \
  include/sofia/sf-sparse-vector.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/sofia_sf-data-set.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/sofia_sf-data-set.o src/sofia/sf-data-set.cc

src/sofia/sofia_sf-hash-inline.o:src/sofia/sf-hash-inline.cc \
  include/sofia/sf-hash-inline.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/sofia_sf-hash-inline.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/sofia_sf-hash-inline.o src/sofia/sf-hash-inline.cc

src/sofia/sofia_sf-hash-weight-vector.o:src/sofia/sf-hash-weight-vector.cc \
  include/sofia/sf-hash-weight-vector.h \
  include/sofia/sf-hash-inline.h \
  include/sofia/sf-weight-vector.h \
  include/sofia/sf-sparse-vector.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/sofia_sf-hash-weight-vector.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/sofia_sf-hash-weight-vector.o src/sofia/sf-hash-weight-vector.cc

src/sofia/sofia_sf-sparse-vector.o:src/sofia/sf-sparse-vector.cc \
  include/sofia/sf-sparse-vector.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/sofia_sf-sparse-vector.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/sofia_sf-sparse-vector.o src/sofia/sf-sparse-vector.cc

src/sofia/sofia_sf-weight-vector.o:src/sofia/sf-weight-vector.cc \
  include/sofia/sf-weight-vector.h \
  include/sofia/sf-sparse-vector.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/sofia_sf-weight-vector.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/sofia_sf-weight-vector.o src/sofia/sf-weight-vector.cc

src/sofia/sofia_sofia-ml-methods.o:src/sofia/sofia-ml-methods.cc \
  include/sofia/sofia-ml-methods.h \
  include/sofia/sf-data-set.h \
  include/sofia/sf-sparse-vector.h \
  include/sofia/sf-weight-vector.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/sofia/sofia_sofia-ml-methods.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/sofia/sofia_sofia-ml-methods.o src/sofia/sofia-ml-methods.cc

src/blas/blas_daxpy.o:src/blas/daxpy.c \
  include/blas/blas.h \
  include/blas/blasp.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/blas/blas_daxpy.o[0m']"
	$(CC) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CFLAGS)  -o src/blas/blas_daxpy.o src/blas/daxpy.c

src/blas/blas_ddot.o:src/blas/ddot.c \
  include/blas/blas.h \
  include/blas/blasp.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/blas/blas_ddot.o[0m']"
	$(CC) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CFLAGS)  -o src/blas/blas_ddot.o src/blas/ddot.c

src/blas/blas_dnrm2.o:src/blas/dnrm2.c \
  include/blas/blas.h \
  include/blas/blasp.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/blas/blas_dnrm2.o[0m']"
	$(CC) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CFLAGS)  -o src/blas/blas_dnrm2.o src/blas/dnrm2.c

src/blas/blas_dscal.o:src/blas/dscal.c \
  include/blas/blas.h \
  include/blas/blasp.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/blas/blas_dscal.o[0m']"
	$(CC) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CFLAGS)  -o src/blas/blas_dscal.o src/blas/dscal.c

src/liblinear/linear_linear.o:src/liblinear/linear.cpp \
  include/liblinear/linear.h \
  include/liblinear/tron.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/liblinear/linear_linear.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/liblinear/linear_linear.o src/liblinear/linear.cpp

src/liblinear/linear_tron.o:src/liblinear/tron.cpp \
  include/liblinear/tron.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/liblinear/linear_tron.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/liblinear/linear_tron.o src/liblinear/tron.cpp

src/libsvm/svm_svm.o:src/libsvm/svm.cpp \
  include/libsvm/svm.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/libsvm/svm_svm.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DNDEBUG $(CXXFLAGS)  -o src/libsvm/svm_svm.o src/libsvm/svm.cpp

src/Testers/melt_ClassifierTester.o:src/Testers/ClassifierTester.cpp \
  include/Testers/ClassifierTester.h \
  include/Testers/Tester.h \
  include/MLCore/Predictor.h \
  include/Prediction/Normalization/NormalizerFactory.h \
  include/Prediction/Normalization/Normalizer.h \
  include/Prediction/Instances/Instances.h \
  include/Prediction/Instances/HeaderSchema.h \
  include/Prediction/Instances/FeatureNamesVector.h \
  include/Prediction/Instances/Instance.h \
  include/Prediction/Normalization/MinMaxNormalizer.h \
  include/Prediction/Normalization/AffineNormalizer.h \
  include/Prediction/Normalization/GaussianNormalizer.h \
  include/Prediction/Normalization/BinNormalizer.h \
  include/Prediction/Calibrate/CalibratorFactory.h \
  include/Prediction/Calibrate/Calibrator.h \
  include/Prediction/Calibrate/SigmoidCalibrator.h \
  include/Prediction/Calibrate/PAVCalibrator.h \
  include/Prediction/Calibrate/NaiveCalibrator.h \
  include/MLCore/PredictionKind.h \
  include/Testers/DatasetMetrics.h \
  include/Utils/Evaluator.h \
  include/Utils/evaluate.h \
  include/Utils/evaluate_def.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Testers/melt_ClassifierTester.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -DMELT_USE_THIRD_PARTY \
  -DMELT_USE_LEGO $(CXXFLAGS)  -o src/Testers/melt_ClassifierTester.o src/Testers/ClassifierTester.cpp

src/Prediction/Normalization/melt_BinNormalizer.o:src/Prediction/Normalization/BinNormalizer.cpp \
  include/Prediction/Normalization/BinNormalizer.h \
  include/Prediction/Normalization/Normalizer.h \
  include/Prediction/Instances/Instances.h \
  include/Prediction/Instances/HeaderSchema.h \
  include/Prediction/Instances/FeatureNamesVector.h \
  include/Prediction/Instances/Instance.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Prediction/Normalization/melt_BinNormalizer.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -DMELT_USE_THIRD_PARTY \
  -DMELT_USE_LEGO $(CXXFLAGS)  -o src/Prediction/Normalization/melt_BinNormalizer.o src/Prediction/Normalization/BinNormalizer.cpp

src/Predictors/melt_LibSVMPredictor.o:src/Predictors/LibSVMPredictor.cpp \
  include/libsvm/svm.h \
  include/Predictors/LibSVMPredictor.h \
  include/MLCore/Predictor.h \
  include/Prediction/Normalization/NormalizerFactory.h \
  include/Prediction/Normalization/Normalizer.h \
  include/Prediction/Instances/Instances.h \
  include/Prediction/Instances/HeaderSchema.h \
  include/Prediction/Instances/FeatureNamesVector.h \
  include/Prediction/Instances/Instance.h \
  include/Prediction/Normalization/MinMaxNormalizer.h \
  include/Prediction/Normalization/AffineNormalizer.h \
  include/Prediction/Normalization/GaussianNormalizer.h \
  include/Prediction/Normalization/BinNormalizer.h \
  include/Prediction/Calibrate/CalibratorFactory.h \
  include/Prediction/Calibrate/Calibrator.h \
  include/Prediction/Calibrate/SigmoidCalibrator.h \
  include/Prediction/Calibrate/PAVCalibrator.h \
  include/Prediction/Calibrate/NaiveCalibrator.h \
  include/MLCore/PredictionKind.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Predictors/melt_LibSVMPredictor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -DMELT_USE_THIRD_PARTY \
  -DMELT_USE_LEGO $(CXXFLAGS)  -o src/Predictors/melt_LibSVMPredictor.o src/Predictors/LibSVMPredictor.cpp

src/Predictors/melt_VWPredictor.o:src/Predictors/VWPredictor.cpp \
  include/vowpalwabbit/parser.h \
  include/vowpalwabbit/io_buf.h \
  include/vowpalwabbit/v_array.h \
  include/vowpalwabbit/parse_primitives.h \
  include/vowpalwabbit/example.h \
  include/vowpalwabbit/vw.h \
  include/vowpalwabbit/global_data.h \
  include/vowpalwabbit/loss_functions.h \
  include/vowpalwabbit/comp_io.h \
  include/vowpalwabbit/config.h \
  include/vowpalwabbit/learner.h \
  include/vowpalwabbit/allreduce.h \
  include/vowpalwabbit/hash.h \
  include/vowpalwabbit/simple_label.h \
  include/vowpalwabbit/parse_args.h \
  include/vowpalwabbit/parse_regressor.h \
  include/Predictors/VWPredictor.h \
  include/MLCore/Predictor.h \
  include/Prediction/Normalization/NormalizerFactory.h \
  include/Prediction/Normalization/Normalizer.h \
  include/Prediction/Instances/Instances.h \
  include/Prediction/Instances/HeaderSchema.h \
  include/Prediction/Instances/FeatureNamesVector.h \
  include/Prediction/Instances/Instance.h \
  include/Prediction/Normalization/MinMaxNormalizer.h \
  include/Prediction/Normalization/AffineNormalizer.h \
  include/Prediction/Normalization/GaussianNormalizer.h \
  include/Prediction/Normalization/BinNormalizer.h \
  include/Prediction/Calibrate/CalibratorFactory.h \
  include/Prediction/Calibrate/Calibrator.h \
  include/Prediction/Calibrate/SigmoidCalibrator.h \
  include/Prediction/Calibrate/PAVCalibrator.h \
  include/Prediction/Calibrate/NaiveCalibrator.h \
  include/MLCore/PredictionKind.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Predictors/melt_VWPredictor.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -DMELT_USE_THIRD_PARTY \
  -DMELT_USE_LEGO $(CXXFLAGS)  -o src/Predictors/melt_VWPredictor.o src/Predictors/VWPredictor.cpp

src/MLCore/melt_PredictoryFactory.o:src/MLCore/PredictoryFactory.cpp \
  include/MLCore/PredictorFactory.h \
  include/MLCore/Predictor.h \
  include/Prediction/Normalization/NormalizerFactory.h \
  include/Prediction/Normalization/Normalizer.h \
  include/Prediction/Instances/Instances.h \
  include/Prediction/Instances/HeaderSchema.h \
  include/Prediction/Instances/FeatureNamesVector.h \
  include/Prediction/Instances/Instance.h \
  include/Prediction/Normalization/MinMaxNormalizer.h \
  include/Prediction/Normalization/AffineNormalizer.h \
  include/Prediction/Normalization/GaussianNormalizer.h \
  include/Prediction/Normalization/BinNormalizer.h \
  include/Prediction/Calibrate/CalibratorFactory.h \
  include/Prediction/Calibrate/Calibrator.h \
  include/Prediction/Calibrate/SigmoidCalibrator.h \
  include/Prediction/Calibrate/PAVCalibrator.h \
  include/Prediction/Calibrate/NaiveCalibrator.h \
  include/MLCore/PredictionKind.h \
  include/Predictors/LinearPredictor.h \
  include/Predictors/GbdtPredictor.h \
  include/Trainers/Gbdt/OnlineRegressionTree.h \
  include/Prediction/Instances/FeatureNamesVector.h \
  include/Predictors/LibSVMPredictor.h \
  include/Predictors/VWPredictor.h \
  include/Predictors/EnsemblePredictor.h \
  include/Predictors/LegoPredictor.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/MLCore/melt_PredictoryFactory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -DMELT_USE_THIRD_PARTY \
  -DMELT_USE_LEGO $(CXXFLAGS)  -o src/MLCore/melt_PredictoryFactory.o src/MLCore/PredictoryFactory.cpp

src/Wrapper/melt_PredictorFactory.o:src/Wrapper/PredictorFactory.cpp \
  include/Wrapper/PredictorFactory.h \
  include/MLCore/PredictorFactory.h \
  include/MLCore/Predictor.h \
  include/Prediction/Normalization/NormalizerFactory.h \
  include/Prediction/Normalization/Normalizer.h \
  include/Prediction/Instances/Instances.h \
  include/Prediction/Instances/HeaderSchema.h \
  include/Prediction/Instances/FeatureNamesVector.h \
  include/Prediction/Instances/Instance.h \
  include/Prediction/Normalization/MinMaxNormalizer.h \
  include/Prediction/Normalization/AffineNormalizer.h \
  include/Prediction/Normalization/GaussianNormalizer.h \
  include/Prediction/Normalization/BinNormalizer.h \
  include/Prediction/Calibrate/CalibratorFactory.h \
  include/Prediction/Calibrate/Calibrator.h \
  include/Prediction/Calibrate/SigmoidCalibrator.h \
  include/Prediction/Calibrate/PAVCalibrator.h \
  include/Prediction/Calibrate/NaiveCalibrator.h \
  include/MLCore/PredictionKind.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40msrc/Wrapper/melt_PredictorFactory.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -DMELT_USE_THIRD_PARTY \
  -DMELT_USE_LEGO $(CXXFLAGS)  -o src/Wrapper/melt_PredictorFactory.o src/Wrapper/PredictorFactory.cpp

endif #ifeq ($(shell uname -m),x86_64)


