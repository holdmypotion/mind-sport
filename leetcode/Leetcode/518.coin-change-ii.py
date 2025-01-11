#
# @lc app=leetcode id=518 lang=python3
#
# [518] Coin Change II
#

# @lc code=start
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # O(n) - Space Complexity because we only need the data of the previous row and current row to compute the value

        prev_row = [0]*(amount + 1)
        prev_row[0] = 1

        for c in coins:
            curr_row = [0]*(amount + 1)
            for a in range(amount + 1):
                curr_row[a] = prev_row[a]
                rem = a - c
                if (rem >= 0):
                    curr_row[a] += curr_row[rem]
            prev_row = curr_row

        return curr_row[amount]
# @lc code=end