#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXN 1010
#define x first
#define y second
#define INF 1e09

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int R,C, W, mat[MAXN][MAXN];
ii src, tgt, p1, p2;

int energy[5][5]={
    {7,6,5,6,7},
    {6,3,2,3,6},
    {5,2,0,2,5},
    {6,3,2,3,6},
    {7,6,5,6,7}
};

int dijkstra(){
    int dist[R+1][C+1];
    FOR(i,R+1) FOR(j, C+1) dist[i][j]=INF;
    dist[src.x][src.y]=0;
    priority_queue<iii, viii, greater<iii> > pq; pq.push(iii(0,src));
    while(!pq.empty()){
        iii tp=pq.top(); pq.pop();
        int d=tp.x; ii u=tp.y;
        if(d>dist[u.x][u.y]) continue;
        if(u==tgt) return dist[u.x][u.y];
        FOR(j, 5){
            FOR(k, 5){
                if(j==2 && k==2) continue; //centro
                int x=u.x-2+j, y=u.y-2+k;
                if(x<0 || x>=R || y<0 || y>=C) continue; //fuera de rango
                if(mat[x][y]) continue; //es agua
                if(energy[j][k]+dist[u.x][u.y]<dist[x][y]){
                    dist[x][y]=energy[j][k]+dist[u.x][u.y];
                    pq.push(iii(dist[x][y],ii(x,y)));
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    while(cin>>R>>C, R&&C){
        cin>>src.x>>src.y>>tgt.x>>tgt.y;
        src.x--; src.y--; tgt.x--; tgt.y--;
        cin>>W;
        memset(mat, 0, sizeof mat);
        FOR(i,W){
            cin>>p1.x>>p1.y>>p2.x>>p2.y;
            loop(i, p1.x-1, p2.x){
                loop(j, p1.y-1, p2.y){
                    mat[i][j]=1;
                }
            }
        }
        if(src==tgt) cout<<0<<endl;
        else{
            int answer = dijkstra();
            if(answer==-1) cout<<"impossible"<<endl;
            else cout<<answer<<endl;
        }
    }
    return 0;
}
/*
4 4
1 1 4 2
2
2 1 3 3
4 3 4 4
4 4
1 1 4 2
1
2 1 3 4
7 6
4 2 7 6
5
4 1 7 1
5 1 5 5
2 4 3 4
7 5 7 5
6 6 6 6
0 0
*/
