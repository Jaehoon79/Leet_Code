import math
import collections

import numpy as np
import pandas as pd
import matplotlib.pyplot as pp


def main():
    #numpy array indexing.
    list1 = [1, 2, 3, 4, 5, 6]
    list2 = [10, 9, 8, 7, 6, 5]
    
    np_list1 = np.array(list1)
    np_list2 = np.array(list2)
    
    #incase of list: we got a error
    #prşnt(list1 * list2)
    print(np_list1 * np_list2)
    
    list1 = [3, 1, 2]
    np_array = np.arange(10, 0, -2)
    print(np_array[np.array([3, 1, 2])])

def basic_slicing_main():
    # Arrange elements from 0 to 19
    a = np.arange(20)
    print("\n Array is:\n ",a)
 
    # a[start:stop:step]
    print("\n a[-8:17:1]  = ", a[-8:17:1]) 
 
    # The : operator means all elements till the end.
    print("\n a[10:]  = ", a[10:])
    
    # A 3-Dimensional array
    a = np.array([[0, 1, 2, 3, 4, 5],
                  [6, 7, 8, 9, 10, 11],
                  [12, 13, 14, 15, 16, 17],
                  [18, 19, 20, 21, 22, 23],
                  [24, 25, 26, 27, 28, 29],
                  [30, 31, 32, 33, 34, 35]])

    print("\n Array is:\n ",a)
    # slicing and indexing
    print("\n a[0, 3:5]  = ", a[0, 3:5]) 
    print("\n a[4:, 4:]  = ", a[4:, 4:]) 
    print("\n a[:, 2]  = ", a[:, 2]) 
    print("\n a[2:;2, ::2]  = ",a[2::2, ::2])

def boolean_array_indexing():
    nparray = np.array([10, 40, 80, 50, 100])
    print(nparray[nparray>50])
    print(nparray[nparray % 40 == 0] ** 2)
    
     
    nparray2 = np.array([[5, 5],[4, 5],[16, 4]])
    sumrow = nparray2.sum(-1)
    print(sumrow)

if __name__ == "__main__":
    #main()
    #basic_slicing_main() 
    boolean_array_indexing()