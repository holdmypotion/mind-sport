#
# @lc app=leetcode id=583 lang=python3
#
# [583] Delete Operation for Two Strings
#

# @lc code=start
class Solution:
    def minDistance(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        dp = [[0] * (m+1) for _ in range(n+1)]

        for i in range(1, n+1):
            dp[i][0] = i

        for j in range(1, m+1):
            dp[0][j] = j

        for i in range(1, n+1):
            for j in range(1, m+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1
        for r in dp:
            print(r)
        return dp[n][m]
        
# @lc code=end

