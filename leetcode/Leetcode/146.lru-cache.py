#
# @lc app=leetcode id=146 lang=python3
#
# [146] LRU Cache
#

# @lc code=start
class Node:

    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}
        self.least, self.most = Node(0, 0), Node(0, 0)
        self.least.next = self.most
        self.most.prev = self.least
        

    def __remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next = nxt
        nxt.prev = prev


    def __insert(self, node):
        prev = self.most.prev
        prev.next = node
        node.prev = prev

        self.most.prev = node
        node.next = self.most


    def get(self, key: int) -> int:
        node = self.cache.get(key)
        if node:
            self.__remove(node)
            self.__insert(node)
            return node.val

        return -1
        

    def put(self, key: int, value: int) -> None:
        node = self.cache.get(key)
        if node:
            node.val = value
            self.__remove(node)
            self.__insert(node)
        else:
            node = Node(key, value)
            self.__insert(node)
            self.cache[key] = node
            if len(self.cache) > self.cap:
                lru = self.least.next
                self.__remove(lru)
                del self.cache[lru.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

