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
    n = inpi()
    a = inpl()

    cnt = [0]*(n+1)
    for i in range(n):
        if a[i] <= n:
            cnt[a[i]] += 1

    catch = [0]*(n+1)
    for i in range(1, n+1):
        for j in range(i, n+1, i):
            catch[j] += cnt[i]

    print(max(catch))


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()
