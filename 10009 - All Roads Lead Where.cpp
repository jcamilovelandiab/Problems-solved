#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef vector<string> vs;

map<string,vs> graph;
map<string,string> p;

int m,q;
string src,tgt;

string path(string v){
    if(v==src){
        return src.substr(0,1);
    }else if(p[v]!=v){
        return path(p[v])+v.substr(0,1);
    }
}

void bfs(){
    for(map<string,vs>::iterator it=graph.begin(); it!=graph.end(); it++){
        p[it->first]=it->first;
    }

    set<string> vis;
    queue<string> q; q.push(src);
    vis.insert(src);
    while(!q.empty()){
        string u = q.front(); q.pop();
        if(u==tgt) break;
        FOR(j, graph[u].size()){
            string v = graph[u][j];
            if(vis.find(v)==vis.end()){
                vis.insert(v); q.push(v); p[v]=u;
            }
        }
    }
    cout<<path(tgt)<<endl;
}

int main(){
    int tc; cin>>tc;
    FOR(t,tc){
        graph.clear();
        cin>>m>>q;
        FOR(i,m){
            string u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(t!=0) cout<<endl;
        FOR(i,q){
            cin>>src>>tgt;
            bfs();
        }
    }
    return 0;
}
