from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)
        pivot = 0
        inTop = 0
        inBottom = 0
        ret = list()
        nums.sort()

        for index in range(0, length -2):
            pivot = index
            inTop = pivot + 1
            inBottom = length -1

            if pivot == 0 or (nums[pivot] != nums[pivot -1]):
                while inBottom > inTop:
                    totSum = nums[pivot] + nums[inTop] + nums[inBottom]
                    #print(totSum)
                    if totSum > 0:
                        inBottom -= 1
                    elif totSum < 0:
                        inTop += 1
                    else:
                        ret.append((nums[pivot], nums[inTop], nums[inBottom]))
                        #print(ret[numofret][0], ret[numofret][1], ret[numofret][2])
                        inTop += 1
                        while inTop < inBottom and nums[inTop] == nums[inTop -1]:
                            inTop += 1
        
        return ret
    

def main():
    nums_1 = [-1,0,1,2,-1,-4]
    nums_2 = [0,1,1]
    nums_3 = [0,0,0]
    
    leet = Solution()
    ret = leet.threeSum(nums_1)
    print(f"1.Answer: {ret}")

if __name__ == "__main__":
    main()