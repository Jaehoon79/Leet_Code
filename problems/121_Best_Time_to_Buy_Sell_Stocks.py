class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        maxprofit = 0
        buy = prices[0]
        
        for sell in prices[1:]:
            if sell > buy:
                maxprofit = max(maxprofit, sell - buy)
            else:
                buy = sell
        
        return maxprofit

def main():
    prices_1 = [7,1,5,3,6,4]
    prices_2 = [7,6,4,3,1]
    
    leet = Solution()
    print(f"1.Out of prices_1: {leet.maxProfit(prices_1)}")
    print(f"2.Out of prices_2: {leet.maxProfit(prices_2)}")
    
if __name__ == "__main__":
    main()