#include <bits/stdc++.h>
#define MAXN 100010
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

char T[MAXN],P[MAXN];
int b[MAXN], n, m, i,j;

void kmpPreprocess(){
	int i,j; b[0]=-1;
	for(i=1, j=-1; P[i]; i++){
		while(j>=0 && P[j+1]!=P[i]) j=b[j];
		if(P[j+1]==P[i]) j++;
		b[i]=j;
	}
}

int kmpSearch(){
	int i,j;
	for(i=0, j=-1; T[i]; i++){
		while(j>=0 && P[j+1]!=T[i]) j=b[j]; //fallo
		if(P[j+1]==T[i]) j++;
	}
	return j;
}

void solve(){
	n = strlen(T); m = strlen(T);
	for(i=0, j=m-1; i<n && j>=0; i++, j--) P[i]=T[j];
	P[m]='\0';
	kmpPreprocess();
	int indice = kmpSearch();
	printf("%s",T);
	loop(i,indice+1, m) printf("%c", P[i]);
	puts("");
}

int main(){
	while(scanf("%s",&T)==1) solve();
	return 0;
}
