#
# @lc app=leetcode id=331 lang=python3
#
# [331] Verify Preorder Serialization of a Binary Tree
#

# @lc code=start
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        preorder = preorder.split(',')
        i = 0
        def dfs() -> bool:
            nonlocal i

            if i >= len(preorder):
                return False

            if preorder[i] == '#':
                return True

            val = True
            i += 1 
            val &= dfs()
            i += 1
            val &= dfs()

            return val
            
        ans = dfs()
        return ans if i == len(preorder)-1 else False

# @lc code=end

