#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   run-param-evaluate.py
#        \author   chenghuige  
#          \date   2014-07-26 16:05:47.131512
#   \Description  
# ==============================================================================

import sys,os
for line in open(sys.argv[1]):
	command = line.strip()
	os.system(command)

 
