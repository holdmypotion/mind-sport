#
# @lc app=leetcode id=542 lang=python3
#
# [542] 01 Matrix
#

# @lc code=start
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        directions = [[1,0], [0,1], [-1,0], [0,-1]]
        R, C = len(mat), len(mat[0])

        q = deque()
        for r in range(R):
            for c in range(C):
                if mat[r][c] == 0:
                    q.append((r, c))
                else:
                    mat[r][c] = float('inf')
        
        while q:
            r, c = q.popleft()

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if (0 <= nr < R and
                    0 <= nc < C and
                    mat[nr][nc] > mat[r][c] + 1):
                    q.append((nr, nc))
                    mat[nr][nc] = mat[r][c] + 1
            
        return mat
# @lc code=end

