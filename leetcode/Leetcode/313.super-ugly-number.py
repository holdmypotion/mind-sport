#
# @lc app=leetcode id=313 lang=python3
#
# [313] Super Ugly Number
#
from typing import List
import heapq

# @lc code=start
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        heap, vis = [1], set()
        for _ in range(n):
            x = heapq.heappop(heap)
            for p in primes:
                num = x * p
                if num not in vis:
                    vis.add(num)
                    heapq.heappush(heap, num)
        return x

# @lc code=end
