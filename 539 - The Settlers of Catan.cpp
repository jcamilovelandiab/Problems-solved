#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef vector<int> vi;

vector<vi> graph(30);
bool vis[27][27];

int n,m, maxPath;

void simplePath(int u, int nodes){
    FOR(j,graph[u].size()){
        int v = graph[u][j];
        if(!vis[u][v]){
            vis[u][v]=vis[v][u]=true;
            simplePath(v, nodes+1);
            vis[u][v]=vis[v][u]=false;
        }
    }
    maxPath=max(maxPath, nodes);
}

int main(){
    int u,v;
    while(cin>>n>>m, n&&m){
        FOR(i,n) graph[i].clear();
        FOR(i,m){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        memset(vis, 0, sizeof vis);
        maxPath=-1;
        FOR(i,n){
            simplePath(i,0);
        }
        cout<<maxPath<<endl;
    }
    return 0;
}
/*
15 16
0 2
1 2
2 3
3 4
3 5
4 6
5 7
6 8
6 9
7 9
8 10
9 11
10 12
11 12
11 13
12 14
*/
