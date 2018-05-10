#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

map<int, vector<int> > graph;
map<int, vector<int> >::iterator it;
map<int, bool> vis;
vector<int> keys;
int V;

bool check(int u){
	loop(i,0,graph[u].size()){
		if(vis[graph[u][i]]) return false;
	}
	return true;
}

void dfs(vector<int>&tps){
	if(tps.size()==V){
		loop(i,0,tps.size()) cout<<(char)(tps[i]+'a');
		puts(""); return;
	}else{
		loop(i,0,V){
			int u=keys[i];
			if(!vis[u] && check(u)){
				vis[u]=true; tps.push_back(u);
				dfs(tps);
				vis[u]=false; tps.pop_back();
			}
		}
	}
}

int main(){
	string line;
	char a,b;
	stringstream ss;
	bool firstCase=true;
	while(getline(cin,line)){
		ss.clear(); graph.clear(); keys.clear(); vis.clear(); 
		ss.str(line); V=0;
		while(ss>>a){
			graph[a-'a']; 
			keys.push_back(a-'a'); 
			vis[a-'a']=false;
			V++;
		}
		sort(keys.begin(),keys.end());
		
		ss.clear();
		getline(cin,line); ss.str(line);
		while(ss>>a>>b){
			graph[a-'a'].push_back(b-'a');
		}
		vector<int>tps;
		if(!firstCase) puts("");
		dfs(tps);
		if(firstCase) firstCase=false;
	}
	return 0;
}
