from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dransom, dmagazine = Counter(ransomNote), Counter(magazine)
        print(dransom, dmagazine)
        print(f"AND: {dransom & dmagazine}")
        print(f"OR: {dransom | dmagazine}")

        if dransom & dmagazine == dransom:
            return True
        return False


def main():
    ransomNote_1 = "a"
    magazine_1 = "b"

    ransomNote_2 = "aa"
    magazine_2 = "ab"

    ransomNote_3 = "aa"
    magazine_3 = "aab"

    ransomNote_4 = "aab"
    magazine_4 = "baa"


    test = Solution()
    print(f'1st answer: {test.canConstruct(ransomNote_1, magazine_1)}')
    print(f'2nd answer: {test.canConstruct(ransomNote_2, magazine_2)}')
    print(f'3rd answer: {test.canConstruct(ransomNote_3, magazine_3)}')
    print(f'3rd answer: {test.canConstruct(ransomNote_4, magazine_4)}')

if __name__ == "__main__":
    main()
