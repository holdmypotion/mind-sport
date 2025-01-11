#
# @lc app=leetcode id=287 lang=python3
#
# [287] Find the Duplicate Number
#

# @lc code=start
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        s, f = nums[0], nums[0]

        while True:
            s = nums[s]
            f = nums[nums[f]]

            if s == f:
                s = nums[0]
                while s != f:
                    s = nums[s]
                    f = nums[f]
                
                return s


        # 1, 3, 4, 2, 2
        # 0, 1, 2, 3, 4

        # 1 -> 3 -> 2 -> 4 -> 2
        
# @lc code=end