import sys
def main():
    cat=[0,1]
    for n in range(2,31):
        cat.append((2*(2*n-1))/(n+1)*cat[-1])

    n=int(sys.stdin.readline())
    while n:
        print(int(cat[n]))
        n=int(sys.stdin.readline())
main()
    
