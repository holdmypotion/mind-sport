#
# @lc app=leetcode id=162 lang=python3
#
# [162] Find Peak Element
#

# @lc code=start
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1

        while l <= r:
            mid = l + (r-l)//2
            if mid+1 < len(nums) and nums[mid+1] > nums[mid]: l = mid + 1
            else: r = mid - 1

        return l
# @lc code=end

