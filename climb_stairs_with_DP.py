
# Add DP (Top-Bottom Approach)
class Solution:
    def climbStairs(self, n: int) -> int:
        def dp(i):
            if i <= 2: 
                return i
            if i not in memo:
                # Instead of just returning dp(i - 1) + dp(i - 2), calculate it once and then
                # store the result inside a hashmap to refer to in the future.
                memo[i] = dp(i - 1) + dp(i - 2)
            
            return memo[i]
        #Dictionary Type
        memo = {}
        return dp(n)

def main():
    wayofstairs_class = Solution()
    test_result = wayofstairs_class.climbStairs(3)
    print(f"kimc: {test_result}")

if __name__ == "__main__":
    main()