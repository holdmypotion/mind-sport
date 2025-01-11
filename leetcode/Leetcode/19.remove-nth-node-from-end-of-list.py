#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        itr = head
        len_count = 1
        while itr.next:
            len_count += 1
            itr = itr.next
        
        node_index_to_remove = len_count - n
        itr = dummy
        while node_index_to_remove:
            itr = itr.next
            node_index_to_remove -= 1
        itr.next = itr.next.next 

        return dummy.next

# @lc code=end

