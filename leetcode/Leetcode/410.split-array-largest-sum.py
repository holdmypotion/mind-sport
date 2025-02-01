#
# @lc app=leetcode id=410 lang=python3
#
# [410] Split Array Largest Sum
#

# @lc code=start
class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def sol_possible(val):
            part, cur_sum = 0, 0

            for ele in nums:
                cur_sum += ele
                if cur_sum > val:
                    part += 1
                    cur_sum = ele

            return part + 1 <= k


        l = max(nums)
        r = sum(nums)
        ans = r
        while l <= r:
            mid = l+(r-l)//2
            if sol_possible(mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1

        return ans

        
# @lc code=end

