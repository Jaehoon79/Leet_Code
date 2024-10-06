from collections import Counter

#Utilize Counter module and most_common method.
class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        return (Counter(nums).most_common(1))[0][0]


def main():
    nums1 = [3, 2, 3]
    nums2 = [2,2,1,1,1,2,2]
    
    leet = Solution()
    
    print(f"1. Output of nums1: {leet.majorityElement(nums1)}")
    print(f"2. Output of nums2: {leet.majorityElement(nums2)}")


if __name__ == "__main__":
    main()