#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        ## Approach 1: Find the pivot, apply binary
        # self.target = target
        # pivot = self.__pivot(nums)
        # print(nums[0: pivot], nums[pivot:])
        # left = self.__binary_search(nums[0:pivot])
        # right = self.__binary_search(nums[pivot:])
        # return max(left, -1 if right == -1 else right + pivot)


        ## Appraoch 2: Straight conditions
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) // 2
            if target == nums[mid]:
                return mid

            if nums[l] <= nums[mid]: # mid value is in left sorted partition
                if target < nums[mid] and target >= nums[l]: # should you stay in the left sorted partition?
                    r = mid - 1
                else:
                    l = mid + 1

            else: # mid value is in right sorted partition
                if target > nums[mid] and target <= nums[r]: # should you stay in the right sorted partition?
                    l = mid + 1
                else:
                    r = mid - 1
        return -1
    
    def __pivot(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        curr_min = float("inf")
        pivot = -1

        while (l <= r):
            mid = (l + r) // 2
            if (curr_min > nums[mid]):
                curr_min = nums[mid]
                pivot = mid
            if (nums[mid] > nums[r]):
                l = mid + 1
            else:
                r = mid - 1

        return pivot
    
    def __binary_search(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1

        while (l <= r):
            mid = (l + r) // 2
            if (nums[mid] < self.target):
                l = mid + 1
            elif (nums[mid] > self.target):
                r = mid - 1
            else:
                return mid
        return -1

# @lc code=end

