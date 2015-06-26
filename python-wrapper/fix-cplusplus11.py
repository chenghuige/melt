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


construct_count = 0
base_classes = set()

#---for enum clas
out = open('enum_class.txt', 'a')
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
		i += 1
		continue

	if (line.find('serialization/') >= 0 or line.find('serialization::') >= 0 or line.find('boost/archive/') >= 0):
		print_('//' + line)
		i += 1
		continue

	# hack define
	if line.replace(' ', '').startswith('#define'):
		while line.endswith('\\'):
			print line
			i += 1
			line = m[i]
		print line
		i += 1
		continue	

	#using Vector::Vector;
	l = [s for s in line.replace(',', ' ').replace(':', ' ').split(' ') if s != '']
	if len(l) >=  4 and (l[0] == 'class' or l[0] == 'struct' or l[0] == 'interface') and l[2] == 'public':
		base_classes = set()
		for item in l[3:]:
			base_classes.add(item)

	if line.startswith('using') and len(base_classes) > 0:
		find = False 
		for item in base_classes:
			if line.endswith('%s::%s;'%(item, item)):
				find = True
				break
			if find:
				print_('//' + line)
				i += 1
				continue

		if line.startswith('enum class'):
			l = line.split()
			class_name = l[2]
			out.write(class_name + '\n');
			if line.endswith('};'):
				line = line[line.find('{') + 1 : line.find('};')]
					member_names = [class_name + '__enum__' + (item + ' ')[:item.find('=')].strip() for item in line.split(',') if item != '']
					print  'enum ' + class_name 
					print '{'
					for member in member_names:
						print member + ','
						print '};'
					i += 1
					continue
			else:
				print line.replace('class', '')
				i += 1
				while not (line.endswith('};')):
					if line.endswith(','):
						print class_name + '__enum__' + line[:line.find('=')]).strip() + ','
					else：
						print class_name + '__enum__' + (line + ' ')[:line.find('=')]).strip() + ','
					i += 1

	if (line.startswith('/') or line.startswith('#') or line.startswith('*') or line.startswith('namespace')):
		print line
		i += 1
		continue 

	print line
	i += 1

 
