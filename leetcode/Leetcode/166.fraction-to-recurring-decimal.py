#
# @lc app=leetcode id=166 lang=python3
#
# [166] Fraction to Recurring Decimal
#

# @lc code=start
class Solution:
    def fractionToDecimal(self, n: int, d: int) -> str:
        ans = n / d
        if int(ans) == ans: return str(int(ans)) # Covering cases like 2.0 -> 2
        ans = '-' * (n / d < 0) + f"{str(abs(int(ans)))}." # Adding - for negative number and taking the int part before the decimal
        n, d = abs(n), abs(d)
        frac, lst, i = "", {}, 0
        n = (n % d) * 10
        while True:
            if n in lst:
                idx = lst[n]
                frac = frac[:idx] + '(' + frac[idx:] + ')'
                ans += frac
                break
            lst[n] = i; i += 1
            frac += str(n // d)
            n = (n % d) * 10
            if n != 0: continue
            ans += frac
            break
        return ans
            


# @lc code=end

