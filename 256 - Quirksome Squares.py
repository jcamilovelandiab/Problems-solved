import sys

answers=dict();

def solve():
    for digits in range(2,9,2):
        print(digits)
        answers[digits]=[]
        limit = 10**digits
        half = 10**(digits//2)
        for number in range(0,limit):
            n1 = number//half
            n2 = number%half
            r=(n1+n2)**2
            if r==number:
                answers[digits].append(number)
    print('DONE')

answers[2]=[0, 1, 81]
answers[4]=[0, 1, 2025, 3025, 9801]
answers[6]=[0, 1, 88209, 494209, 998001]
answers[8]=[0, 1, 4941729, 7441984, 24502500, 25502500, 52881984, 60481729, 99980001]

def main():
    #solve()
    #print('answers=dict()')
    for i in range(2,9,2):
        for j in range(len(answers[i])):
            answers[i][j]=str(answers[i][j]).zfill(i)
        #print(*answers[i])
    n=sys.stdin.readline().strip()
    while n!='':
        n=int(n)
        for e in answers[n]: print(e)
        n=sys.stdin.readline().strip()
main()
