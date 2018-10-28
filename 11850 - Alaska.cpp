#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)

using namespace std;

int main(){
	int n, x;
	while(cin>>n, n){
		vector<int> stations;
		FOR(i,n){
			cin>>x;
			stations.push_back(x);
		}
		sort(stations.begin(), stations.end());
		bool ans=true;
		FOR(i,n-1){
			if(stations[i]+200<stations[i+1]){
				ans=false; break;
			}
		}
		if(200<(1422-stations[n-1])*2) ans=false;
		cout<<((ans)?"POSSIBLE":"IMPOSSIBLE")<<endl;
	}
	return 0;
}

