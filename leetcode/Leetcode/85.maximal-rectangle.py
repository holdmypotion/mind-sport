#
# @lc app=leetcode id=85 lang=python3
#
# [85] Maximal Rectangle
#

# @lc code=start
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int: 
        m = len(matrix[0])
        hist = [0] * m
        max_area = 0

        for row in matrix:
            for i in range(m):
                hist[i] = hist[i] + 1 if row[i] == '1' else 0

            stack = []
            for i, h in enumerate(hist):
                start = i
                while stack and stack[-1][1] > h:
                    idx, height = stack.pop()
                    max_area = max(max_area, height * (i - idx))
                    start = idx

                stack.append((start, h))
        
            for i, h in stack:
                max_area = max(max_area, h * (m - i))

        return max_area
# @lc code=end
