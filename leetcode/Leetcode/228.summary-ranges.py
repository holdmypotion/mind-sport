#
# @lc app=leetcode id=228 lang=python3
#
# [228] Summary Ranges
#

# @lc code=start
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:        
        if not nums: return []

        res = []
        cur = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i-1] + 1 == nums[i]:
                cur.append(nums[i])
            else:
                s = f"{cur[0]}"
                if len(cur) > 1:
                    s += f"->{cur[-1]}"
                res.append(s)
                cur = [nums[i]]

        s = f"{cur[0]}"
        if len(cur) > 1:
            s += f"->{cur[-1]}"
        res.append(s)

        return res
# @lc code=end

