#
# @lc app=leetcode id=853 lang=python3
#
# [853] Car Fleet
#

# @lc code=start
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = list(zip(position, speed))
        cars.sort(reverse=True)

        stack = []

        for idx, (pos, s) in enumerate(cars):
            time = (target - pos) / s
            if idx == 0:
                stack.append(time)
            if stack and stack[-1] < time:
                stack.append(time)
            
        return len(stack)

        
# @lc code=end

