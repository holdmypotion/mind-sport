#
# @lc app=leetcode id=695 lang=python3
#
# [695] Max Area of Island
#

from types import List
from collections import deque
# @lc code=start

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        directions = [[0,1], [1,0], [0,-1], [-1,0]]
        R, C = len(grid), len(grid[0])

        def bfs(i, j):
            q = deque([(i, j)])
            count = 0
            while q:
                r, c = q.popleft()
                grid[i][j] = 0
                count += 1
                
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if (0 <= nr < R and
                        0 <= nc < C and
                        grid[nr][nc] == 1):
                        q.append((nr, nc))
            
            return count
    
        mx_area = 0
        for i in range(R):
            for j in range(C):
                if grid[i][j] == 1:
                    mx_area = max(mx_area, bfs(i, j))
        
        return mx_area

        
# @lc code=end

