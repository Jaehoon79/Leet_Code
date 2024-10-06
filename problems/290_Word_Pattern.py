class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        map1, map2 = list(), list()
        
        for ch in pattern:
            map1.append(pattern.index(ch))
        for str in s.split():
            map2.append(s.split().index(str))
        
        #print(map1)
        #print(map2)
        
        if map1 ==  map2:
            return True
        return False

def main():
    #True
    pattern_1 = "abba"
    s_1 = "dog cat cat dog"
    #False
    pattern_2 = "abba"
    s_2 = "dog cat cat fish"
    #False
    pattern_3 = "aaaa"
    s_3 = "dog cat cat dog"

    leet = Solution()

    print(f"1.Out of Pattern_1: {leet.wordPattern(pattern_1, s_1)}")
    print(f"2.Out of Pattern_2: {leet.wordPattern(pattern_2, s_2)}")
    print(f"2.Out of Pattern_3: {leet.wordPattern(pattern_3, s_3)}")
    

if __name__ == "__main__":
    main()