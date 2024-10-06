class Solution:
    def longestPalindrome(self, s: str) -> str:
        ret = s[0]
        maxcount = 0

        for index in range(0, len(s) - 1):
            end = len(s)
            while end > index and (end - index > maxcount):
                checklist = s[index:end]
                if checklist == checklist[::-1]:
                    maxcount = end - index - 1
                    ret = s[index:end]
                end -= 1
     
        return ret

def main():
    s_1 = "babad"
    s_2 = "cbbd"

    leet = Solution()
    
    print(f"1.Answer of 1-Q: {leet.longestPalindrome(s_1)}")
    print(f"2.Answer of 2-Q: {leet.longestPalindrome(s_2)}")

if __name__ == "__main__":
    main()