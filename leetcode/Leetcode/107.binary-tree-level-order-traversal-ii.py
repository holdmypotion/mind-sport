#
# @lc app=leetcode id=107 lang=python3
#
# [107] Binary Tree Level Order Traversal II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque([(root, 0)])
        levels = []
        
        while q:
            node, level = q.popleft()
            if node:
                while len(levels) <= level:
                    levels.append([])
                levels[level].append(node.val)

                q.append((node.left, level + 1))
                q.append((node.right, level + 1))

        return levels[::-1]
# @lc code=end
