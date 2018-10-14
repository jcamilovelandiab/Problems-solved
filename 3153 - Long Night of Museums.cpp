#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 1e09
#define MAXN 20
#define LIMIT 420

using namespace std;

int N, dist[MAXN][MAXN], wnode[MAXN], dp[1<<MAXN];

int f(int u, int mask, int sum){
    if(dp[mask]!=-1) return dp[mask];
    int ans=1;
    FOR(v,N){
        if(u==v) continue;
        int d= sum+dist[u][v]+wnode[v];
        if(!((mask>>v)&1) && d<=LIMIT){
            ans=max(ans, 1+f(v,mask|(1<<v), d));
        }
    }
    return dp[mask]=ans;
}

int main(){
    while(cin>>N, N){
        FOR(i,N) cin>>wnode[i];
        FOR(i,N) FOR(j,N) cin>>dist[i][j];
        int maxNodes=0;
        FOR(u, N){
            if(wnode[u]>LIMIT) continue;
            memset(dp, -1, sizeof dp);
            maxNodes=max(maxNodes,f(u, 1<<u, wnode[u]));
        }
        cout<<maxNodes<<endl;
    }
    return 0;
}

