#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   set-verion.py
#        \author   chenghuige  
#          \date   2015-05-15 21:40:02.612500
#   \Description  
# ==============================================================================

import sys,os

for line in open(sys.argv[1]):
    #-DVERSION=\"1.9.8.7\"
    line = line.rstrip()
    prefix = '-DVERSION=\\"'
    end = '\\"'
    pos = line.find(prefix) 
    if pos < 0:
        print line
    else: 
        if line.endswith('\\'):
            end += ' \\'
        #print line[pos + len(prefix):-3]
        print line[:pos] + prefix + sys.argv[2] + end

