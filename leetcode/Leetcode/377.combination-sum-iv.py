#
# @lc app=leetcode id=377 lang=python3
#
# [377] Combination Sum IV
#

# @lc code=start
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        ## Brutre Force Recursion where you are counting each path the leads to sum 4.
        # def dfs(curr_sum):
        #     if curr_sum == target:
        #         return 1

        #     count = 0
        #     for num in nums:
        #         if curr_sum + num > target:
        #             continue

        #         count += dfs(curr_sum + num)

        #     return count 
        # return dfs(0)

        ## Optimized:
        # In our descion tree,
        # when we reach a `value` < target and from there calculate the number of way to make target.
        # we can store that for when we'll get to a point where that `value ` is formed again 
        # because now we won't have to calculate the number of paths again from `value` to target as we already did that before

        # dp[i] stores number of ways to reach to target: 1 using all the available numbers
        # dp = [0] * (target + 1)

        # dp[0] = 1

        # for i in range(target + 1):
        #     for num in nums:
        #         if i - num >= 0:
        #             dp[i] += dp[i - num]

        # return dp[target]

    
        # If -ve numbers are allowed then the solutions changes like so
        dp = { 0 : 1 }

        for i in range(1, target + 1):
            dp[i] = 0
            for num in nums:
                dp[i] += dp.get(i-num, 0)
        
        return dp[target]


# @lc code=end
