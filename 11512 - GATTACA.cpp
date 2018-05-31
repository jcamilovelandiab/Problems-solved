#include <bits/stdc++.h>
#define MAXN 5010
#define FOR(i,a) for(int i=0; i<a ; i++)

using namespace std;

typedef pair<int,int> ii;

char T[MAXN], P[MAXN];
int n, m;
int RA[MAXN], tempRA[MAXN];
int SA[MAXN], tempSA[MAXN];
int c[MAXN], Phi[MAXN], PLCP[MAXN], LCP[MAXN];

void countingSort(int k){
	int i, sum, maxi = max(300,n);
	memset(c,0, sizeof c);
	for(i=0; i<n; i++) c[(i+k<n)? RA[i+k] : 0]++;
	for(i=sum=0; i<maxi; i++){
		int t=c[i]; c[i]=sum; sum+=t;
	}
	for(i=0; i<n; i++) tempSA[c[(SA[i]+k<n)? RA[SA[i]+k]: 0]++] = SA[i];
	for(i=0; i<n; i++) SA[i]=tempSA[i];
}

void constructSA(){
	int i,k,r;
	for(i=0; i<n; i++) RA[i]=T[i];
	for(i=0; i<n; i++) SA[i]=i;
	for(k=1; k<n; k<<=1){
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r =0;
		for(i=1; i<n; i++){
			tempRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k] ) ? r: ++r;
		}
		for(i=0; i<n; i++) RA[i]=tempRA[i];
		if(RA[SA[n-1]]==n-1) break;
	}
}

void computeLCP(){
	int i,L;
	Phi[SA[0]]=-1;
	for(i=1; i<n; i++) Phi[SA[i]] = SA[i-1];
	for(i=L=0; i<n; i++){
		if(Phi[i]==-1){
			PLCP[i]=0; continue;
		}
		while(T[i+L]==T[Phi[i]+L]) L++;
		PLCP[i]=L;
		L=max(L-1,0);
	}
	for(i=0; i<n; i++) LCP[i]=PLCP[SA[i]];
}

ii stringMatching(){
	int lo=0, hi=n-1, mid=lo;
	while(lo<hi){
		mid=(lo+hi)/2;
		int res = strncmp(T+SA[mid], P, m);
		if(res>=0) hi=mid;
		else 	   lo=mid+1;
	}
	if(strncmp(T+SA[lo], P, m)!=0) return ii(-1,-1);
	ii ans; ans.first=lo;
	lo=0; hi=n-1; mid=lo;
	while(lo<hi){
		mid=(lo+hi)/2;
		int res=strncmp(T+SA[mid], P, m);
		if(res>0) hi=mid;
		else      lo=mid+1;
	}
	if(strncmp(T+SA[hi], P, m)!=0) hi--;
	ans.second=hi;
	return ans;
}

int main(){
	int tc;
	cin>>tc;
	getchar();
	while(tc--){
		n=(int)strlen(gets(T));
		T[n++]='$';
		constructSA();
		computeLCP();
		//FIND THE INDEX OF THE LONGEST REPEATED SUBSTRING
		int lenLRS=0, indexLRS=-1;
		FOR(i,n){
			if(LCP[i]>lenLRS){
				lenLRS=LCP[i];
				indexLRS=i;
			}
		}
		if(indexLRS==-1){
			cout<<"No repetitions found!"<<endl;
		}else{
			strncpy(P, T+SA[indexLRS], LCP[indexLRS]); // THE LONGEST REPEATED SUBSTRING
			P[LCP[indexLRS]]='\0';
			m=(int)strlen(P);
			ii ans = stringMatching();
			cout<<P<<" "<<ans.second-ans.first+1<<endl;
		}
	}
	return 0;
}
