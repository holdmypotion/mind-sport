#
# @lc app=leetcode id=354 lang=python3
#
# [354] Russian Doll Envelopes
#

# @lc code=start
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        n = len(envelopes)

        width = []
        height = []
        for (w, h) in envelopes:
            if not height or (width[-1] < w and height[-1] < h):
                width.append(w)
                height.append(h)
            else:
                idx = bisect_left(height, h)
                width[idx] = w
                height[idx] = h

        return len(height)

# @lc code=end

