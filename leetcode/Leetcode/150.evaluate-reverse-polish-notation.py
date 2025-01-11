#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators = ['+', '-', '*', '/']
        for t in tokens:
            if t in operators:
                op2 = stack.pop()
                op1 = stack.pop()
                res = int(eval(f'{op1} {t} {op2}'))
                stack.append(res)
            else:
                stack.append(t)
        return int(stack.pop())
# @lc code=end
