#!/usr/bin/python

import ctypes
TestLib = ctypes.cdll.LoadLibrary('./TestLib.so')

def SampleAdd(x,y):
    return TestLib.SampleAddInt(x,y)
