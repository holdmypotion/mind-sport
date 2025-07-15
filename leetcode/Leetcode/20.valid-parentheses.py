#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pair_map = {
            '(': ')',
            '{': '}',
            '[': ']'
        }

        for bracket in s:
            if bracket in pair_map:
                stack.append(bracket)
            elif not stack or bracket != pair_map[stack.pop()]:
                return False

        return len(stack) == 0
        
# @lc code=end