#
# @lc app=leetcode id=74 lang=python3
#
# [74] Search a 2D Matrix
#

# @lc code=start
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l, r = 0, len(matrix) - 1

        while (l <= r):
            mid = (l + r) // 2
            if (matrix[mid][0] < target):
                l = mid + 1
            elif (matrix[mid][0] > target):
                r = mid - 1
            else:
                return True

        # matrix[r][0] is the index of the element less than target
        # matrix[l][0] is the index of the element greater than targer
        # we know that matrix[r] -> might have target inside
        # but matrix[l] would never as the first element is greater than target
        return self.__binary_search(matrix[r], target)
        
    def __binary_search(self, arr: List[int], target: int) -> bool:
        l, r = 0, len(arr) - 1

        while (l <= r):
            mid = (l + r) // 2
            if (arr[mid] < target):
                l = mid + 1
            elif (arr[mid] > target):
                r = mid - 1
            else:
                return True

        return False
        
# @lc code=end

