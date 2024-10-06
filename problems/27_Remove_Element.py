class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        k = 0
        for index in range(len(nums)):
            if nums[index] != val:
                nums[k] = nums[index]
                k += 1
        return k

def main():
    inputList_1 = [3, 2, 2, 3]
    inputval_1 = 3

    inputList_2 = [0, 1, 2, 2, 3, 0, 4, 2]
    inputVal_2 = 2
    
    testClass = Solution()
    output1 = testClass.removeElement(inputList_1, inputval_1)
    output2 = testClass.removeElement(inputList_2, inputVal_2)
    
    print(f'Test Result1: K = {output1}, List = {inputList_1}')
    print(f'Test Result2: K = {output2}, List = {inputList_2}')


if __name__ == '__main__':
    main()