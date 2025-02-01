#
# @lc app=leetcode id=2493 lang=python3
#
# [2493] Divide Nodes Into the Maximum Number of Groups
#

# @lc code=start
from collections import deque
from typing import List

class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for _ in range(n+1)]
        self.dist = [0]*(n+1)
        self.color = [-1]*(n+1)
        self.vis = [False]*(n+1)
        self.q = deque()
    
    def add_edge(self, u, v):
        self.adj[u].append(v)
    
    def bfs(self, i):
        self.q.append(i)
        mx = 0

        while self.q:
            u = self.q.popleft()
            if self.color[u] == -1: self.color[u] = 1
            mx = max(mx, self.dist[u])

            for v in self.adj[u]:
                if self.color[v] == self.color[u]: return [False, 0]
                if self.vis[v]: continue
                self.vis[v] = True
                self.dist[v] = self.dist[u] + 1
                self.color[v] = 1 - self.color[u]
                self.q.append(v)

            return [True, mx+1]

    def reset(self):
        self.q = deque()
        self.dist = [0]*(self.n+1)
        self.color = [-1]*(self.n+1)
        self.vis = [False]*(self.n+1)


class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        g = Graph(n)
        for u, v in edges:
            g.add_edge(u, v)
            g.add_edge(v, u)

        ans = -1
        for i in range(1, n+1):
            g.reset()
            total = 0
            skip = False
            for j in range(1, n+1):
                if not g.vis[j]:
                    possible, groups = g.bfs(j)
                    if not possible:
                        skip = True
                        break
                    else:
                        total += groups
            print(i, g.dist, g.color, total)
            if not skip:
                ans = max(ans, total)
        
        return ans
        
# @lc code=end

