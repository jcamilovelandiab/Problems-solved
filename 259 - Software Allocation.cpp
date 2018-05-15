#include <bits/stdc++.h>
#define MAX_V 38
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++) 
#define INF 1e9
// 38 porque 0 -> s, 1..26 ->A..Z, 27..36 -> 0..9 computers, 37 -> t
// 1+26+10+1 = 38

using namespace std;

int res[MAX_V][MAX_V], mf, f, s, t;
typedef vector<int> vi;
vi p;

void augment(int v, int minEdge){
	if(v==s){
		f=minEdge; return;
	}else if(p[v]!=-1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v]-=f;
		res[v][p[v]]+=f;
	}
}

void printLetter(int i){
	loop(j,1,27){
		if(res[i][j]==1){
			cout<<(char)('A' + j - 1);
			return;
		}
	}
	cout<<"_";
}

int main(){
	ios::sync_with_stdio(false);
	string line;
	s=0; t=37;
	while(getline(cin, line)){
		memset(res,0, sizeof(res));
		
		int total=0;
		while(true){
			res[s][line[0]-'A'+1]=line[1]-'0';
			total+=line[1]-'0';
			loop(i,3,line.size()){
				if(line[i]==';') break;
				res[line[0]-'A'+1][27+line[i]-'0']=INF;
			}
			getline(cin, line);
			if(line=="") break;
		}
		loop(i,27,37) res[i][t]=1;
		
		//cout<<"Y"<<endl;
		
		mf=0;
		while(1){
			f=0;
			vi dist(MAX_V, INF); dist[s]=0;
			queue<int> q; q.push(s);
			p.assign(MAX_V, -1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u==t) break;
				FOR(v,MAX_V){
					if(res[u][v]>0 && dist[v]==INF){
						dist[v]=dist[u]+1;
						p[v]=u;
						q.push(v);
					}
				}
			}
			augment(t, INF);
			if(f==0) break;
			mf+=f;
		}
		if(mf==total){
			loop(i,27,37){
				printLetter(i);
			}
		}else cout<<"!";
		cout<<endl;
	}	
}
