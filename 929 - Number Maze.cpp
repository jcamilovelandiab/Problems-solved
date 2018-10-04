#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 1e09
#define x first
#define y second
#define MAXTAM 1010

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;

int N,M, mat[MAXTAM][MAXTAM];
int dx[]={-1, 1, 0, 0};
int dy[]={ 0, 0,-1, 1};

int dijkstra(){
    int dist[N][M];
    FOR(i,N) FOR(j,M) dist[i][j]=INF;
    dist[0][0]=mat[0][0];
    priority_queue<iii, viii, greater<iii> > pq; pq.push(iii(dist[0][0],ii(0,0)));
    while(!pq.empty()){
        iii tp = pq.top(); pq.pop();
        int d=tp.x; ii u=tp.y;
        if(d>dist[u.x][u.y]) continue;
        if(u.x==N-1 && u.y==M-1) return dist[u.x][u.y];
        FOR(j,4){
            int x=u.x+dx[j], y=u.y+dy[j];
            if(x<0 || x>=N || y<0 || y>=M) continue;
            if(dist[u.x][u.y]+mat[x][y]<dist[x][y]){
                dist[x][y]=dist[u.x][u.y]+mat[x][y];
                pq.push(iii(dist[x][y],ii(x,y)));
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int tc; cin>>tc;
    while(tc--){
        cin>>N>>M;
        FOR(i,N) FOR(j,M) cin>>mat[i][j];
        cout<<dijkstra()<<endl;
    }
    return 0;
}
