#
# @lc app=leetcode id=494 lang=python3
#
# [494] Target Sum
#

# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # P: All Numbers that we'll be adding + to
        # N: All the Number that we'll be adding - to
        # target = P - N
        # Sum of the Array = P + N
        # i.e, P - target = sum of array - P
        # Hence, P = (target + sum of array) // 2
        # New problem statement becomes:
        # Find the number of subsets in the array that sum to (total + target) // 2.
        # This transformation is powerful because:
        # It reduces the problem to a well-known problem (subset sum), which can be solved efficiently with dynamic programming.
        # It eliminates the need to consider both addition and subtraction explicitly.
        

        total_sum = sum(nums)
        if abs(target) > total_sum or (total_sum + target) % 2 != 0:
            return 0

        target = (total_sum + target) // 2

        # dp[i] -> Number of ways to form i
        # if you iterate from num, target. You'll be considering the cases where a single num can be duplicated as many times. 
        dp = [0] * (target + 1)
        dp[0] = 1
        
        for num in nums:
            for i in range(target, num-1, -1):
                dp[i] += dp[i-num]
        
        return dp[target]
# @lc code=end
