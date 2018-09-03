#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 1e09

using namespace std;

typedef pair<string,int> si;
typedef vector<si> vsi;
typedef vector<string> vs;

int N;
map<string, vsi> graph;
map<string,bool> vis;
map<string, vsi>::iterator it;
map<string,int> dist;
string src;
vs tps;

void dfs(string u){
    vis[u]=true;
    FOR(j,graph[u].size()){
        string v = graph[u][j].first;
        if(!vis[v]) dfs(v);
    }
    tps.push_back(u);
}

int LP_DAG(){
    tps.clear(); vis.clear(); dist.clear();
    for(it=graph.begin(); it!=graph.end(); it++){
        string u = (it->first);
        if(!vis[u]) dfs(u);
        dist[u]=INF;
    }
    src=tps[tps.size()-1];
    dist[src]=0;
    int answer=0;
    for(int i=tps.size()-1; i>=0; i--){
        string u = tps[i];
		FOR(j, graph[u].size()){
			si v = graph[u][j];
			if(dist[u]+v.second < dist[v.first]){
				dist[v.first]=dist[u]+v.second;
				answer=max(answer,-dist[v.first]);
			}
		}
	}
    return answer;
}

int main(){
    //freopen("in.txt","r", stdin);
    int tc, w;
    string u, uu, v, vv, node, parents, line;
    cin>>tc;
    cin.ignore();
    cin.ignore();
    FOR(t, tc){
        graph.clear();
        while (getline(cin, line), line != ""){
            stringstream ss(line);
            ss>>node>>w;
            v = node[0]; vv = v+v;
            graph[v].push_back(si(vv,-w));
            if(ss>>parents){
                FOR(k,parents.size()){
                    u=parents[k]; uu=u+u; //uu=u+1;
                    graph[uu].push_back(si(v,0));
                }
            }
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
