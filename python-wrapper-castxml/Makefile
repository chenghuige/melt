#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=g++
CXX=g++
CXXFLAGS=-g \
  -O3 \
  -pipe \
  -W \
  -Wall \
  -fPIC \
  -DPYTHON_WRAPPER \
  -DHAVE_NETINET_IN_H \
  -Wno-unused-parameter \
  -fPIC \
  -Wl,-Bsymbolic \
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
  -DPYTHON_WRAPPER \
  -DHAVE_NETINET_IN_H \
  -Wno-unused-parameter \
  -fPIC \
  -Wl,-Bsymbolic \
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
INCPATH=-I/home/users/chenghuige/.jumbo//include/python2.7 \
  -I./
DEP_INCPATH=-I../../../../../../app/search/ksarch/store/proxy-lib/redis \
  -I../../../../../../app/search/ksarch/store/proxy-lib/redis/include \
  -I../../../../../../app/search/ksarch/store/proxy-lib/redis/output \
  -I../../../../../../app/search/ksarch/store/proxy-lib/redis/output/include \
  -I../../../../../../app/search/sep/anti-spam/gezi \
  -I../../../../../../app/search/sep/anti-spam/gezi/include \
  -I../../../../../../app/search/sep/anti-spam/gezi/output \
  -I../../../../../../app/search/sep/anti-spam/gezi/output/include \
  -I../../../../../../app/search/sep/anti-spam/gezi/third \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/include \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/output \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/output/include \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/rabit \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/rabit/include \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/rabit/output \
  -I../../../../../../app/search/sep/anti-spam/gezi/third/rabit/output/include \
  -I../../../../../../app/search/sep/anti-spam/melt \
  -I../../../../../../app/search/sep/anti-spam/melt-train \
  -I../../../../../../app/search/sep/anti-spam/melt-train/include \
  -I../../../../../../app/search/sep/anti-spam/melt-train/output \
  -I../../../../../../app/search/sep/anti-spam/melt-train/output/include \
  -I../../../../../../app/search/sep/anti-spam/melt/include \
  -I../../../../../../app/search/sep/anti-spam/melt/output \
  -I../../../../../../app/search/sep/anti-spam/melt/output/include \
  -I../../../../../../baidu/nlp-dnn/liblego \
  -I../../../../../../baidu/nlp-dnn/liblego/include \
  -I../../../../../../baidu/nlp-dnn/liblego/output \
  -I../../../../../../baidu/nlp-dnn/liblego/output/include \
  -I../../../../../../com/btest/gtest \
  -I../../../../../../com/btest/gtest/include \
  -I../../../../../../com/btest/gtest/output \
  -I../../../../../../com/btest/gtest/output/include \
  -I../../../../../../ps/se/toolchain \
  -I../../../../../../ps/se/toolchain/include \
  -I../../../../../../ps/se/toolchain/output \
  -I../../../../../../ps/se/toolchain/output/include \
  -I../../../../../../public/configure \
  -I../../../../../../public/configure/include \
  -I../../../../../../public/configure/output \
  -I../../../../../../public/configure/output/include \
  -I../../../../../../public/ub \
  -I../../../../../../public/ub/include \
  -I../../../../../../public/ub/output \
  -I../../../../../../public/ub/output/include \
  -I../../../../../../st/nlp/lm-score \
  -I../../../../../../st/nlp/lm-score/include \
  -I../../../../../../st/nlp/lm-score/output \
  -I../../../../../../st/nlp/lm-score/output/include \
  -I../../../../../../third-64/boost \
  -I../../../../../../third-64/boost.1.53 \
  -I../../../../../../third-64/boost.1.53/include \
  -I../../../../../../third-64/boost.1.53/output \
  -I../../../../../../third-64/boost.1.53/output/include \
  -I../../../../../../third-64/boost/include \
  -I../../../../../../third-64/boost/output \
  -I../../../../../../third-64/boost/output/include \
  -I../../../../../../third-64/gflags \
  -I../../../../../../third-64/gflags.bak \
  -I../../../../../../third-64/gflags.bak/include \
  -I../../../../../../third-64/gflags.bak/output \
  -I../../../../../../third-64/gflags.bak/output/include \
  -I../../../../../../third-64/gflags/include \
  -I../../../../../../third-64/gflags/output \
  -I../../../../../../third-64/gflags/output/include \
  -I../../../../../../third-64/glog \
  -I../../../../../../third-64/glog/include \
  -I../../../../../../third-64/glog/output \
  -I../../../../../../third-64/glog/output/include \
  -I../../../../../../third-64/libcurl \
  -I../../../../../../third-64/libcurl/include \
  -I../../../../../../third-64/libcurl/output \
  -I../../../../../../third-64/libcurl/output/include \
  -I../../../../../../third-64/protobuf \
  -I../../../../../../third-64/protobuf/include \
  -I../../../../../../third-64/protobuf/output \
  -I../../../../../../third-64/protobuf/output/include \
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
COMAKE_MD5=043c37d97e02fb6281f9f245f6940573  COMAKE


.PHONY:all
all:comake2_makefile_check libmelt.so 
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
	rm -rf libmelt.so
	rm -rf ./output/so/libmelt.so
	rm -rf melt_melt_py.o

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

libmelt.so:melt_melt_py.o \
  ./lib/libpython2.7.so \
  ./lib/libboost_python.so
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlibmelt.so[0m']"
	$(CXX) -shared melt_melt_py.o -Xlinker "-(" ./lib/libpython2.7.so \
  ./lib/libboost_python.so ../../../../../../app/search/ksarch/store/proxy-lib/redis/libredisclient.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/gezi/third/rabit/lib/librabit.a \
  ../../../../../../app/search/sep/anti-spam/gezi/third/rabit/lib/librabit_base.a \
  ../../../../../../app/search/sep/anti-spam/gezi/third/rabit/lib/librabit_mock.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../app/search/sep/anti-spam/melt/libblas.a \
  ../../../../../../app/search/sep/anti-spam/melt/liblinear.a \
  ../../../../../../app/search/sep/anti-spam/melt/libmelt.a \
  ../../../../../../app/search/sep/anti-spam/melt/libsofia.a \
  ../../../../../../app/search/sep/anti-spam/melt/libsvm.a \
  ../../../../../../app/search/sep/anti-spam/melt/libvw.a \
  ../../../../../../baidu/nlp-dnn/liblego/libliblego.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/ub/output/lib/libub.a \
  ../../../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../../../public/ub/output/lib/libub_client.a \
  ../../../../../../public/ub/output/lib/libub_conf.a \
  ../../../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../../../public/ub/output/lib/libub_log.a \
  ../../../../../../public/ub/output/lib/libub_misc.a \
  ../../../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../../../public/ub/output/lib/libub_naming.a \
  ../../../../../../public/ub/output/lib/libub_server.a \
  ../../../../../../public/ub/output/lib/libubex.a \
  ../../../../../../public/ub/output/lib/libubfw.a \
  ../../../../../../st/nlp/lm-score/output/lib/libScoreCal.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_atomic.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_chrono.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_context.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_date_time.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_exception.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_filesystem.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_graph.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_locale.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_math_c99.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_math_c99f.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_math_c99l.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_math_tr1.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_math_tr1f.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_math_tr1l.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_mpi.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_mpi_python.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_prg_exec_monitor.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_program_options.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_python.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_random.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_regex.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_serialization.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_signals.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_system.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_test_exec_monitor.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_thread.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_timer.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_unit_test_framework.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_wave.a \
  ../../../../../../third-64/boost.1.53/lib/libboost_wserialization.a \
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
  ../../../../../../third-64/gflags.bak/lib/libgflags.a \
  ../../../../../../third-64/gflags.bak/lib/libgflags_nothreads.a \
  ../../../../../../third-64/gflags/lib/libgflags.a \
  ../../../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../../../third-64/glog/lib/libglog.a \
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../../../third-64/protobuf/lib/libprotoc.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lrt \
  -lcrypto \
  -lssl \
  -ldl \
  -rdynamic \
  -L./ \
  -L./lib \
  -lpython2.7 \
  -lboost_python \
  -Wl,-rpath=./ \
  -lgomp \
  -rdynamic \
  -Wl,-rpath=./lib/ -Xlinker "-)" -o libmelt.so
	mkdir -p ./output/so
	cp -f --link libmelt.so ./output/so

melt_melt_py.o:melt_py.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mmelt_melt_py.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) -D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\" \
  -O3 \
  -DPYTHON_WRAPPER \
  -DNDEBUG \
  -DNO_BAIDU_DEP \
  -DBOOST_BIND_PLACEHOLDERS_HPP_INCLUDED $(CXXFLAGS)  -o melt_melt_py.o melt_py.cc

endif #ifeq ($(shell uname -m),x86_64)


