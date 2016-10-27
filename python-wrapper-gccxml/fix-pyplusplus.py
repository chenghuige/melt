#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   gen-py.py
#        \author   chenghuige  
#          \date   2014-03-02 17:04:31.480595
#   \Description  
# ==============================================================================

import sys,os

find = False
find_warning = False

print '#define private public'
print '#define protected public'
print '#include "python_util.h"'

input = sys.stdin
if len(sys.argv) > 1:
    input = open(sys.argv[1])
for line in input:
        line = line.rstrip()

        #if line.find('::std::ostream &') >=0 and line.endswith(';'):
        #    print '//' + line
        #    continue 

        if line.find('PyHack_') >= 0:
            print '//' + line 
            continue

	if(line.find('undefined call policies') < 0):
		if (find_warning):
			print '//',
			find_warning = False

                l = line.split('/')
                if l[0].startswith('#include ') and l[0].endswith('include.python'):
                    l[0] = l[0][:len('#include "')]
                    print l[0] + '/'.join(l[1:])
                    continue
                
                #bp::enum_< color>("color")
                # .value("color__enum__red", color__enum__red)
                if line.find('__enum__') >= 0:
                    if line.lstrip().startswith('.value("'):
                        l = line.split('"')
                        l[1] = l[1].split('__enum__')[-1]
                        l[2] = l[2].replace('__enum__', '::')
                        print '"'.join(l)
                    else:
                        line = line.replace('__enum__', '::')
                        print line 
                    continue

                line = line.replace('boost::unordered::', 'std::')
                line = line.replace('boost::unordered', 'std::unordered')
                line = line.replace('boost::shared_ptr', 'std::shared_ptr')
                line = line.replace('boost::make_shared', 'std::make_shared')
		print line
		if (line.find('WARNING:') >= 0):
			find_warning = True 
		if (find == False and line.find('BOOST_PYTHON_MODULE') >= 0):
			find = True
			print '''DEF_VEC(ivec);
			DEF_VEC(dvec);
			DEF_VEC(uvec);
			DEF_VEC(svec);
			DEF_VEC(ulvec);
			DEF_MAP(id_map);
			DEF_MAP(sd_map);
			DEF_MAP(si_map);
			DEF_MAP(ss_map);
			DEF_PAIR(ii_pair);
			DEF_PAIR(si_pair);
			DEF_PAIR(wsi_pair);
			DEF_VEC(si_pair_vec);
			DEF_VEC(wsi_pair_vec);
			DEF_SET(iset);
			DEF_SET(lset);
			DEF_SET(ulset);
			'''
	else:
		result = '            , bp::return_internal_reference<>())'
		if (line.find(';') >= 0):
			result += ';'
		print result

