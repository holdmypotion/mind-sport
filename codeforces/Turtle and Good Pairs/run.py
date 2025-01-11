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
    s = inp()
    arr = [(0, i) for i in range(26)]  # (freq, idx)

    for ch in s:
        arr[ord(ch) - ord('a')] = (arr[ord(ch) - ord('a')][0]+1, ord(ch) - ord('a'))

    q = deque()  # (freq, idx)
    for a in arr:
        if a[0] != 0:
            q.append(a)

    ans = []

    while q:
        freq, idx = q.popleft()
        ans.append(chr(idx + ord('a')))

        freq -= 1
        if freq > 0:
            q.append((freq, idx))

    print(''.join(ans))


def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()


if __name__ == "__main__":
    main()
