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

def mod_fact(n, x):
    if n >= x:
        return 0

    r = 1
    for i in range(1, min(n+1, x)):
        r = (r*i) % x

    return r


def potion():
    n, d = inpl()

    ans = [1]
    if d*mod_fact(n, 3) % 3 == 0:
        ans.append(3)
    if d == 5:
        ans.append(5)
    if n >= 3 or d == 7:
        ans.append(7)
    if d*mod_fact(n, 9) % 9 == 0:
        ans.append(9)

    print(' '.join(map(str, ans)))


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()
