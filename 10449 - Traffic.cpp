#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF LLONG_MAX
#define fi first
#define se second

using namespace std;

typedef pair<long long, long long> ll;
typedef vector<long long> vl;
typedef vector<ll> vll;

long long n, r;

vector<vll> graph(205);
vl dist(205), weights(205);

void bellmanFord(){
	int src=1; dist[src]=0;
	
	bool isUpdated;
	FOR(k, n-1){
		isUpdated=false;
		loop(u,1, n+1){
			FOR(j,graph[u].size()){
				ll v = graph[u][j];
				if(dist[v.fi]>dist[u]+v.se && dist[u]!=INF){
					dist[v.fi]=dist[u]+v.se;
					isUpdated=true;
				}
			}
		}
		if(!isUpdated) break;
	}
	
	loop(u,1, n+1){
		FOR(j,graph[u].size()){
			ll v = graph[u][j];
			if(dist[v.fi]>dist[u]+v.se && dist[u]!=INF){
				dist[v.fi]=INT_MIN;
			}
		}
	}
}

int main(){
	//freopen("in10449.txt","r",stdin);
	ios::sync_with_stdio(false);
	
	long long tc=1, u, v, w, q, tgt;
	while(cin>>n){
		
		loop(i,1,n+1){
			cin>>weights[i];
			graph[i].clear();
			dist[i]=INF;
		}
		
		cin>>r;
		while(r--){
			cin>>u>>v;
			w=weights[v]-weights[u]; 
			w=w*w*w;
			graph[u].push_back(ll(v,w));
		}
		
		bellmanFord();
		
		cout<<"Set #"<<tc++<<endl;
		cin>>q;
		while(q--){
			cin>>tgt;
			if(dist[tgt]<3 || dist[tgt]==INF)  cout<<"?"<<endl;
			else cout<<dist[tgt]<<endl;
		}
	}
	return 0;
}

