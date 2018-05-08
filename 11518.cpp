/**
	UVa Online Judge 11518 - Dominos 2
**/

#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define rev(i,a,b) for(int i=a; i>=b; i--)

using namespace std;

vector<vector<int> > graph(10000+5);
vector<bool> vis(10000+5);

int total;

void dfs(int u){
	vis[u]=true;
	FOR(j,graph[u].size()){
		int v = graph[u][j];
		if(!vis[v]){
			dfs(v);
		}
	}
	total+=1;
}

int main(){
	ios::sync_with_stdio(false);
	int n,m,l, x ,y, tc, z;
	cin>>tc;
	while(tc--){
		cin>>n>>m>>l;
		
		loop(i,1,n+3){
			graph[i].clear();
			vis[i]=false;
		}
		
		FOR(i,m){
			cin>>x>>y;
			graph[x].push_back(y);
		}
		
		total=0;
		FOR(i,l){
			cin>>z;
			if(!vis[z]){
				dfs(z);
			}
		}
		cout<<total<<endl;
	}
	return 0;
}
