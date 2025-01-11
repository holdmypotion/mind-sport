#
# @lc app=leetcode id=216 lang=python3
#
# [216] Combination Sum III
#

# @lc code=start
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        candidates = range(1, 10)

        def backtrack(i, curr_sum, curr):
            if curr_sum == n and len(curr) == k:
                res.append(curr[::])
                return

            for j in range(i, len(candidates)):
                if curr_sum + candidates[j] > n:
                    break
                elif j>i and candidates[j] == candidates[j-1]:
                    continue

                curr.append(candidates[j])
                backtrack(j+1, curr_sum + candidates[j], curr)
                curr.pop()
                 

        backtrack(0, 0, [])
        return res 
# @lc code=end

