#
# @lc app=leetcode id=211 lang=python3
#
# [211] Design Add and Search Words Data Structure
#

# @lc code=start
class Node:
    def __init__(self):
        self.ends_with = False
        self.links = {}


class WordDictionary:

    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        cur = self.root
        for letter in word:
            if letter not in cur.links:
                cur.links[letter] = Node()

            cur = cur.links[letter]
        cur.ends_with = True
    
    def __search(self, word, node):
        cur = node
        for idx, letter in enumerate(word):
            if letter == '.':
                for ch in cur.links:
                    if self.__search(ch + word[idx+1:], cur):
                        return True
            if letter not in cur.links:
                return False
            cur = cur.links[letter]
        
        return cur.ends_with

    def search(self, word: str) -> bool:
        return self.__search(word, self.root)
        

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
# @lc code=end

