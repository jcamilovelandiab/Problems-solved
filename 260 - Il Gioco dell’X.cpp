#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b; i++)

using namespace std;

char matrix[300][300];

int dx[]={-1,-1, 0, 0, 1, 1};
int dy[]={-1, 0, -1,1, 0, 1};

int N;
char winner;

void floodFill(int i, int j){
	if(i==N-1){
		winner='B'; return;
	}
	matrix[i][j]='#';
	loop(k, 0, 6){
		int x=i+dx[k], y=j+dy[k];
		if(x>=0 && x<N &&  y>=0 && y<N && matrix[x][y]=='b'){
			floodFill(x,y);
		}
	}
}


int main(){
	int cont=1;
	while(scanf("%d",&N),N){
		loop(i,0,N) scanf("%s",&matrix[i]);
		winner='W';
		loop(j,0,N){
			if(matrix[0][j]=='b'  && winner=='W') floodFill(0,j);
		}
		printf("%d %c\n",cont++, winner);
	}
	return 0;
}
