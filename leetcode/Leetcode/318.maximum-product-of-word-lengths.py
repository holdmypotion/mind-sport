#
# @lc app=leetcode id=318 lang=python3
#
# [318] Maximum Product of Word Lengths
#

# @lc code=start
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        bit_masks = [0] * n
        max_product = 0

        for i in range(n):
            for c in words[i]:
                bit_masks[i] |= 1 << (ord(c) - ord('a'))
            
        for i in range(n):
            for j in range(i+1, n):
                if not (bit_masks[i] & bit_masks[j]):
                    max_product = max(max_product, len(words[i]) * len(words[j]))
        
        return max_product
        
# @lc code=end

