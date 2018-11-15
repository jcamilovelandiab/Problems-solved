#include <bits/stdc++.h>
#define MAXV 105
#define INF 1e9
#define loop(i,a,b) for(int i=a; i<b; i++)
#define FOR(i,a) for(int i=0; i<a; i++)
#define fi first
#define se second

using namespace std;


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi p;

int mf, f, s, t, n, res[MAXV][MAXV];

void augment(int v, int minEdge){
	//cout<<"V: "<<v<<endl;
	if(v==s){
		f=minEdge; return;
	}else if(p[v]!=-1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v]-=f; 
		res[v][p[v]]+=f;
	}
}

void bfs(){
	vi dist(MAXV, INF); dist[s]=0; queue<int> q; q.push(s);
	p.assign(MAXV, -1);
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==t) break;
		FOR(v, MAXV){
			if( res[u][v] > 0 && dist[v]==INF){
				dist[v]=dist[u]+1, q.push(v), p[v]=u;
			}
		}
	}
}

int EdmondsKarp(){
	mf=0;
	while(1){
		f=0;
		bfs();
		augment(t, INF);
		if(f==0) break;
		mf+=f;
	}
	return mf;
}

int main(){
	
	ios::sync_with_stdio(false);
	int u, v, w, c, tc=1;
	while(cin>>n, n){
		
		//clear the residual graph
		memset(res, 0, sizeof res);
		cin>>s>>t>>c;
		while(c--){
			cin>>u>>v>>w;
			res[u][v]+=w;
			res[v][u]+=w;
		}
		/*
		cout<<endl;
		loop(i,1,n+1){
			loop(j,1,n+1) cout<<res[i][j]<<" ";
			cout<<endl;
		}*/
		
		cout<<"Network "<<tc++<<endl;
		cout<<"The bandwidth is "<<EdmondsKarp()<<".\n\n";
		/*
		loop(i,1,n+1){
			loop(j,1,n+1) cout<<res[i][j]<<" ";
			cout<<endl;
		}*/
	}
	return 0;
}


