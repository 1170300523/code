# -*- coding: utf-8 -*-
"""
Created on Thu Feb  7 15:26:19 2019

@author: lee32
"""
import numpy as np
a = np.arange(100).reshape(5,20)
np.savetxt('test.csv',a,fmt = '%d',delimiter = ',')
