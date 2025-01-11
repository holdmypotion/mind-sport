#
# @lc app=leetcode id=3202 lang=python3
#
# [3202] Find the Maximum Length of Valid Subsequence II
#

# @lc code=start
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        ## Basic Idea
        # 1. We'll have to find the sub sequence for all the resulting mods, i.e mod = (sub[0] + sub[1]) % K. It could be anything form [0, k-1]
        # 2. (x + y) % k = mod
        # 3. if (x + y) < k then (x + y) % k == (x + y) == mod. Hence x = mod - y
        # 4. if (x + y) >= k then y = (mode - x + k) % k. [Try this for x = 1, y = 8, k = 10. You'll get it]

        # dp[y][mod]: length of the subseq ending with value y where (pervNum + y) % k = mod
        # dp = [[0] * k for _ in range(k)]
        # max_subseq_len = 1
        # for num in nums:
        #     y = num % k
        #     for mod in range(k):
        #         x = (mod - y + k) % k
        #         dp[y][mod] = max(dp[y][mod] , 1 + dp[x][mod])
        #         max_subseq_len = max(max_subseq_len , dp[y][mod])
        # return max_subseq_len

        ## Better Solution
        # Traverse in reverse order and keep checking the longest sub seq tha can be formed starting with that element.

        dp = [[1]*k for _ in range(len(nums))]
        mx = 0
        for i in range(len(nums) - 2, -1, -1):
            for j in range(i + 1, len(nums)):
                mod = (nums[i] + nums[j]) % k
                dp[i][mod] = max(dp[i][mod], 1 + dp[j][mod])
            mx = max(mx, max(dp[i]))
        return mx
        
# @lc code=end