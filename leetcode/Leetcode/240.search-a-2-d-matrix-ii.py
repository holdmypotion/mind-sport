#
# @lc app=leetcode id=240 lang=python3
#
# [240] Search a 2D Matrix II
#

# Things to go over
# 1. DP
# 2. Trees
# 3. Old questions from maybe neetcode for revision
# 4. Try writing questions in google doc
# 5. Practice some questions
# @lc code=start
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            l, r = 0, len(row)-1
            while l <= r:
                mid = l + (r-l)//2
                if row[mid] == target:
                    return True
                elif row[mid] > target:
                    r = mid - 1
                else:
                    l = mid + 1
            
        return False

# @lc code=end

