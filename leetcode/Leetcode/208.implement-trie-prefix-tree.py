#
# @lc app=leetcode id=208 lang=python3
#
# [208] Implement Trie (Prefix Tree)
#

# @lc code=start
class Node:
    def __init__(self):
        self.ends_with = False
        self.links = {}

class Trie:
    def __init__(self):
        self.root = Node()
        

    def insert(self, word: str) -> None:
        cur = self.root
        for letter in word:
            if letter not in cur.links:
                cur.links[letter] = Node()

            cur = cur.links[letter]
        cur.ends_with = True
        

    def search(self, word: str) -> bool:
        cur = self.root
        for letter in word:
            if letter not in cur.links:
                return False
            cur = cur.links[letter]
        
        return cur.ends_with
        

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for letter in prefix:
            if letter not in cur.links:
                return False
            cur = cur.links[letter]
        
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
# @lc code=end
