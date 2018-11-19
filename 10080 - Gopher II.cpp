/**
	10080 - Gopher II, Uva online judge
	MCBM Max cardinality Bipartite Matching
	time: 0.160s
	@author JCamiloV
*/

#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXN 210
#define x first
#define y second
#define INF 1e09

using namespace std;

typedef pair<double,double> dd;
typedef vector<int> vi;


int Vt, src, tgt, N,M, S, V, mf, f, res[MAXN][MAXN];
double X;
vi p;

void augment(int v, int minEdge){
	if(v==src){
		f=minEdge; return;
	}else if(p[v]!=-1){
		augment(p[v], min(res[p[v]][v], minEdge));
		res[p[v]][v]-=f;
		res[v][p[v]]+=f;
	}
}

void bfs(){
	p.assign(Vt, -1); bitset<MAXN> vis; vis.set(src);
	queue<int> q; q.push(src);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(u==tgt) break;
		FOR(v, Vt){
			if(res[u][v]>0 && !vis[v]){
				vis.set(v); q.push(v); p[v]=u;
			}
		}
	}
}

int edmondsKarp(){
	mf=0;
	while(1){
		f=0;
		bfs();
		augment(tgt, INF);
		if(f==0) break;
		mf+=f;
	}
	return mf;
}

double dist(dd p, dd q){
	return sqrt(pow(p.x-q.x,2)+ pow(p.y-q.y,2));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	double x,y;
	while(cin>>N>>M>>S>>V){
		memset(res, 0, sizeof res);
		X=(double)S*(double)V;
		vector<dd> gophers;
		FOR(i,N){
			cin>>x>>y;
			gophers.push_back(dd(x,y));
		}
		src=0;
		loop(i,1,N+1) res[src][i]=1;
		//cout<<"X = "<<X<<endl;
		FOR(i,M){
			cin>>x>>y;
			dd p = dd(x,y);
			FOR(j, gophers.size()){
				dd q = gophers[j];
				double distance = dist(p,q);
				//cout<<"("<<p.x<<","<<p.y<<") - ("<<q.x<<","<<q.y<<") d=";
				//cout<<distance<<endl;
				if(distance <= X){
					res[j+1][i+1+N]=1;
				}
			}
		}
		Vt=N+M+2; tgt=Vt-1;
		loop(i,N+1, N+M+1) res[i][tgt]=1;
		/*
		FOR(i,Vt){
			cout<<i<<" ->";
			FOR(j,Vt){
				cout<<" "<<res[i][j];
			}
			cout<<endl;
		}*/
		
		cout<<N-edmondsKarp()<<endl;
	}
	return 0;
}

