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
# sys.stdin = open('/Users/loona-mac/personal/mind-sport/input.txt', 'r')
# sys.stdout = open('/Users/loona-mac/personal/mind-sport/output.txt', 'w', buffering=1)
input = sys.stdin.readline
# Fast input functions
def inp(): return input().strip()
def inpi(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())


def potion():
    n = inpi()
    points = []
    for i in range(n):
        points.append(inpl())

    cnt = 0
    # Brute force
    # for i in range(n):
    #     for j in range(i+1, n):
    #         x, y = points[i]
    #         X, Y = points[j]
    #
    #         slop = abs(Y-y) / abs(X-x) if X != x else 0
    #         if slop in [0, 1, -1]:
    #             cnt += 1
    #
    # Optimized
    hor = defaultdict(int)
    ver = defaultdict(int)
    tilt = defaultdict(int)
    tilt_neg = defaultdict(int)

    for x, y in points:
        hor[x] += 1
        ver[y] += 1
        tilt[x-y] += 1
        tilt_neg[x+y] += 1

    for v in hor.values():
        cnt += v * (v-1)

    for v in ver.values():
        cnt += v * (v-1)

    for v in tilt.values():
        cnt += v * (v-1)

    for v in tilt_neg.values():
        cnt += v * (v-1)

    print(cnt)


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()
