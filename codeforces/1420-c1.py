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


# TLE - Solution
# def potion():
#     n, q = inpl()
#     a = inpl()
#
#     def dfs(i, cs, flip):
#         if i >= n:
#             return cs
#
#         return max(dfs(i+1, cs+a[i]*flip, flip*-1), dfs(i+1, cs, flip))
#
#     print(dfs(0, 0, 1))


# DP
# def potion():
#     n, q = inpl()
#     a = inpl()
#
#     # maximize: (ai - (a[i+1] - a[i+2] + a[i+3] ...))
#     # mx[i] and mn[i]: max and min strength resp. from [a[i]..a[n-1]]
#
#     mx = [0]*(n+1)
#     mn = [0]*(n+1)
#
#     for i in range(n-1, -1, -1):
#         mx[i] = max(mx[i+1], a[i] - mn[i+1])
#         mn[i] = min(mn[i+1], a[i] - mx[i+1])
#
#     print(mx[0])

# Simple pattern.
def potion():
    n, q = inpl()
    a = inpl()

    ans = 0
    for i in range(n):
        x = a[i]
        y = 0 if i == n-1 else a[i+1]
        ans += max(x-y, 0)

    print(ans)


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()

