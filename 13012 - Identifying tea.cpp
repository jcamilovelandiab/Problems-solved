#include <bits/stdc++.h>
#define FOR(i,a) for(int i=0; i<a; i++)

using namespace std;

int main(){
	int te, x;
	while(cin>>te){
		int ans=0;
		FOR(i,5){
			cin>>x;
			if(x==te) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

