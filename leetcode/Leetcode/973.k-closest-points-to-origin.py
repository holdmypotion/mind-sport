#
# @lc app=leetcode id=973 lang=python3
#
# [973] K Closest Points to Origin
#

# @lc code=start
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        ## Sort
        # points.sort(key=lambda p: p[0]**2 + p[1]**2)
        # return points[:k]

        ## MinHeap
        minHeap = []

        for x, y in points:
            dist = x**2 + y**2

            minHeap.append((dist, x, y))

        heapq.heapify(minHeap)
        res = []
        while k > 0:
            _, x, y = heapq.heappop(minHeap)
            res.append([x, y])
            k -= 1
        
        return res


# @lc code=end
