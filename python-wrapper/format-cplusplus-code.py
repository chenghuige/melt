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

    if line != '{' and line != '}' and line.replace(' ', '') != '};' and not line.startswith('namespace')and not line.startswith('#define') and not(i > 1 and m[i -1].strip().endswith('\\')) and not line.startswith('enum class '):
        l = []
        for item in line:
            if item == '{' or item == '}':
                l.append('\n')
                l.append(item)
                l.append('\n')
            else:
                l.append(item)
        l = [f.strip() for f in ''.join(l).strip().split('\n') if f.strip() != '']
        print '\n'.join(l).strip()
        i += 1
        continue

    print line 
    i += 1


 
