class Dsu:
    def __init__(self, n):
        self.p = list(range(n+1))
        self.size = [1] * (n+1)
        self.num_of_connected_comp = n

    def find(self, u):
        if u == self.p[u]:
            return u

        self.p[u] = self.find(self.p[u])
        return self.p[u]

    def unite(self, u, v):
        u, v = self.find(u), self.find(v)

        if u != v:
            return False

        if self.size[u] > self.size[v]:
            u, v = v, u
        self.p[u] = v
        self.size[v] += self.size[u]
        self.num_of_connected_comp -= 1

        return True

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = Dsu(n)

        for u, v in edges:
            dsu.unite(u, v)

        return dsu.num_of_connected_comp

