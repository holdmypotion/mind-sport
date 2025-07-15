#
# @lc app=leetcode id=363 lang=python3
#
# [363] Max Sum of Rectangle No Larger Than K
#

# @lc code=start
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        R, C = len(matrix), len(matrix[0])

        prefix_matrix = [[0]*(C+1) for _ in range(R+1)]
        for r in range(R):
            for c in range(C):
                prefix_matrix[r][c] = prefix_matrix[r-1][c-1] \
                    + prefix_matrix[r][c-1] \
                    + prefix_matrix[r-1][c] \
                    + matrix[r-1][c-1]
        
        for row in matrix:
            print(row)
        for row in prefix_matrix:
            print(row)
        max_sum = 0
        for a in range(R):
            for b in range(C):
                for c in range(a):
                    for d in range(b):
                        cur_sum = prefix_matrix[a][b] \
                            - prefix_matrix[a][d] \
                            - prefix_matrix[c][b] \
                            + prefix_matrix[c][d]
                        print(max_sum, cur_sum, k)
                        if max_sum < cur_sum <= k:
                            max_sum = cur_sum

        return max_sum
                    

        
# @lc code=end

