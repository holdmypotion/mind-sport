 
 
 
def main():
 
 
    m,n = map(int,input().split())
    grid = []
 
    target = 0
    for _ in range(m):
        s = input()
        grid.append(s)
        for c in s:
            if c in "\/":  target += 1
 
    def nextd(c,d):
        if c=='/':
            return d ^ 1
        else:
            return 3 - d
 
 
    direc = [[0,1],[-1,0],[0,-1],[1,0]]
 
 
 
    def calculate(x,y,d):
        count = set()
        while True:
            if grid[x][y] in "\/":
                count.add((x,y))
                d = nextd(grid[x][y],d)
            x += direc[d][0]
            y += direc[d][1]
            if x < 0 or x >= m or y < 0 or y >= n:  
                break
 
        return len(count)
 
    ans = []
    for i in range(m):
        res = calculate(i,0,0)
        if res == target:
            ans.append("W"+str(i+1))
        res = calculate(i,n-1,2)
        if res == target:
            ans.append("E"+str(i+1))
 
    for j in range(n):
        res = calculate(0,j,3)
        if res == target:
            ans.append("N"+str(j+1))
        res = calculate(m-1,j,1)
        if res == target:
            ans.append("S"+str(j+1))
 
    print(len(ans))
    print(*ans)
        
 
 
            
        
        
        
 
 
 
 
 
 
 
 
 
 
main()
