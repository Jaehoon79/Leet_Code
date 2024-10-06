import math
import collections

import numpy as np
import pandas as pd
import matplotlib.pyplot as pp

def main():
    discography = np.load('discography.npy')    
    print(discography.dtype)
    print(discography['title'])
    
    minidisco = np.zeros(len(discography), dtype = [('title', 'U16'), ('release', 'M8[s]')])
    print(minidisco)
    
    minidisco['title'] = discography['title']
    minidisco['release'] = discography['release']
    
    print(minidisco)
    
    print(np.ones((3,3)) * np.linspace(0,1,3))
    

if __name__ == "__main__":
    main()