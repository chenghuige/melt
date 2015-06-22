#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   gen-contents.py
#        \author   chenghuige  
#          \date   2014-03-02 14:55:09.010411
#   \Description  
# ==============================================================================

import sys,os
import mysql_urate
from libchg import *

out = open(sys.argv[2],'w')
conn, cur = mysql_urate.urate_db()
for line in open(sys.argv[1]):
	try:
		l = line.strip().split('\t')
		pid = l[0]
		label = l[1]
		nresult = cur.execute('select title, content from instances where post_id=%s'%pid)
		results = cur.fetchmany(nresult)
		out.write('%s\t%s\t%s\n'%(label,results[0][0],results[0][1]))
	except Exception:
		print line,
		continue
