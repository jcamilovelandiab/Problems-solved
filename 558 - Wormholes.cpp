#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define INF 1e9
#define fi first
#define se second


using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n, m;

vector<vii> graph(1005);

vi dist(1005);

bool bellmanFord(){
	int src=0; dist[src]=0;
	FOR(k,n-1){
		FOR(u,n){
			FOR(j,graph[u].size()){
				ii v = graph[u][j];
				dist[v.fi]=min(dist[v.fi], dist[u]+ v.se);
			}
		}
	}
	
	FOR(u,n){
		FOR(j,graph[u].size()){
			ii v = graph[u][j];
			if(dist[v.fi]> dist[u]+v.se){
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	int c, u, v, w;
	cin>>c;
	while(c--){
		cin>>n>>m;
		FOR(i,n+2){
			graph[i].clear();
			dist[i]=INF;
		}
		while(m--){
			cin>>u>>v>>w;
			graph[u].push_back(ii(v,w));
		}
		
		if(bellmanFord()) cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
	}
	
	return 0;
}
