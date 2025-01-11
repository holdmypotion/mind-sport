#
# @lc app=leetcode id=297 lang=python3
#
# [297] Serialize and Deserialize Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []
        q = deque([root])

        while q:
            node = q.popleft()
            if node:
                res.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                res.append('N')

        return ','.join(res)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        tree_list = data.split(',')
        val = tree_list[0]
        if val == 'N':
            return None
        
        val = int(val)
        root = TreeNode(val)
        q = deque([root])
        idx = 1

        while q:
            node = q.popleft()
            if tree_list[idx] != 'N':
                node.left = TreeNode(int(tree_list[idx]))
                q.append(node.left)
            idx += 1

            if tree_list[idx] != 'N':
                node.right = TreeNode(int(tree_list[idx]))
                q.append(node.right)
            idx += 1

        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
# @lc code=end

