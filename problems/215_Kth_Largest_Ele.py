
class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        nums.sort()
        #print(f"Sorted List: {nums}")
        return nums[-k]
        

def main():
    nums_1 = [3,2,1,5,6,4]
    k_1 = 2
    nums_2 = [3,2,3,1,2,4,5,5,6]
    k_2 = 4
    
    leet = Solution()
    print(f"1.Answer of 1stQ:{leet.findKthLargest(nums_1, k_1)}")
    print(f"2.Answer of 2stQ:{leet.findKthLargest(nums_2, k_2)}")

if __name__ == "__main__":
    main()