#
# @lc app=leetcode id=140 lang=python3
#
# [140] Word Break II
#

# @lc code=start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        n = len(s)
        wordDict = set(wordDict)
        res = []
        sentence = []

        def dfs(i):
            if i == n:
                res.append(" ".join(sentence))
                return

            for k in range(i, n):
                sub = s[i:k+1]
                if sub in wordDict:
                    sentence.append(sub)
                    dfs(k+1)
                    sentence.pop()

        dfs(0)
        return res

# @lc code=end

