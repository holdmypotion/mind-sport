#
# @lc app=leetcode id=524 lang=python3
#
# [524] Longest Word in Dictionary through Deleting
#

# @lc code=start
class Solution:
    def sub_seq(self, s, t):
        n, m = len(s), len(t)
        l, r = 0, 0

        while l < n and r < m:
            if s[l] == t[r]:
                l += 1
                r += 1
            else:
                l += 1
        
        return r == m


    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        res = ""

        for word in sorted(dictionary, key=lambda x: (-len(x), x)):
            if len(res) < len(word) and self.sub_seq(s, word):
                res = word
                break
        
        return res

        
# @lc code=end

