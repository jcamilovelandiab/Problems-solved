import sys

def f(i,suma):
    global p, n, value, dp
    if suma in dp:
        return dp[suma]
    if i==n:
        if suma>50: dp[suma]=value/suma*100
        else: dp[suma]=0.00
        return dp[suma]
            
    else:
        dp[suma]=max(f(i+1,suma+p[i]),f(i+1, suma))
        return dp[suma]
def main():
    global p,n,value, dp
    n,x=[int(x)for x in sys.stdin.readline().strip().split()]
    while n:
        p=[]; value=-1
        for i in range(n):
            if i+1==x: value=float(sys.stdin.readline())
            else: p.append(float(sys.stdin.readline()))
        #print(*p,'value=',value)
        n-=1
        dp=dict()
        print('%.2f'%f(0,value))
        n,x=[int(x)for x in sys.stdin.readline().strip().split()]
main()
'''
5 5
20.00
12.00
29.00
14.00
25.00
2 1
56.87
43.13
2 2
56.87
43.13
3 1
10.00
45.00
45.00
0 0
'''
