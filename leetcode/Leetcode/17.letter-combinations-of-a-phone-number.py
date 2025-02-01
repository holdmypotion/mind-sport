#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#

# @lc code=start
class Solution:
    def letterCombinations(self, d: str) -> List[str]:
        n = len(d)
        if n == 0: return []

        mp = {
            2: "abc",
            3: "def",
            4: "ghi",
            5: "jkl",
            6: "mno",
            7: "pqrs",
            8: "tuv",
            9: "wxyz",
        }

        res = []
        comb = []
        def dfs(i):
            if i == n:
                res.append(''.join(comb))
                return

            for ch in mp[int(d[i])]:
                comb.append(ch)
                dfs(i+1)
                comb.pop()

        dfs(0) 
        return res

        
# @lc code=end

