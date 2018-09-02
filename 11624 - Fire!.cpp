#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define x first
#define y second

using namespace std;

int N,M;
typedef pair<int,int> ii;

char mat[1010][1010];

ii src;

int dx[]={-1, 1, 0, 0};
int dy[]={ 0, 0,-1, 1};

int bfs(){
    int J[N][M], F[N][M];
    queue<ii> fire, joe;
    FOR(i,N){
        FOR(j,M){
            J[i][j]=-1; F[i][j]=-1;
            if(mat[i][j]=='J'){
                J[i][j]=0; joe.push(ii(i,j));
            }else if(mat[i][j]=='F'){
                F[i][j]=0; fire.push(ii(i,j));
            }
        }
    }
    //puts("BFS fire");
    while(!fire.empty()){
        ii u=fire.front(); fire.pop();
        FOR(k,4){
            int x=u.x+dx[k], y=u.y+dy[k];
            if(x<0 || x>=N || y<0 || y>=M || mat[x][y]=='#') continue;
            if(F[x][y]==-1){
                F[x][y]=F[u.x][u.y]+1;
                fire.push(ii(x,y));
            }
        }
    }
    //puts("BFS JOE");
    while(!joe.empty()){
        ii u=joe.front(); joe.pop();
        if(u.x==0 || u.x==N-1 || u.y==0 || u.y==M-1) return J[u.x][u.y]+1;
        FOR(k,4){
            int x=u.x+dx[k],y=u.y+dy[k];
            if(x<0 || x>=N || y<0 || y>=M || mat[x][y]!='.') continue;
            if(J[x][y]==-1 && (F[x][y]==-1 || J[u.x][u.y]+1<F[x][y])){
                J[x][y]=J[u.x][u.y]+1;
                joe.push(ii(x,y));
            }
        }
    }
    return -1;
}

int main(){
    //freopen("in.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&N, &M);
        FOR(i,N) scanf("%s",mat[i]);

        int answer = bfs();
        if(answer==-1) printf("IMPOSSIBLE\n");
        else printf("%d\n",answer);
    }
    return 0;
}
/*
3
6 8
..F....#
.....#.#
#J......
..##....
#.#.....
##..##.#
17 13
..#.........#
...#...#.....
..J......#...
......#......
..#.#.#......
..##.#.#..#.F
..#.......#..
.#.....#..#..
....#..#.##..
.....#.......
#............
#........#...
..####.....#.
#.#..........
#....##.##..#
##.#......#..
.............
12 6
..#.#.
##.#..
.#.#.#
...###
##.#..
......
......
#....J
..F##.
##..#.
......
..#...
*/
