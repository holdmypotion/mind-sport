#
# @lc app=leetcode id=357 lang=python3
#
# [357] Count Numbers with Unique Digits
#

# @lc code=start
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
            
        memo = {}
        
        def dp(pos, used_mask, started):
            """
            pos: current position (0-indexed from left)
            used_mask: bitmask of digits already used
            started: whether we've started forming a non-zero number
            """
            if pos == n:
                return 1
                
            key = (pos, used_mask, started)
            if key in memo:
                return memo[key]
                
            result = 0
            
            # If we haven't started forming a number yet
            if not started:
                # 1. Place a leading zero (which doesn't count as using digit 0)
                result += dp(pos + 1, used_mask, False)
                
            # 2. Start with digits 1-9 if the number hasn't started or from 0-9 if it is
            start = 0 if started else 1
            for digit in range(start, 10):
                # Skip if digit already used
                if (used_mask >> digit) & 1:
                    continue
                new_mask = used_mask | (1 << digit)
                result += dp(pos + 1, new_mask, True)
            
            memo[key] = result
            return result

        return dp(0, 0, False)
# @lc code=end

