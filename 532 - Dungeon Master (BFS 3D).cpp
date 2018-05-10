#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int n,m,l;
char matrix[40][40][40];

int dx[]={ 0, 0, 0, 0, 1,-1};
int dy[]={ 1,-1, 0, 0, 0, 0};
int dz[]={ 0, 0,-1, 1, 0, 0};

struct pos{
	int x, y, z;
	pos() : x(-1), y(-1), z(-1) {}
	pos(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

int BFS(pos S, pos E){
	int dist [40][40][40];
	memset(dist,-1,sizeof(dist));

	dist[S.x][S.y][S.z]=0;
		
	queue<pos> q; q.push(S);
	while(!q.empty()){
		pos u=q.front(); q.pop();
		vector<pos> neighboors; // lista de adyacencia de u
		loop(i,0,6){
			int X=u.x+dx[i], Y=u.y+dy[i], Z=u.z+dz[i];
			if(X>=0 && X<n && Y>=0 && Y<m && Z>=0 && Z<l && (matrix[X][Y][Z]=='.'||matrix[X][Y][Z]=='E')) neighboors.push_back(pos(X,Y,Z));
		}
		loop(j,0,neighboors.size()){
			pos v=neighboors[j];
			if(dist[v.x][v.y][v.z]==-1){
				dist[v.x][v.y][v.z]=dist[u.x][u.y][u.z]+1;
				q.push(v);
			}
		}
	}
	/*loop(i,0,n){
		loop(j,0,m){
			loop(k,0,l) printf("%d ",dist[i][j][k]);
			puts("");
		}
		puts("");
	}*/
	return dist[E.x][E.y][E.z];
}

int main(){
	
	while(cin>>n>>m>>l, n){
		pos S, E;
		loop(i,0,n){
			loop(j,0,m){
				cin>>matrix[i][j];
				loop(k,0,l){
					if(matrix[i][j][k]=='S') S.x=i, S.y=j, S.z=k;
					else if(matrix[i][j][k]=='E') E.x=i, E.y=j, E.z=k;
				}
			}
		}
		int closestPath=BFS(S,E);
		if(closestPath!=-1) printf("Escaped in %d minute(s).\n", closestPath);
		else puts("Trapped!");
	}
	return 0;
}
