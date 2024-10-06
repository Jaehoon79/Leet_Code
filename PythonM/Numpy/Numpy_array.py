import math
import collections

import numpy as np
import pandas as pd
import matplotlib.pyplot as pp



def main():
    '''
    monalisa_bw = np.loadtxt('monalisa.txt')
    print(f"load monalisa txt {monalisa_bw}")
    print("--------------------------")
    print(f"ndim : {monalisa_bw.ndim}")
    print(f"shape : {monalisa_bw.shape}")
    print(f"dtype : {monalisa_bw.dtype}")
    print("--------------------------")
    
    #show image
    pp.imshow(monalisa_bw)
    print("Not show??")
    pp.show()

    #load npy file
    monalisa = np.load('monalisa.npy')
    print(f"shape: {monalisa.shape}")
    print(f"ndim: {monalisa.ndim}")
    pp.figure(figsize=(5,8))
    pp.imshow(monalisa)
    pp.show()
    '''
    
    #make new array.
    #np.zeros
    zero_1d = np.zeros(8, np.intc)
    print(zero_1d.dtype, zero_1d.size, zero_1d)
    
    zero_2d = np.zeros((8,8), np.float64)
    print(zero_2d.dtype, zero_2d.size, zero_2d)
    
    #np.zeros_like
    monalisa = np.loadtxt('monalisa.txt')
    zeros_like = np.zeros_like(monalisa)
    
    print(monalisa.ndim, monalisa.dtype, monalisa.size)
    print(zeros_like.ndim, zeros_like.dtype, zeros_like.size)
    print(monalisa)
    print(zeros_like)
    
    #np.linspace
    np_array = np.linspace(start=0, stop=100, num=5)
    print(np_array)
    np_array = np.linspace(0, 1, 16)
    print(np_array)
    #pp.plot(np_array, 'o')
    #pp.show()
    
    np_array = np.arange(start=0, stop=1.5, step=0.1)
    print(np_array)
    
    np_array = np.random.random(size=(8,8))
    print(np_array)
    
if __name__ == "__main__":
    main()