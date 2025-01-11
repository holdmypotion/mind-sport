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
    n, m = inpl()
    a = [[0]*n for _ in range(m)]
    for i in range(n):
        temp = inpl()
        for j in range(m):
            a[j][i] = temp[j]

    total = 0
    for j in range(m):
        a[j].sort(reverse=True)
        ps = [0]*(n+1)
        for i in range(1, n+1):
            ps[i] = ps[i-1] + a[j][i-1]

        for i in range(n):
            total += a[j][i]*(n-i-1) - (ps[n] - ps[i+1])

    print(total)

def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()
