#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAX_M 110
#define MAX_N 25
#define x first
#define y second
#define INF 1e09

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int N,M, weight[MAX_M];
char des[MAX_M][MAX_N], fix[MAX_M][MAX_N];

bool canApply(int bugs, int patch){
    FOR(i, N){
        if(des[patch][i]=='+' && !(1&(bugs>>i)) ) return false;
        else if(des[patch][i]=='-' && (1&(bugs>>i)) ) return false;
    }
    return true;
}

int applyPatch(int bugs, int patch){
    int newBug=0;
    for(int i=N-1; i>=0; i--){
        if(fix[patch][i]=='+'){
            newBug|=(1<<i);
        }else if(fix[patch][i]=='0' && (1&(bugs>>i)) ){
            newBug|=(1<<i);
        }
    }
    return newBug;
}

int dijkstra(int src, int tgt){
    priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0,src));
    vi dist(1048580, INF); dist[src]=0;
    while(!pq.empty()){
        ii tp = pq.top(); pq.pop();
        int w=tp.x, u=tp.y;
        if(u==tgt) return dist[u];
        FOR(patch,M){
            if(canApply(u, patch)){
                int v=applyPatch(u, patch), d=dist[u]+weight[patch];
                if(d<dist[v]){
                    dist[v]=d;
                    pq.push(ii(d,v));
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); //desincronizar las librerias de C
    cin.tie(); //mas rapido
    int tc=1;
    while(cin>>N>>M, N){
        FOR(i,M){
            cin>>weight[i]>>des[i]>>fix[i];
        }
        cout<<"Product "<<tc++<<endl;
        int answer=dijkstra((int)pow(2,N)-1, 0);
        if(answer!=-1){
            cout<<"Fastest sequence takes "<<answer<<" seconds."<<endl;
        }else{
            cout<<"Bugs cannot be fixed."<<endl;
        }
        cout<<endl;
    }
    return 0;
}
