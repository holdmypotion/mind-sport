#
# @lc app=leetcode id=98 lang=python3
#
# [98] Validate Binary Search Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        ## DFS
        # def dfs(node, left, right):
        #     if not node:
        #         return True
        #     if not (left < node.val < right):
        #         return False
            
        #     return dfs(node.left, left, node.val) and \
        #         dfs(node.right, node.val, right)

        # return dfs(root, float('-inf'), float('inf'))

        ## BFS
        q = deque([(root, float('-inf'), float('inf'))])

        while q:
            node, left, right = q.popleft()

            if node:
                if not (left < node.val < right):
                    return False

                q.append((node.left, left, node.val))
                q.append((node.right, node.val, right))
        
        return True
# @lc code=end

