class Solution2:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mydict = dict()
        for index in range(0, len(s)):
            if s[index] not in mydict.keys():
                if t[index] not in mydict.values():
                    mydict[s[index]] = t[index]
                else:
                    return False
            else:
                if mydict[s[index]] != t[index]:
                    return False
            print(mydict)
            
        return True
    
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        map1, map2 = list(), list()
        for val in s:
            map1.append(s.index(val))
        for val in t:
            map2.append(t.index(val))

        if map1 == map2:
            return True
        return False

def main():
    s1, t1 = "egg", "add"
    s2, t2 = "foo", "bar"
    s3, t3 = "paper", "title"
    s4, t4 = "badc", "baba"

    test = Solution()

    print(f"1st Answer {test.isIsomorphic(s1, t1)}")
    #print(f"2nd Answer {test.isIsomorphic(s2, t2)}")
    #print(f"3rd Answer {test.isIsomorphic(s3, t3)}")
    #print(f"4th Answer {test.isIsomorphic(s4, t4)}")

if __name__ == "__main__":
    main()

