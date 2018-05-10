#include <bits/stdc++.h>
#define loop(i, a ,b) for(int i=a; i<b; i++)
#define loopN(i, a) for(int i=0; i<a; i++)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

using namespace std;

typedef pair<int,int> ii;

map<int,vector<int> > mapAdy;
int dfsNumberCounter;
map<int, int> dfs_parent, dfs_num, dfs_low;
vector<ii> criticalLinks;

void articulationBridges(int u){
	dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
	loopN(j, mapAdy[u].size()){
		int v=mapAdy[u][j];
		if(dfs_num[v]==-1){
			dfs_parent[v]=u;
			articulationBridges(v);					
			if(dfs_low[v]>dfs_num[u]){
				criticalLinks.push_back(ii(min(u,v),max(u,v)));
			}
			dfs_low[u]=min(dfs_low[u], dfs_low[v]);
		}else if(v!=dfs_parent[u]){
			dfs_low[u]=min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int noServers, server, tamServer, anotherServer;
	while(cin>>noServers){
		criticalLinks.clear(); mapAdy.clear(); 
		dfs_parent.clear(); dfs_num.clear(); dfs_low.clear(); dfsNumberCounter=0;
		loopN(i,noServers){
			dfs_num[i]=-1;
			dfs_low[i]=0; dfs_parent[i]=0;
			mapAdy[i];
		}
		loopN(i,noServers){
			scanf("%d (%d)",&server, &tamServer);
			loopN(j,tamServer){
				cin>>anotherServer;
				mapAdy[server].push_back(anotherServer);
			}
		}
		
		loopN(i,noServers){
			if(dfs_num[i]==-1){
				articulationBridges(i);
			}
		}
		
		sort(all(criticalLinks));
		cout<<criticalLinks.size()<<" critical links"<<endl;
		loopN(i,criticalLinks.size()){
			cout<<criticalLinks[i].fi<<" - "<<criticalLinks[i].se<<endl;
		}
		puts("");
	}
	return 0;
}

