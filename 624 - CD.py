import sys

bestTime, bestTrack = 0, []

def f(i,time,track):
    global bestTime, bestTrack, timeLimit, nSongs, songs
    
    if time>timeLimit: return
    if time==bestTime:
        if len(track)>len(bestTrack):
            bestTrack=track; bestTime=time;
    elif time>bestTime:
        bestTrack=track; bestTime=time;
        
    if i>=nSongs: return
    
    f(i+1,time+songs[i], track+[songs[i]])
    f(i+1, time, track)

def main():
    global bestTime, bestTrack, timeLimit, nSongs, songs
    l =[int(x)for x in sys.stdin.readline().strip().split()]
    while l:
        timeLimit, nSongs, *songs = l
        bestTime, bestTrack = 0, []
        f(0,0, [])
        print(*bestTrack,'sum:{}'.format(bestTime))
        l =[int(x)for x in sys.stdin.readline().strip().split()]
main()
