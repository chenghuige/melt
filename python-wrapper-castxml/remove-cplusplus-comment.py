#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   remove-cplusplus-comment.py
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
    if line.startswith('//'):
        i += 1
        continue
    
    if line.startswith('/*'):
        nl, nr = count_pair(line, '/*', '*/', 0, 0)
        while (nl != nr):
            i += 1
            nl, nr = count_pair(m[i], '/*', '*/', nl, nr)
        i += 1
        continue

    if line.find('//') > 0 :
        line = line[:line.find('//')]

    if line.find('/*') > 0:
        print line[:line.find('/*')]
        nl, nr = count_pair(line, '/*', '*/', 0, 0)
        while (nl != nr and i + 1 < len(m)):
            i += 1
            nl, nr = count_pair(m[i], '/*', '*/', nl, nr)
        i += 1
        continue

    print line 
    i += 1


 
