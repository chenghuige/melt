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

m = [f.strip() for f in input.readlines()]

i = 0

while i < len(m):
	line = m[i] 

	is_func = False
	func_idx = line.find('//func')
	if func_idx >= 0:
		is_func = True
		line = line[:func_idx] 

	#------cereal shared ptr
	if line.startswith('CEREAL_REGISTER_TYPE'):
		print '//' + line
		i += 1
		continue
	
	if line.startswith('extern '):
		print '//' + line
		i += 1
		continue
				
	#-------cereal to boost
	line = line.replace('cereal::', 'boost::serialization::')

	#---- hack boost, serialization
	if (line.find("boost/math/distributions/students_t.hpp") >= 0 or line.find("boost/date_time/posix_time/posix_time.hpp") >= 0):
		print '//' + line
		i += 1
		continue

	if (line.find('serialization/') >= 0 or line.find('serialization::') >= 0 or line.find('boost/archive/') >= 0):
		print '//' + line
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

	#vector<int> vec = {1,2, 3};
	if line.endswith('='):
		if i + 1 < len(m) and m[i + 1].startswith('{'):
			print line[:line.rfind('=')].rstrip() + ';'
			while not (m[i].startswith('};')) and not (m[i].strip() == ';' and i - 1 >= 0 and m[i - 1].strip() == '}'):
				i += 1
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
			print '//' + line
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
			print '{'
			i += 2
			while not (m[i].endswith('};')):
				if m[i].endswith(','):
					print (class_name + '__enum__' + m[i][:m[i].find('=')]).strip() + ','
				else:
					print (class_name + '__enum__' + (m[i] + ' ')[:m[i].find('=')]).strip() + ','
				i += 1
			print m[i]
			i += 1
			continue

	if (line.startswith('/') or line.startswith('#') or line.startswith('*') or line.startswith('namespace')):
		print line
		i += 1
		continue 


	end_idx = line.rfind(';')
	if (end_idx == -1):
		print line
		i += 1
		continue
	if (line.startswith('const static') or line.startswith('static')):
		print line
		i += 1
		continue

	# idx1 = line.rfind(')')
	# idx2 = line.rfind('=')
	# idx3 = line.find('(')
	# idx4 = line.find('=')
				
	# line2 = line.replace(' ', '')
	# if idx3 >= 0 and idx4 >= 0 and idx3 > idx4 and line2.find('operator=') < 0 and line2.find('operator>') < 0 and line2.find('operator<') < 0 and line2.find('operator!')< 0 and line2.find('operator+') < 0 and line2.find('operator-') < 0 and line2.find('operator*') and line2.find('operator/') < 0:
	# 	line = line[:idx4] + ';'
	# 	if line.startswith('const'):
	# 		line = line[len('const') + 1:]
	# 		print line
	# 		i += 1 
	# 		continue

	# if (idx1 > idx2):
	# 	print line
	# 	i += 1
	# 	continue

	# if idx2 == -1:
	# 	print line
	# 	i += 1
	# 	continue 

	# line = line[:idx2]
	# line = line.strip() + ';'
	# if line.startswith('const'):
	# 	line = line[len('const') + 1:]
	# 	print line
	# 	i += 1
	# 	continue 

	#const int x = 3;	
	if not is_func:
		idx = line.find('=')
		line = line[:idx].strip() + ';'
		if line.startswith('const') and not line.find('*') > 0:
			line = line[len('const') + 1:]

	print line
	i += 1

 
