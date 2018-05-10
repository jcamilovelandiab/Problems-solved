#include <bits/stdc++.h>

#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

map<char,vector<char> > graph;
map<char, bool> vis;
vector<char> keys;

string line;
int V;
bool hasTPS;
char a,b,c;

bool check(char u){
	loop(i,0,graph[u].size()) {
		if(vis[graph[u][i]]) return false;
	}
	return true;
}

bool dfs(vector<char>&tps){
	if(tps.size()==V){
		cout<<tps[0];  loop(i,1,tps.size()) cout<<" "<<tps[i]; puts("");
		hasTPS=true;
	}else{
		loop(i,0,V){
			char u=keys[i];
			if(!vis[u] && check(u)){
				vis[u]=true;  tps.push_back(u);
				dfs(tps);
				vis[u]=false; tps.pop_back();
			}
		}
	}
}

int main(){
	stringstream ss;
    int cases;
    cin>>cases;
    getchar();
    loop(k,0,cases){
    	graph.clear(); vis.clear(); keys.clear();
		hasTPS=false; ss.clear(); V=0;
		
    	getchar();
        getline(cin,line); ss.str(line);
        while(ss>>a){
        	keys.push_back(a);
        	vis[a]=false; V++;
		}
		sort(keys.begin(),keys.end());
		
        ss.clear(); getline(cin, line); ss.str(line);
        while(ss>>a>>b>>c) graph[a].push_back(c);
		
		vector<char> tps;
		dfs(tps);
		if(!hasTPS) puts("NO");
		if(k!=cases-1) puts("");
    }
    return 0;
}
