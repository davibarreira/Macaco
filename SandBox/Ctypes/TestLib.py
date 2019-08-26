#!/usr/bin/python

import ctypes

def main():
        TestLib = ctypes.cdll.LoadLibrary('./TestLib.so')
        print(TestLib.SampleAddInt(1, 2))

if __name__ == '__main__':
        main()
