#
# @lc app=leetcode id=212 lang=python3
#
# [212] Word Search II
#

# @lc code=start
from typing import List

class Node:
    def __init__(self, prefix=""):
        self.ends_with = False
        self.prefix = prefix
        self.links = {}
    

class Trie:
    def __init__(self, board):
        self.root = Node()
        self.directions = [[0,1], [1,0], [0,-1], [-1,0]]
        self.board = board
        self.R, self.C = len(self.board), len(self.board[0])
        self.visited = [[False]*self.C for _ in range(self.R)]

    def add(self, word):
        cur = self.root
        for idx, letter in enumerate(word):
            if letter not in cur.links:
                cur.links[letter] = Node(word[:idx+1])
            cur = cur.links[letter]
        cur.ends_with = True
    
    def recursive_search(self, r, c, node) -> List[str | None]:
        letter = self.board[r][c]
        if letter not in node.links: return None
        else: node = node.links[letter]
        self.visited[r][c] = True
        res = [node.prefix] if node.ends_with else []
        for dr, dc in self.directions:
            nr, nc = r + dr, c + dc
            if (0 <= nr < self.R and
                0 <= nc < self.C and
                not self.visited[nr][nc]):
                val = self.recursive_search(nr, nc, node)
                if val:
                    res.extend(val)
        self.visited[r][c] = False
        return res

    def search(self):
        res = []
        for r in range(self.R):
            for c in range(self.C):
                val = self.recursive_search(r, c, self.root)
                if val:
                    res.extend(val)
    
        return list(set(res))


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie(board)

        for word in words:
            trie.add(word)
        
        return trie.search()
# @lc code=end

