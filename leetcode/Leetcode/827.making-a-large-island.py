#
# @lc app=leetcode id=827 lang=python3
#
# [827] Making A Large Island
#

# @lc code=start
class Dsu:
    def __init__(self, n):
        self.n = n
        self.p = [[[i, j] for j in range(n)] for i in range(n)]
        self.size = [[1]*n for _ in range(n)]

    def find(self, i, j):
        if self.p[i][j] == [i, j]:
            return [i, j]

        self.p[i][j] = self.find(*self.p[i][j])
        return self.p[i][j]
    
    def unite(self, i, j, x, y):
        i, j = self.find(i, j)
        x, y = self.find(x, y)

        if [i, j] != [x, y]:
            if self.size[i][j] < self.size[x][y]:
                i, j, x, y = x, y, i, j
            
            self.p[x][y] = [i, j]
            self.size[i][j] += self.size[x][y]
        

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        directions = [[1,0], [0,1], [-1,0], [0,-1]]
        n = len(grid)
        dsu = Dsu(n)

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    for dr, dc in directions:
                        nr, nc = i+dr, j+dc
                        if (nr >= 0 and nr < n and
                            nc >= 0 and nc < n and
                            grid[nr][nc] == 1):
                            dsu.unite(i,j,nr,nc)
        

        ans = 1
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    total = 1
                    for dr, dc in directions:
                        nr, nc = i+dr, j+dc
                        if (nr >= 0 and nr < n and
                            nc >= 0 and nc < n and
                            grid[nr][nc] == 1):
                            pr, pc = dsu.find(nr, nc)
                            total += dsu.size[pr][pc]
        
                    ans = max(ans, total)
        print(dsu.p, dsu.size)
        return ans

# @lc code=end

