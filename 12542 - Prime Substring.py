import sys

def criba(n):
    res=set(range(1,n+1))
    for i in range(2,n+1):
        if i in res: res-=set(range(i+i, n+1, i))
    return list(res)

def main():
    primes=criba(100000)
    n=sys.stdin.readline().strip()
    while n!='0':
        for i in range(len(primes)-1,-1,-1):
            if str(primes[i]) in n:
                print(primes[i]); break
        n=sys.stdin.readline().strip()
main()
