def lps(s, p):
    t = p + "$" + s
    n = len(t)

    pi = [0] * n
    k = 0
    for i in range(1, n):
        while k > 0 and t[i] != t[k]:
            k = p[k-1]

        if t[i] == t[k]:
            k += 1
        p[i] = k

    return pi
