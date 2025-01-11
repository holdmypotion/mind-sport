#
# @lc app=leetcode id=79 lang=python3
#
# [79] Word Search
#

# @lc code=start
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # row, col = len(board), len(board[0])
        # # path = set() - Using Set
        # visited = [[False] * col for _ in range(row)]


        # def dfs(r, c, i):
        #     if i == len(word):
        #         return True
        #     if (r < 0 or c < 0 or r >= row or c >= col or
        #         word[i] != board[r][c] or
        #         # (r, c) in path
        #         visited[r][c]
        #         ):
        #         return False

        #     # path.add((r, c)) 
        #     visited[r][c] = True
        #     res = (dfs(r + 1, c, i+1) or
        #         dfs(r - 1, c, i+1) or
        #         dfs(r, c + 1, i+1) or
        #         dfs(r, c - 1, i+1))
        #     visited[r][c] = False
        #     # path.remove((r, c)) 
        #     return res

    
        # for r in range(row):
        #     for c in range(col):
        #         if dfs(r, c, 0):
        #             return True

        # return False

        ## Using inplace edits to the board
        row, col = len(board), len(board[0])


        def dfs(r, c, i):
            if i == len(word):
                return True
            if (r < 0 or c < 0 or r >= row or c >= col or
                word[i] != board[r][c]):
                return False

            board[r][c] = "#"
            res = (dfs(r + 1, c, i+1) or
                dfs(r - 1, c, i+1) or
                dfs(r, c + 1, i+1) or
                dfs(r, c - 1, i+1))
            board[r][c] = word[i]
            return res

    
        for r in range(row):
            for c in range(col):
                if dfs(r, c, 0):
                    return True

        return False

# @lc code=end
