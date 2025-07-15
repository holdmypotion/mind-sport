class BIT:
    def __init__(self, n: int) -> None:
        self.n = n
        self.arr = [0]*(n+1)
        self.tree = [0]*(n+1)

    def add(self, k: int, x: int) -> None:
        # Add the element to the array
        self.arr[k] = x

        # add the element to the fenwick tree
        while k <= self.n:
            self.tree[k] += x
            k += (k & -k)

    def __prefix_sum(self, k: int) -> int:
        res = 0
        while k > 0:
            res += self.tree[k]
            k -= (k & -k)

        return res

    def sum(self, left: int, right: int) -> int:
        return self.__prefix_sum(right) - self.__prefix_sum(left-1)


if __name__ == '__main__':
    n = int(input())

    bit = BIT(n)

    for i in range(1, n+1):
        bit.add(i, int(input()))

    print(bit.sum(3, 5))

