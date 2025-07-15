class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        s = str(n)

        memo = {}

        def dp(pos, tight, used, started):
            if pos >= len(s):
                return 1 if started else 0

            key = (pos, tight, used, started)
            if key in memo:
                return memo[key]

            res = 0
            if not started:
                res += dp(pos + 1, False, used, False)

            start = 0 if started else 1
            limit = int(s[pos]) if tight else 9

            for digit in range(start, limit+1):
                if (used >> digit) & 1:
                    continue

                new_mask = used | (1 << digit)
                new_tight = tight and (digit == limit)
                res += dp(pos + 1, new_tight, new_mask, True)

            memo[key] = res
            return res


        return n-dp(0, True, 0, False)
