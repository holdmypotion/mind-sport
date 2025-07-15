#
# @lc app=leetcode id=230 lang=python3
#
# [230] Kth Smallest Element in a BST
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def dfs(root):
            nonlocal k
            if not root:
                return -1

            val = dfs(root.left)
            k -= 1
            if k == 0:
                return root.val
            val = max(val, dfs(root.right))
            return val

        return dfs(root)

        
# @lc code=end

