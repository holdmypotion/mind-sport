#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # subset = []        
        # res = []
        # def dfs(idx):
        #     nonlocal res, subset
        #     if idx >= len(nums):
        #         res.append(subset.copy())
        #         return

        #     subset.append(nums[idx])
        #     dfs(idx + 1)
        #     subset.pop()
        #     dfs(idx + 1)
        
        # dfs(0)
        # return res

        ## Bit Operations
        n = len(nums)
        res = []
        for b in range(1<<n):
            res.append([nums[i] for i in range(n) if (b&(1<<i))])

        return res
        
# @lc code=end

