
# author: holdmypotion
import sys
from collections import defaultdict, Counter, deque
from math import gcd, lcm
from typing import List, Set, Dict, Tuple
import heapq

# Type aliases
Matrix = List[List[int]]
Graph = List[List[int]]

# Constants
MOD = 998244353
INF = float('inf')
NINF = float('-inf')

# Fast I/O setup
# sys.stdin = open('/Users/loona-mac/personal/mind-sport/codeforces/input.txt', 'r')
# sys.stdout = open('/Users/loona-mac/personal/mind-sport/codeforces/output.txt', 'w', buffering=1)  # Line buffered output
input = sys.stdin.readline
# Fast input functions
def inp(): return input().strip()
def inpi(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

############ Solution ############

def potion():
    [r, c] = inpl()

    grid = [[] for _ in range(r)]

    for i in range(r):
        grid[i].extend(list(inp()))
    
    mirror_count = 0
    for row in grid:
        for ele in row:
            if ele in ['\\', '/']:
                mirror_count += 1


    def dfs(x, y, dir):
        nonlocal grid, count
        if x < 0 or x >= r or y < 0 or y >= c:
            return False

        if grid[x][y] == '/':
            count -= 1
            if dir == 'N':
                dir = 'E'
            elif dir == 'S':
                dir = 'W'
            elif dir == 'E':
                dir = 'N'
            elif dir == 'W':
                dir = 'S'
        elif grid[x][y] == '\\':
            count -= 1
            if dir == 'N':
                dir = 'W'
            elif dir == 'S':
                dir = 'E'
            elif dir == 'E':
                dir = 'S'
            elif dir == 'W':
                dir = 'N'
        
        if count == 0:
            return True

        if dir == 'N':
            x -= 1
        elif dir == 'S':
            x += 1
        elif dir == 'E':
            y += 1
        elif dir == 'W':
            y -= 1

        return dfs(x, y, dir)


    ans = []
    for dir in ['N', 'S', 'E', 'W']:
        for i in range(1, r+1):
            x, y = 0, 0
            if dir == 'N':
                x, y = r-1, i-1
            elif dir == 'S':
                x, y = 0, i-1
            elif dir == 'E':
                x, y = i-1, 0
            elif dir == 'W':
                x, y = i-1, c-1
            
            count = mirror_count
            if dfs(x, y, dir):
                ans_dir = dir
                if dir == 'N':
                    ans_dir = 'S'
                elif dir == 'S':
                    ans_dir = 'N'
                elif dir == 'E':
                    ans_dir = 'W'
                elif dir == 'W':
                    ans_dir = 'E'

                ans.append(f"{ans_dir}{i}")

    print(len(ans))
    print(' '.join(ans))


############ Main ############
def main():
    # t = inpi()
    # for _ in range(t):
    #     potion()

    potion()

if __name__ == "__main__":
    main()
