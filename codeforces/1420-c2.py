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
    n, q = inpl()
    a = inpl()

    def val(i):
        if i < 0 or i >= n:
            return 0

        x = a[i]
        y = 0 if i == n-1 else a[i+1]
        return max(x-y, 0)

    def swap(x, y):
        a[x], a[y] = a[y], a[x]

    ans = 0
    for i in range(n):
        ans += val(i)

    print(ans)
    for _ in range(q):
        x, y = inpl()
        x -= 1
        y -= 1

        if x < y:
            ans -= val(x)
            ans -= val(x-1)
            ans -= val(y)
            if x != y-1:
                ans -= val(y-1)

            swap(x, y)

            ans += val(x-1)
            ans += val(x)
            ans += val(y)

            if x != y-1:
                ans += val(y-1)

        print(ans)

def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()

if name == "main":
    main()
