import os 
import sys
import glob
from pyplusplus import module_builder

import conf 
mb = module_builder.module_builder_t(
        gccxml_path = '~/.jumbo/bin/gccxml',
        define_symbols = conf.define_symbols,
        files = conf.files,
        include_paths = [conf.root + f + '/include' for f in conf.include_paths]
                        + [conf.root + f + '/include.python' for f in conf.include_paths_python]
                        + [conf.root + f  for f in conf.include_paths_obsolute]
        )

mb.build_code_creator( module_name='libmelt' )

mb.code_creator.user_defined_directories.append( os.path.abspath('.') )

mb.write_module( os.path.join( os.path.abspath('./'), 'melt_py.cc' )) 
