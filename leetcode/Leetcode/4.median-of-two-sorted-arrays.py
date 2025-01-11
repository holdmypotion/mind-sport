#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        shorter, longer = nums1, nums2
        total = len(shorter) + len(longer)
        half = total // 2

        if len(shorter) > len(longer):
            shorter, longer = longer, shorter

        l, r = 0, len(shorter) - 1
        while True:
            i = (l + r) // 2 
            j = half - i - 2

            s_left = shorter[i] if i >= 0 else float("-infinity")
            s_right = shorter[i+1] if (i+1) < len(shorter) else float("infinity")
            l_left = longer[j] if j >= 0 else float("-infinity")
            l_right = longer[j+1] if (j+1) < len(longer) else float("infinity")

            if s_left <= l_right and l_left <= s_right:
                if total % 2:
                    return min(s_right, l_right)
                return (max(s_left, l_left) + min(s_right, l_right)) / 2
            elif s_left > l_right:
                r = i - 1
            else:
                l = i + 1
            
# @lc code=end