#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define FOR(i,a) for(int i=0; i<a; i++)
#define rev(i,a,b) for(int i=a; i>=b ; i--)
#define pb push_back
#define fi first
#define se second

using namespace std;

map<string,vector<string> > graph;
map<string,vector<string> >::iterator it;
map<string, int> dist;

string src, tgt;

int bfs(){
	dist.clear(); 
	for(it=graph.begin(); it!=graph.end(); it++) dist[it->fi]=-1;
	dist[src]=0;
	
	queue<string> q; q.push(src);
	while(!q.empty()){
		string u = q.front(); q.pop();
		if(u==tgt) return dist[tgt];
		FOR(j,graph[u].size()){
			string v =graph[u][j];
			if(dist[v]==-1){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist[tgt];	
}

int main(){
	//freopen("in.txt","r",stdin);
	
	ios::sync_with_stdio(false);
	int tc, value, M, N, P;
	string u,v;
	
	cin>>tc;
	cout<<"SHIPPING ROUTES OUTPUT"<<endl;
	loop(i,1,tc+1){
		graph.clear();
		cin>>M>>N>>P;
		
		FOR(j,M){
			cin>>u; graph[u];
		}
		
		FOR(j,N){
			cin>>u>>v;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		
		cout<<"\nDATA SET  "<<i<<"\n\n";
		FOR(j,P){
			cin>>value>>src>>tgt;
			int res=bfs();
			if(res==-1){
				cout<<"NO SHIPMENT POSSIBLE"<<endl;
			}else{
				cout<<"$"<<res*value*100<<endl;
			}
		}
		
	}
	cout<<"\nEND OF OUTPUT"<<endl;
	return 0;
}

/*
2
6 7 5
AA CC QR FF DD AB
AA CC
CC QR
DD CC
AA DD
AA AB
DD QR
AB DD
5 AA AB
14 DD CC
1 CC DD
2 AA FF
13 AB QR
3 0 1
AA BB CC
5 AA CC
*/
