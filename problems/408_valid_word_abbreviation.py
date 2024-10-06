class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        numStack = []
        num = 0
        num_cnt = 0
        word_len = len(word)
        word_index = 0

        word += '#'
        abbr += '#'
    
        print(word, abbr)

        for val in abbr:
            if val.isdigit():
                if num_cnt == 0 and int(val) == 0:
                    return False
                num = num * 10 + int(val)
                num_cnt += 1
            else:
                print(word_index, num)
                word_index += num
                if word_index > word_len:
                    return False
                if word[word_index] != val:
                    return False
                else:
                    word_index += 1
                    num = 0
                    num_cnt = 0
                
        return True
    
def main():
    word_1 = "internationalization"
    abbr_1 = "i12iz4n"
    
    word_2 = "apple"
    abbr_2 = "a2e"
    
    word_3 = "a"
    abbr_3 = "2"
    
    leet = Solution()
    
    print(f"1.Answer of 1st-Q: {leet.validWordAbbreviation(word_1, abbr_1)}")
    print(f"2.Answer of 2nd-Q: {leet.validWordAbbreviation(word_2, abbr_2)}")
    print(f"3.Answer of 3rd-Q: {leet.validWordAbbreviation(word_3, abbr_3)}")

if __name__ == "__main__":
    main()