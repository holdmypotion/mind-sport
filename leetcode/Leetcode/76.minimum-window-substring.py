#
# @lc app=leetcode id=76 lang=python3
#
# [76] Minimum Window Substring
#

# @lc code=start
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t): return ""
        if s == t: return s

        tmp = Counter(t)

        smp = defaultdict(int)

        res = (0, float('inf'))
        have, need = 0, len(tmp)
        l = 0
        for r in range(len(s)):
            smp[s[r]] += 1
            if s[r] in tmp and smp[s[r]] == tmp[s[r]]:
                have += 1

            # if r-l+1 >= len(t):
            while have >= need:
                if (r-l < res[1] - res[0]): res = (l, r)

                if s[l] in tmp and smp[s[l]] == tmp[s[l]]:
                    have -= 1
                smp[s[l]] -= 1
                l += 1


        return s[res[0]: res[1]+1] if res[1] != float('inf') else ""
# @lc code=end

