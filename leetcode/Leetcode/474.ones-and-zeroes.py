#
# @lc app=leetcode id=474 lang=python3
#
# [474] Ones and Zeroes
#

# @lc code=start
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        
        for s in strs:
            zeros = s.count('0')
            ones = s.count('1')
            
            # Update dp table from bottom-right to top-left to avoid counting the same string multiple times
            for i in range(n, ones-1, -1):
                for j in range(m, zeros-1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - ones][j - zeros] + 1)

        return dp[n][m]

# @lc code=end

