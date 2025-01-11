#
# @lc app=leetcode id=875 lang=python3
#
# [875] Koko Eating Bananas
#

# @lc code=start
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        self.piles = piles
        l, r = 1, max(piles)
        k = 0

        while (l <= r):
            mid = (l + r) // 2
            time = self.__calc_time(mid)
            if (time <= h):
                k = mid
                r = mid -1
            else:
                l = mid + 1
        
        return k

    def __calc_time(self, val: int) -> int:
        h = 0
        for pile in self.piles:
            h += (pile//val + (0 if pile%val == 0 else 1))

        return h
        
# @lc code=end

