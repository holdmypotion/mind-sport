#
# @lc app=leetcode id=138 lang=python3
#
# [138] Copy List with Random Pointer
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        old_to_copy_map = { None: None }

        itr = head
        while itr:
            old_to_copy_map[itr] = Node(itr.val)
            itr = itr.next
        
        itr = head
        while itr:
            copy_node = old_to_copy_map[itr]
            copy_node.next = old_to_copy_map[itr.next]
            copy_node.random = old_to_copy_map[itr.random]
            itr = itr.next

        return old_to_copy_map[head]
# @lc code=end