#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define rev(i,a,b) for(int i=a; i>=b; i--)
#define INF 1e9

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> boxes;
vector<vii> graph(35);
vi tps, p(35), path;

int src;

bool vis[35];

bool cmp(vi x, vi y){
	FOR(i,x.size()){
		if(x[i]>=y[i]) return false;
	}
	return true;
}

void dfs(int u){
	vis[u]=true;
	FOR(j, graph[u].size()){
		int v=graph[u][j].first;
		if(!vis[v]) dfs(v);
	}
	tps.push_back(u);
}

void findPath(int u){
	if(u==src){
		path.push_back(src); return;
	}
	findPath(p[u]);
	path.push_back(u);
}

void LONGEST_PATH_DAG(int V){
	tps.clear(); path.clear();
	memset(vis, false, sizeof vis);
	
	FOR(u, V){
		if(!vis[u]) dfs(u);
		p[u]=u;
	}
	vi dist(V, INF); dist[src]=0;
	
	rev(i, V-1, 0){
		int u = tps[i];
		FOR(j, graph[u].size()){
			ii v = graph[u][j];
			if(dist[u]+v.second < dist[v.first]){
				dist[v.first]=dist[u]+v.second;
				p[v.first]=u;
			}
		} 
	}
	findPath(V-1); //dest V-1
	cout<<path.size()-2<<endl;
	cout<<path[1]; loop(i,2, path.size()-1) cout<<" "<<path[i]; cout<<endl;
}

int main(){
	int k, n, value;
	while(cin>>k>>n){
		boxes.clear();
		graph[0].clear(); graph[k+1].clear(); src=0;
		
		loop(i,1,k+1){
			vi box;
			FOR(j,n){
				cin>>value; box.push_back(value);
			}
			sort(box.begin(), box.end());
			boxes.push_back(box);
			graph[i].clear();
		}
		
		loop(i,1,boxes.size()+1){
			graph[0].push_back(ii(i, 0));
			graph[i].push_back(ii(k+1,0));
		}
		
		FOR(i,boxes.size()){
			FOR(j, boxes.size()){
				if(cmp(boxes[i], boxes[j])){
					graph[i+1].push_back(ii(j+1,-1));
				}
			}
		}
		LONGEST_PATH_DAG(k+2);
	}
	return 0;
}
