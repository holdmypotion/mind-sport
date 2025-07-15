#
# @lc app=leetcode id=105 lang=python3
#
# [105] Construct Binary Tree from Preorder and Inorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        ## Recursive DFS - Brute Force - T&S: O(n^2)
        # # preorder -> Root -> Left -> Right
        # # inorder -> Left -> Root -> Right

        # if not preorder or not inorder:
        #     return None

        # root = TreeNode(preorder[0]) # preorder[0] -> root for this subtree
        # mid = inorder.index(root.val) # left sub array is the left subtree | right sub array is the right subtree
        # # preorder[1:mid+1] -> left subtree  | inorder[:mid] -> left subtree
        # # preorder[mid+1:] -> right subtree  | inorder[mid+1:] -> right subtree
        # root.left = self.buildTree(preorder[1:mid+1], inorder[:mid]) 
        # root.right = self.buildTree(preorder[mid+1:], inorder[mid+1:])

        # return root


        ## Hash Map Optimization - Binary Division Flow

        indices = { v: idx for idx, v in enumerate(inorder) }

        rootIdx = 0
        def dfs(l, r):
            nonlocal rootIdx

            if l > r:
                return None

            root = TreeNode(preorder[rootIdx])
            rootIdx += 1
            mid = indices[root.val]
            # Because mid is already the root
            root.left = dfs(l, mid-1)
            root.right = dfs(mid+1, r)
            return root

        return dfs(0, len(inorder)-1)
# @lc code=end

