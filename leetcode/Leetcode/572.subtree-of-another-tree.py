#
# @lc app=leetcode id=572 lang=python3
#
# [572] Subtree of Another Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# [3,4,5,1,2,null,null,null,null,0]
# [4,1,2]

class Solution:
    def isSubtree(
            self, root: Optional[TreeNode],
            subRoot: Optional[TreeNode]
        ) -> bool:
        if not subRoot:
            return True
        elif not root:
            return False

        return self.__is_equal(root, subRoot) \
            or self.isSubtree(root.left, subRoot) \
            or self.isSubtree(root.right, subRoot)


    def __is_equal(self, p, q) -> bool:
        if not p and not q:
            return True

        if p and q and p.val == q.val:
            return self.__is_equal(p.left, q.left) \
                and self.__is_equal(p.right, q.right)
        else:
            return False

# @lc code=end
