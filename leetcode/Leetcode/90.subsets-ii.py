#
# @lc app=leetcode id=90 lang=python3
#
# [90] Subsets II
#

# @lc code=start
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        # res = []
        # nums.sort()

        # def backtrack(i, subset):
        #     if i == len(nums):
        #         res.append(subset[::])
        #         return
            
        #     subset.append(nums[i])
        #     backtrack(i+1, subset)
        #     subset.pop()

        #     # When you are skipping if you skip all occurences of
        #     # that number you'll get the subsets without duplicates
        #     while i + 1 < len(nums) and nums[i] == nums[i+1]:
        #         i += 1
        #     backtrack(i+1, subset)
        
        # backtrack(0, [])
        # return res

        res = []
        nums.sort()

        def backtrack(i, subset):
            print(subset)
            res.append(subset[::])

            for j in range(i, len(nums)):
                if j > i and nums[j] == nums[j-1]:
                    continue

                subset.append(nums[j])
                backtrack(j+1, subset)
                subset.pop()
        
        backtrack(0, [])
        return res
            

# @lc code=end
