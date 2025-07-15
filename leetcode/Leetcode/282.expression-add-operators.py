#
# @lc app=leetcode id=282 lang=python3
#
# [282] Expression Add Operators
#

# @lc code=start
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        def dfs(index, value, prev_operand, expression):
            if index == len(num):
                if value == target:
                    result.append(expression)
                return

            for i in range(index, len(num)):
                if i != index and num[index] == '0':
                    break

                current_operand = int(num[index:i+1])
                if index == 0:
                    dfs(i + 1, current_operand, current_operand, expression + str(current_operand))
                else:
                    dfs(i + 1, value + current_operand, current_operand, expression + '+' + str(current_operand))
                    dfs(i + 1, value - current_operand, -current_operand, expression + '-' + str(current_operand))
                    dfs(i + 1, value - prev_operand + (prev_operand * current_operand), prev_operand * current_operand, expression + '*' + str(current_operand))

        result = []
        dfs(0, 0, 0, "")
        return result

        
# @lc code=end

