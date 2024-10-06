from typing import List
import statistics

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        numtot = nums1 + nums2
        return float(statistics.median(numtot))
    
def main():
    nums1 = [1, 3]
    nums2 = [2]
    
    leet = Solution()

    print(f"1.Answer of 1-Q: {leet.findMedianSortedArrays(nums1, nums2)}")

if __name__ == "__main__":
    main()