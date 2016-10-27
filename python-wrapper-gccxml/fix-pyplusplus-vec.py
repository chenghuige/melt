#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   fix-pyplusplus-stl.py
#        \author   chenghuige  
#          \date   2014-10-03 14:25:12.388520
#   \Description  
# ==============================================================================

import sys,os

def fix_vec(line):
	if line.strip().startswith('//'):
		return line
	pattern = 'bp::vector_indexing_suite<'
	pos = line.find(pattern)
	if pos >= 0:
		pos += len(pattern) 
		pos2 = line.rfind('>')
		line2 = line[pos : pos2]
		if line2.find('true') > 0:
			pos3 = line2.rfind(',')
			line2 = line2[0 : pos3]
		name = line2.strip() 
		return line.strip()[:-1] + '\n' + 'VEC_METHOD(%s)'%name + ";\n"
	else:
		return line

input = sys.stdin 
if len(sys.argv) > 1:
    input = open(sys.argv[1])

for line in input:
	print fix_vec(line),
 
