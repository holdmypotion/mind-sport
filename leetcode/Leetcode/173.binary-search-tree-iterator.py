#
# @lc app=leetcode id=173 lang=python3
#
# [173] Binary Search Tree Iterator
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root

    def next(self) -> int:
        while self.root:
            if not self.root.left:
                val = self.root.val
                self.root = self.root.right
                return val

            pred = self.root.left # we'll get the node just smaller than root which will exists at the right most end of the left subtree
            while pred.right and pred.right != self.root:
                pred = pred.right
            
            if not pred.right:
                pred.right = self.root
                self.root = self.root.left
            else:
                pred.right = None
                val = self.root.val
                self.root = self.root.right
                return val

    def hasNext(self) -> bool:
        return self.root is not None


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
# @lc code=end

