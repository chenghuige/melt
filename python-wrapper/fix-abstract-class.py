#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   fix-abstract-class.py
#        \author   chenghuige  
#          \date   2015-06-25 15:45:38.061066
#   \Description  
# ==============================================================================

import sys,os

abstract_classes = set()
for line in open('abstract_class.txt'):
    aclass = line.split()[0]
    if not aclass.startswith('::'):
        aclass = '::' + aclass
    abstract_classes.add(aclass)

input = sys.stdin 
if len(sys.argv) > 1:
    input = open(sys.argv[1])

m = input.readlines()

def deal(m, i):
    m[i] = m[i].replace('>',  ', boost::noncopyable >')
    print m[i],
    m[i + 1] = m[i + 1].replace(');', ', bp::no_init);')
    print m[i + 1],

#{ //::gezi::Trainer 
i = 0
while i < len(m):
    if m[i].lstrip().startswith('{'):
        name = m[i].lstrip()[len('{\t//'):].rstrip()
        print m[i],
        i += 1
        if name in abstract_classes:
            deal(m, i)
            i += 2
        continue
    print m[i],
    i += 1

 
