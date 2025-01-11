#
# @lc app=leetcode id=739 lang=python3
#
# [739] Daily Temperatures
#

# @lc code=start
from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0]*len(temperatures)
        stack: List[tuple] = [] # (idx, temp)

        for idx, temp in enumerate(temperatures):
            while stack and temp > stack[-1][1]:
                s_idx, _ = stack.pop()
                res[s_idx] = idx - s_idx
            
            stack.append((idx, temp))

        return res
        
# @lc code=end

