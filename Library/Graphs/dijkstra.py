import heapq


class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for _ in range(n)]
        self.dist = [float('inf') for _ in range(n)]
        self.visited = [False for _ in range(n)]

    def add_edge(self, u, v, w):
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))

    def dijkstra(self, s):
        self.dist[s] = 0

        q = [(0, s)]

        heapq.heapify(q)

        while q:
            d, u = heapq.heappop(q)

            if self.visited[u]:
                continue

            self.visited[u] = True
            for v, w in self.adj[u]:
                if not self.visited[v] and self.dist[v] > d + w:
                    self.dist[v] = d + w
                    heapq.heappush(q, (self.dist[v], v))

