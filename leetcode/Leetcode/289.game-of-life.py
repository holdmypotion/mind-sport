#
# @lc app=leetcode id=289 lang=python3
#
# [289] Game of Life
#

# @lc code=start
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        directions = [[0,1], [1,0],[-1,0],[0,-1],[1,1],[-1,-1],[1,-1],[-1,1]]
        R, C = len(board), len(board[0])
        tmp = [list(board[i]) for i in range(R)]

        for r in range(R):
            for c in range(C):
                ones = 0
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if (0 <= nr < R and
                        0 <= nc < C and
                        tmp[nr][nc] == 1):
                        ones += 1

                if board[r][c] == 0 and ones == 3:
                    board[r][c] = 1
                elif board[r][c] == 1:
                    if ones < 2:
                        board[r][c] = 0
                    elif 2 <= ones <= 3:
                        board[r][c] = 1
                    elif ones > 3:
                        board[r][c] = 0

# @lc code=end

