#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef pair<int,int> ii;
vector<vector<int> > listAdy(105);
vector<int> vis(105), dfs_parent(105), articulation_vertex(105), dfs_low(105);
vector<int> dfs_num(105);
int dfsRoot;

int N, dfsNumberCounter, rootChildren;

void print(){
	loop(i,0,N+1){
		cout<<i<<": ";
		loop(j,0,listAdy[i].size()) cout<<" "<<listAdy[i][j];
		puts("");
	}
}

void articulationPoints(int u){
	dfs_low[u]=dfs_num[u]=dfsNumberCounter++;
	loop(j,0,listAdy[u].size()){
		int v=listAdy[u][j];
		if(dfs_num[v]==-1){ // no he visitado a v
			dfs_parent[v]=u;
			if(u==dfsRoot) rootChildren++; // caso especial
			articulationPoints(v);
			
			if(dfs_low[v]>=dfs_num[u]){
				articulation_vertex[u]=1;
			}
			
			dfs_low[u]=min(dfs_low[u],dfs_low[v]); // actualiza dfs_low[u]
		
		}else if(v!=dfs_parent[u]){
			dfs_low[u]=min(dfs_low[u], dfs_num[v]); // actualiza dfs_low[u]
		}
	}
}



int main(){
	int x, y;
	string line;
	stringstream ss;
	while(cin>>N, N){
		dfsNumberCounter=0;
		loop(i,0,105){
			listAdy[i].clear();
			dfs_num[i]=-1; dfs_low[i]=0;
			dfs_parent[i]=0; articulation_vertex[i]=0;
		}
		
		getchar();
		while(true){ // construyo la lista de adyacencia
			ss.clear(); getline(cin,line); ss.str(line);
			ss>>x;
			if(x==0) break;
			while(ss>>y){
				listAdy[x].push_back(y);
				listAdy[y].push_back(x);
			}
		}
		
		loop(i,1,N+1){
			if(dfs_num[i]==-1){
				dfsRoot=i; rootChildren=0;
				articulationPoints(i);
				articulation_vertex[dfsRoot]=(rootChildren>1);
			}
		}
		
		int cnt=0;
		//cout<<"ARTICULATION POINTS:"<<endl;
		loop(i,1,N+1){
			if(articulation_vertex[i]){
				//cout<<i<<endl;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
