#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define revLoop(i,a,b) for(int i=a; i>=b ; i--)


using namespace std;

string origen,destino;
map<string, vector<string> > graph;
map<string, int> dist;
map<string, string> parent;
vector<string> path;

typedef pair<int,int> ii;

void findPath(string u){
	if(u==origen){ 
		path.push_back(u); return;
	}
	findPath(parent[u]);
	path.push_back(u);
}

void bfs(){
	dist[origen]=0;
	queue<string> q; q.push(origen);
	
	while(!q.empty()){
		string u=q.front(); q.pop();
		loop(i,0,graph[u].size()){
			string v = graph[u][i];
			if(dist[v]==-1){
				dist[v]=dist[u]+1;
				parent[v]=u;
				q.push(v);
			}
		}
	}
	if(dist[destino]==-1){
		puts("No route");
	}else{
		findPath(destino);
		loop(i,0,path.size()-1) cout<<path[i]<<" "<<path[i+1]<<endl;
	}
}

int main(){
	int lines;
	string x,y;
	bool primera=false;
	
	while(scanf("%d",&lines)!=EOF){
		graph.clear(); dist.clear(); parent.clear(); path.clear();
		loop(i,0,lines){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
			dist[x]=-1; dist[y]=-1;
		}
		cin>>origen>>destino;
		dist[origen]=-1; dist[destino]=-1;
		if(primera) puts(""); primera=true;
		bfs();
	}
	
	return 0;
}


