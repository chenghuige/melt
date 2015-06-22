#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   fix-add-more-vector.py
#        \author   chenghuige  
#          \date   2014-10-06 17:59:31.486882
#   \Description  
# ==============================================================================

import sys,os

vectors = ['Vector', 'FeatureVector', 'Instances']

s = set()
def add_vector(line, name):
	if line.strip().startswith('%s_exposer.def'%name):
		item = 'VEC_METHOD2({0}_exposer, gezi::{0});'.format(name)
		if not item in s:
			s.add(item)
			print item

input = sys.stdin 
if len(sys.argv) > 1:
    input = open(sys.argv[1])
for line in input:
        for vector in vectors:
            add_vector(line, vector)
	print line,

 
