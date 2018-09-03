#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 1e09

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int weights[35], src;
vector<vii> graph(35);

int N, parent[35];
bool vis[35];
vi path, tps;

void dfs(int u){
    vis[u]=true;
    FOR(j,graph[u].size()){
        int v = graph[u][j].first;
        if(!vis[v]) dfs(v);
    }
    tps.push_back(u);
}

void findPath(int u){
    if(u==src){
        path.push_back(src); return;
    }
    findPath(parent[u]);
    path.push_back(u);
}

int LP_DAG(){
    tps.clear(); path.clear();
    memset(vis, false, sizeof vis);
    FOR(i,N){
        if(!vis[i]) dfs(i);
        parent[i]=i;
    }
    src=0;
    vi dist(N, INF); dist[src]=0;
    for(int i=N-1; i>=0; i--){
        int u = tps[i];
		FOR(j, graph[u].size()){
			ii v = graph[u][j];
			if(dist[u]+v.second < dist[v.first]){
				dist[v.first]=dist[u]+v.second;
				parent[v.first]=u;
			}
		}
	}
    path.clear(); findPath(N-1);
    int answer=0;
    loop(i,1, path.size()-1) answer+=weights[path[i]];
    return answer;
}

int main(){
    //freopen("in.txt","r", stdin);
    int tc, u , v, w, sz; cin>>tc;
    string line;
    cin.ignore();
    cin.ignore();
    FOR(t, tc){
        N=0;
        FOR(i,30) graph[i].clear();
        while(getline(cin,line), line!=""){
            sz=line.size();
            v = line[0]-'A'+1; w = line[2]-'0';
            weights[v]=w;
            if(sz>4){
                loop(k,4,sz){
                    u=line[k]-'A'+1; graph[u].push_back(ii(v,-1));
                }
            }
            N++;
        }
        N+=2; //agrego dos nodos src, y tgt
        loop(i,1,N-1){
            graph[0].push_back(ii(i,0));
            graph[i].push_back(ii(N-1,0));
        }
        if(t!=0) cout<<endl;
        cout<<LP_DAG()<<endl;
    }
    return 0;
}
/*
2

A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC

A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC

*/
