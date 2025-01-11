#
# @lc app=leetcode id=445 lang=python3
#
# [445] Add Two Numbers II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        s1 = []
        s2 = []

        while l1:
            s1.append(l1.val)
            l1 = l1.next


        while l2:
            s2.append(l2.val)
            l2= l2.next


        carry = 0
        itr = None
        while s1 or s2 or carry:
            v1 = s1.pop() if len(s1) != 0 else 0
            v2 = s2.pop() if len(s2) != 0 else 0

            val = v1 + v2 + carry
            carry = val // 10
            val = val % 10

            itr = ListNode(val, itr)

        return itr

# @lc code=end

