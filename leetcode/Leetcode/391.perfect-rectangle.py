#
# @lc app=leetcode id=391 lang=python3
#
# [391] Perfect Rectangle
#

# @lc code=start
class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        area = 0
        corners = set()

        for x, y, X, Y in rectangles:
            area += ((X-x) * (Y-y))
            corners ^= {(x,y), (x,Y), (X,y), (X,Y)}

        if len(corners) != 4:
            return False
        x, y = min(corners, key=lambda x: x[0] + x[1])
        X, Y = max(corners, key=lambda x: x[0] + x[1])
        return area == ((X-x) * (Y-y))
# @lc code=end

