/**
	11506 - Angry Programmer UVa online judge
	Time= 0.040s
	@author JCamiloVB
*/


#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXN 105
#define INF 1e09

using namespace std;

typedef vector<int> vi;

int N,M, res[MAXN][MAXN], V, mf, f, src, tgt;
vi p;

void augment(int v, int minEdge){
	if(v==src){
		f=minEdge; return;
	}else if(p[v]!=-1){
		augment(p[v], min(res[p[v]][v], minEdge));
		res[p[v]][v]-=f;
		res[v][p[v]]+=f;
	}
}

void bfs(){
	vi dist(V,INF); dist[src]=0;
	p.assign(V, -1);
	queue<int> q; q.push(src);
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==tgt) break;
		loop(v,1, V){
			if(res[u][v]>0 && dist[v]==INF ){
				dist[v]=dist[u]+1, q.push(v), p[v]=u;
			}
		}
	}
}

int edmondsKarp(){
	mf=0;
	while(1){
		f=0;
		bfs();
		augment(tgt, INF);
		if(f==0) break; //no hay mas flujo por mandar
		mf+=f;
	}
	return mf;
}

int main(){
	//freopen("inAngry.txt","r", stdin);
	ios::sync_with_stdio(false);
	cin.tie();
	int x,y,w;
	while(cin>>N>>M, N){
		memset(res, 0, sizeof res);
		V=2*N+1; src=1; tgt=2*N;
		res[1][N+1]=res[N][N+N]=INF; //src -> src', tgt->tgt'
		FOR(i,N-2){
			cin>>x>>w;
			res[x][x+N]=w; // x -> x'
		}
		FOR(i,M){
			cin>>x>>y>>w;
			if(x==y) continue;
			res[x+N][y]=res[y+N][x]=w; //x' -> y, y' -> x
		}
		cout<<edmondsKarp()<<endl;
	}	
	return 0;
}
