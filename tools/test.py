#!/usr/bin/env python
#coding=gbk
# ==============================================================================
#          \file   test.py
#        \author   chenghuige  
#          \date   2014-04-25 13:09:50.053362
#   \Description  
# ==============================================================================

import sys,os
from gezi import * 
p = PredictorFactory.LoadPredictor('./model.fastrank/')
print p.Output(Vector())
print p.Predict(Vector())

