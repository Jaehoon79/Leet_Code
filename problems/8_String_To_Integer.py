class Solution:
    def myAtoi(self, s: str) -> int:
        num = 0
        sign = 1
        num_start = 0
        ret = 0
        
        for val in s:
            if val.isdigit():
                num =  num * 10 + int(val)
                if num_start == 0:
                    num_start = 1
            elif val == '+':
                if num_start == 0:
                    sign = 1
                    num_start = 1
                else:
                    break
            elif val == '-':
                if num_start == 0:
                    sign = -1
                    num_start = 1
                else:
                    break
            else:
                if num_start == 1 or (num_start == 0 and val !=' '):
                    break
            
        ret = num * sign
        if ret > pow(2, 31) - 1:
            ret = pow(2, 31) - 1
        if ret < pow(2, 31) * -1:
            ret = pow(2, 31) * -1
        return ret
    
def main():
    s_1 = "42"
    s_2 = "   -42"
    s_3 = "4193 with words"
    s_4 = "words and 987"
    s_5 = "   +0 123"
    
    leet = Solution()
    
    print(f"1.Answer of Q: {leet.myAtoi(s_1)}")
    print(f"2.Answer of Q: {leet.myAtoi(s_2)}")
    print(f"3.Answer of Q: {leet.myAtoi(s_3)}")
    print(f"4.Answer of Q: {leet.myAtoi(s_4)}")
    print(f"5.Answer of Q: {leet.myAtoi(s_5)}")

if __name__ == "__main__":
    main()