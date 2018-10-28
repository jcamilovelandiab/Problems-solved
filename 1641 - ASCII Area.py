import sys
def main():
    hw=[int(x)for x in sys.stdin.readline().strip().split()]
    while hw:
        h,w=hw
        mat=[]
        for x in range(h):
            mat.append(sys.stdin.readline().strip())
        i=0; area=0.5
        while i<h:
            j=0
            while j<w:
                if mat[i][j]=='/' or mat[i][j]=='\\':
                    area+=0.5
                    j+=1
                    while True:
                        if mat[i][j]=='/' or mat[i][j]=='\\':
                            area+=0.5; break;
                        elif mat[i][j]=='.':
                            area+=1; j+=1;
                j+=1;
            i+=1;
        print(int(area))
        hw=[int(x)for x in sys.stdin.readline().strip().split()]
main()
