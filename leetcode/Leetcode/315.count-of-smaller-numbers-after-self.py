#
# @lc app=leetcode id=315 lang=python3
#
# [315] Count of Smaller Numbers After Self
#

# @lc code=start
LIMIT = 10**4 + 1
class BIT:
    def __init__(self, n):
        self.n = n
        self.tree = [0]*(n+1)
    
    def add(self, k, x=1):
        while k <= self.n:
            self.tree[k] += x
            k += (k & -k)
    
    def sum(self, k):
        res = 0
        while k > 0:
            res += self.tree[k]
            k -= (k & -k)
        
        return res

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # Need to shift [-10**4, 10**4] to [1, 2*10**4] as BIT only works for positive numbers
        for el in nums:
            el += LIMIT

        bit = BIT(LIMIT)

        ans = [] 
        for el in nums[::-1]:
            ans.append(bit.sum(el))
            bit.add(el)
        
        return ans[::-1]


        
# @lc code=end

