from collections import defaultdict


class SegmentTree:
    """
    Base Implementation
    """
    def __init__(self, range_min: int, range_max: int) -> None:
        self.tree: defaultdict[int] = defaultdict(int)
        self.lazy: defaultdict[int] = defaultdict(int)
        self.range_min: int = 0
        self.range_max: int = 10**9

    def __propagate(self, idx: int, rl: int, rr: int) -> None:
        if idx in self.lazy and self.lazy[idx] != 0:
            mid: int = rl + (rr - rl) // 2

            # Update Left Child
            self.tree[2 * idx] += self.lazy[idx] * (mid - rl + 1)
            self.lazy[2 * idx] += self.lazy[idx]

            # Update Right Child
            self.tree[2 * idx + 1] += self.lazy[idx] * (rr - mid)
            self.lazy[2 * idx + 1] += self.lazy[idx]

            del self.lazy[idx]

    def __update(self, ql: int, qr: int, val: int, idx: int, rl: int, rr: int) -> None:
        # No Overlap
        if ql > rr or qr < rl:
            return

        # Complete Overlap
        if ql <= rl and qr >= rr:
            self.tree[idx] += val * (rr - rl + 1)  # Value * (number of children)
            self.lazy[idx] += val
            return

        # Partial Overlap
        self.__propagate(idx, rl, rr)
        mid: int = rl + (rr - rl) // 2
        self.__update(ql, qr, val, 2 * idx, rl, mid)
        self.__update(ql, qr, val, 2 * idx + 1, mid + 1, rr)
        self.tree[idx] = self.tree[2 * idx] + self.tree[2 * idx + 1]

    def __query(self, ql: int, qr: int, idx: int, rl: int, rr: int) -> int:
        # No Overlap
        if ql > rr or qr < rl:
            return 0

        # Complete Overlap
        if ql <= rl and qr >= rr:
            return self.tree[idx]

        # Partial Overlap
        self.__propagate(idx, rl, rr)
        mid = rl + (rr - rl) // 2
        return self.__query(ql, qr, 2 * idx, rl, mid) + \
            self.__query(ql, qr, 2 * idx + 1, mid + 1, rr)

    def update(self, ql: int, qr: int, val: int) -> None:
        self.__update(ql, qr, val, 1, self.range_min, self.range_max)

    def query(self, ql: int, qr: int) -> int:
        return self.__query(ql, qr, 1, self.range_min, self.range_max)


class RangeSum:
    def __init__(self):
        self.tree = SegmentTree()

    def addToRange(self, left, right, val):
        self.tree.update(left, right, val)

    def removeFromRange(self, left, right, val):
        self.tree.update(left, right, -val)

    def queryRange(self, left, right):
        return self.tree.query(left, right)


########### Implementation On a Question ##############
# Question: https://leetcode.com/problems/range-module/


class SegmentTree:
    def __init__(self):
        self.tree = defaultdict(lambda: False)
        self.lazy = defaultdict(lambda: False)
        self.range_min = 0
        self.range_max = 10**9

    def __propagate(self, idx: int):
        if idx in self.lazy:
            self.tree[2 * idx] = self.lazy[2 * idx] = self.lazy[idx]
            self.tree[2 * idx + 1] = self.lazy[2 * idx + 1] = self.lazy[idx]

            del self.lazy[idx]

    def __update(self, ql: int, qr: int, val: bool, idx: int, rl: int, rr: int):
        # No Overlap
        if ql > rr or qr < rl:
            return

        # Complete Overlap
        if ql <= rl and qr >= rr:
            self.tree[idx] = self.lazy[idx] = val
            return

        # Partial Overlap
        self.__propagate(idx)
        mid = rl + (rr - rl) // 2
        self.__update(ql, qr, val, 2 * idx, rl, mid)
        self.__update(ql, qr, val, 2 * idx + 1, mid + 1, rr)
        self.tree[idx] = self.tree[2 * idx] and self.tree[2 * idx + 1]

    def __query(self, ql: int, qr: int, idx: int, rl: int, rr: int) -> bool:
        # No Overlap
        if ql > rr or qr < rl:
            return True  # No contributtion and hence marking True

        # Complete Overlap
        if ql <= rl and qr >= rr:
            return self.tree[idx]

        # Partial Overlap
        self.__propagate(idx)
        mid = rl + (rr - rl) // 2
        return self.__query(ql, qr, 2 * idx, rl, mid) and \
            self.__query(ql, qr, 2 * idx + 1, mid + 1, rr)

    def update(self, ql: int, qr: int, val: bool) -> None:
        self.__update(ql, qr, val, 1, self.range_min, self.range_max)

    def query(self, ql: int, qr: int) -> bool:
        return self.__query(ql, qr, 1, self.range_min, self.range_max)


class RangeModule:

    def __init__(self):
        self.tree = SegmentTree()

    def addRange(self, left, right):
        self.tree.update(left, right - 1, True)

    def removeRange(self, left, right):
        self.tree.update(left, right - 1, False)

    def queryRange(self, left, right):
        return self.tree.query(left, right - 1)
