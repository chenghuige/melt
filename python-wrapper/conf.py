#define_symbols = ['GCCXML','PYTHON_WRAPPER','NO_BAIDU_DEP']
define_symbols = ['GCCXML','PYTHON_WRAPPER']

files = [
                                './gezi.include.python/common_util.h',
                                './gezi.include.python/Numeric/Vector/Vector.h',
                                './gezi.include.python/Numeric/Vector/WeightVector.h',
                                './gezi.include.python/Numeric/Vector/vector_util.h',
                                './gezi.include.python/Identifer.h',
                                './gezi.include.python/Segmentor.h',
                                './include.python/MLCore/Predictor.h',
                                './include.python/MLCore/PredictorFactory.h',
                                './include.python/MLCore/Trainer.h',
                                './include.python/MLCore/TrainerFactory.h',
                                './include.python/MLCore/TextPredictor.h',
                                #'./include.python/PythonWrapper/example.h',
                                #'./gezi.include.python/Segmentor.h',
				]

import gezi 
#files += [f for f in gezi.get_filepaths('./include.python/MLCore/') if f.endswith('.h')]

root = '/home/users/chenghuige/rsc/'

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
	      ]

include_paths_python = [
				'app/search/sep/anti-spam/melt/python-wrapper',
		       ]

include_paths_obsolute = [
                'app/search/sep/anti-spam/melt/python-wrapper/gezi.include.python',
        	'lib2-64/wordseg', 
        	'public/comlog-plugin',
        ]
