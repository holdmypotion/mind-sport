#
# @lc app=leetcode id=638 lang=python3
#
# [638] Shopping Offers
#

# @lc code=start
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        max_need = max(needs)
        items = len(price)

        dp = [[float('inf')]*(max_need+1) for _ in range(items)]

        for i in range(items):
            dp[i][0] = 0

        for k in range(1, max_need+1):
            for offer in special:
                offer_price = offer[-1]
                for i in range(items):
                    # print(i, k, offer[i], needs[i], price[i])
                    dp[i][k] = min(
                        dp[i][k],
                        (dp[i][k-offer[i]] + offer_price) if k >= offer[i] else float('inf'),
                        dp[i][k-1] + price[i]
                    )
        for r in dp:
            print(r)

        res = 0
        for i, need in enumerate(needs):
            res += dp[i][need]

        return res
# @lc code=end

