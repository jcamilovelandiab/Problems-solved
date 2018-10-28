#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)
#define INF 1e09

using namespace std;

int N,M, best;

int main(){
	int u,d;
	while(cin>>N>>M){
		best=INF;
		FOR(i,M){
			cin>>u>>d;
			int lo=0,hi=N;
			while(lo<=hi){
				int mid=(lo+hi)/2;
				int res=u*mid-d*(N-mid);
				if(res<=0){
					lo=mid+1;
				}else{
					hi=mid-1;
					if(res<best) best=res;
				}
			}
		}
		cout<<best<<endl;
	}
	return 0;
}

