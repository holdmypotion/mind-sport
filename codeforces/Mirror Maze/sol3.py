import sys
import math
# import heapq as q
from collections import deque, defaultdict, Counter
import bisect
 
# input = lambda: sys.stdin.readline()[:-1]
ii = lambda: int(input())
mii = lambda: map(int,input().split())
lmii = lambda: list(map(int,input().split()))
gmii = lambda: map(lambda x: int(x) - 1,input().split())
glmii = lambda: list(map(lambda x: int(x) - 1,input().split()))
 
out = []
# for _ in range(ii()):
R, C = mii()
m = []
sm = 0
for i in range(R):
    n = input()
    m.append(n)
    sm += C-n.count(".")
 
dh = ["W", "N", "E", "S"]
 
ans = []
for hi in range(4):
    for di in range(R):
        dhi = set()
        h = hi
        smi, i, j = 0, 0, 0
        if hi==0 or hi==2: i = di
        else: j = di
        if hi==0: i = di; j=0
        if hi==1: j = di; i=0
        if hi==2: i = di; j=C-1
        if hi==3: j = di; i=R-1
        
        while i<R and j<C and i>=0 and j>=0:
            if m[i][j]!=".":
                dhi.add((i, j))
                if h%2==0:
                    if m[i][j]=="/":
                        h = (h-1)%4
                    else:
                        h = (h+1)%4
                else:
                    if m[i][j]=="/":
                        h = (h+1)%4
                    else:
                        h = (h-1)%4
            if h==0: j+=1   
            if h==1: i+=1
            if h==2: j-=1
            if h==3: i-=1
        if len(dhi)==sm:
            ans.append(dh[hi]+str(di+1))
 
n = len(ans)
print(n)
if n!=0:
    print(*ans)
    
    # sys.stdout.write('\n'.join(map(str, out)))
