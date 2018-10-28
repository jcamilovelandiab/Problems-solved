#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)

using namespace std;

typedef vector<string> vs;

char mat[30][30];

int N,M, ans, cnt;

int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};

void ff(int i, int j){
	mat[i][j]='0';
	cnt++;
	FOR(k, 8){
		int x=i+dx[k], y=j+dy[k];
		if(x<0 || x>=N || y<0 || y>=M || mat[x][y]!='1') continue;
		ff(x,y);
	}
	ans=max(ans, cnt);
}

int main(){
	int tc; 
	scanf("%d\n",&tc);
	FOR(t,tc){
		
		N=0, M=0;
		
		while(gets(mat[N]), mat[N][0]!='\0'){
			//puts("HEY");
			M=max(M,(int)strlen(mat[N]));
			//printf("%s\n",mat[N]);
			N++;
		}
		/*FOR(i,N){
			printf("%s\n", mat[i]);
		}*/
		ans=0;
		FOR(i,N){
			FOR(j,N){
				if(mat[i][j]=='1'){
					cnt=0;
					ff(i,j);
				}
			}
		}
		if(t!=0) puts("");
		printf("%d\n",ans);
	}	
	return 0;
}
/*
1

11000
01100
00101
10001
01011
*/
