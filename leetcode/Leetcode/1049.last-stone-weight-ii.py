#
# @lc app=leetcode id=1049 lang=python3
#
# [1049] Last Stone Weight II
#

# @lc code=start
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        stones_sum = sum(stones)
        target = ceil(stones_sum / 2)
        
        dp = [0] * (target + 1)

        for i in range(len(stones)):
            for j in range(target, stones[i] - 1, -1):
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i])

        # p2 = (t - p1)
        # dif = p1 - (t - p1)
        # dif = 2p1 - t
        return abs(2*dp[target] - stones_sum)
# @lc code=end
