#
# @lc app=leetcode id=1574 lang=python3
#
# [1574] Shortest Subarray to be Removed to Make Array Sorted
#

# @lc code=start
class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        # Get the first element of the right sorted array
        right = len(arr) - 1
        while right > 0 and arr[right] >= arr[right-1]:
            right -= 1

        ans = right
        left = 0
        while left < right and (left == 0 or arr[left] >= arr[left-1]):
            while right < len(arr) and arr[left] > arr[right]:
                right += 1
            
            ans = min(ans, right - left - 1)
            left += 1
        
        return ans

# @lc code=end

