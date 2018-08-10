#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define second s
#define first f
#define INF 1e09

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;

int C, S, Q, AdjMat[102][102];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u, v, w, tc=1;
    while(cin>>C>>S>>Q, C){
        FOR(i,C+2) FOR(j, C+2) AdjMat[i][j]=INF;
        FOR(i,S){
            cin>>u>>v>>w;
            AdjMat[u][v]=w;
            AdjMat[v][u]=w;
        }
        loop(k,1,C+1){
            loop(i,1, C+1){
                loop(j,1, C+1){
                    AdjMat[i][j]=min(AdjMat[i][j], max(AdjMat[i][k], AdjMat[k][j]));
                }
            }
        }
        if(tc!=1) cout<<endl;
        cout<<"Case #"<<tc++<<endl;
        FOR(i,Q){
            cin>>u>>v;
            if(AdjMat[u][v]==INF) cout<<"no path"<<endl;
            else cout<<AdjMat[u][v]<<endl;
        }
    }
    return 0;
}
