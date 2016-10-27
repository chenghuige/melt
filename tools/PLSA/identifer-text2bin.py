#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   identifer-text2bin.py
#        \author   chenghuige  
#          \date   2014-05-05 10:43:12.711473
#   \Description  
# ==============================================================================

import sys,os

from libmelt import *

identifer = Identifer()

identifer.load(sys.argv[1])

identifer.Save(sys.argv[2])
 
