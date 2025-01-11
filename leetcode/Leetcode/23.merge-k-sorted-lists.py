#
# @lc app=leetcode id=23 lang=python3
#
# [23] Merge k Sorted Lists
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists or len(lists) == 0:
            return None

        while len(lists) > 1:
            mergedLists = [] 
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i+1] if (i+1) < len(lists) else None
                mergedLists.append(self.__merge_lists(l1, l2))

            lists = mergedLists

        return lists[0]

    def __merge_lists(self, l1: List, l2: List):
        dummy = ListNode()
        itr = dummy

        while l1 and l2:
            if l1.val < l2.val:
                itr.next = l1
                l1 = l1.next
            else:
                itr.next = l2
                l2 = l2.next
            itr = itr.next

        if l1:
            itr.next = l1
        elif l2:
            itr.next = l2
        
        return dummy.next

# @lc code=end

