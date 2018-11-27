#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 1e09
#define MAXN 505


using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> graph(MAXN);
vector<vi> parents(MAXN);


int N,M, src, tgt, bestPath;
bool edges[MAXN][MAXN];

void findPaths(int v){
	if(v==src){
			return;
	}else if(parents[v].size()>0){
		FOR(j, parents[v].size()){
			edges[parents[v][j]][v]=true;
			findPaths(parents[v][j]);
		}
	}
}

int ASP_dijsktra(){
	FOR(i, N) parents[i].clear();
	vi dist(N, INF); dist[src]=0;
	priority_queue<ii, vii, greater<ii> > pq;  pq.push(ii(0, src));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d=front.first, u= front.second;
		FOR(j, graph[u].size()){
			ii v = graph[u][j];
			if(dist[u]+v.second <= dist[v.first]){
				if(dist[u]+v.second<dist[v.first]){
					parents[v.first].clear();
				}
				parents[v.first].push_back(u);
				dist[v.first]=dist[u]+v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	findPaths(tgt);
	return dist[tgt];
}

int dijsktra(){
	vi dist(N, INF); dist[src]=0;
	priority_queue<ii, vii, greater<ii> > pq;  pq.push(ii(0, src));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d=front.first, u= front.second;
		if(u==tgt) return dist[u];
		if(d>dist[u]) continue;
		FOR(j, graph[u].size()){
			ii v = graph[u][j];
			if(edges[u][v.first]) continue; // no puede agarrar ese arco
			if(dist[u]+v.second <= dist[v.first]){
				dist[v.first]=dist[u]+v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	return -1;
}

int main(){
	while(cin>>N>>M, N){
		FOR(i,N) graph[i].clear();
		cin>>src>>tgt;
		FOR(i, M){
			int u,v,w;
			cin>>u>>v>>w;
			graph[u].push_back(ii(v,w));
		}
		//cout<<"RUN DIJSKTRA"<<endl;
		memset(edges, false, sizeof edges);
		bestPath=ASP_dijsktra();
		cout<<dijsktra()<<endl;
	}
	return 0;
}
