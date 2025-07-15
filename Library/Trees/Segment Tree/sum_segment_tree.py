# Range Sum Segment Tree
class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0]*(2*n)
        self.arr = []

    def insert(self, k, ele):
        # Last n nodes are leave nodes and first n nodes are internal nodes
        k += self.n
        self.tree[k] = ele
        k //= 2
        while k >= 1:
            self.tree[k] = self.tree[2*k] + self.tree[2*k+1]
            # Note: left child always divides by 2 and right child always never divides by 2
            k //= 2

    def build(self, arr):
        self.arr = arr
        for idx, ele in enumerate(arr):
            self.insert(idx, ele)

    def sum(self, l, r):
        res = 0
        # Move to the leave nodes
        l += self.n
        r += self.n
        while l <= r:
            if l & 1:  # if l is right child of parent
                res += self.tree[l]
                l += 1
            if r & 1 == 0:  # if r is left child of parent
                res += self.tree[r]
                r -= 1
            # Move up the tree
            l //= 2
            r //= 2

        return res

