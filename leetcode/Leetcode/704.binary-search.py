#
# @lc app=leetcode id=704 lang=python3
#
# [704] Binary Search
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l,r = 0, len(nums)-1

        while (l <= r):
            mid = (l+r)//2
            if (nums[mid] < target):
                l = mid + 1
            elif (nums[mid] > target):
                r = mid - 1
            else:
                return mid
        
        return -1

# @lc code=end

