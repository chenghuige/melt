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
nameonly_classes = set()
for line in open('abstract_class.txt'):
    aclass = line.split()[0]
    if not aclass.startswith('::'):
        aclass = '::' + aclass
    abstract_classes.add(aclass)
    nameonly_classes.add('%s'%aclass.split('::')[-1])

input = sys.stdin 
if len(sys.argv) > 1:
    input = open(sys.argv[1])

m = input.readlines()


#{ //::gezi::Trainer 
# { //::gezi::Trainer
# typedef bp::class_< Trainer_wrapper , boost::noncopyable > Trainer_exposer_t;
# Trainer_exposer_t Trainer_exposer = Trainer_exposer_t( "Trainer" , bp::no_init);
def deal(m, i):
    print m[i].replace('>',  ', boost::noncopyable >'),
    print m[i + 1].replace(');', ', bp::no_init);'),


#bp::class_< ValidatingTrainer_wrapper, bp::bases< gezi::Trainer > >( "ValidatingTrainer", bp::init< >()  )
#bp::class_< ValidatingTrainer_wrapper, bp::bases< gezi::Trainer >, boost::noncopyable >( "ValidatingTrainer", bp::no_init )
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
    
    if m[i].lstrip().startswith('bp::class_'):
        name = m[i][m[i].index('"') + 1 : m[i].rindex('"')]
        remove_end = m[i][ : m[i].rindex('"') + 1]
        if name in nameonly_classes:
            print remove_end.replace('> >', '>, boost::noncopyable >') + ', bp::no_init )'
            i += 1
            continue

    print m[i],
    i += 1

 
