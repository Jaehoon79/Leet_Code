from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        upper = len(nums) -1
        lower = 0
        
        while lower <= upper:
            mid = int((lower + upper) / 2)
            if nums[mid] == target:
                return mid
            else:
                if nums[mid] > target:
                    upper = mid - 1
                else:
                    lower = mid + 1
        
        return -1
        
def main():
    nums_1 = [-1,0,3,5,9,12]
    target_1 = 9
    
    nums_2 = [-1,0,3,5,9,12]
    target_2 = 2
    
    leet = Solution()
    print(f"1.Answer of Q: {leet.search(nums_1, target_1)}")
    print(f"2.Answer of Q: {leet.search(nums_2, target_2)}")


if __name__ == "__main__":
    main()