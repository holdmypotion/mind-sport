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
# sys.stdout = open('/Users/loona-mac/personal/mind-sport/codeforces/output.txt', 'w')
input = sys.stdin.readline
# Fast input functions
def inp(): return input().strip()
def inpi(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())


def fact(x):
    res = 1
    for i in range(x, 0, -1):
        res = (res * x) % MOD
        x -= 1

    return res

# def potion():
#     s = input()
#
#     res = 1
#     k = len(s)
#     n = len(s)
#     i = 0
#
#     while i < n:
#         j = i + 1
#         while j < n and s[i] == s[j]:
#             j += 1
#
#         res = (res * (j - i)) % MOD
#         k -= 1
#         i = j
#
#     for i in range(1, k + 1):
#         res = (res * i) % MOD
#
#     print(k, res)

def potion():
    s = inp()
    n = len(s)

    count = 0
    a = []
    for i in range(n-1):
        if s[i] == s[i+1]:
            count += 1
        elif count != 0:
            a.append(count)
            count = 0
    if count != 0:
        a.append(count)

    val = sum(a)
    res = fact(val)
    for ele in a:
        res = (res * (ele+1)) % MOD

    print(val, res)

def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()

