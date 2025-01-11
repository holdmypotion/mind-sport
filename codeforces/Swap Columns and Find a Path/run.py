# author: holdmypotion
import sys
from collections import defaultdict, Counter, deque
from math import gcd, lcm
from typing import List, Set, Dict, Tuple

# Type aliases
Matrix = List[List[int]]
Graph = List[List[int]]

# Constants
MOD = 998244353
INF = float('inf')
NINF = float('-inf')

# Fast I/O setup
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')
input = sys.stdin.readline

# Fast input functions
def inp(): return input().strip()
def inpi(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

############ Solution ############
def potion():
    n = inpi()
    r1 = inpl()
    r2 = inpl()

    mv = 0 # max value
    p = NINF# pivot
    # The optimal solution for this problem would look something like
    # max, max, max, min
    #                max, max, max
    # Here (min, max) is the pivot ->
    # The optimal solution should have the max value of all the min values as pivot
    # because we need to have at least one min value in the solution
    for i in range(n):
        mv += max(r1[i], r2[i])
        p = max(p, min(r1[i], r2[i]))

    print(mv + p)


############ Main ############
def main():
    t = inpi()
    for _ in range(t):
        potion()

if __name__ == "__main__":
    main()
