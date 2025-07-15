#
# @lc app=leetcode id=526 lang=python3
#
# [526] Beautiful Arrangement
#

# @lc code=start
class Solution:
    def countArrangement(self, n: int) -> int:
        def backtrack(i, cur, mask):
            if i >= n:
                return 1

            val = 0
            for k in range(1, n+1):
                if (mask >> k) & 1 or not (k % (i+1)==0 or (i+1) % k==0):
                    continue

                val += backtrack(i+1, cur+[k], mask | (1 << k))
            
            return val
            
        return backtrack(0, [], 0)
        
# @lc code=end

