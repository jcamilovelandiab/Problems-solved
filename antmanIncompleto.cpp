#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define pushb push_back
#define MAXN 110

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph(MAXN);
vvi newGraph(MAXN);

int N,M, bipartite[MAXN*2][MAXN*2];
bool vis[MAXN];

vi dfs(int u){
    vis[u]=true;
    vi l; l.pushb(u);
    FOR(i,graph[u].size()){
        int v = graph[u][i];
        if(!vis[v]){
            vi lChild = dfs(v);
            l.insert(l.end(),lChild.begin(), lChild.end());
        }else{
            l.push_back(v);
            l.insert(l.end(),newGraph[v].begin(), newGraph[v].end());
        }
    }
    newGraph[u].insert(newGraph[u].end(),l.begin()+1, l.end());
    return l;
}

void makeBipartiteGraph(){
    memset(bipartite, 0, sizeof bipartite);
    FOR(i,N) graph[0][i+1]=1;
    cout<<"YES"<<endl;
    FOR(u,N){
        FOR(j, graph[u].size()){
            int v = graph[u][j];
            bipartite[u+1][v+1+N]=1;
        }
    }
    FOR(i,N) graph[i+1+N][2*N+1]=1;
}

int main(){
    int x,y;
    while(cin>>N>>M){
        FOR(i,N){
            graph[i].clear();
            newGraph[i].clear();
        }
        FOR(i,M){
            cin>>x>>y;
            graph[x].pushb(y);
        }
        memset(vis, false, sizeof vis);
        FOR(u,N){
            if(!vis[u]){
                dfs(u);
            }
        }
        FOR(i,N){
            cout<<i<<" -> ";
            FOR(j,newGraph[i].size()){
                cout<<","<<newGraph[i][j];
            }
            cout<<endl;
        }
        cout<<"BITARTITE GRAPH"<<endl;
        makeBipartiteGraph();
        cout<<"BITARTITE GRAPH"<<endl;
        FOR(i,2*N+1){
            cout<<i<<" -> ";
            FOR(j, 2*N+1){
                cout<<","<<bipartite[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
/*
5 4
1 3
2 3
3 4
3 5
*/
