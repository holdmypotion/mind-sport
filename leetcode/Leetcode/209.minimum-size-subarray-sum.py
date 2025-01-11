#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0
        csum = 0
        ans = float("inf")
        for r in range(len(nums)):
            csum += nums[r]

            while csum >= target:
                csum -= nums[l]
                ans = min(ans, r-l+1)
                l += 1

        return ans if ans != float("inf") else 0

# @lc code=end

