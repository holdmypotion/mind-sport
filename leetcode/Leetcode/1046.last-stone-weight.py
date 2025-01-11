#
# @lc app=leetcode id=1046 lang=python3
#
# [1046] Last Stone Weight
#
import heapq
# @lc code=start
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        ## Using Max Heap
        stones = [-x for x in stones]
        heapq.heapify(stones)
        while len(stones) > 1:
            x = heapq.heappop(stones)
            y = heapq.heappop(stones)
            heapq.heappush(stones, x-y) if y > x else None

        return abs(stones[0]) if len(stones) > 0 else 0

        ## Using Bucket Sort
        # maxStone = max(stones)
        # bucket = [0] * (maxStone + 1)
        # for stone in stones:
        #     bucket[stone] += 1
        
        # first = second = maxStone
        # while first > 0:
        #     if bucket[first] % 2 == 0:
        #         first -= 1
        #         continue
            
        #     j = min(first - 1, second)
        #     while j > 0 and bucket[j] == 0:
        #         j -= 1
            
        #     if j == 0:
        #         return first
        #     second = j
        #     bucket[first] -= 1
        #     bucket[second] -= 1
        #     bucket[first - second] += 1
        #     first = max(first - second, second)
        # return first
# @lc code=end