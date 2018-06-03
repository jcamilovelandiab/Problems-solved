#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 1e9

using namespace std;

int N, mat[110][110], tgt;
char dom[110][110];
bool vis[110];

void dfs(int u){
	vis[u]=true;
	if(u==tgt) return;
	FOR(v, N){
		if(mat[u][v] && !vis[v]){
			dfs(v);
		}
	}
}

int main(){
	int T;
	string line;
	cin>>T;
	FOR(c, T){
		cin>>N;
		FOR(i,N) FOR(j,N) cin>>mat[i][j];
		memset(dom, 'N', sizeof dom);

		//DFS INICIAL
		memset(vis, 0, N+2);
		tgt=N;
		dfs(0);
		FOR(u,N){
			if(vis[u]){
				dom[0][u]='Y';
				dom[u][u]='Y';
			}
		}
		// DESACTIVAMOS VERTICES UNO POR UNO Y CHEQUEAMOS
		bool visINI[110]; FOR(i,N+1) visINI[i]=vis[i]; //HACEMOS COPIA DE LOS VISITADOS INICIALES
		loop(u,1,N){
			memset(vis, 0, N+2);
			vis[u]=true;
			dfs(0);
			FOR(v, N){
				if(visINI[v] && !vis[v]) dom[u][v]='Y';
			}
		}
		
		cout<<"Case "<<c+1<<":"<<endl;
		int tam=2*N+1;
		cout<<"+"; loop(j, 1, tam-1) cout<<"-"; cout<<"+"<<endl;
		FOR(i,N){
			cout<<"|"; FOR(j,N) cout<<dom[i][j]<<"|";
			cout<<endl;
			cout<<"+"; loop(j, 1, tam-1) cout<<"-"; cout<<"+"<<endl;
		}
	}
	return 0;
}
