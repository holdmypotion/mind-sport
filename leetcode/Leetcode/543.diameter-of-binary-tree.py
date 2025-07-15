#
# @lc app=leetcode id=543 lang=python3
#
# [543] Diameter of Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        max_dia = 0

        def dfs(root):
            nonlocal max_dia

            if not root:
                return 0
            
            left = dfs(root.left)
            right = dfs(root.right)
            max_dia = max(max_dia, left + right) # max dia that passes through this node as root

            return 1 + max(left, right) # pick the max length path and move up a node hence +1

        dfs(root)
        return max_dia

        
# @lc code=end
