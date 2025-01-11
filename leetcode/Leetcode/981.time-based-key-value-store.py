#
# @lc app=leetcode id=981 lang=python3
#
# [981] Time Based Key-Value Store
#

# @lc code=start
class TimeMap:

    def __init__(self):
        self.timemap = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.timemap:
            self.timemap[key] = []
        self.timemap[key].append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        values = self.timemap.get(key, [])

        l, r = 0, len(values) - 1
        res = ""
        while l <= r:
            mid = (l + r) // 2
            if timestamp >= values[mid][1]:
                res = values[mid][0]
                l = mid + 1
            elif timestamp < values[mid][1]:
                r = mid - 1
        
        return res

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
# @lc code=end

