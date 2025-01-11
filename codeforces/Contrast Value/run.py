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
# sys.stdout = open('/Users/loona-mac/personal/mind-sport/codeforces/output.txt', 'w', buffering=1)  # Line buffered output
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

    ua = [arr[0]]
    for ele in arr:
        if ele != ua[-1]:
            ua.append(ele)

    n = len(ua)
    count = n
    for i in range(n-2):
        # Simple check - Covers both strictily increasing and decreasing seq
        if abs(ua[i] - ua[i+1]) + abs(ua[i+1] - ua[i+2]) == abs(ua[i] - ua[i+2]):
            count -= 1

        # Another possibility way to check
        # # Case 1: strictly increasing sequence
        # count -= (ua[i] < ua[i+1] < ua[i+2])
        # # Case 2: strictly decreasing sequence
        # count -= (ua[i] > ua[i+1] > ua[i+2])

    print(count)


############ Main ############
def main():
    # potion()
    t = inpi()
    for _ in range(t):
        potion()

if __name__ == "__main__":
    main()

