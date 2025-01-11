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
    b = inpl()

    bs = sorted(list(set(b)))

    mp = {}
    for ele in b:
        if ele in mp:
            mp[ele] += 1
        else:
            mp[ele] = 1

    ans = []
    i = 0
    for ele in bs:
        freq = mp[ele]
        val = (n-1-i)
        while freq > 0 and val > 0:
            ans.append(ele)
            freq = freq - val
            i += 1
            val = (n-1-i)

    ans.append(bs[-1])
    print(' '.join(map(str, ans)))


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()