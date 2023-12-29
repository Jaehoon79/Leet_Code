class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if len(nums) == 1: return 1

        # Set - is a collecton in which elements have no order.
        CheckSet = sorted(set(nums))

        for index, val in enumerate(CheckSet):
            nums[index] = val
            

        return len(CheckSet)
            


def main():
    input1List = [-1, 0, 0, 0, 0, 3, 3]
    input2List = [0,0,1,1,1,2,2,3,3,4]
    
    print(f'Output1: {Solution().removeDuplicates(input1List)}, nums: {input1List}')
    print(f'Output1: {Solution().removeDuplicates(input2List)}, nums: {input2List}')
    

if __name__ == '__main__':
    main()