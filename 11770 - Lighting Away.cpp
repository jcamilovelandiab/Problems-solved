#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define FOR(i,a) for(int i=0; i<a; i++)
#define rev(i,a,b) for(int i=a; i>=b; i--)
#define UNVISITED 0
#define VISITED 1

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vector<vi> adjList(10000+5);
vector<int> tps, vis(10000+5);

void Kosajaru(int u, int pass){
    vis[u]=VISITED;
    FOR(j,adjList[u].size()){
        int v = adjList[u][j];
        if(vis[v]==UNVISITED){
            Kosajaru(v,pass);
        }
    }
    if(pass) tps.push_back(u);
}

int main(){
    ios::sync_with_stdio(false);
    int T, N, M, a,b, numSCC;
    cin>>T;
    loop(k,1,T+1){
        cin>>N>>M;
        FOR(i,N+5){
            adjList[i].clear();
            vis[i]=UNVISITED;
        }

        FOR(i,M){
            cin>>a>>b;
            adjList[a].push_back(b);
        }

        //FOR(i,N)

        tps.clear();
        loop(u,1,N+1){
            if(vis[u]==UNVISITED){
                Kosajaru(u,1);
            }
        }

        numSCC=0;
        FOR(i,N+5) vis[i]=UNVISITED;
        rev(i,N-1,0){
            int u=tps[i];
            if(vis[u]==UNVISITED){
                numSCC++;
                Kosajaru(u,0);
            }
        }
        cout<<"Case "<<k<<": "<<numSCC<<endl;
    }
    return 0;
}
