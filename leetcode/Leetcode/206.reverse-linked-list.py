#
# @lc app=leetcode id=206 lang=python3
#
# [206] Reverse Linked List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head

        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        return prev

        # Recusive List Constructor
        # def list_constructor(ll, rl):
        #     if not ll:
        #         return rl
            
        #     return list_constructor(ll.next, ListNode(ll.val, rl))
        
        # return list_constructor(head, None)


# @lc code=end

