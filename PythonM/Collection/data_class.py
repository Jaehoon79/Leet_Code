#dataclass was added from python 3.7 as a standard library.
from dataclasses import dataclass

@dataclass
class point:
    x:int
    y:int
    help:str = 'unknown'
    def sum (self):
        return self.x + self.y

def main():
    p = point(10, 100)
    print(p, type(p))
    print(f"Sum of x and y: {p.sum()}")
if __name__ == "__main__":
    main()