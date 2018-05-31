#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define MAXN 20010

using namespace std;

char s[MAXN], temp[MAXN];
int f[MAXN], n;

int booth(){
	int k=0, j, i;
	strcpy(temp,s); strcat(s,temp); memset(f,-1, sizeof f);
	loop(j,1,2*n){
		i=f[j-k-1];
		while(i!=-1 && s[j]!=s[k+i+1]){
			if(s[j]<s[k+i+1]) k=j-i-1;
			i=f[i];
		}
		if(i==-1 && s[j]!=s[k+i+1]){
			if(s[j]<s[k+i+1]) k=j-i-1;
			f[j-k]=-1;
		}else{
			f[j-k]=i+1;
		}
	}
	return k;
}

int main(){
	int tc;
	cin>>tc;
	getchar();
	while(tc--){
		n=(int)strlen(gets(s));
		cout<<booth()+1<<endl;
	}
	return 0;
}
