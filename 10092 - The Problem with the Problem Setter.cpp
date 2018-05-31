#include <bits/stdc++.h>
#define MAXV 1030
#define INF 1e9
#define loop(i,a,b) for(int i=a; i<b; i++)
#define FOR(i,a) for(int i=0; i<a; i++)

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi p;

int mf, f, s, t, res[MAXV][MAXV], nMAX;
vector<vi> graph(MAXV);

void augment(int v, int minEdge){
	if(v==s){
		f=minEdge; return;
	}else if(p[v]!=-1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v]-=f; 
		res[v][p[v]]+=f;
	}
}

void bfs(){
	vi dist(nMAX, INF); dist[s]=0; queue<int> q; q.push(s);
	p.assign(nMAX, -1);
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==t) break;
		FOR(j,graph[u].size()){
			int v = graph[u][j];
			if( res[u][v] > 0 && dist[v]==INF){
				dist[v]=dist[u]+1, q.push(v), p[v]=u;
			}
		}
	}
}

void EdmondsKarp(){
	mf=0;
	while(1){
		f=0;
		bfs();
		augment(t, INF);
		if(f==0) break;
		mf+=f;
	}
}

int main(){
	int c, p, w, n, v, success;
	while(cin>>c>>p, c){
		
		// construct the graph
		s=0; t=p+c+1; nMAX=t+1;
		success=0;
		
		memset(res, 0, sizeof res); // clear the residual graph
		FOR(i,nMAX) graph[i].clear(); //clear the graph
		
		loop(u,1,p+1){
			res[s][u]=1;
			graph[s].push_back(u);
			graph[u].push_back(s);
		}
		
		FOR(i,c){
			int u=p+i+1;
			cin>>w; 
			res[u][t]=w; 
			graph[u].push_back(t); 
			graph[t].push_back(u);
			success+=w;
		}
		
		loop(u,1,p+1){
			cin>>n;
			FOR(i,n){
				cin>>v; v+=p;
				res[u][v]=1;
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}

		// RUNS EDMONSKARP
		EdmondsKarp();
		
		if(mf==success){
			cout<<"1"<<endl;
			loop(u,p+1, p+c+1){
				bool flag=false;
				FOR(j, graph[u].size()){
					int v = graph[u][j];
					if(res[u][v]){
						if(flag) cout<<" ";
						cout<<v; flag=true;
					}
				}
				cout<<endl;
			}
		}else{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
