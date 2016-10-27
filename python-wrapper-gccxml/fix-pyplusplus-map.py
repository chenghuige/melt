#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   fix-pyplusplus-stl.py
#        \author   chenghuige  
#          \date   2014-10-03 14:25:12.388520
#   \Description  
# ==============================================================================

import sys,os

def fix_map(line):
	if line.strip().startswith('//'):
		return line
	pattern = 'bp::map_indexing_suite<'
	pos = line.find(pattern)
	if pos >= 0:
		#print line
		pos += len(pattern) 
		pos2 = line.find('>')
		line2 = line[pos : pos2 + 1]
		#print line2
		#pos3 = line2.rfind(',')
		#line2 = line2[0 : pos3]
		#print line2
		name = line2.strip().replace(',', ' COMMA ')
		#print name
		return line.strip()[:-1] + '\n' + 'MAP_METHOD(%s)'%name + ";\n"
	else:
		return line

input = sys.stdin
if len(sys.argv) > 1:
    input = open(sys.argv[1])

for line in input:
	print fix_map(line),
 
