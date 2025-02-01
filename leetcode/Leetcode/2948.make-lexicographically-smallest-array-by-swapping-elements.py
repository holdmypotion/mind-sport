#
# @lc app=leetcode id=2948 lang=python3
#
# [2948] Make Lexicographically Smallest Array by Swapping Elements
#

# @lc code=start
import heapq
from collections import defaultdict

class DSU:
    def __init__(self, n):
        self.n = n
        self.p = list(range(n+1))
        self.size = [1]*(n+1)

    def find(self, u):
        if self.p[u] == u:
            return u
        self.p[u] = self.find(self.p[u])
        return self.p[u]

    def unite(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a
            self.size[a] += self.size[b]
            self.p[b] = a
            return True
        return False

    def same(self, a, b):
        return self.find(a) == self.find(b)

class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        # Q: [1,6,18,7,2,1,4], limit = 3
        # A: [1,4,18,6,1,2,7]


        # Sorted: [1,1,2,6,7,18]
        # G1: [1,1,2]
        # G2: [4,6,7]
        # G3: [18]

        dsu = DSU(len(nums))
        sn = sorted([(ele, idx) for idx, ele in enumerate(nums)])

        for i in range(1, len(sn)):
            if abs(sn[i-1][0] - sn[i][0]) <= limit:
                dsu.unite(sn[i-1][1], sn[i][1])

        mp = defaultdict(list)
        for idx, ele in enumerate(nums):
            heapq.heappush(mp[dsu.find(idx)], ele)
        
        for i in range(len(nums)):
            nums[i] = heapq.heappop(mp[dsu.find(i)])
        
        return nums

        
# @lc code=end


