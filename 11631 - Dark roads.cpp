#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)


using namespace std;
typedef pair<int, int > ii;
typedef pair<int, ii > iii;

vector<iii> graph;
int rank[200010], parent[200010];


int findParent(int x){
	if(x!=parent[x]) parent[x]=findParent(parent[x]);
	return parent[x];
}

void init(){
	loop(i,0,200010){
		parent[i]=i;
		rank[i]=1;
	}
}

void Union(int rootX, int rootY){
	if(rank[rootX]>rank[rootY]){
		parent[rootY]=rootX;
		rank[rootX]+=rank[rootY];
	}else{
		parent[rootX]=rootY;
		rank[rootY]+=rank[rootX];
	}
}

long long kruskal(){
	init();
	sort(graph.begin(), graph.end());
	long long wTree=0;
	loop(i,0,graph.size()){
		int w=graph[i].first, x=graph[i].second.first, y=graph[i].second.second;
		int rootX=findParent(x), rootY=findParent(y);
		if(rootX!=rootY){
			Union(rootX,rootY);
			wTree+=(long long)w;
		}
	}
	return wTree;
}

int main(){
	int m,n, x, y, w;
	while(scanf("%d %d",&m,&n)==2){
		if(m==0 && n==0) break; 
		graph.clear(); 
		long long wDist=0;
		loop(i,0,n){
			scanf("%d %d %d",&x, &y, &w);
			graph.push_back(iii(w,ii(x,y)));
			wDist+=(long long)w;
		}
		cout<<wDist-kruskal()<<endl;
	}
	return 0;
}
