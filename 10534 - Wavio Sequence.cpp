#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

void doLIS(const vector<int> &S, vector<int> &LIS){
	vector<int> L(S.size());
	int lisCount=0;
	loop(i,0,S.size()){
		int pos=lower_bound(L.begin(),L.begin()+lisCount,S[i]) - L.begin();
		L[pos] = S[i];
		if(pos==lisCount) ++lisCount;
		LIS[i]=pos+1;
	}
}

int main(){
	int N, value;
	while(cin>>N){
		vector<int> arr(N);
		loop(i,0,N) cin>>arr[i];
		
		vector<int> LIS(N), LDS(N);
		doLIS(arr,LIS);
		reverse(arr.begin(),arr.end());
		doLIS(arr,LDS);
		reverse(LDS.begin(),LDS.end());
		int maxLIS=0;
		loop(i,0,LIS.size()){
			maxLIS = max(maxLIS, 2*min(LIS[i],LDS[i])-1);
		}
		cout<<maxLIS<<endl;
	}	
	return 0;
}
