#include <bits/stdc++.h>
#define MAXN 100010
#define loop(i,a,b) for(int i=a; i<b; i++)

using namespace std;

char T[MAXN], P[MAXN];
int b[MAXN], i, j, n, m, cont;

int kmpPreprocess(){
	i=0, j=-1, b[0]=-1;
	while(i<m){
		while(j>=0 && P[i]!=P[j]) j=b[j];
		i++; j++;
		b[i]=j;
	}
	return j;
}

int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		getchar();
		scanf("%s",&P);
		m=strlen(P);
		int r=kmpPreprocess();
		if(m%(m-r)) printf("%d\n",m);
		else printf("%d\n",m-r);
		if(N) puts("");
	}
	
	return 0;
}
