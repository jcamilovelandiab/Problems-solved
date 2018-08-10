#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define second s
#define first f
#define INF 1e09

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> graph;
vii sssp;

int N,M, best, Sbest;

int dijkstra(int s, int t){
    vi dist(N+1, INF); dist[s]=0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0,s));
    while(!q.empty()){
        ii fr = pq.top(); pq.pop();
        int d = front.f, u = f.second;
        if(d>dist[u]) continue;
        FOR(j, graph[u].size()){
            ii v = graph[u][j];
            if(dist[u]+v.second < dist[v.first]){
                dist[v.first]=dist[u]+v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
}

int main(){
    int T, u, v, w;
    cin>>T;
    while(T--){
        cin>>N>>M;
        FOR(i,N+1) graph[i].clear();
        FOR(i,M){
            cin>>u>>v>>w;
            graph[u].push_back(ii(v,w));
        }
    }
    return 0;
}
