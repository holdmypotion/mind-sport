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


def lz(x):
    cnt = 0
    while not (x & (1 << (31))):
        x <<= 1
        cnt += 1

    return cnt


def potion():
    n, a = inpi(), inpl()
    cnt = [0]*33

    for i in range(n):
        cnt[lz(a[i])] += 1

    ans = 0
    for v in cnt:
        if v:
            ans += v*(v-1)//2

    print(ans)


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()

