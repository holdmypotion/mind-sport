#
# @lc app=leetcode id=10 lang=python3
#
# [10] Regular Expression Matching
#

# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)

        dp = [[False]*(m+1) for _ in range(n+1)]
        dp[-1][-1] = True # -> Empty string at the end
        # dp[i][j] -> suffix regex match till s[i] and p[j]

        for i in range(n, -1, -1):
            # Starting from j = m-1 because
            # if you are at the end of p but s still remain the value should be false
            for j in range(m-1, -1, -1):
                match = i < n and (s[i] == p[j] or p[j] == '.')

                if j+1 < m and p[j+1] == '*': # x* -> needs to be considered together
                    dp[i][j] = dp[i][j+2] or (match and dp[i+1][j])
                else: # remaining case of english letters and .
                    dp[i][j] = match and dp[i+1][j+1]

        return dp[0][0]
# @lc code=end

