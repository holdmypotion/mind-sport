#
# @lc app=leetcode id=104 lang=python3
#
# [104] Maximum Depth of Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        ### Recursive DFS
        # if not root:
        #     return 0

        # return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

        ### Iterative DFS - Pre order - Root -> Left -> Right
        max_dist = 0
        stack = [(root, 1)]
        while stack:
            node, dist = stack.pop()

            if node:
                max_dist = max(max_dist, dist)
                stack.append((node.right, dist+1))
                stack.append((node.left, dist+1))

        return max_dist

        ### BFS
        # max_dist = 0
        # q = deque([(root, 1)])

        # while q:
        #     node, dist = q.popleft()

        #     if node:
        #         q.append((node.left, dist+1))
        #         q.append((node.right, dist+1))
        #         max_dist = max(max_dist, dist)

        # return max_dist


# @lc code=end

