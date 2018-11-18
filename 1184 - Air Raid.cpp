/**
	1184 - Air Raid, UVa online judge
	Min Path Cover on DAG
	Time: 0.170s
	@author JCamiloVB
*/

#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXN 245
#define INF 1e09

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int mf,f,res[MAXN][MAXN];
int N,M,Vt, src, tgt;
vi p;

void augment(int v, int minEdge){
	if(v==src){
		f=minEdge; return;
	}else if(p[v]!=-1){
		augment(p[v], min(res[p[v]][v],minEdge));
		res[p[v]][v]-=f;
		res[v][p[v]]+=f;
	}
}

void bfs(){
	p.assign(Vt,-1); bitset<MAXN> vis; vis.set(src);
	queue<int> q; q.push(src);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(u==tgt) break;
		FOR(v,Vt){
			if(res[u][v]>0 && !vis[v]){
				vis.set(v); q.push(v); p[v]=u;
			}
		}
	}
}

int edmondsKarp(){
	mf=0;
	while(1){
		f=0;
		bfs();
		augment(tgt,INF);
		if(f==0) break;
		mf+=f;
	}
	return mf;
}

int main(){
	int tc,x,y; cin>>tc;
	while(tc--){
		cin>>N>>M;
		src=0; tgt=2*N+1; Vt=tgt+1;
		memset(res, 0, sizeof res);
		
		loop(i,1,N+1) res[src][i]=1; 
		FOR(i,M){
			cin>>x>>y;
			res[x][y+N]=1;
		}
		loop(i,N+1,2*N+1) res[i][tgt]=1;
		
		cout<<N-edmondsKarp()<<endl; //MPC = N-mf
	}
	return 0;
}


