class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if not s: return s

        m = len(s)
        t = s + "#" + s[::-1]
        n = len(t)

        pi = [0] * n
        k = 0
        for i in range(1, n):
            while k > 0 and t[i] != t[k]:
                k = pi[k - 1]
            if t[i] == t[k]:
                k += 1
            pi[i] = k

        max_prefix = pi[-1]
        return s[max_prefix:][::-1] + s
