import numpy as np
import pandas as pd

def main1():
    #from dict of series or dicts
    d = {
    "one": pd.Series([1.0, 2.0, 3.0], index=["a", "b", "c"]),
    "two": pd.Series([1.0, 2.0, 3.0, 4.0], index=["a", "b", "c", "d"]),
    }
    df = pd.DataFrame(d)
    print(df)
    """
    df = pd.DataFrame(d, index = ["d", "b", "a"])
    print(df)
    
    df = pd.DataFrame(d, index=["d", "b", "a"], columns=["two", "three"])
    print(df)
    """
    print(f"DataFrame Index: {df.index}")
    print(f"DataFrame Columns: {df.columns}")

def main2():
    #From dict of ndarrays / lists
    d = {"one": [1.0, 2.0, 3.0, 4.0], "two": [4.0, 3.0, 2.0, 1.0]}
    df = pd.DataFrame(d)
    print(df)
    #add index (a, b, c, d)
    df = pd.DataFrame(d, index=["a", "b", "c", "d"])
    print(df)

def main3():
    #From a list of dicts
    data2 = [{"a": 1, "b": 2}, {"a": 5, "b": 10, "c": 20}]
    mydf = pd.DataFrame(data2)
    print(mydf)
    mydf = pd.DataFrame(data2, index = ["first","second"])
    print(mydf)
    #remove C from column list.
    mydf = pd.DataFrame(data2, columns = ["a", "b"])
    print(mydf)

def main4():
    #From a dict of tuples
    mydf = pd.DataFrame({
        ("a", "b"): {("A", "B"): 1, ("A", "C"): 2},
        ("a", "a"): {("A", "C"): 3, ("A", "B"): 4},
        ("a", "c"): {("A", "B"): 5, ("A", "C"): 6},
        ("b", "a"): {("A", "C"): 7, ("A", "B"): 8},
        ("b", "b"): {("A", "D"): 9, ("A", "B"): 10},
    })
    print(mydf)
    
    #From a Series
    ser = pd.Series(range(3), index = list("abc"), name = "ser")
    mydf = pd.DataFrame(ser)
    print(ser, mydf)

from collections import namedtuple

def main5():
    #From a list of namedtuples
    Point = namedtuple("Point", "x y")
    mydf = pd.DataFrame([Point(0,0), Point(0, 3), Point(2,3)])
    print(mydf)
    
    Point3D = namedtuple("Point3D", "x y z")
    mydf = pd.DataFrame([Point3D(0,0,0), Point3D(0,3,5), Point(2, 3)])
    print(mydf)

from dataclasses import make_dataclass

def main6():
    #From a list of dataclasses
    Point = make_dataclass("Point", [("x", int), ("y", int)])
    mydf = pd.DataFrame([Point(0, 0), Point(0, 3), Point(2, 3)])
    print(mydf)
    
def main7():
    #Alternate Contructors
    #from_dict
    mydf = pd.DataFrame.from_dict(dict([("A", [1, 2, 3]), ("B", [4,5,6])]))
    print(mydf)
    mydf = pd.DataFrame.from_dict(dict([("A", [1, 2, 3]), ("B", [4,5,6])]),
                                  orient="index",
                                  columns=["one", "two", "three"])
    print(mydf)

    

if __name__ == "__main__":
    #main1()
    #main2()
    #main3()
    #main4()
    #main5()
    #main6()
    main7()