class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        if n != 0:
            for index, val in enumerate(nums2):
                nums1[m+index] = val
        nums1.sort()
        
def main():
    input1_nums1 = [1,2,3,0,0,0]
    input1_m , input1_n = 3, 3
    input1_nums2 = [2,5,6]
    
    input2_nums1 = [1]
    input2_m , input2_n = 1, 0
    input2_nums2 = []
    
    input3_nums1 = [0]
    input3_m , input3_n = 0, 1
    input3_nums2 = [1]
    
    testS = Solution()
    testS.merge(input1_nums1, input1_m, input1_nums2, input1_n)
    testS.merge(input2_nums1, input2_m, input2_nums2, input2_n)
    testS.merge(input3_nums1, input3_m, input3_nums2, input3_n)
    
    print(f'Result: A1 {input1_nums1}, A2 {input2_nums1}, A3 {input3_nums1}')
    
    pass


if __name__ == '__main__':
    main()