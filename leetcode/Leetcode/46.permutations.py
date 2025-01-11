#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
#

# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # Idea:
        # Break it into sub problems where you start form just 1 element at the end and keep adding just one element and the possible permuations
        # EG:
        # 1,2,3
        # base -> [[]]
        # 3 -> [[3]]
        # 2,3 -> [[2,3], [3,2]]
        # 1,2,3 -> [[1,2,3], [2,1,3], [2,3,1], [1,3,2], [3,1,2], [3,2,1]]

        # At each stage you are just iterating over all permuations
        # and adding the new element at every place to get the permuations and then return it to the parent

        ## Recursion
        # if len(nums) == 0:
        #     return [[]]
        
        # permutations = self.permute(nums[1:])
        # res = []

        # for p in permutations:
        #     # len(p) + 1 because we'd like append to the end as well. We are essentially increasing the array len by 1 by adding that element
        #     for i in range(len(p)+1):
        #         p_c = p.copy()
        #         p_c.insert(i, nums[0])
        #         res.append(p_c)

        # return res

        ## Iterative
        # res = [[]]
        # for num in nums:
        #     permutations = []
        #     for p in res:
        #         for i in range(len(p) + 1):
        #             p_c = p.copy()
        #             p_c.insert(i, num)
        #             permutations.append(p_c)
        #     res = permutations
        # return res

        ## Backtracking
    #     self.res = []
    #     self.nums = nums
    #     self.picked = [False] * len(self.nums)
    #     self.__backtrack([])
    #     return self.res

    # def __backtrack(self, perm):
    #     if len(self.nums) == len(perm):
    #         self.res.append(perm.copy())
    #         return
        
    #     for j in range(len(self.nums)):
    #         if not self.picked[j]:
    #             perm.append(self.nums[j])
    #             self.picked[j] = True
    #             self.__backtrack(perm)
    #             perm.pop()
    #           self.picked[j] = False

        ## Backtracking - Bit mask for picked
        ## TC: O(n! * n)
        ## SC: O(n)
        self.res = []
        self.nums = nums
        self.picked = 1 << len(nums)
        self.__backtrack([])
        return self.res

    def __backtrack(self, perm):
        if len(self.nums) == len(perm):
            self.res.append(perm.copy())
            return
        
        for j in range(len(self.nums)):
            if not (self.picked & (1 << j)):
                perm.append(self.nums[j])
                self.picked |= (1 << j)
                self.__backtrack(perm)
                perm.pop()
                self.picked &= ~(1 << j)
        
# @lc code=end
