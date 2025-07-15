#
# @lc app=leetcode id=447 lang=python3
#
# [447] Number of Boomerangs
#

# @lc code=start
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        count = 0
        for x, y in points:
            dist = defaultdict(int)
            for X, Y in points:
                dis = (Y-y)**2 + (X-x)**2
                dist[dis] += 1
            
            for v in dist.values():
                if v >= 2:
                    count += v*(v-1)
        
        return count
                

# @lc code=end

