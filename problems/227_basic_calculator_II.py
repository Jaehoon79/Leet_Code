class Solution:
    def calculate(self, s: str) -> int:
        calist = list()
        slist = "".join(s.split())
        slist += '+'
        pre_op = '+'
        num = 0
    
        for ch in slist:
            if ch.isdigit():
               num = (num * 10) + int(ch)
            else:
                if pre_op == '+':
                    calist.append(num)
                elif pre_op == '-':
                    calist.append(num * -1)
                elif pre_op == '*':
                    lnum = calist.pop()
                    calist.append(lnum * num)
                elif pre_op == '/':
                    lnum = calist.pop()
                    calist.append(int(lnum / num))

                pre_op = ch
                num = 0
    
        return sum(calist)
    
def main():
    s_1 = "3+2*2"
    s_2 = " 3/2 "
    s_3 = " 3+5 / 2 "
    s_4 = "14/3*2"
    
    leet = Solution()
    
    print(f"1.Answer of 1st-Q: {leet.calculate(s_1)}")
    print(f"2.Answer of 2nd-Q: {leet.calculate(s_2)}")
    print(f"3.Answer of 3rd-Q: {leet.calculate(s_3)}")


if __name__ == "__main__":
    main()