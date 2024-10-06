class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        checkList = list(s.split())
        return len(checkList.pop())
    
def main():
    s_1 = "Hello World"
    s_2 = "   fly me   to   the moon  "
    s_3 = "luffy is still joyboy"
    
    leet = Solution()
    
    print(f"1. Output of s_1: {leet.lengthOfLastWord(s_1)}")
    print(f"2. Output of s_2: {leet.lengthOfLastWord(s_2)}")
    print(f"3. Output of s_3: {leet.lengthOfLastWord(s_3)}")

if __name__ == "__main__":
    main()