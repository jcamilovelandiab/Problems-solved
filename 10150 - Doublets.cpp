#include <bits/stdc++.h>

#define loop(i,a,b) for(int i=a; i<b; i++)
#define fi first
#define se second

using namespace std;

typedef vector<string> vs;
typedef pair<string,int> si;

map<string, int> dist;
map<string,string> parent;
vector<bool> make(20);
vector<vector<string> > graph(20);
map<string, vector<string> > adjMap;
string src, dest;

void printPath(string u){
	if(u==src){
		cout<<src<<endl; return;
	}
	printPath(parent[u]);
	cout<<u<<endl;
}

bool bfs(){
	parent.clear(); dist.clear();
	
	dist[src]=0;
	queue<string> q; q.push(src);
	while(!q.empty()){
		string u = q.front(); q.pop();
		if(u==dest) return true;
		loop(j,0,adjMap[u].size()){
			string v = adjMap[u][j];
			if(dist[v]) continue;
			dist[v]=dist[u]+1;
			parent[v]=u;
			q.push(v);
		}
	}
	return false;
}

void makeGraph(int size){
	loop(i,0,graph[size].size()){
		string u = graph[size][i];
		loop(j,i+1,graph[size].size()){
			string v = graph[size][j];
			int diff=0;
			loop(k,0, u.size() ){
				if(u[k]!=v[k]) diff++;
				if(diff>1) break;
			}
			if(diff==1){
				adjMap[u].push_back(v);
				adjMap[v].push_back(u);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	
	loop(i,0,20) make[i]=false;
	
	string line;
	while(getline(cin,line)){
		if(line=="") break;
		graph[line.size()].push_back(line);
	}
	//cout<<"YEAH"<<endl;
	bool flag=true;
	while((cin>>src>>dest)){
		if(flag) flag=false;
		else cout<<endl;
		
		if(src.size()!=dest.size()){
			cout<<"No solution."<<endl;
		}else{
			//cout<<"GRAFO:"<<endl;
			//loop(i,0,graph[src.size()].size() ) cout<<" "<<graph[src.size()][i]; cout<<endl;
			if(!make[src.size()]){
				make[src.size()]=true;
				makeGraph(src.size());
			}
			if(bfs()) printPath(dest);
			else cout<<"No solution."<<endl;
		}
		
	}
	return 0;
}
