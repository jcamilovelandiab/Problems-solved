/**
    13066 - Ant-Man's Sugar Journey
    UVa Online judge
    time = 0.160s
    @author JCamiloVB
*/

#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define pushb push_back
#define MAXN 110
#define INF 1e09

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph(MAXN);
vvi newGraph(MAXN);

int N,M, res[MAXN*2][MAXN*2], mf, f, src, tgt, MAXVR;
bool vis[MAXN];
vi p;

vi dfs(int u){
    vis[u]=true;
    vi l; l.push_back(u);
    FOR(j, graph[u].size()){
        int v = graph[u][j];
        if(!vis[v]){
            vi lChild = dfs(v);
            l.insert(l.end(), lChild.begin(), lChild.end());
        }
    }
    return l;
}

void makeBipartiteGraph(){
    memset(res, 0, sizeof res);
    FOR(i,N) res[0][i+1]=1;
    FOR(u,N){
        FOR(j, newGraph[u].size()){
            int v = newGraph[u][j];
            res[u+1][v+1+N]=1;
        }
    }
    FOR(i,N) res[i+1+N][2*N+1]=1;
}

void augment(int v, int minEdge){
    if(v==src){
        f=minEdge; return;
    }else if(p[v]!=-1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v]-=f;
        res[v][p[v]]+=f;
    }
}

void bfs(){
    vi dist(MAXVR, INF); dist[src]=0;
    p.assign(MAXVR, -1);
    queue<int> q; q.push(src);
    while (!q.empty()){
        int u=q.front(); q.pop();
        if(u==tgt) break;
        FOR(v, MAXVR){
            if(res[u][v]>0 && dist[v]==INF){
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
        augment(tgt,INF);
        if(f==0) break;
        mf+=f;
    }
    return mf;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int x,y;
    while(cin>>N>>M){
        FOR(i,M){
            cin>>x>>y;
            graph[x].pushb(y);
        }
        FOR(u,N){
            memset(vis, false, N+1);
            vi l=dfs(u);
            newGraph[u].insert(newGraph[u].end(), l.begin()+1, l.end());
        }
        makeBipartiteGraph();

        MAXVR=2*N+2;
        src=0; tgt=2*N+1;
        cout<<N-EdmondsKarp()<<endl;
        FOR(i,N){
            graph[i].clear();
            newGraph[i].clear();
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
8 13
0 4
0 6
1 4
1 7
2 0
2 1
2 3
2 4
2 5
3 0
5 4
6 4
7 4
*/
