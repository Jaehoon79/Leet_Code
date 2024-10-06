from collections import Counter

class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:        
        if len(nums) == 1:
            return 1
        ct_list = Counter(nums)
    
        for num, cnt in ct_list.items():
            while (cnt > 2):
                nums.remove(num)
                cnt -= 1
        return len(nums)
        '''
        for key in ct_list.keys():
            while (ct_list[key] > 2):
                nums.remove(key)
                ct_list[key] -= 1

        return len(nums)
        '''
        


def main():
    nums_1 = [1,1,1,2,2,3]
    nums_2 = [0,0,1,1,1,1,2,3,3]
    
    leet = Solution()
    
    print(f"1.Out of nums_1: {leet.removeDuplicates(nums_1)}")
    print(f"2.Out of nums_2: {leet.removeDuplicates(nums_2)}")
    

if __name__ == '__main__':
    main()