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
# sys.stdout = open('/Users/loona-mac/personal/mind-sport/codeforces/output.txt', 'w')
input = sys.stdin.readline
# Fast input functions
def inp(): return input().strip()
def inpi(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

############ Solution ############
def potion():
    n = inpi()
    arr = inpl()

    heap = [(arr[i], i) for i in range(len(arr))]
    heapq.heapify(heap)

    ans = []
    s = -1
    while len(heap):
        ele, idx = heapq.heappop(heap)

        if idx > s:
            s = idx
            ans.append(ele)
        else:
            heapq.heappush(heap, (ele+1, n))
            n += 1

    print(' '.join(map(str, ans)))

############ Main ############
def main():
    t = inpi()
    for _ in range(t):
        potion()

if __name__ == "__main__":
    main()
