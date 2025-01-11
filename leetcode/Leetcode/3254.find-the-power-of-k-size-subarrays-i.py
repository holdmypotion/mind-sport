#
# @lc app=leetcode id=3254 lang=python3
#
# [3254] Find the Power of K-Size Subarrays I
#

# @lc code=start
class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        # Input: nums = [1,2,3,4,3,2,5], k = 3
        # Output: [3,4,-1,-1,-1]

        ## Brute Force
        # TC: O(n.k)
        res = []

        for i in range(len(nums)):
            if i+k > len(nums):
                break

            flag = False
            j = i + 1
            while j < i + k:
                # check if not consecutive
                if (nums[j] - nums[j-1] != 1):
                    flag = True
                    break
                j += 1
                
            if flag:
                res.append(-1)
            else:
                res.append(nums[j-1])
        
        return res


# @lc code=end

