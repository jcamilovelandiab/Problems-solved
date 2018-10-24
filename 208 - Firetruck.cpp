#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 1e09
#define MAXV 21

using namespace std;

typedef vector<int> vi;

vector<vi> graph(MAXV);

int tgt;
bool vis[MAXV];
vi path;
vector<vi> allPaths;

int reach;

void reachable(int u){
	reach=reach|(1<<u);
	FOR(j, graph[u].size()){
		
		int v = graph[u][j];
		if(!((reach>>v)&1)){
			reachable(v);
		}
	}
}

void dfs(int u){
    if(u==tgt){
        allPaths.push_back(path);
        return;
    }
    FOR(j,graph[u].size()){
        int v = graph[u][j];
        if( ((reach>>v)&1) && !vis[v]){
            vis[v]=true;
            path.push_back(v);
            dfs(v);
            vis[v]=false;
            path.pop_back();
        }
    }
}

int main(){
    int x,y, tc=1;
    while(cin>>tgt){
        FOR(i,21) graph[i].clear();
        while(cin>>x>>y, x && y){
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        reach=0; reachable(tgt);

		
        memset(vis, false, sizeof vis);
        allPaths.clear(); path.clear();
        path.push_back(1); vis[1]=true;
        dfs(1);
        sort(allPaths.begin(), allPaths.end());
        
        cout<<"CASE "<<tc++<<":\n";
        FOR(i,allPaths.size()){
        	cout<<allPaths[i][0];
        	loop(j,1, allPaths[i].size()){
        		cout<<" "<<allPaths[i][j];
			}
			cout<<endl;
		}
		cout<<"There are "<<allPaths.size()<<" routes from the firestation to streetcorner "<<tgt<<".\n";
    }
    return 0;
}
