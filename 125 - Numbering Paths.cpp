#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define loop(i,a,b) for(int i=a; i<b; i++)
#define x first
#define y second
#define MAXN 31

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int graph[MAXN][MAXN];

int main(){
	int M,x,y, N, city=0;
	while(cin>>M){
		memset(graph, 0, sizeof graph);
		N=0;
		FOR(i,M){
			cin>>x>>y;
			graph[x][y]=1;
			N=max(N, max(x,y));
		}
		N++;
		FOR(k,N){
			FOR(i,N){
				FOR(j,N){
					if(graph[i][k]!=0 && graph[k][j]!=0){ //existe un camino de i->k->j
						graph[i][j]+=graph[i][k]*graph[k][j];
					}
				}
			}
		}
		FOR(k,N){
			if(graph[k][k]!=0){ //existe un ciclo en el nodo k
				FOR(i,N){
					FOR(j,N){
						if(graph[i][k]!=0 && graph[k][j]!=0){ //existe un camino de i->k->j
							graph[i][j]=-1; // i, j esta en el ciclo de k
						}
					}
				}
			}
		}
		cout<<"matrix for city "<<city++<<endl;
		FOR(i,N){
			cout<<graph[i][0];
			loop(j,1,N) cout<<" "<<graph[i][j];
			cout<<endl;
		}
	}
	return 0;
}

