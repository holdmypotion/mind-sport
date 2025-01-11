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
sys.stdin = open('/Users/loona-mac/personal/mind-sport/codeforces/input.txt', 'r')
# sys.stdout = open('/Users/loona-mac/personal/mind-sport/codeforces/output.txt', 'w', buffering=1)
input = sys.stdin.readline
# Fast input functions
def inp(): return input().strip()
def inpi(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

sys.set_int_max_str_digits(8000)

def fact(x):
    if x == 0:
        return 1
    return x * fact(x-1)


def potion():
    n, d = inpl()
    n = min(n, 6)
    num = int(str(d) * fact(n))

    ans = []
    for i in [1, 3, 5, 7, 9]:
        if num % i == 0:
            ans.append(i)

    print(' '.join(map(str, ans)))


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()

