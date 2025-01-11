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
# sys.stdout = open('/Users/loona-mac/personal/mind-sport/codeforces/output.txt', 'w', buffering=1)
input = sys.stdin.readline
# Fast input functions
def inp(): return input().strip()
def inpi(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())


def potion():
    n, x, y = inpl()
    yv = n-y+1

    ans = []
    if x < y:
        for i in range(1, n+1):
            val = 1
            if x < i < y:
                val = -1

            ans.append(val)
    else:
        ans = [1]*n
        val = -1
        for i in range(y-2, -1, -1):
            ans[i] = val
            val *= -1

        val = -1
        for i in range(x, n):
            ans[i] = val
            val *= -1

    print(' '.join(map(str, ans)))


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()
