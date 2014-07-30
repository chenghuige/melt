#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   gen-commands-from-params.py
#        \author   chenghuige  
#          \date   2014-07-26 12:54:00.222597
#   \Description  
# ==============================================================================

import sys,os

prefix = './melt %s -vl -1 -cl fr -c cv2 -calibrate=0 -rs 12345678'%sys.argv[1]
param_names = []
param_values = []
for line in open(sys.argv[2]):
	l = line.strip().split('=')
	param_names.append(' -' + l[0] + ' ')
	param_values.append(l[1].split(','))


def gen_all(level):
	if level == len(param_names):
		return ['']
	l = gen_all(level + 1)
	l2 = []
	for i in range(len(param_values[level])):
		for param in l:
			l2.append(param_names[level] + param_values[level][i] + ' ' + param)
	return l2

l = gen_all(0)
for param in l:
	command = prefix + param
	print command
