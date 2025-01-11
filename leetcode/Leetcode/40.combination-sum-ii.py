#
# @lc app=leetcode id=40 lang=python3
#
# [40] Combination Sum II
#

# @lc code=start
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backtrack(i, curr_sum, curr):
            if curr_sum == target:
                res.append(curr[::])
                return

            for j in range(i, len(candidates)):
                if curr_sum + candidates[j] > target:
                    break
                elif j>i and candidates[j] == candidates[j-1]:
                    continue

                curr.append(candidates[j])
                backtrack(j+1, curr_sum + candidates[j], curr)
                curr.pop()
                 

        backtrack(0, 0, [])
        return res
# @lc code=end

