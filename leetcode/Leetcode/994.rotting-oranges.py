#
# @lc app=leetcode id=994 lang=python3
#
# [994] Rotting Oranges
#

# @lc code=start
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        q = deque()

        fresh = 0
        for r in range(n):
            for c in range(m):
                if grid[r][c] == 1:
                    fresh += 1
                elif grid[r][c] == 2:
                    q.append((r, c))

        time = 0
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        while q and fresh:
            # Looping through the rotten in the list because this is a multisource BFS
            for _ in range(len(q)):
                # For this particular rotten orage, make all the neighbors rotten
                r, c = q.popleft()

                for dr, dc in directions:
                    x = r + dr
                    y = c + dc

                    if (x < 0 or y < 0 or
                        x == n or y == m or
                        grid[x][y] != 1):
                        continue
                    
                    grid[x][y] = 2
                    q.append((x, y))
                    fresh -= 1
                    
            time += 1

        return time if fresh == 0 else -1

        
# @lc code=end

