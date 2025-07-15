#
# @lc app=leetcode id=503 lang=python3
#
# [503] Next Greater Element II
#

# @lc code=start
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stack = []  # monotonically dec
        ans = [-1] * len(nums)
        for i, el in enumerate(nums):
            while stack and stack[-1][1] < el:
                idx,_ = stack.pop()
                ans[idx] = el
            stack.append((i, el))
        
        for el in nums:
            while stack and stack[-1][1] < el:
                idx,_ = stack.pop()
                ans[idx] = el

        return ans


# @lc code=end

