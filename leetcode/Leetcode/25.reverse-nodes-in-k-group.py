#
# @lc app=leetcode id=25 lang=python3
#
# [25] Reverse Nodes in k-Group
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k <= 1:
            return head
        
        dummy = itr = ListNode(0, head)
        count = self.__length(head) // k

        while count:
            count -= 1
            node_pairs_to_reverse = k-1
            prev = itr.next # 1
            curr = itr.next.next # 2
            while node_pairs_to_reverse:
                node_pairs_to_reverse -= 1
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp 

            last = itr.next # first node in the window becomes the last
            last.next = curr # 1 points to next node outside of window
            itr.next = prev # last node in the window becomes the first
            itr = last # Move to the last node in the window to reverse the next window in the next iteration
        
        return dummy.next
        

    def __length(self, head: Optional[ListNode]) -> int:
        count = 0
        while head:
            count += 1
            head = head.next
        
        return count
    
# @lc code=end

