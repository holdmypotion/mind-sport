class DSU:
    def __init__(self, n):
        self.n = n
        self.p = list(range(n+1))
        self.size = [1]*(n+1)

    def find(self, u):
        if self.p[u] == u:
            return u

        # Path compression - Makes successive find runs in O(1);
        self.p[u] = self.find(self.p[u])
        return self.p[u]

    def unite(self, a, b):
        a, b = self.find(a), self.find(b)

        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a
            self.size[a] += self.size[b]
            self.p[b] = a
            return True
        return False

    def same(self, a, b):
        return self.find(a) == self.find(b)
