#include <bits/stdc++.h>
#define MAXN 1005
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef vector<int> vi;

vector<vi> graph(MAXN);
vi num(MAXN), low(MAXN), parent(MAXN);

int isBridge[MAXN][MAXN], n, m, dfsCounter;

void findBridges(int u){
	low[u]=num[u]=dfsCounter++;
	FOR(j, graph[u].size()){
		int v = graph[u][j];
		if(num[v]==-1){
			parent[v]=u;
			findBridges(v);
			if(low[v]>num[u]){ // es un puente de articulacion
				isBridge[u][v]=1; isBridge[v][u]=1; // no se puede poner en una direccion
			}else if(!isBridge[v][u]){
				isBridge[u][v]=1; // como v,u no es un puente de articulacion se puede poner unidireccional
			}
			low[u]=min(low[u], low[v]);
		}else if( v != parent[u]){
			low[u]=min(low[u], num[v]);
			if(!isBridge[v][u]) 
				isBridge[u][v]=1; // como v,u no es un puente de articulacion se puede poner unidireccional
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int u,v, cnt=1;
	while(cin>>n>>m, n){
		
		FOR(i,n+2){
			low[i]=0; num[i]=-1; parent[i]=0;
			graph[i].clear();
		}
		memset(isBridge, 0, sizeof(isBridge));
		dfsCounter=0;
		
		FOR(i,m){
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		findBridges(1);
		cout<<cnt++<<endl<<endl;
		
		loop(u,1,n+1){
			loop(v,1,n+1){
				if(isBridge[u][v]){
					cout<<u<<" "<<v<<endl;
				}
			}
		}
		cout<<"#"<<endl;
	}
	return 0;
}
