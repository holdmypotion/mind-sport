#
# @lc app=leetcode id=279 lang=python3
#
# [279] Perfect Squares
#
import math
# @lc code=start
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [float('inf')]*(n+1)
        dp[0] = 0

        for i in range(1, n+1):
            for j in range(1, int(math.sqrt(i))+1):
                dp[i] = min(dp[i], dp[i-j*j]+1)

        return dp[n]

# @lc code=end

