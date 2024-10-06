class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        s = "".join(c for c in s if c.isalpha()).lower().replace(" ", "")
        print(s[:])
        print(s[::-1])
        return True if s[:] == s[::-1] else False

def main():
    #True
    s_1 = "A man, a plan, a canal: Panama"
    #False
    s_2 = "race a car"
    #True
    s_3 = " "
    
    leet = Solution()
    
    print(f"1.Out of S_1: {leet.isPalindrome(s_1)}")
    print(f"2.Out of S_2: {leet.isPalindrome(s_2)}")
    print(f"3.Out of S_3: {leet.isPalindrome(s_3)}")
    

if __name__ == "__main__":
    main()