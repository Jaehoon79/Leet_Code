from collections import Counter
""" My Solution.
class Solution(object):
    def singleNumber(self, nums):
        num_ct = Counter(nums)
        for key, cnt in num_ct.items():
            if cnt == 1
                return key
"""

#Another Solution.
class Solution(object):
    def singleNumber(self, nums):
        uniqueN = 0
        for val in nums:
            uniqueN ^= val

        return uniqueN

def main():
    nums_1 = [2,2,1]
    nums_2 = [4,1,2,1,2]
    
    leet = Solution()
    print(f"1.Answer of 1st-Q: {leet.singleNumber(nums_1)}")
    print(f"2.Answer of 2nd-Q: {leet.singleNumber(nums_2)}")

if __name__ == "__main__":
    main()