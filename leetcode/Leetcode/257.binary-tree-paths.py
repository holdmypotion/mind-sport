#
# @lc app=leetcode id=257 lang=python3
#
# [257] Binary Tree Paths
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        res = []
        path = []
        def dfs(node):
            if not node.left and not node.right:
                path.append(node.val)
                res.append("->".join(map(str, path)))
                path.pop()
                return

            if node.left:
                path.append(node.val)
                dfs(node.left)
                path.pop()
            if node.right:
                path.append(node.val)
                dfs(node.right)
                path.pop()
    
        dfs(root)
        return res
    

        
# @lc code=end

