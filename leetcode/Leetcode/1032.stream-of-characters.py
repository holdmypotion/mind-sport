#
# @lc app=leetcode id=1032 lang=python3
#
# [1032] Stream of Characters
#

# @lc code=start
from typing import Dict, List
from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.__links: Dict[str, 'TrieNode'] = defaultdict(TrieNode)
        self.__is_end: bool = False

    @property
    def is_end(self) -> bool:
        return self.__is_end

    @is_end.setter
    def is_end(self, value: bool) -> None:
        self.__is_end = value

    def get_link(self, char: str) -> 'TrieNode':
        return self.__links[char]

    def has_link(self, char: str) -> bool:
        return char in self.__links


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        self.__insert(word)

    def __insert(self, word: str) -> None:
        itr = self.root
        for ch in word:
            itr = itr.get_link(ch)
        itr.is_end(True)

    def search(self, stream: str) -> bool:
        return self.__search(stream)

    def __search(self, stream: str) -> bool:
        itr = self.root
        print(stream)
        for ch in stream:
            if itr.has_link(ch):
                itr = itr.get_link(ch)
                if itr.is_end:
                    return True
            else:
                return False
        return True

class StreamChecker:

    def __init__(self, words: List[str]):
        self.trie = Trie()
        self.stream = ""
        for word in words:
            self.trie.insert(word[::-1])

    def query(self, letter: str) -> bool:
        self.stream += letter
        return self.trie.search(self.stream[::-1])

        


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
# @lc code=end

