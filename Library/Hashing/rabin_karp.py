import random


class HashT:
    p = 2 * random.randint(13, 10**8) + 1
    mod = 1000000009
    invp = pow(p, mod-2, mod)

    def __init__(self, s):
        self.s = s
        self.n = len(s)
        self.hash = [0] * (self.n + 1)
        self.power = [1] * (self.n + 1)
        self.invpower = [1] * (self.n + 1)

        for i in range(1, self.n+1):
            self.power[i] = self.power[i-1] * self.p % self.mod
            self.invpower[i] = self.invpower[i-1] * self.invp % self.mod
            self.hash[i] = (self.hash[i-1] +
                            (ord(s[i-1]) - ord('a') + 1) * self.power[i]) % self.mod

    def gethash(self, le, ri):
        f = self.hash[ri+1] - self.hash[le]
        if f < 0:
            f += self.mod
        f *= self.invpower[le+1]
        return f % self.mod


if __name__ == '__main__':
    s = "ababdabcabababd"
    p = "ababd"
    doc, n = HashT(s), len(s)
    search, m = HashT(p), len(p)

    cnt = 0
    search_hash = search.gethash(0, m-1)
    for i in range(n-m+1):
        if doc.gethash(i, i+m-1) == search_hash:
            cnt += 1

    print(cnt)
