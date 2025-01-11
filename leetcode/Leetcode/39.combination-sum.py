#
# @lc app=leetcode id=39 lang=python3
#
# [39] Combination Sum
#

# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ## Backtracking DFS
        # Idea: We are just listing all the possible combinations
        # and making sure that they are unique by only alllowing combinations with candidates >= array index of current candidate
        # This forms a decision tree like for candidate at index i, we have (n-i) branches. This goes on recursively
        # TC:
        #   Height of the decision tree is limited by target value because in worst case it'll be as large as target.
        #   Hence min value of the candidates also impact the height
        #   Although it seems that we creating a lot of branches from a single node, in reality the decision is binary.
        #   i.e., either to include the current candidate or not. and we do that at max t times when min candidate value is 1 otherwise it reduces by t/m
        #   Hence, TC: O(2^t/m)

        res = []

        def dfs(curr, curr_sum, i):
            if curr_sum == target:
                res.append(curr.copy())
                return

            for j in range(i, len(candidates)):
                if curr_sum + candidates[j] > target:
                    continue
                curr.append(candidates[j])
                dfs(curr, curr_sum + candidates[j], j)
                curr.pop()

        dfs([], 0 , 0)
        return res

# @lc code=end
