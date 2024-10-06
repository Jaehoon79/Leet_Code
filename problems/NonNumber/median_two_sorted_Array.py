from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()

        if (len(nums1) % 2) == 0:
            median = ( nums1[int(len(nums1) / 2 -1)] + nums1[int(len(nums1)/2)] )  / 2
        else:
            median = nums1[int(len(nums1) / 2)]

        return median
    


# Main Function to get test _result
def main ():
    nums1 = [1, 2]
    nums2 = [3, 4]
    nums3 = [1, 3]
    nums4 = [2]
    
    test = Solution()
    result_test = test.findMedianSortedArrays(nums1, nums2)
    result_test2 = test.findMedianSortedArrays(nums3, nums4)
    
    print(f"Median Result: {result_test}, {result_test2}")

if __name__ =="__main__":
        main()