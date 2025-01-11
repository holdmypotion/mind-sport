# Recursive

def binpow(a, b):
    if b == 0: return 1

    res = binpow(a, b/2) * a
    if b & 1:
        return res * res * a
    else:
        return res * res


# Iterative
def binpow(a, b):
    res = 1
    while b:
        if b & 1:
            res = res * a
        a *= a
        b >>= 1

    return res

# Application in modular multiplicative inverse
def binpow(a, b, m):
    res = 1
    a %= a
    while b:
        if b & 1:
            res = res * a % m
        a *= a % m
        b >>= 1

    return res

