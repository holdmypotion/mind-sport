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
    a = inp()
    b = inp()
    c = inp()

    n, m = len(a), len(b)

    # dp[i][j] ->
    #     - min num of char mismatches when considering first i characters from a
    #     - first j characters from b
    #     - from the resultant c string with characters (i+j)

    dp = [[0] * (m+1) for _ in range(n+1)]

    for i in range(1, n+1):
        dp[i][0] = dp[i-1][0] + (a[i-1] != c[i-1])

    for j in range(1, m+1):
        dp[0][j] = dp[0][j-1] + (b[j-1] != c[j-1])

    for i in range(1, n+1):
        for j in range(1, m+1):
            dp[i][j] = min(
                dp[i-1][j] + (a[i-1] != c[i+j-1]),
                dp[i][j-1] + (b[j-1] != c[i+j-1]),
            )

    print(dp[n][m])


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()
