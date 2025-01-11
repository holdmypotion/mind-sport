#
# @lc app=leetcode id=1448 lang=python3
#
# [1448] Count Good Nodes in Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        good_nodes = 0

        def dfs(root, mv):
            nonlocal good_nodes

            if not root:
                return

            if mv <= root.val:
                good_nodes += 1

            mv = max(mv, root.val)
            dfs(root.left, mv)
            dfs(root.right, mv)
        
        dfs(root, root.val)
        return good_nodes

        
# @lc code=end

