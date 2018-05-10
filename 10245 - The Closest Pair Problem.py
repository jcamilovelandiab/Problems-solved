import sys
from math import *

points=[]

def dist(p1,p2): return ((p1[0]-p2[0])**2+(p1[1]-p2[1])**2)**(1/2)

def f(low,high):
    global points
    #print(points)
    if high-low<=1:
        ans = float('inf')
    else:
        mid=(low+high)//2
        ans=min(f(low,mid),f(mid,high))
        for j in range(mid,high):
            for i in range(mid-1,low-1,-1):
                if points[j][0]-points[i][0]>=ans: break
                ans=min(ans, dist(points[i],points[j]))
            if points[j][0]-points[mid-1][0]>=ans: break
    return ans

def rotate(point, theta):
    rad=theta*pi/180
    return [point[0]*cos(rad)-point[1]*sin(rad),point[0]*sin(rad)+point[1]*cos(rad)]

def main():
    global points
    n=int(sys.stdin.readline())
    while n:
        points=[];
        for i in range(n):
            points.append([float(x)for x in sys.stdin.readline().strip().split()])
            points[-1]=rotate(points[-1],37.5) # ROTO LOS PUNTOS 
        points.sort()
        answer=f(0,n)
        if answer>=10000: print('INFINITY')
        else: print('%.4f'%answer)
        n=int(sys.stdin.readline())
main()
