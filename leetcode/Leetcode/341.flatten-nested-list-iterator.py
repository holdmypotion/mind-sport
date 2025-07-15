#
# @lc app=leetcode id=341 lang=python3
#
# [341] Flatten Nested List Iterator
#

# @lc code=start
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.flattened_list = []
        self.cur_itr = 0

        def list_flattener(nestedList: [NestedInteger]):
            for ele in nestedList:
                if ele.isInteger():
                    self.flattened_list.append(ele.getInteger())
                else:
                    list_flattener(ele.getList())
        
        list_flattener(nestedList)
    
    def next(self) -> int:
        val = self.flattened_list[self.cur_itr]
        self.cur_itr += 1
        return val
    
    def hasNext(self) -> bool:
        return self.cur_itr < len(self.flattened_list)
         

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
# @lc code=end

