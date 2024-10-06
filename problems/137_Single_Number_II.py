from collections import Counter

class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        ct = Counter(nums)
        return sorted(ct.items(), key=lambda i:i[1])[0][0]


def main():
    nums_1 = [2,2,3,2]
    nums_2 = [0,1,0,1,0,1,99]
    
    leet = Solution()
    print(f"1.Answer of 1st-Q: {leet.singleNumber(nums_1)}")
    print(f"2.Answer of 2nd-Q: {leet.singleNumber(nums_2)}")

if __name__ == "__main__":
    main()