#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#

# @lc code=start
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        self.stack = []
        self.n = n
        self.__backtrack()

        return self.res
    
    def __backtrack(self, start: int=0, end: int=0) -> None:
        if (start == end == self.n):
            self.res.append("".join(self.stack))
            return

        if (start < self.n):
            self.stack.append('(')
            self.__backtrack(start + 1, end)
            self.stack.pop()

        if (end < start):
            self.stack.append(')')
            self.__backtrack(start, end + 1)
            self.stack.pop()


# @lc code=end

