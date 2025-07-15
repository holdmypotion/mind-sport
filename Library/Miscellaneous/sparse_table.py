class SparseTable:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)
        self.bin_log = self.compute_log(self.n)
        self.MAX_LOG = self.bin_log[self.n]
        self.table = self.build_table

    def compute_log(self, n):
        bin_log = [0]*(n+1)
        bin_log[1] = 0
        for i in range(2, n+1):
            bin_log[i] = bin_log[i//2] + 1

        return bin_log

    def build_table(self):
        table = [[0]*(self.MAX_LOG) for _ in range(self.n)]

        # k = 0 -> 2^k = 2^0 = 1 hence lenght == 1 subarrays (element itself)
        for i in range(n):
            table[i][0] = self.arr[i]

        for k in range(1, self.MAX_LOG):
            for i in range(self.n - (1 << k)-1):
                table[i][k] = max(table[i][k-1], table[i+(1 << (k-1))][k-1])

        return table

    def max(self, l, r):
        k = self.bin_log[r-l+1]
        return max(self.table[l][k], self.table[r-(1 << k)+1][k])


