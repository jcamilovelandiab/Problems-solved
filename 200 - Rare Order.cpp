#include <bits/stdc++.h>
#define loop(i,a) for(int i=0; i<a; i++)
#define loopr(i,a) for(int i=a; i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define fi first
#define se second

using namespace std;

vector<vector<int> > listAdj(30);
vector<int> util(30), vis(30);
vector<int> tps;

void dfsTPS(int u){
	vis[u]=true;
	loop(i,listAdj[u].size()){
		int v = listAdj[u][i];
		if(!vis[v]){
			dfsTPS(v);
		}
	}
	tps.push_back(u);
}

int main(){
	int limit;
	string linebef, line;
	
	loop(i,30){
		util[i]=false; vis[i]=false;
	}
	
	getline(cin,linebef);
	while(getline(cin,line), line!="#"){
		limit=min(linebef.size(), line.size());
		loop(i,limit){
			if(linebef[i]!=line[i]){
				listAdj[linebef[i]-'A'].push_back(line[i]-'A');
				util[linebef[i]-'A']=true;
				util[line[i]-'A']= true;
				break;
			}
		}
		linebef=line;
	}
	
	loop(u,26){
		if( util[u] && !vis[u]){
			dfsTPS(u);
		}
	}
	
	loopr(i,tps.size()-1) printf("%c",tps[i]+'A');
	puts("");
	
	return 0;
}
