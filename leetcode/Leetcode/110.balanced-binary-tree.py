#
# @lc app=leetcode id=110 lang=python3
#
# [110] Balanced Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        is_balanced = True

        def dfs(root):
            nonlocal is_balanced

            if not root:
                return 0
            
            left = dfs(root.left)
            right = dfs(root.right)

            is_balanced &= (True if abs(right - left) <= 1 else False)
            return 1 + max(left, right)
        
        dfs(root)
        return is_balanced
# @lc code=end

