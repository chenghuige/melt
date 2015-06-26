#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   c++11fix.py
#        \author   chenghuige  
#          \date   2014-04-16 16:19:59.330937
#   \Description  
# ==============================================================================

import sys,os
import re 

#@NOTICE assume input has been deal with remove-comment and format-c++ script
pre_nogccxml = 0
pre_rvalue = False
pre_construct = False
construct_count = 0
pre_define = False
pre_comment = 0
base_classes = set()

#---for enum clas
out = open('enum_class.txt', 'a')
pre_enum_class = False
class_name = ''


input = sys.stdin
if len(sys.argv) > 1:
	input = open(sys.argv[1])

m = input.readlines()

i = 0

while i < len(m):
	line = m[i]
	#------cereal shared ptr
	if line.startswith('CEREAL_REGISTER_TYPE'):
		print_('//' + line)
		i += 1
		continue
				
	#-------cereal to boost
	line = line.replace('cereal::', 'boost::serialization::')

		#---- hack boost, serialization
		if (line.find("boost/math/distributions/students_t.hpp") >= 0 or line.find("boost/date_time/posix_time/posix_time.hpp") >= 0):
			print_('//' + line)
			continue

		if (line.find('serialization/') >= 0 or line.find('serialization::') >= 0 or line.find('boost/archive/') >= 0):
			print_('//' + line)
			continue

		# hack define
		if line.replace(' ', '').startswith('#define'):
			while not line.endswith('\\'):
				print line
				i += 1
				line = m[i]
			continue	
	print line
	i += 1

 
