import sys

def main():
    tc=int(sys.stdin.readline())
    for t in range(tc):
        inst=sys.stdin.readline().strip()
        tira=[0 for x in range(100)]
        punt=0
        for x in inst:
            if x=='.': continue
            elif x=='+':
                tira[punt]=(tira[punt]+1)%256
            elif x=='-':
                tira[punt]=(tira[punt]-1)%256
            elif x=='<':
                punt=(punt-1)%100
            elif x=='>':
                punt=(punt+1)%100
        print('Case {}:'.format(t+1),end='')
        for x in tira:
            h=hex(x)[2:].upper()
            if len(h)==1: h='0'+h
            print(' '+h,end='')
        print()            
main()
'''
1
..++<><<+++>>++++++++++++++++++++++++++>>>+++ <+...++<><<+++>>++++++++++++++++++++++++++>>>+++<+...++<><<+++>>++++++++++++++++++++++++++>>>+++<+.
'''
