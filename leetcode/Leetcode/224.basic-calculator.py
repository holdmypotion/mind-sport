#
# @lc app=leetcode id=224 lang=python3
#
# [224] Basic Calculator
#

# @lc code=start
class Solution:
    def update(self, stack, op, v):
        if op == "+": stack.append(v)
        if op == "-": stack.append(-v)
        if op == "*": stack.append(stack.pop() * v)
        if op == "/": stack.append(int(stack.pop() / v))


    def calculate(self, s):    
        def calc(it):        
            num, stack, sign = 0, [], "+"
            
            while it < len(s):
                if s[it].isdigit():
                    num = num * 10 + int(s[it])
                elif s[it] in "+-*/":
                    self.update(stack, sign, num)
                    num, sign = 0, s[it]
                elif s[it] == "(":
                    num, it = calc(it + 1)
                elif s[it] == ")":
                    self.update(stack, sign, num)
                    return sum(stack), it
                it += 1
            self.update(stack, sign, num)
            return sum(stack), it

        return calc(0)[0]
        
# @lc code=end

