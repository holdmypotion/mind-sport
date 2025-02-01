#
# @lc app=leetcode id=31 lang=python3
#
# [31] Next Permutation
#

# @lc code=start
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0:
            if nums[i] < nums[i+1]:
                for j in range(len(nums)-1, i, -1):
                    if nums[i] < nums[j]:
                        break

                nums[i], nums[j] = nums[j], nums[i]
                break

            i-=1
        nums[i+1:] = sorted(nums[i+1:])

        return nums
        # Q: 1,2,5

        # 5 -> [1, 2]
        #     -> 2 -> _, _, 2
        # 2 -> [1, 5]
        #     -> 5 -> _, 5, 2
        # 1 -> [1]
        #     -> 1 -> 1, 5, 2
        
        # Q: 5, 2, 1

        # 1 -> [5, 2]
        #     -> 2 -> _, _, 2
        # 2 -> [5, 1]
        #     -> 1 -> _, 1, 2
        # 5 -> [5]
        #     -> 5 -> 5, 1, 2


        # 2 1 5
        # 2 5 1 
        # 5 1 2
        # 5 2 1
# @lc code=end

