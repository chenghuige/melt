import os 
import sys
import glob
from pyplusplus import module_builder

root = '/home/users/chenghuige/rsc/'
name = 'melt_predict'
#define_symbols = ['GCCXML','PYTHON_WRAPPER','NO_BAIDU_DEP']
define_symbols = ['GCCXML','PYTHON_WRAPPER']

files = [
                                './gezi.include.python/common_util.h',
                                './include.python/MLCore/Predictor.h',
                                './include.python/MLCore/TextPredictor.h',
                                './gezi.include.python/Identifer.h',
                                './include.python/MLCore/PredictorFactory.h',
                                './gezi.include.python/Numeric/Vector/Vector.h',
                                './gezi.include.python/Numeric/Vector/WeightVector.h',
                                './gezi.include.python/Numeric/Vector/vector_util.h',
                                './gezi.include.python/feature/FeatureVector.h',
                                './gezi.include.python/feature/features_util.h',
                                './gezi.include.python/feature/FeatureExtractor.h',
                                './gezi.include.python/feature/FeaturesExtractorMgr.h',
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
				'app/search/sep/anti-spam/melt/python-wrapper',
		       ]

include_paths_obsolute = [
          'app/search/sep/anti-spam/melt/python-wrapper/gezi.include.python',
        	'lib2-64/wordseg', 
        	'public/comlog-plugin',
					'app/search/sep/anti-spam/gezi/third',
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
