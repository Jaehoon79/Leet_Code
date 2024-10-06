from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
    
def main():
    nums_1 = [1,2,3]
    nums_2 = [3,2,1]
    nums_3 = [1,1,5]
    
    leet = Solution()
    
    print(f"1.Answer {leet.nextPermutation(nums_1)}")
    print(f"2.Answer {leet.nextPermutation(nums_2)}")
    print(f"3.Answer {leet.nextPermutation(nums_3)}")

if __name__ == "__main__":
    main()