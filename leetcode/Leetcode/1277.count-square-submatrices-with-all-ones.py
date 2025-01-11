#
# @lc app=leetcode id=1277 lang=python3
#
# [1277] Count Square Submatrices with All Ones
#

# @lc code=start
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        # dp[i,j] -> Possible Square Submatrices at location i,j
        n, m = len(matrix)+1, len(matrix[0])+1
        prev_row = [0]*m
        
        total = 0
        for i in range(1, n):
            curr_row = [0]*m
            for j in range(1, m):
                if matrix[i-1][j-1] == 1:
                    curr_row[j] = 1 + min(curr_row[j-1], prev_row[j], prev_row[j-1])
                    total += curr_row[j]
            prev_row = curr_row
        return total
        
# @lc code=end
