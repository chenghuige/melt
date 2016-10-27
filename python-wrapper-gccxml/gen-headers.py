#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   gen-headers.py
#        \author   chenghuige  
#          \date   2015-06-19 22:26:58.345598
#   \Description  
# ==============================================================================

import sys,os
import conf

for file_ in conf.files:
    file2_ = file_.replace('include', 'include.python')
    os.system('cp %s %s'%(file_, file2_)) 
    cmd = 'gen-header.sh ' + file2_ 
    print cmd
    os.system(cmd)
 
