#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=~/.jumbo/opt/gcc48/bin/g++
CXX=~/.jumbo/opt/gcc48/bin/g++
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
  -fopenmp
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
  -fopenmp
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\"
INCPATH=-I/home/users/chenghuige/.jumbo//include/python2.7
DEP_INCPATH=-I../../../../../../app/search/ksarch/store/proxy-lib/redis \
  -I../../../../../../app/search/ksarch/store/proxy-lib/redis/include \
  -I../../../../../../app/search/ksarch/store/proxy-lib/redis/output \
  -I../../../../../../app/search/ksarch/store/proxy-lib/redis/output/include \
  -I../../../../../../app/search/sep/anti-spam/gezi \
  -I../../../../../../app/search/sep/anti-spam/gezi/include \
  -I../../../../../../app/search/sep/anti-spam/gezi/output \
  -I../../../../../../app/search/sep/anti-spam/gezi/output/include \
  -I../../../../../../app/search/sep/anti-spam/melt \
  -I../../../../../../app/search/sep/anti-spam/melt-train \
  -I../../../../../../app/search/sep/anti-spam/melt-train/include \
  -I../../../../../../app/search/sep/anti-spam/melt-train/output \
  -I../../../../../../app/search/sep/anti-spam/melt-train/output/include \
  -I../../../../../../app/search/sep/anti-spam/melt/include \
  -I../../../../../../app/search/sep/anti-spam/melt/output \
  -I../../../../../../app/search/sep/anti-spam/melt/output/include \
  -I../../../../../../com/btest/gtest \
  -I../../../../../../com/btest/gtest/include \
  -I../../../../../../com/btest/gtest/output \
  -I../../../../../../com/btest/gtest/output/include \
  -I../../../../../../com/idlcompiler \
  -I../../../../../../com/idlcompiler/include \
  -I../../../../../../com/idlcompiler/output \
  -I../../../../../../com/idlcompiler/output/include \
  -I../../../../../../inf/computing/ant \
  -I../../../../../../inf/computing/ant/include \
  -I../../../../../../inf/computing/ant/output \
  -I../../../../../../inf/computing/ant/output/include \
  -I../../../../../../inf/computing/java6 \
  -I../../../../../../inf/computing/java6/include \
  -I../../../../../../inf/computing/java6/output \
  -I../../../../../../inf/computing/java6/output/include \
  -I../../../../../../inf/computing/zookeeper \
  -I../../../../../../inf/computing/zookeeper/include \
  -I../../../../../../inf/computing/zookeeper/output \
  -I../../../../../../inf/computing/zookeeper/output/include \
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
  -I../../../../../../lib2-64/nlp/compact-trie \
  -I../../../../../../lib2-64/nlp/compact-trie/include \
  -I../../../../../../lib2-64/nlp/compact-trie/output \
  -I../../../../../../lib2-64/nlp/compact-trie/output/include \
  -I../../../../../../lib2-64/others-ex \
  -I../../../../../../lib2-64/others-ex/include \
  -I../../../../../../lib2-64/others-ex/output \
  -I../../../../../../lib2-64/others-ex/output/include \
  -I../../../../../../lib2-64/postag \
  -I../../../../../../lib2-64/postag/include \
  -I../../../../../../lib2-64/postag/output \
  -I../../../../../../lib2-64/postag/output/include \
  -I../../../../../../lib2-64/string \
  -I../../../../../../lib2-64/string/include \
  -I../../../../../../lib2-64/string/output \
  -I../../../../../../lib2-64/string/output/include \
  -I../../../../../../lib2-64/text-util \
  -I../../../../../../lib2-64/text-util/include \
  -I../../../../../../lib2-64/text-util/output \
  -I../../../../../../lib2-64/text-util/output/include \
  -I../../../../../../lib2-64/ullib \
  -I../../../../../../lib2-64/ullib/include \
  -I../../../../../../lib2-64/ullib/output \
  -I../../../../../../lib2-64/ullib/output/include \
  -I../../../../../../lib2-64/wordseg \
  -I../../../../../../lib2-64/wordseg/include \
  -I../../../../../../lib2-64/wordseg/output \
  -I../../../../../../lib2-64/wordseg/output/include \
  -I../../../../../../op/oped/noah/webfoot/naming-lib \
  -I../../../../../../op/oped/noah/webfoot/naming-lib/include \
  -I../../../../../../op/oped/noah/webfoot/naming-lib/output \
  -I../../../../../../op/oped/noah/webfoot/naming-lib/output/include \
  -I../../../../../../ps/se/dict-set \
  -I../../../../../../ps/se/dict-set/include \
  -I../../../../../../ps/se/dict-set/output \
  -I../../../../../../ps/se/dict-set/output/include \
  -I../../../../../../ps/se/include \
  -I../../../../../../ps/se/include/include \
  -I../../../../../../ps/se/include/output \
  -I../../../../../../ps/se/include/output/include \
  -I../../../../../../ps/se/toolchain \
  -I../../../../../../ps/se/toolchain/include \
  -I../../../../../../ps/se/toolchain/output \
  -I../../../../../../ps/se/toolchain/output/include \
  -I../../../../../../public/bslext \
  -I../../../../../../public/bslext/include \
  -I../../../../../../public/bslext/output \
  -I../../../../../../public/bslext/output/include \
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
  -I../../../../../../public/gm/galileo \
  -I../../../../../../public/gm/galileo/include \
  -I../../../../../../public/gm/galileo/output \
  -I../../../../../../public/gm/galileo/output/include \
  -I../../../../../../public/idlcompiler \
  -I../../../../../../public/idlcompiler/include \
  -I../../../../../../public/idlcompiler/output \
  -I../../../../../../public/idlcompiler/output/include \
  -I../../../../../../public/mcpack \
  -I../../../../../../public/mcpack/include \
  -I../../../../../../public/mcpack/output \
  -I../../../../../../public/mcpack/output/include \
  -I../../../../../../public/nshead \
  -I../../../../../../public/nshead/include \
  -I../../../../../../public/nshead/output \
  -I../../../../../../public/nshead/output/include \
  -I../../../../../../public/odict \
  -I../../../../../../public/odict/include \
  -I../../../../../../public/odict/output \
  -I../../../../../../public/odict/output/include \
  -I../../../../../../public/spreg \
  -I../../../../../../public/spreg/include \
  -I../../../../../../public/spreg/output \
  -I../../../../../../public/spreg/output/include \
  -I../../../../../../public/ub \
  -I../../../../../../public/ub/include \
  -I../../../../../../public/ub/output \
  -I../../../../../../public/ub/output/include \
  -I../../../../../../public/uconv \
  -I../../../../../../public/uconv/include \
  -I../../../../../../public/uconv/output \
  -I../../../../../../public/uconv/output/include \
  -I../../../../../../public/urlparser \
  -I../../../../../../public/urlparser/include \
  -I../../../../../../public/urlparser/output \
  -I../../../../../../public/urlparser/output/include \
  -I../../../../../../quality/autotest/reportlib/cpp \
  -I../../../../../../quality/autotest/reportlib/cpp/include \
  -I../../../../../../quality/autotest/reportlib/cpp/output \
  -I../../../../../../quality/autotest/reportlib/cpp/output/include \
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
  -I../../../../../../third-64/pcre \
  -I../../../../../../third-64/pcre/include \
  -I../../../../../../third-64/pcre/output \
  -I../../../../../../third-64/pcre/output/include \
  -I../../../../../../third-64/protobuf \
  -I../../../../../../third-64/protobuf/include \
  -I../../../../../../third-64/protobuf/output \
  -I../../../../../../third-64/protobuf/output/include \
  -I../../../../../../third-64/stlport \
  -I../../../../../../third-64/stlport/include \
  -I../../../../../../third-64/stlport/output \
  -I../../../../../../third-64/stlport/output/include \
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
COMAKE_MD5=8eaf505e305e51eb232f54508c7ea8d3  COMAKE


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
	$(CC) -shared melt_melt_py.o -Xlinker "-(" ./lib/libpython2.7.so \
  ./lib/libboost_python.so ../../../../../../app/search/ksarch/store/proxy-lib/redis/libredisclient.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_common.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_cppformat.a \
  ../../../../../../app/search/sep/anti-spam/gezi/libgezi_json.a \
  ../../../../../../app/search/sep/anti-spam/gezi/output/lib/libPYNotation.a \
  ../../../../../../app/search/sep/anti-spam/melt-train/libmelt_trainers.a \
  ../../../../../../app/search/sep/anti-spam/melt/libblas.a \
  ../../../../../../app/search/sep/anti-spam/melt/liblinear.a \
  ../../../../../../app/search/sep/anti-spam/melt/libmelt.a \
  ../../../../../../app/search/sep/anti-spam/melt/libsofia.a \
  ../../../../../../app/search/sep/anti-spam/melt/libsvm.a \
  ../../../../../../app/search/sep/anti-spam/melt/libvw.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../../../com/idlcompiler/parser/libparser.a \
  ../../../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../../../inf/computing/zookeeper/output/c_client/lib/libzookeeper_mt.a \
  ../../../../../../inf/computing/zookeeper/output/c_client/lib/libzookeeper_st.a \
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
  ../../../../../../lib2-64/nlp/compact-trie/lib/libctrie.a \
  ../../../../../../lib2-64/others-ex/lib/libullib_ex.a \
  ../../../../../../lib2-64/postag/lib/libpostag.a \
  ../../../../../../lib2-64/string/lib/libstring.a \
  ../../../../../../lib2-64/text-util/lib/libtextutil.a \
  ../../../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../../../lib2-64/wordseg/libsegment.a \
  ../../../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../../../ps/se/dict-set/libdictset.a \
  ../../../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../../../public/bslext/output/lib/libbslext.a \
  ../../../../../../public/comlog-plugin/libcomlog.a \
  ../../../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../../../public/configure/libconfig.a \
  ../../../../../../public/connectpool/libconnectpool.a \
  ../../../../../../public/gm/galileo/libgalileo.a \
  ../../../../../../public/gm/galileo/output/lib/libzookeeper_mt.a \
  ../../../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../../../public/mcpack/libmcpack.a \
  ../../../../../../public/nshead/libnshead.a \
  ../../../../../../public/odict/libodict.a \
  ../../../../../../public/spreg/libspreg.a \
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
  ../../../../../../public/uconv/libuconv.a \
  ../../../../../../public/urlparser/libnewurl.a \
  ../../../../../../quality/autotest/reportlib/cpp/libautotest.a \
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
  ../../../../../../third-64/boost/lib/libboost_context.a \
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
  ../../../../../../third-64/libcurl/lib/libcurl.a \
  ../../../../../../third-64/pcre/lib/libpcre.a \
  ../../../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../../../third-64/protobuf/lib/libprotoc.a \
  ../../../../../../third-64/tcmalloc/lib/libprofiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_and_profiler.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_debug.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal.a \
  ../../../../../../third-64/tcmalloc/lib/libtcmalloc_minimal_debug.a \
  ../../../../../../third-64/zlib/lib/libz.a -lpthread \
  -lcurl \
  -lrt \
  -lcrypto \
  -lldap \
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
  -DBOOST_BIND_PLACEHOLDERS_HPP_INCLUDED $(CXXFLAGS)  -o melt_melt_py.o melt_py.cc

endif #ifeq ($(shell uname -m),x86_64)


