class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        map = {}
        
        for index, val in enumerate(nums):
            fval = target - val
            if fval in map:
                return [map[fval], index]
            map[val] = index
        return []
    

def main():
    nums_1 = [2,7,11,15]
    target_1 = 9
    
    nums_2 = [3,2,4]
    target_2 = 6
    
    nums_3 = [3,3]
    target_3 = 6
    
    leet = Solution()
    
    print(f"1.Answer of 1st-Q: {leet.twoSum(nums_1, target_1)}")
    print(f"2.Answer of 2nd-Q: {leet.twoSum(nums_2, target_2)}")
    print(f"3.Answer of 3th-Q: {leet.twoSum(nums_3, target_3)}")
    
if __name__ == "__main__":
    main()