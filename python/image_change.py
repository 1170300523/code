# -*- coding: utf-8 -*-
"""
Created on Thu Feb  7 17:11:12 2019

@author: lee32
"""

from PIL import Image
import numpy as np
a = np.array(Image.open("C:/Users/lee32/Desktop/task/program/python/1.jpg"))
b  = a * 0.5 
im = Image.fromarray(b.astype('uint8'))
im.save("C:/Users/lee32/Desktop/task/program/python/changed.jpg")