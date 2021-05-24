# -*- coding: utf-8 -*-
"""
Created on Mon Dec  9 22:14:55 2019

@author: NIHAL KHALED
"""
from keras.models import load_model
model = load_model('model.h5')
model.summary()
model.evaluate(5)
