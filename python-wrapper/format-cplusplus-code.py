#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   format-cplusplus-comment.py
#        \author   chenghuige  
#          \date   2015-06-24 16:45:06.071654
#   \Description  
# ==============================================================================

import sys,os

def count_pair(line, pl, pr, nl, nr):
    nl += line.count(pl)
    nr += line.count(pr)
    return nl,nr

input = sys.stdin
if len(sys.argv) > 1:
    input = open(sys.argv[1])
m = input.readlines()

i = 0
while i < len(m):
    line = m[i].strip()
    if line == '':
        i += 1
        continue
    idx = line.find('{')
    if not line.startswith('namespace') and not line.startswith('#define') and idx > 0 and not(i > 1 and m[i - 1].rstrip().endswith('\\')):
        print line[:idx]
        print line[idx:]
        i += 1
        continue

    print line 
    i += 1


 
