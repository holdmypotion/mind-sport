#
# @lc app=leetcode id=486 lang=python3
#
# [486] Predict the Winner
#

# @lc code=start
class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:

        @cache
        def dfs(i, j, turn, p1, p2):
            if i == j:
                if turn:
                    p1 += nums[i]
                else:
                    p2 += nums[i]

                return (p1, p2)

            p1v1, p2v1 = dfs(i+1, j, not turn, p1, p2)
            p1v2, p2v2 = dfs(i, j-1, not turn, p1, p2)

            vals = [0, 0]
            if turn:
                if p1v1 + nums[i] > p1v2 + nums[j]:
                    vals[0] = p1v1 + nums[i]
                    vals[1] = p2v1
                else:
                    vals[0] = p1v2 + nums[j]
                    vals[1] = p2v2
            else:
                if p2v1 + nums[i] > p2v2 + nums[j]:
                    vals[0] = p1v1
                    vals[1] = p2v1 + nums[i]
                else:
                    vals[0] = p1v2
                    vals[1] = p2v2 + nums[j]

            p1 += vals[0]
            p2 += vals[1]
            return (p1, p2)
        
        p1, p2 = dfs(0, len(nums)-1, True, 0, 0)

        return p1 >= p2
        

        
# @lc code=end
