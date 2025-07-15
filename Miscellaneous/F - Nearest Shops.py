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
sys.stdin = open('/Users/loona-mac/personal/mind-sport/input.txt', 'r')
sys.stdout = open('/Users/loona-mac/personal/mind-sport/output.txt', 'w', buffering=1)
input = sys.stdin.readline
# Fast input functions
def inp(): return input().strip()
def inpi(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())


def main():
    n, m, _ = inpl()
    anime_cities = inpl()

    adj = [[] for _ in range(n+1)]
    dist = [[float('inf'), 0] for _ in range(n+1)] # (dist, anime_city)
    for city in anime_cities:
        dist[city] = [0, city]

    for _ in range(m):
        u, v = inpl()
        adj[u].append(v)
        adj[v].append(u)

    q = deque(anime_cities)
    level = 0
    while q:
        for _ in range(len(q)):
            u = q.popleft()

            for v in adj[u]:
                if dist[v][0] > level + 1:
                    dist[v] = [level + 1, dist[u][1]]
                    q.append(v)
        level += 1
    
    # Updating anime cities
    def update_anime_city(s):
        q = deque([(s, 0)])
        vis = [False for _ in range(n)]
        while q:
            u, level = q.popleft()

            for v in adj[u]:
                if v in anime_cities and v != s:
                    dist[s] = [level + 1, v]
                    return True
                elif dist[v][1] != s:
                    dist[s] = [dist[v][0] + level + 1, dist[v][1]]
                    return True

                if not vis[v]:
                    q.append((v, level + 1))
                    vis[v] = True

        dist[s] = [-1, None]
        return False

    for city in anime_cities:
        update_anime_city(city)

    ans = [d[0] for d in dist[1:]]
    ans = [-1 if x == float('inf') else x for x in ans]
    print(" ".join(map(str, ans)))

    

if __name__ == "__main__":
    main()

