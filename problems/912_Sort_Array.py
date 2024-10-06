from typing import List

# Quick and Heap Sort Algorithm
class Solution:
    def QsortArray(self, nums: List[int]) -> List[int]:
        length = len(nums)
        
        if length <= 1:
            return nums
        
        else:
            pivot = nums.pop()
            bigger_v = list()
            lower_v = list()
            
            for item in nums:
                if item > pivot:
                    bigger_v.append(item)
                else:
                    lower_v.append(item)
        
        return self.QsortArray(lower_v) + [pivot] + self.QsortArray(bigger_v)
    
    def HsortArray(self, nums: List[int]) -> List[int]:
        return nums

def main():
    nums1 = [5,2,3,1]
    nums2 = [5,1,1,2,0,0]
    
    leet = Solution()
    print(f"1.Answer of Q {leet.QsortArray(nums1)}")
    print(f"2.Answer of Q {leet.QsortArray(nums2)}")

if __name__ == "__main__":
    main()