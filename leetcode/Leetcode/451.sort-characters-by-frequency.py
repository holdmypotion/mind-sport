#
# @lc app=leetcode id=451 lang=python3
#
# [451] Sort Characters By Frequency
#

# @lc code=start
class Solution:
    def frequencySort(self, s: str) -> str:
        count = Counter(s)
        count = dict(sorted(count.items(), key=lambda item: -item[1]))
        res = ""
        for k, v in count.items():
            res += k*v
        
        return res

        
# @lc code=end

