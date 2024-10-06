import math
import collections

import numpy as np
import pandas as pd
import matplotlib.pyplot as pp

def main():
    nparr = np.linspace(0, 5 * math.pi, 64)
    npsin = np.sin(nparr)
    print(npsin)
    
    #pp.plot(nparr, npsin, color='red', maker='o', linestyle='dashed')
    pp.plot(nparr, npsin, label='sin(x)')
    pp.plot(nparr, np.cos(nparr), label='cos(x)')
    pp.plot(nparr, np.log(1+ nparr), label='log(1+x)')
    pp.legend()
    pp.show()
    
if __name__ == "__main__":
    main()