# Leading Zeros in int Function
def lz(x):
    cnt = 0
    while not (x & (1 << (31))):
        x <<= 1
        cnt+=1
    return cnt

