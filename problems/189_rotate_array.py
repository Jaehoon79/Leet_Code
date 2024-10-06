class MySolution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        while (k > 0):
            last_el = nums.pop()
            nums.insert(0, last_el)
            print(nums)
            k -= 1

class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        rotate = k % len(nums)
        nums[:] = nums[-rotate:] + nums[:-rotate]
            
def main():
    nums_1 = [1, 2, 3, 4, 5, 6, 7]
    k_1 = 3
    
    nums_2 = [-1,-100,3,99]
    k_2 = 2
    
    leet = Solution()
    leet.rotate(nums_1, k_1)
    print(f"1. output of nums_1: {nums_1}")

    leet.rotate(nums_2, k_2)
    print(f"2. output of nums_2: {nums_2}")
    
if __name__ == "__main__":
    main()