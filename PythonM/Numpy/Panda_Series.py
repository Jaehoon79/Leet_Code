import numpy as np
import pandas as pd


def main():
    #series : one-dimentional labeled array
    #mys = pd.Series(np.random.random(5), index =['a', 'b', 'c', 'd', 'e'])
    #print(mys)
    #mys = pd.Series(np.random.randint(low = 0, high = 10,size = 10))
    #print(mys)
    
    #From dict
    #myd = {"b": 1, "a": 0, "c": 2}
    #mys = pd.Series(myd)
    #print(mys)

    #add index.    
    #myd = {"b": 1, "a": 0, "c": 2}
    #mys = pd.Series(myd, index = ['b', 'c', 'd', 'a'])
    #mys = pd.Series(np.random.randint(low=0, high=10,
    #                                  size = 10))
    #iloc: integer-based-location indexing
    #print(mys.iloc[:10])
    #print(mys.iloc[[4, 3, 1]])
    #print(f"median: {mys.median()}")
    #print(mys[mys > mys.median()])
    #print(np.exp(mys))
    #print(mys.array)
    #Even if the series is backed by ExtensionArray,
    #Series.to_numpy() will return a Numpy
    #print(mys.to_numpy())
    
    #Series is dict-like
    mys = pd.Series(np.random.random(5), index =['a', 'b', 'c', 'd', 'e'])
    print(mys['a'])
    print('e' in mys)
    print('f' in mys)
    
    #if a label is not contained in the index,
    #an exception is raised
    #print(mys['f'])
    #Using the Series.get() method, a mising label will return None or Specific default:
    print(mys.get('f')) #return None
    
    
if __name__ == "__main__":
    main()