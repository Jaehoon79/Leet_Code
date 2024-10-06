from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ds, dt = Counter(s), Counter(t)
        if ds == dt:
            return True
        return False

def main():
    s1, t1 = "anagram", "nagaram"
    s2, t2 = "rat", "car"

    test = Solution()
    print(f"1st Answer {test.isAnagram(s1, t1)}")
    print(f"1st Answer {test.isAnagram(s2, t2)}")

if __name__ == "__main__":
    main()