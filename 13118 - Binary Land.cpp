#include <bits/stdc++.h>
#define x first
#define y second
#define loop(i,a,b) for(int i=a; i<b; i++)
#define FOR(i,a) for(int i=0; i<a; i++)
#define INF 1e09

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> state;

int r,c;
char mat[41][41];

int dx[]={ 1,-1, 0, 0};
int dy[]={ 0, 0,-1, 1};

int ox[]={ 1,-1, 0, 0};
int oy[]={ 0, 0, 1,-1};

int bfs(state src, ii tgt){
    
	if(src==state(tgt, tgt)) return 0;

	int dist[r][c][r][c]; FOR(i,r) FOR(j,c) FOR(k,r) FOR(l,c) dist[i][j][k][l]=-1;

	queue<state> pq; pq.push(src); dist[src.x.x][src.x.y][src.y.x][src.y.y]=0;
	
	while(!pq.empty()){
		state u = pq.front(); pq.pop();
		if(u==state(tgt, tgt)) break;
		FOR(k,4){
		    // PENGUIN #1
            ii p1 = u.x, p2=u.y;

			int x=dx[k]+p1.x, y=dy[k]+p1.y;

			if(!(x<0 || x>=r || y<0 || y>=c || mat[x][y]=='#')){
                p1.x=x; p1.y=y;
			}
			
            // PENGUIN #2
			x=ox[k]+p2.x, y=oy[k]+p2.y;

            if(!(x<0 || x>=r || y<0 || y>=c || mat[x][y]=='#')){
                p2.x=x; p2.y=y;
			}
			
			if(dist[p1.x][p1.y][p2.x][p2.y]==-1){
				dist[p1.x][p1.y][p2.x][p2.y]=dist[u.x.x][u.x.y][u.y.x][u.y.y]+1;
				pq.push(state(p1,p2));
			}
		}
	}
	return dist[tgt.x][tgt.y][tgt.x][tgt.y];
}

int main(){

	while(scanf("%d %d",&r,&c)==2){
		ii love, p1, p2;
		scanf("%d %d %d %d %d %d",&love.x, &love.y, &p1.x, &p1.y, &p2.x, &p2.y);
		p1.x-=1; p1.y-=1; love.x-=1; love.y-=1; p2.x-=1; p2.y-=1;
		
		getchar();
		FOR(i, r) gets(mat[i]);
		
		int ans=bfs(state(p1, p2), love);
        if(ans==-1) puts("NO LOVE");
        else printf("%d\n", ans);
	}
	return 0;
}
