#
# @lc app=leetcode id=310 lang=python3
#
# [310] Minimum Height Trees
#

# @lc code=start
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        ind = [0] * n
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            ind[v] += 1
            ind[u] += 1

        q = deque()
        for i in range(n):
            if ind[i] == 1:
                q.append(i)

        while q:
            if n <= 2:
                return list(q)

            for _ in range(len(q)):
                n -= 1
                u = q.popleft()
                for v in adj[u]:
                    ind[v] -= 1
                    if ind[v] == 1:
                        q.append(v)

        return [0]
# @lc code=end
