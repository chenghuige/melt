#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   seg-text.py
#        \author   chenghuige  
#          \date   2014-03-08 17:01:57.385278
#   \Description  input is like urate feature file, ouput (pid, label, seged title, seged content)
#                 get title, content from db
# ==============================================================================

import sys, os
from gezi import *

LogHelper.set_level(4)
Segmentor.init()
seg = Segmentor()
print seg.segment('我的扣扣是', '|', SEG_MERGE_NEWWORD)
total = len(open(sys.argv[1]).readlines())
print 'total: %d'%total 
_pb = ProgressBar(total)
_identifer = Idf()
out = open(sys.argv[2], 'w')
num = 0
for line in open(sys.argv[1]):
	_pb.progress(num)
	try:
		l = line.strip().split('\t')
		title = l[2]
		content = ''
		if (len(l) > 3):
			content = l[3]
		title = get_real_title(title)
		content = strip_html(content)
		content = normalize_str(content)
		src = title + ' ' + content
		#vec = seg.segment(src, SEG_MERGE_NEWWORD)
		vec = seg.segment(src)
		for item in vec:
			_identifer.add(item)
		out.write('%s\n'%('\t'.join(vec)))
		num += 1
	except Exception:
		print line,
		pass

_identifer.save(sys.argv[3], 5, 3)
#_identifer.Save(sys.argv[4])
print "num: %d"%num
