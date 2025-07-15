#
# @lc app=leetcode id=218 lang=python3
#
# [218] The Skyline Problem
#
import heapq
# @lc code=start
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []  #  (point, height, type)
        for l, r, h in buildings:
            events.append((l, -h, 'start'))
            events.append((r, h, 'end'))
        
        events.sort(key=lambda x: (x[0], x[1]))
        res, mx_h, h_count = [], [0], defaultdict(int)
        h_count[0] = 1

        for point, height, type in events:
            prev_max = -mx_h[0]
            if type == 'start':
                heapq.heappush(mx_h, height)
                h_count[height] += 1
            else:
                h_count[-height] -= 1
                while mx_h and h_count[mx_h[0]] == 0:
                    heapq.heappop(mx_h)

            cur_max = -mx_h[0]
            if cur_max != prev_max:
                res.append([point, cur_max])

        return res

# @lc code=end

