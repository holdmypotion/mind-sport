#
# @lc app=leetcode id=153 lang=python3
#
# [153] Find Minimum in Rotated Sorted Array
#
from typing import List
# @lc code=start
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        cur_min = float("inf")

        while (l <= r):
            mid = (l + r) // 2
            cur_min = min(cur_min, nums[mid])

            if (nums[r] < nums[mid]):
                l = mid + 1
            else:
                r = mid - 1
        
        return cur_min
        
# @lc code=end

