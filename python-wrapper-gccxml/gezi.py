import os 
import sys
import glob
from pyplusplus import module_builder

root = '/home/users/chenghuige/rsc/'
name = 'gezi'
#define_symbols = ['GCCXML','PYTHON_WRAPPER','NO_BAIDU_DEP']
define_symbols = ['GCCXML','PYTHON_WRAPPER']

files = [
					'include.python/common_util.h',  #for safe let it be first for without it file_util.h or string_util.h... will fail
					
					#'./include.python/Numeric/Vector/Vector.h',
					#'./include.python/feature/FeatureVector.h', 

					##------------below has been tested ok
					##feature related
					#'./include.python/feature/features_util.h',
					#'./include.python/feature/FeaturesExtractor.h',
					#'./include.python/feature/FeaturesExtractorMgr.h',
					##-------------predictor 
					##'./include.python/PythonWrapper/TextPredictor.h',
					#'./include.python/PythonWrapper/Predictor.h',
					#'./include.python/PythonWrapper/PredictorFactory.h',
					##-------------ip util
					#'./include.python/tools/IpFinder.h',
					#'./include.python/tools/ip.h',
					#'./include.python/tools/uname_util.h',
					##-------------redis util
          ##'./include.python/tools/redis/RedisClient.h',
					##-------------feature selector and idf 
					#'./include.python/feature/FeatureSelector.h',
					#'./include.python/Idf.h',
					#'./include.python/Numeric/collocation.h',
					#-------------segmentor 
					#'./include.python/Segmentor.h',
					#-------------common utils
					'./include.python/ProgressBar.h',
					#'./include.python/Identifer.h',
          #'./include.python/SharedIdentifers.h',
          #'./include.python/SharedObjects.h',
					'./include.python/conf_util.h',
					'./include.python/serialize_util.h',
					'./include.python/log_util.h',
					'./include.python/tools/content_process.h',
					'./include.python/string_util.h',
					'./include.python/reg_util.h',
					'./include.python/file_util.h',
					'./include.python/encoding_convert.h',
					##-------------tieba utils 
					#'./include.python/tieba/tieba_util.h',
					#'./include.python/tieba/get_info.h',
          #'./include.python/tieba/get_parsed_info.h',
          #'./include.python/tieba/info/delete_info.h',
          #'./include.python/tieba/info/forum_info.h',
          #'./include.python/tieba/info/post_info.h',
          #'./include.python/tieba/info/thread_info.h',
          #'./include.python/tieba/info/url_info.h',
          #'./include.python/tieba/info/user_info.h',
          #'./include.python/tieba/info/user_posts_info.h',
          #'./include.python/tieba/info_def.h',
          #'./include.python/tieba/uname_util.h',
          #'./include.python/tieba/common_def.h',
          #'./include.python/tieba/urate/get_urate_info.h',
          #'./include.python/tieba/urate/urate_info.h'
				]

paths = [
            #'./gezi.include.python/Numeric/Vector/',
            #'./include.python/MLCore/',
            #'./include.python/Prediction/Instances/',
        ]

#import gezi 
#for path in paths:
#    files += [f for f in gezi.get_filepaths(path) if f.endswith('.h')]

include_paths=[ 
				'third-64/glog',
				'third-64/gflags',
                                'third-64/gtest',
				'third-64/boost.1.53',
                'lib2-64/bsl',
        	'lib2-64/postag',
        	'lib2-64/dict',
        	'lib2-64/libcrf',
        	'lib2-64/others-ex',
        	'lib2-64/ullib',
                'lib2-64/ccode',
                'public/odict/output',
                'public/uconv/output',
                'public/configure/output',
                'other/rabit',
	      ]

include_paths_python = [
				'app/search/sep/anti-spam/gezi/python-wrapper-new',
		       ]

include_paths_obsolute = [
          #'app/search/sep/anti-spam/melt/python-wrapper/gezi.include.python',
        	'lib2-64/wordseg', 
        	'public/comlog-plugin',
        ]

mb = module_builder.module_builder_t(
        gccxml_path = '~/.jumbo/bin/gccxml',
        define_symbols = define_symbols,
        files = files,
        include_paths = [root + f + '/include' for f in include_paths]
                        + [root + f + '/include.python' for f in include_paths_python]
                        + [root + f  for f in include_paths_obsolute]
        )

mb.build_code_creator( module_name='lib%s'%name )

mb.code_creator.user_defined_directories.append( os.path.abspath('.') )

mb.write_module( os.path.join( os.path.abspath('./'), '%s_py.cc'%name) ) 
