class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = 0
        maxcount = 0
        length = len(s)

        if length == 0 or length == 1:
            return length

        for index in range(0, length-1):
            count = 0
            map = dict()
            map[s[index]] = 1
            count += 1
            for subindex in range(index+1, length):
                if s[subindex] not in map:
                    map[s[subindex]] = 1
                    count += 1
                    maxcount = max(maxcount, count)
                else:
                    maxcount = max(maxcount, count)
                    break
        
        return maxcount
                    
    
def main():
    intput_s1 = "abcabcbb"
    intput_s2 = "bbbbb"
    intput_s3 = "pwwkew"
    
    leet = Solution()
    
    print(f"1.Answer of 1-Q: {leet.lengthOfLongestSubstring(intput_s1)}")
    print(f"2.Answer of 2-Q: {leet.lengthOfLongestSubstring(intput_s2)}")
    print(f"3.Answer of 3-Q: {leet.lengthOfLongestSubstring(intput_s3)}")

if __name__ == "__main__":
    main()