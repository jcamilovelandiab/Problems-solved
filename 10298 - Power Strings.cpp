#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXN 1000010

using namespace std;

char P[MAXN];
int b[MAXN], i, j, m;

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
	while(scanf("%s",&P)==1, P[0]!='.'){
		m=strlen(P);
		int r=kmpPreprocess();
		if(r==0) printf("%d\n",1);
		else printf("%d\n",m/(m-r));
	}
	return 0;
}
