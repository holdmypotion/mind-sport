#
# @lc app=leetcode id=133 lang=python3
#
# [133] Clone Graph
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        vis = {}
        vis[node] = Node(node.val)
        q = deque([node])

        while q:
            u = q.popleft()
            for v in u.neighbors:
                if v not in vis:
                    vis[v] = Node(v.val)
                    q.append(v)
                
                vis[u].neighbors.append(vis[v])

        return vis[node]
        
# @lc code=end

