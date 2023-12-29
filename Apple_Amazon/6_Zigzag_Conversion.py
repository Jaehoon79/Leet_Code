class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s

        retStr = ""
        for rowInd in range(numRows):
            incrment = 2 * (numRows - 1)
            for wrInd in range(rowInd, len(s), incrment):
                retStr += s[wrInd]
                if ((rowInd > 0 and rowInd < numRows - 1) and (wrInd + incrment - (2 * rowInd )) < len(s)):
                    retStr += s[wrInd + (incrment - (2 * rowInd))]

        return retStr
                
    
def main():
    input1Str = 'PAYPALISHIRING'
    input1Row = 3
    
    input2Str = 'PAYPALISHIRING'
    input2Row = 4
    
    test = Solution()
    output1 = test.convert(input1Str, input1Row)
    output2 = test.convert(input2Str, input2Row)
    
    print(f'output1: {output1}')
    print(f'output2: {output2}')
    
if __name__ == '__main__':
    main()